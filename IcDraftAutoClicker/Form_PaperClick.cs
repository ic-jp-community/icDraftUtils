using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Automation;
using System.Windows.Forms;
using static IcDraftAutoClicker.IcDraftAutoClickerRetCode;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Tab;

namespace IcDraftAutoClicker
{
    public partial class Form_PaperClick : Form
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
            public string data;

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
        private string _clickPaperName = string.Empty;
        private string _icVersion = string.Empty;

        public Form_PaperClick(string version, string targetExbFilePath , string paperName)
        {
            InitializeComponent();
            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, string.Format("Start Exb:{0} PaperName:{1} ", targetExbFilePath, paperName ), string.Empty, false);
            this._icVersion = version;
            this._targetExbFilePath = targetExbFilePath;
            this._clickPaperName = paperName;
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

        private void FindPaperTabs(AutomationElement IcWindowForm, string fileName, string modelPaperName, ref AutomationElement targetWindowTab, ref AutomationElement targetModelPaperTab)
        {
            string shorteningWindowTitle = string.Empty;
            targetWindowTab = null;
            targetModelPaperTab = null;

            AutomationElementCollection mainWindowTabList = IcWindowForm.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Tab));
            if (mainWindowTabList == null || mainWindowTabList.Count == 0)
            {
                return;
            }
            foreach (AutomationElement mainWindow in mainWindowTabList)
            {
                AutomationElementCollection windowTabList = mainWindow.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.TabItem));
                foreach (AutomationElement windowTab in windowTabList)
                {
                    string windowTabName = windowTab.Current.Name.TrimEnd('*');
                    if (windowTabName == fileName)
                    {
                        targetWindowTab = windowTab;
                        break;
                    }
                }
                if ((targetWindowTab == null) && 
                    (fileName.Length > 10))
                {
                    /* 文字列が長すぎて省略された可能性があるため再探索 */
                    foreach (AutomationElement windowTab in windowTabList)
                    {
                        if(windowTab.Current.Name.Length < 10)
                        {
                            continue;
                        }
                        string windowTabName = windowTab.Current.Name.TrimEnd('*');
                        string windowTabNameUpper = windowTabName.Substring(0, 10);
                        string windowTabNameLower = windowTabName.Substring((windowTabName.Length - 6), 6);
                        string fileNameUpper = fileName.Substring(0, 10);
                        string fileNameLower = fileName.Substring((fileName.Length - 6), 6);
                        if ((string.Equals(windowTabNameUpper, fileNameUpper) == true) &&
                            (string.Equals(windowTabNameLower, fileNameLower) == true))
                        {
                            shorteningWindowTitle = windowTab.Current.Name;
                            targetWindowTab = windowTab;
                            break;
                        }
                    }
                }
            }

            AutomationElementCollection paneList = IcWindowForm.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Pane));
            foreach (AutomationElement pane in paneList)
            {
                AutomationElementCollection windowList = pane.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Window));
                foreach (AutomationElement window in windowList)
                {
                    string windowName = window.Current.Name;
                    if(string.IsNullOrEmpty(windowName) == true)
                    {
                        continue;
                    }
                    if ((windowName.Contains(fileName) == true) ||
                        (string.Equals(windowName, shorteningWindowTitle) == true))
                    {
                        AutomationElementCollection tabList = window.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Pane));
                        foreach (AutomationElement tab in tabList)
                        {
                            AutomationElementCollection tabSubList = tab.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.Tab));
                            foreach (AutomationElement subTab in tabSubList)
                            {
                                AutomationElementCollection modelPaperList = subTab.FindAll(TreeScope.Children, new PropertyCondition(AutomationElement.ControlTypeProperty, ControlType.TabItem));
                                foreach (AutomationElement modelPaper in modelPaperList)
                                {
                                    if (modelPaper.Current.Name.Contains(Path.GetFileName(modelPaperName)) == true)
                                    {
                                        targetModelPaperTab = modelPaper;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return;
        }

        public async void PaperClicker()
        {
            int timerMs = 10000;
            timerMs = this._config.CommonConfig.AutoClickerConfig.saveWindowCheckTimerMs;
            this.labelAutoClicker.Text = "自動クリック処理の実行中です。";
            this.labelCurrentMode.Text = string.Format("model/paperタブ[{0}]を検索しています。", this._clickPaperName);

            /* クリック対象のウィンドウ */
            AutomationElement rootElement = AutomationElement.RootElement;
            if (rootElement == null)
            {
                return;
            }

            /* IRONCADのプロセスを取得する */
            Process[] procList = Process.GetProcessesByName("IRONCAD");
            foreach (Process proc in procList)
            {

                /* 実行パスとタイトルを取得 */
                string exePath = proc.MainModule.FileName;
                string title = proc.MainWindowTitle;

                do
                {
                    WindowPropList.Clear();

                    /* 子ウィンドウを取得 */
                    EnumThreadWindows(proc.Threads[0].Id, EnumerateThreadWindows, IntPtr.Zero);

                    /* 子ウィンドウからクリックするウィンドウを見つける */
                    for (int i = 0; i < WindowPropList.Count; i++)
                    {
                        WindowProp prop = WindowPropList[i];

                        /* クリック対象のウィンドウかチェックする */
                        AutomationElement IcWindowForm = AutomationElement.FromHandle(prop.hwnd);
                        AutomationElement targetWindowTab = null;
                        AutomationElement targetModelPaperTab = null;
                        FindPaperTabs(IcWindowForm, Path.GetFileName(this._targetExbFilePath), this._clickPaperName, ref targetWindowTab, ref targetModelPaperTab);
                        if(targetWindowTab != null)
                        {
                            InvokePattern invokePattern = (InvokePattern)targetWindowTab.GetCurrentPattern(InvokePattern.Pattern);
                            invokePattern.Invoke();
                        }
                        if(targetModelPaperTab != null)
                        {
                            InvokePattern invokePattern = (InvokePattern)targetModelPaperTab.GetCurrentPattern(InvokePattern.Pattern);
                            invokePattern.Invoke();
                            exitCode = RETCODE_PAPERCLICK_CLICK_OK;
                            break;
                        }
                    }
                    if ((exitCode & RETCODE_PAPERCLICK_CLICK_OK) != 0) 
                    {
                        break;
                    }
                    await Task.Delay(timerMs);
                } while (true);
            }
            Application.Exit();
        }
        private void IcDraftSingleClicker_FormClosing(object sender, FormClosingEventArgs e)
        {
            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, string.Format("End Exb:{0} PaperName:{1} ExitCode:{2}", _targetExbFilePath, _clickPaperName, exitCode), string.Empty, false);
            Environment.ExitCode = exitCode;
        }
        private void SetExitCode(int exitCode)
        {
            this.exitCode = this.exitCode | exitCode;
        }
        private void IcDraftAutoClicker_Shown(object sender, EventArgs e)
        {
                this.buttonSettings.Visible = false;
                this.buttonParseLog.Visible = false;
                PaperClicker();
        }

        private void buttonSettings_Click(object sender, EventArgs e)
        {
            Form_Settings settings = new Form_Settings();
            settings.ShowDialog();
        }

        private IcDraftAutoClickerSetting.IcDraftUtilsConfig _config = new IcDraftAutoClickerSetting.IcDraftUtilsConfig();
        private void IcDraftAutoClicker_Load(object sender, EventArgs e)
        {
            IcDraftAutoClickerSetting.ReadIcDraftUtilsCommonSetting(IcDraftAutoClickerSetting.GetCommonConfigFilePath());
            IcDraftAutoClickerSetting.ReadIcDraftUtilsUserSetting(IcDraftAutoClickerSetting.GetUserConfigFilePath());
            this._config = IcDraftAutoClickerSetting.GetConfig();
        }

        private void buttonParseLog_Click(object sender, EventArgs e)
        {
            Form_ShowResult frmShowResult = new Form_ShowResult(string.Empty, string.Empty);
            frmShowResult.ShowDialog();
        }
    }
}
