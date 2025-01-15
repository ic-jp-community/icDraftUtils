using ArcSuiteAddinSetting;
using IcDraftAutoClicker;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SetupConfiguration
{
    public class WindowWrapper : IWin32Window
    {
        private readonly IntPtr hwnd;
        public IntPtr Handle
        {
            get { return hwnd; }
        }
        public WindowWrapper(IntPtr handle)
        {
            hwnd = handle;
        }
    }
    public static class TopMostMessageBox
    {
        public static void Show(string message)
        {
            var proc = Process.GetProcessesByName("msiexec").FirstOrDefault(p => p.MainWindowTitle == "IcDraftUtils");
            if (proc != null)
            {
                MessageBox.Show(new WindowWrapper(proc.MainWindowHandle), message); // 結果、メッセージボックスも最前面に表示される
            }
            else
            {
                MessageBox.Show(message); // 結果、メッセージボックスも最前面に表示される
            }
        }
    }
    
    [System.ComponentModel.RunInstaller(true)]
    public class IronCAD_Config : System.Configuration.Install.Installer
    {
        public override void Install(System.Collections.IDictionary stateSaver)
        {
            base.Install(stateSaver);
#if false
            MessageBox.Show("install", "debug", MessageBoxButtons.OK);
#endif
            string targetdir = this.Context.Parameters["dir"];
            targetdir = targetdir.TrimEnd('\\');
            string crxFilePath = Path.Combine(targetdir, "CrxIcDraftUtils.crx");
           
            /* IRONCAD[CAXA]のConfigファイルを書き換える */
            bool ret1 = AddinConfig.AddConfig(@"C:\Program Files\IronCAD\2021\bin\CAXADraft\Modules\CxAutorun.cx",
                                    crxFilePath);
            bool ret2 = AddinConfig.AddConfig(@"C:\Program Files\IronCAD\2022\bin\CAXADraft\Modules\CxAutorun.cx",
                                    crxFilePath);
            bool ret3 = AddinConfig.AddConfig(@"C:\Program Files\IronCAD\2023\bin\CAXADraft\Modules\CxAutorun.cx",
                                    crxFilePath);
            bool ret4 = AddinConfig.AddConfig(@"C:\Program Files\IronCAD\2024\bin\CAXADraft\Modules\CxAutorun.cx",
                                    crxFilePath);
            if ((ret1 != true) && (ret2 != true) && (ret3 != true) && (ret4 != true))
            {
                TopMostMessageBox.Show("IRONCADが見つかりませんでした。\n(インストールは続行されます)");
            }

            /* 新しいコンフィグファイルに設定を引き継ぐ(もしくは新規に作成する) */
            InstallNewCommonConfig();
            InstallNewUserConfig();
        }

        /// <summary>
        /// 共通コンフィグを作成/引継ぎする
        /// </summary>
        private void InstallNewCommonConfig()
        {
            string BakUpCommonConfigPath = string.Empty;
            string CommonConfigPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData), @"IRONCAD JP Community\IcDraftUtils\IcDraftUtilsCommon.config");
            string targetDirectory = Path.GetDirectoryName(CommonConfigPath);

            /* 古い共通コンフィグ ファイルをバックアップする */
            if (File.Exists(CommonConfigPath) == true)
            {
                BakUpCommonConfigPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData), @"IRONCAD JP Community\IcDraftUtils\IcDraftUtilsCommon_Backup" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".config");
                File.Move(CommonConfigPath, BakUpCommonConfigPath);
            }

            /* 共通コンフィグ ファイルの格納ディレクトリが無かったら作成する */
            if (Directory.Exists(targetDirectory) == false)
            {
                Directory.CreateDirectory(targetDirectory);
            }

            /* 新しい共通コンフィグ ファイルに古い共通コンフィグファイルのデータを反映する */
            if (string.IsNullOrEmpty(BakUpCommonConfigPath) != true)
            {
                ///* 古い共通コンフィグ ファイルあり。設定値の読み込みにトライ */
                IcDraftAutoClickerSetting.IcDraftUtilsCommonConfig oldCommonConfig = new IcDraftAutoClickerSetting.IcDraftUtilsCommonConfig();
                bool ret = IcDraftAutoClickerSetting.ReadIcDraftUtilsCommonSetting(BakUpCommonConfigPath, ref oldCommonConfig, false);
                if(ret == false)
                {
                    TopMostMessageBox.Show("以前のバージョンの共通設定の引き継ぎに失敗しました。\n設定から再設定をお願いいたします。");
                }
            }
            else
            {
                ///* 古い共通コンフィグファイルなし。デフォルト値で共通コンフィグ ファイルを作成 */
                IcDraftAutoClickerSetting.SetCommonConfig(new IcDraftAutoClickerSetting.IcDraftUtilsCommonConfig());
            }

            /* 現在の設定値で共通コンフィグ ファイルを作成する */
            IcDraftAutoClickerSetting.WriteIcDraftUtilsCommonSetting(CommonConfigPath);
            setEveryOneAccessControl(CommonConfigPath);
        }

        /// <summary>
        /// ユーザコンフィグを作成/引継ぎする
        /// </summary>
        private void InstallNewUserConfig()
        {
            string BakUpUserConfigPath = string.Empty;
            string UserConfigPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), @"IRONCAD JP Community\IcDraftUtils\IcDraftUtilsUser.config");
            string targetDirectory = Path.GetDirectoryName(UserConfigPath);

            /* 古いユーザコンフィグ ファイルをバックアップする */
            if (File.Exists(UserConfigPath) == true)
            {
                BakUpUserConfigPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), @"IRONCAD JP Community\IcDraftUtils\IcDraftUtilsUser_Backup" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".config");
                File.Move(UserConfigPath, BakUpUserConfigPath);
            }

            /* ユーザコンフィグ ファイルの格納ディレクトリが無かったら作成する */
            if (Directory.Exists(targetDirectory) == false)
            {
                Directory.CreateDirectory(targetDirectory);
            }

            /* 新しいユーザコンフィグ ファイルに古いユーザコンフィグファイルのデータを反映する */
            if (string.IsNullOrEmpty(BakUpUserConfigPath) != true)
            {
                /* 古いユーザコンフィグ ファイルあり。設定値の読み込みにトライ */
                IcDraftAutoClickerSetting.IcDraftUtilsUserConfig oldUserConfig = new IcDraftAutoClickerSetting.IcDraftUtilsUserConfig();
                bool ret = IcDraftAutoClickerSetting.ReadIcDraftUtilsUserSetting(BakUpUserConfigPath, ref oldUserConfig, false);
                if (ret == false)
                {
                    TopMostMessageBox.Show("以前のバージョンのユーザー設定の引き継ぎに失敗しました。\n設定から再設定をお願いいたします。");
                }
            }
            else
            {
                ///* 古いユーザコンフィグファイルなし。デフォルト値でユーザコンフィグ ファイルを作成 */
                IcDraftAutoClickerSetting.SetUserConfig(new IcDraftAutoClickerSetting.IcDraftUtilsUserConfig());
            }

            /* 現在の設定値でユーザコンフィグ ファイルを作成する */
            IcDraftAutoClickerSetting.WriteIcDraftUtilsUserSetting(UserConfigPath);
            setEveryOneAccessControl(UserConfigPath);
        }

        public override void Commit(System.Collections.IDictionary savedState)
        {
            base.Commit(savedState);
        }

        public override void Rollback(System.Collections.IDictionary savedState)
        {
            base.Rollback(savedState);
        }

        public override void Uninstall(System.Collections.IDictionary savedState)
        {
            base.Uninstall(savedState);
#if false
            MessageBox.Show("uninstall", "debug", MessageBoxButtons.OK);
#endif
            string targetdir = this.Context.Parameters["dir"];
            targetdir = targetdir.TrimEnd('\\');
            string crxFilePath = Path.Combine(targetdir, "CrxIcDraftUtils.crx");

            for (int count = 0; count < 10; count++)
            {
                int delnum =  AddinConfig.DeleteConfig(@"C:\Program Files\IronCAD\2021\bin\CAXADraft\Modules\CxAutorun.cx",
                                                           crxFilePath);
                delnum += AddinConfig.DeleteConfig(@"C:\Program Files\IronCAD\2022\bin\CAXADraft\Modules\CxAutorun.cx",
                                           crxFilePath);
                delnum += AddinConfig.DeleteConfig(@"C:\Program Files\IronCAD\2023\bin\CAXADraft\Modules\CxAutorun.cx",
                                           crxFilePath);
                delnum += AddinConfig.DeleteConfig(@"C:\Program Files\IronCAD\2024\bin\CAXADraft\Modules\CxAutorun.cx",
                                           crxFilePath);
                if (delnum == 0)
                {
                    break;
                }
            }
            //UnRegistCOM();
            //CheckAndDeleteTransferClient();
        }


        /// <summary>
        /// ファイルにEveryOneのアクセス権限を付与する
        /// </summary>
        /// <param name="filePath"></param>
        private void setEveryOneAccessControl(string filePath)
        {
            if(File.Exists(filePath) != true)
            {
                return;
            }
            /* EveryOneのアクセス権限を作成する */
            FileSystemAccessRule rule = new FileSystemAccessRule(
              new NTAccount("everyone"),
              FileSystemRights.Modify,
              AccessControlType.Allow);

            /* 現在のアクセス権限を取得する */
            FileSecurity security = File.GetAccessControl(filePath);

            /* EveryOne権限を追加する */
            security.AddAccessRule(rule);
            File.SetAccessControl(filePath, security);
        }
    }
}
