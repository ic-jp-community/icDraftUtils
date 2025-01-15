using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Automation;
using System.Windows.Forms;
using static IcDraftAutoClicker.IcDraftAutoClickerRetCode;

namespace IcDraftAutoClicker
{
    public partial class IcDraftAutoClicker : Form
    {
        #region win32Api
        // EnumWindowsから呼び出されるコールバック関数のデリゲート
        private delegate bool EnumThreadDelegate(IntPtr hWnd, IntPtr lParam);
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        static extern bool EnumThreadWindows(int dwThreadId, EnumThreadDelegate lpfn, IntPtr lParam);

        // ウィンドウの表示状態を調べる(WS_VISIBLEスタイルを持つかを調べる)
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        private static extern bool IsWindowVisible(IntPtr hWnd);

        //ウィンドウのタイトルの長さを取得する
        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern int GetWindowTextLength(IntPtr hWnd);
        
        // ウィンドウのタイトルバーのテキストを取得
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        private static extern int GetWindowText(IntPtr hWnd, StringBuilder title, int size);

        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern int GetWindowThreadProcessId(IntPtr hWnd, out int lpdwProcessId);
        #endregion

        public class WindowProp
        {
            public IntPtr hwnd { get; set; }
            public int ProcessId { get; set; }
            public string Title { get; set; }

            public WindowProp()
            {
                this.hwnd = IntPtr.Zero;
                this.ProcessId = -1;
                this.Title = string.Empty;
            }
            public WindowProp(IntPtr ptr, int procId, string title)
            {
                this.hwnd = ptr;
                this.ProcessId = procId;
                this.Title = title;
            }
        }

        private static List<WindowProp> WindowPropList = new List<WindowProp>();
        public int exitCode = RETCODE_NONE;
        private string _targetExbFilePath = string.Empty;
        private bool _waitSaveDialog = false;
        private bool _waitNoSave = false;
        private bool _waitUpdateDialog = false;
        private bool _waitUpdatePaperDialog = false;
        private string _icVersion = string.Empty;
        private IcDraftAutoClickerSetting.IcDraftUtilsConfig _config = new IcDraftAutoClickerSetting.IcDraftUtilsConfig();

        public IcDraftAutoClicker(string version, string targetExbFilePath , bool waitSaveDialog, bool waitNoSave, bool waitUpdateDialog, bool waitUpdatePaperDialog)
        {
            InitializeComponent();
            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, string.Format("Start Exb:{0}  WaitSaveDialog:{1}  WaitUpdateDialog:{2}  waitUpdatePaperDialog:{3}", targetExbFilePath, waitSaveDialog, waitUpdateDialog, waitUpdatePaperDialog), string.Empty, false);
            this._icVersion = version;
            this._targetExbFilePath = targetExbFilePath;
            this._waitSaveDialog = waitSaveDialog;
            this._waitNoSave = waitNoSave; ;
            this._waitUpdateDialog = waitUpdateDialog;
            this._waitUpdatePaperDialog = waitUpdatePaperDialog;
        }

        private void IcDraftAutoClicker_Load(object sender, EventArgs e)
        {
            IcDraftAutoClickerSetting.ReadIcDraftUtilsCommonSetting(IcDraftAutoClickerSetting.GetCommonConfigFilePath());
            IcDraftAutoClickerSetting.ReadIcDraftUtilsUserSetting(IcDraftAutoClickerSetting.GetUserConfigFilePath());
            this._config = IcDraftAutoClickerSetting.GetConfig();
        }

        private void IcDraftAutoClicker_Shown(object sender, EventArgs e)
        {
            if ((this._waitSaveDialog == true) || (this._waitUpdateDialog == true) || (this._waitUpdatePaperDialog == true))
            {
                this.buttonSettings.Visible = false;
                this.buttonParseLog.Visible = false;
                AutoUpdateClicker();
            }
        }

