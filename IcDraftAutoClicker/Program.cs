using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IcDraftAutoClicker
{
    internal static class Program
    {
        /// <summary>
        /// アプリケーションのメイン エントリ ポイントです。
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            log4net.Config.XmlConfigurator.Configure(new System.IO.FileInfo("log4netAutoClicker.config"));
            if (args.Count() > 0)
            {
                /* 引数あり */
                bool waitSaveDialog = false;
                bool waitNoSave = false;
                bool waitUpdateDialog = false; /* 単シートもしくは最初に開いたmodel/paperの更新 */
                bool waitUpdatePaperDialog = false; /* 複数シートの2枚目以降のmodel/paperの更新(タイムアウト付きで処理) */
                bool paperClickDialog = false;
                bool windowClickDialog = false;
                bool settingsDialog = false;
                bool setFilesDialog = false;
                bool showResultDialog = false;
                string allArgs = string.Empty;
                string version = string.Empty;
                string result_selectFilesListPath = string.Empty;
                string result_resultFilePath = string.Empty;
                string clickPaperName = string.Empty;
                for (int i = 0; i < args.Count(); i++)
                {
                    string arg = args[i];
                    switch (arg.ToLower())
                    {
                        case "/selectfiles":
                            setFilesDialog = true;
                            break;
                        case "/showresult":
                            if (args.Count() >= (i+2))
                            {
                                result_selectFilesListPath = args[i + 1];
                                result_resultFilePath = args[i + 2];
                            }
                            showResultDialog = true;
                            break;
                        case "/save":
                            waitSaveDialog = true;
                            waitNoSave = false;
                            break;
                        case "/nosave":
                            waitSaveDialog = true;
                            waitNoSave = true;
                            break;
                        case "/update":
                            waitUpdateDialog = true;
                            break;
                        case "/updatepaper":
                            waitUpdatePaperDialog = true;
                            break;
                        case "/setting":
                            settingsDialog = true;
                            break;
                        case "/paperclick":
//                            MessageBox.Show("debug", "debug", MessageBoxButtons.OK);
                            paperClickDialog = true;
                            if (args.Count() >= (i + 1))
                            {
                                clickPaperName = args[i + 1];
                            }
                            break;
                        default:
                            if (arg.Contains("/ic:") == true)
                            {
                                version = arg.Replace("/ic:", string.Empty);
                            }
                            break;
                    }
                    allArgs += string.Format(" {0}", arg);
                }
                if(setFilesDialog == true)
                {
                    string setSelectFilePath = allArgs.ToString().Replace("/selectfiles", string.Empty).Trim();
                    Application.Run(new Form_SelectFiles(setSelectFilePath));
                }
                else if(showResultDialog == true)
                {
                    Application.Run(new Form_ShowResult(result_selectFilesListPath, result_resultFilePath));
                }
                else if (settingsDialog == true)
                {
                    Application.Run(new Form_Settings());
                }
                else if(paperClickDialog == true)
                {
                    int cutStart = allArgs.LastIndexOf("/target:") + "/target:".Length;
                    string targetFilePath = allArgs.Substring(cutStart, allArgs.Length- cutStart).Trim();
                    Application.Run(new Form_PaperClick(version, targetFilePath, clickPaperName));
                }
                else
                {
                    string targetFilePath = allArgs.ToString().Replace("/save", string.Empty).Replace("/update", string.Empty).Replace("/target:", string.Empty).Trim();
                    Application.Run(new IcDraftAutoClicker(version, targetFilePath, waitSaveDialog, waitNoSave, waitUpdateDialog, waitUpdatePaperDialog));
                }
            }
            else
            {
                Application.Run(new IcDraftAutoClicker(string.Empty, string.Empty, false, false, false, false));
            }
        }
    }
}