        // ウィンドウを列挙するコールバックメソッド
        private static bool EnumerateThreadWindows(IntPtr hWnd, IntPtr lParam)
        {
            // ウィンドウが可視かどうか調べて、表示してないのものを除外する
            if (IsWindowVisible(hWnd) != true)
            {
                return true;
            }

            //ウィンドウのタイトルの長さを取得する
            int textLen = GetWindowTextLength(hWnd);
            if (textLen == 0)
            {
                return true;
            }

            //ウィンドウのタイトルを取得する
            var title = new StringBuilder(textLen + 1);
            GetWindowText(hWnd, title, title.Capacity);
            
            // ウィンドウハンドルからプロセスIDを取得
            int processId;
            GetWindowThreadProcessId(hWnd, out processId);
            
           
            WindowPropList.Add(new WindowProp(hWnd, processId, title.ToString()));

            // 途中で列挙をやめるときは、return false;にする
            // ウィンドウの列挙を継続する
            return true;
        }

        private bool ExistCaxaTab(AutomationElement IcWindowForm, string fileName)
        {
            AutomationElement saveText = null;
            if(IcWindowForm.Current.Name.Contains(fileName) == true)
            {
                return true;
            }
            AutomationElementCollection tabList = IcWindowForm.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Tab));
            foreach (AutomationElement tab in tabList)
            {
                AutomationElementCollection tabItems = tab.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.TabItem));
                foreach (AutomationElement tabItem in tabItems)
                {
                    if (string.Equals(tabItem.Current.Name, fileName) == true)
                    {
                        return true;
                        break;
                    }
                }
            }
            return false;
        }

        public async void AutoUpdateClicker()
        {
            int timerMs = 10000;
            int timeOutMs = -1;
            if (_waitSaveDialog == true)
            {
                timerMs = this._config.CommonConfig.AutoClickerConfig.saveWindowCheckTimerMs;
                this.labelAutoClicker.Text = "自動更新処理の実行中です。";
                this.labelCurrentMode.Text = "保存ウィンドウを待っています。";
            }
            if((_waitUpdateDialog == true) || (_waitUpdatePaperDialog == true))
            {
                timerMs = this._config.CommonConfig.AutoClickerConfig.updateWindowCheckTimerMs;
                timeOutMs = this._config.CommonConfig.AutoClickerConfig.updatePaperTimeOutMs;
                this.labelAutoClicker.Text = "自動更新処理の実行中です。";
                this.labelCurrentMode.Text = "更新ウィンドウを待っています。";
            }
            /* クリック対象のウィンドウ */
            AutomationElement rootElement = AutomationElement.RootElement;
            if (rootElement == null)
            {
                return;
            }

            /* IRONCADのプロセスを取得する */
            Process[] procList = Process.GetProcessesByName("IRONCAD");
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            foreach (Process proc in procList)
            {
                /* 実行パスとタイトルを取得 */
                string exePath = proc.MainModule.FileName;
                string title = proc.MainWindowTitle;
                await Task.Delay(3000);
                do
                {
                    bool IcSubWindowFindFlag = false;
                    bool AlreadyClosedFlag = false;
                    WindowPropList.Clear();

                    /* 子ウィンドウを取得 */
                    EnumThreadWindows(proc.Threads[0].Id, EnumerateThreadWindows, IntPtr.Zero);

                    /* 子ウィンドウからクリックするウィンドウを見つける */
                    for (int i = 0; i < WindowPropList.Count; i++)
                    {
                        WindowProp prop = WindowPropList[i];

                        if (_waitSaveDialog == true)
                        {
                            /* クリック対象のウィンドウかチェックする */
                            if (prop.Title != string.Concat("IRONCAD ", this._icVersion))
                            {
                                /* クリック対象のウィンドウでない */
                                AutomationElement IcWindowForm = AutomationElement.FromHandle(prop.hwnd);
                                bool tabExist = ExistCaxaTab(IcWindowForm, Path.GetFileName(this._targetExbFilePath));
                                if(tabExist != true)
                                {
                                    /* Tabがないので閉じた */
                                    AlreadyClosedFlag = true;
                                    break;
                                }
                            }
                            else
                            {
                                IcSubWindowFindFlag = true;
                                /* クリック対象のウィンドウ */
                                AutomationElement IcWindowForm = AutomationElement.FromHandle(prop.hwnd);
                                bool tabExist = ExistCaxaTab(IcWindowForm, Path.GetFileName(this._targetExbFilePath));
                                AutomationElement saveText = null;
                                AutomationElementCollection aecListItems = IcWindowForm.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Text));
                                foreach (AutomationElement aec in aecListItems)
                                {
                                    if (aec.Current.Name.Contains("への変更を保存しますか?") == true)
                                    {
                                        saveText = aec;
                                        break;
                                    }
                                }
                                AutomationElement buttonYes = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "はい(Y)")); // This part gets the handle of the button inside the messagebox
                                AutomationElement buttonNo = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "いいえ(N)")); // This part gets the handle of the button inside the messagebox
                                if (saveText != null)
                                {
                                    if(_waitNoSave == true)
                                    {
                                        /* 保存のウィンドウ */
                                        if (buttonNo != null)
                                        {
                                            /* はいをクリックして更新する */
                                            InvokePattern invokePattern = (InvokePattern)buttonNo.GetCurrentPattern(InvokePattern.Pattern);
                                            invokePattern.Invoke();
                                            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, "Save ClickNo", string.Empty, false);
                                            SetExitCode(RETCODE_WINDOW_SAVE_SET_NO);
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        /* 保存のウィンドウ */
                                        if (buttonYes != null)
                                        {
                                            /* はいをクリックして更新する */
                                            InvokePattern invokePattern = (InvokePattern)buttonYes.GetCurrentPattern(InvokePattern.Pattern);
                                            invokePattern.Invoke();
                                            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, "Save ClickYes", string.Empty, false);
                                            SetExitCode(RETCODE_WINDOW_SAVE_SET_YES);
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    /* 保存のウィンドウでない */
                                    /* とりあえず、いいえをクリック */
                                    if (buttonNo != null)
                                    {
                                        InvokePattern invokePattern = (InvokePattern)buttonNo.GetCurrentPattern(InvokePattern.Pattern);
                                        invokePattern.Invoke();
                                        IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, "NoSave ClickNo", string.Empty, false);
                                        SetExitCode(RETCODE_WINDOW_UNDEF_SET_NO);
                                    }
                                }
                            }
                        }
                        if ((_waitUpdateDialog == true) || (_waitUpdatePaperDialog == true))
                        {
                            /* クリック対象のウィンドウかチェックする */
                            if (prop.Title == string.Concat("IRONCAD ", this._icVersion))
                            {
                                StringBuilder sbErrorText = new StringBuilder();
                                IcSubWindowFindFlag = true;
                                /* クリック対象のウィンドウ */
                                AutomationElement IcWindowForm = AutomationElement.FromHandle(prop.hwnd);
                                AutomationElement updateText = null;
                                AutomationElement update3DLinkNotFoundText = null; 
                                AutomationElementCollection aecListItems = IcWindowForm.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Text));
                                foreach (AutomationElement aec in aecListItems)
                                {
                                    if (aec.Current.Name.Contains("3Dシーン ファイルの内容が変更されました。変更を反映しますか？") == true)
                                    {
                                        updateText = aec;
                                        break;
                                    }
                                    if (aec.Current.Name.Contains("3Dシーン ファイルの位置を更新してください:") == true)
                                    {
                                        update3DLinkNotFoundText = aec;
                                        break;
                                    }
                                }
                                if((updateText ==null) && (update3DLinkNotFoundText == null))
                                {
                                    foreach (AutomationElement aec in aecListItems)
                                    {
                                        sbErrorText.AppendLine(aec.Current.Name);
                                    }
                                }
                                if (updateText != null)
                                {
                                    AutomationElement buttonYes = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "はい(Y)")); // This part gets the handle of the button inside the messagebox
                                    AutomationElement buttonNo = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "いいえ(N)")); // This part gets the handle of the button inside the messagebox
                                    /* 更新のウィンドウ */
                                    if (buttonYes != null)
                                    {
                                        /* はいをクリックして更新する */
                                        InvokePattern invokePattern = (InvokePattern)buttonYes.GetCurrentPattern(InvokePattern.Pattern);
                                        invokePattern.Invoke();
                                        SetExitCode(RETCODE_WINDOW_UPDATE_SET_YES);
                                        IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, "Update ClickYes", string.Empty, false);
                                        break;
                                    }
                                }
                                else if (update3DLinkNotFoundText != null)
                                {
                                    AutomationElement buttonYes = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "はい(Y)")); // This part gets the handle of the button inside the messagebox
                                    AutomationElement buttonNo = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "いいえ(N)")); // This part gets the handle of the button inside the messagebox
                                    if (buttonNo != null)
                                    {
                                        /* いいえをクリックして更新する */
                                        InvokePattern invokePattern = (InvokePattern)buttonNo.GetCurrentPattern(InvokePattern.Pattern);
                                        invokePattern.Invoke();
                                        SetExitCode(RETCODE_WINDOW_3DNOTFOUND_SET_NO);
                                        IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, "3DNotFound ClickNo", string.Empty, false);
                                        break;
                                    }
                                }
                                else
                                {
                                    AutomationElement buttonYes = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "はい(Y)")); // This part gets the handle of the button inside the messagebox
                                    AutomationElement buttonNo = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "いいえ(N)")); // This part gets the handle of the button inside the messagebox
                                    AutomationElement buttonOk = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "OK")); // This part gets the handle of the button inside the messagebox
                                    AutomationElement buttonCancel = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "キャンセル")); // This part gets the handle of the button inside the messagebox
                                    /* 更新のウィンドウでない */
                                    /* とりあえず、いいえをクリック */
                                    if (buttonNo != null)
                                    {
                                        InvokePattern invokePattern = (InvokePattern)buttonNo.GetCurrentPattern(InvokePattern.Pattern);
                                        invokePattern.Invoke();
                                        IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_ERROR, string.Format("未定義のウィンドウが見つかりました。\n処理中のファイル:{0}", _targetExbFilePath), string.Format("windowのテキスト: {0}",sbErrorText.ToString()), true);
                                        SetExitCode(RETCODE_WINDOW_UNDEF_SET_NO);
                                    }
                                }
                            }
                            else if (prop.Title == "寸法のチェック")
                            {
                                IcSubWindowFindFlag = true;
                                /* クリック対象のウィンドウ */
                                AutomationElement IcWindowForm = AutomationElement.FromHandle(prop.hwnd);
                                AutomationElement buttonOk = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "OK")); // This part gets the handle of the button inside the messagebox
                                AutomationElement buttonCancel = IcWindowForm.FindFirst(TreeScope.Descendants, new PropertyCondition(AutomationElement.NameProperty, "キャンセル")); // This part gets the handle of the button inside the messagebox
                                /* 更新のウィンドウでない */
                                /* とりあえず、いいえをクリック */
                                if (buttonCancel != null)
                                {
                                    InvokePattern invokePattern = (InvokePattern)buttonCancel.GetCurrentPattern(InvokePattern.Pattern);
                                    invokePattern.Invoke();
                                    IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, "DimensionCheck ClickCancel", string.Empty, false);
                                    SetExitCode(RETCODE_WINDOW_DIM_CHECK_SET_CANCEL);
                                    break;
                                }
                            }
                            else
                            {
                                /* クリック対象のウィンドウでない */
                                continue;
                            }
                        }
                    }
                    if (((exitCode & RETCODE_WINDOW_SAVE_SET_YES) != 0) ||
                        ((exitCode & RETCODE_WINDOW_SAVE_SET_NO) != 0) ||
                        ((exitCode & RETCODE_WINDOW_DIM_CHECK_SET_CANCEL) != 0) ||
                        (AlreadyClosedFlag == true))
                    {
                        break;
                    }
                    if((timeOutMs != -1) &&
                       (stopwatch.ElapsedMilliseconds > timeOutMs))
                    {
                        break;
                    }
                    await Task.Delay(timerMs);
                } while (true);
            }
            Application.Exit();
        }
        private void IcDraftAutoClicker_FormClosing(object sender, FormClosingEventArgs e)
        {
            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, string.Format("End Exb:{0} WaitSaveDialog:{1} WaitUpdateDialog:{2}  WaitPaperUpdateDialog:{3}  ExitCode:{4}", _targetExbFilePath, _waitSaveDialog, _waitUpdateDialog, _waitUpdatePaperDialog,  exitCode), string.Empty, false);
            Environment.ExitCode = exitCode;
        }
        private void SetExitCode(int exitCode)
        {
            this.exitCode = this.exitCode | exitCode;
        }


        private void buttonSettings_Click(object sender, EventArgs e)
        {
            Form_Settings settings = new Form_Settings();
            settings.ShowDialog();
        }



        private void buttonParseLog_Click(object sender, EventArgs e)
        {
            Form_ShowResult frmShowResult = new Form_ShowResult(string.Empty, string.Empty);
            frmShowResult.ShowDialog();
        }
    }
}
