using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static IcDraftAutoClicker.IcDraftAutoClickerRetCode;
using static IcDraftAutoClicker.IcDraftAutoClickerCommon;
using System.CodeDom.Compiler;

namespace IcDraftAutoClicker
{
    public partial class Form_ShowResult : Form
    {
        private int _exitCode = 0;
        private string _selectFileListPath = string.Empty;
        private string _resultFilePath = string.Empty;
        public Form_ShowResult(string selectFileListPath, string resultFilePath)
        {
            InitializeComponent();
            this._selectFileListPath = selectFileListPath;
            this._resultFilePath = resultFilePath;
        }

        public bool OpenDirectoryDialog(string title, ref string directoryPath)
        {
            /* 保存先のダイアログを表示する */
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.FileName = "フォルダを選択";
            ofd.Title = title;
            ofd.Filter = "フォルダ|.";
            ofd.ValidateNames = false;
            ofd.CheckFileExists = false;
            ofd.CheckPathExists = true;
            if (ofd.ShowDialog() != DialogResult.OK)
            {
                /* 取得キャンセル */
                return false;
            }
            directoryPath = Path.GetDirectoryName(ofd.FileName);
            return true;
        }

        public bool OpenSelectFileDialog(string title, ref List<string> selectFiles)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.FileName = String.Empty;
            ofd.Title = title;
            ofd.Filter = "すべてのファイル|*";
            ofd.ValidateNames = false;
            ofd.Multiselect = false;
            ofd.CheckFileExists = true;
            ofd.CheckPathExists = true;
            if (ofd.ShowDialog() != DialogResult.OK)
            {
                /* 取得キャンセル */
                return false;
            }
            selectFiles = ofd.FileNames.ToList();
            return true;
        }

        public static List<String> GetAllFiles(String DirPath, bool includeChildFolder)
        {
            List<String> fileList = new List<String>();    // 取得したファイル名を格納するためのリスト

            System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(DirPath);
            System.IO.FileInfo[] files = null;
            if(includeChildFolder == true)
            {
                files = di.GetFiles("*.exb", System.IO.SearchOption.AllDirectories);
            }
            else
            {
                files = di.GetFiles("*.exb", System.IO.SearchOption.TopDirectoryOnly);
            }
            foreach(FileInfo fi in files)
            {
                fileList.Add(fi.FullName);
            }
            return fileList;

        }

        public class ResultData
        {
            public string fileName;
            public string filePath;
            public bool execute;
            public bool update;
            public bool multiPaper;
            public bool error3DScene;
            public bool errorDimCheck;
            public bool errorMultiSheet;
            public ResultData()
            {
                this.fileName = string.Empty;
                this.filePath = string.Empty;
                this.execute = false;
                this.update = false;
                this.multiPaper = false;
                this.error3DScene = false;
                this.errorDimCheck = false;
                this.errorMultiSheet = false;
            }
            public ResultData(string fileName, string filePath)
            {
                this.fileName = fileName;
                this.filePath = filePath;
                this.execute = false;
                this.update = false;
                this.multiPaper = false;
                this.error3DScene = false;
                this.errorDimCheck = false;
                this.errorMultiSheet = false;
            }
        }

        private void showResult()
        {
            if(File.Exists(this._selectFileListPath) != true)
            {
                return;
            }
            if (File.Exists(this._resultFilePath) != true)
            {
                return;
            }
            dataGridViewResult.Rows.Clear();
            List<ResultData> resultData = new List<ResultData>();
            List<string> unknownResultData = new List<string>();
 //           List<string> selectFileList = File.ReadAllLines(this._selectFileListPath, System.Text.Encoding.GetEncoding("shift_jis")).ToList();
 //           List<string> resultFile = File.ReadAllLines(this._resultFilePath, System.Text.Encoding.GetEncoding("shift_jis")).ToList();
            List<string> selectFileList = File.ReadAllLines(this._selectFileListPath).ToList();
            List<string> resultFile = File.ReadAllLines(this._resultFilePath).ToList();
            List<string> updateFile = new List<string>();
            List<string> notUpdateFile = new List<string>();
            foreach (string selectFile in selectFileList)
            {
                resultData.Add(new ResultData(Path.GetFileName(selectFile),selectFile));
            }

            int updateFileStartIndex = 0;
            int updateFileEndIndex = 0;
            int notUpdateFileStartIndex = 0;
            int notUpdateFileEndIndex = resultFile.Count;
            
            /* 開始時刻と終了時刻を取得 */
            for (int i = 0; i < resultFile.Count; i++)
            {
                string row = resultFile[i];
                if (row.Contains("■開始時刻:") == true)
                {
                    labelStartTime.Text = row.Replace("■開始時刻:", string.Empty); ;
                }
                if (row.Contains("■終了時刻:") == true)
                {
                    labelEndTime.Text = row.Replace("■終了時刻:", string.Empty); ;
                    break;
                }
            }
            /* 処理結果をパースする */
            for (int i = 0;  i < resultFile.Count; i++)
            {
                string row = resultFile[i];
                if (row.Contains("[更新したファイル]") == true)
                {
                    updateFileStartIndex = i;
                }
                if (row.Contains("[更新しなかったファイル]") == true)
                {
                    updateFileEndIndex = i - 1;
                    notUpdateFileStartIndex = i; ;
                }
                /*  */
                if ((updateFileStartIndex != 0) &&
                    (notUpdateFileStartIndex == 0))
                {
                    updateFile.Add(row);
                }

                if (notUpdateFileStartIndex != 0)
                {
                    notUpdateFile.Add(row);
                }
            }

            /* 更新したファイル */
            foreach(string row in updateFile)
            {
                bool foundFlag = false;
                string updateResult = row.ToLower();
                string updateFilePath = string.Empty;
                if (updateResult.Contains(".exb") == true)
                {
                    updateFilePath = updateResult.Substring(0, updateResult.IndexOf(".exb") + (".exb").Length);
                    for (int i = 0; i < resultData.Count; i++)
                    {
                        if(string.Equals(resultData[i].filePath.ToLower(), updateFilePath) == true)
                        {
                            resultData[i].execute = true;
                            resultData[i].update = true;
                            if(updateResult.Contains("注意:3dシーンファイルが見つかりませんでした") == true)
                            {
                                resultData[i].error3DScene = true;
                            }
                            else
                            {
                                resultData[i].error3DScene = false;
                            }
                            if (updateResult.Contains("注意:寸法のチェックが必要です") == true)
                            {
                                resultData[i].errorDimCheck = true;
                            }
                            else
                            {
                                resultData[i].errorDimCheck = false;
                            }
                            if (updateResult.Contains("複数シート") == true)
                            {
                                resultData[i].multiPaper = true;
                            }
                            else
                            {
                                resultData[i].multiPaper = false;
                            }
                            if (updateResult.Contains("注意:複数シートの更新に失敗しました") == true)
                            {
                                resultData[i].errorMultiSheet = true;
                            }
                            else
                            {
                                resultData[i].errorMultiSheet = false;
                            }
                            foundFlag = true;
                            break;
                        }
                    }
                    if(foundFlag != true)
                    {
                        unknownResultData.Add(updateResult);
                    }
                }
            }
            /* 更新しなかったファイル */
            foreach (string row in notUpdateFile)
            {
                bool foundFlag = false;
                string notUpdateResult = row.ToLower();
                string notUpdateFilePath = string.Empty;
                if (notUpdateResult.Contains(".exb") == true)
                {
                    notUpdateFilePath = notUpdateResult.Substring(0, notUpdateResult.IndexOf(".exb") + (".exb").Length);
                    for (int i = 0; i < resultData.Count; i++)
                    {
                        if (string.Equals(resultData[i].filePath.ToLower(), notUpdateFilePath) == true)
                        {
                            resultData[i].execute = true;
                            resultData[i].update = false;
                            if (notUpdateResult.Contains("注意:3dシーンファイルが見つかりませんでした") == true)
                            {
                                resultData[i].error3DScene = true;
                            }
                            else
                            {
                                resultData[i].error3DScene = false;
                            }
                            if (notUpdateResult.Contains("注意:寸法のチェックが必要です") == true)
                            {
                                resultData[i].errorDimCheck = true;
                            }
                            else
                            {
                                resultData[i].errorDimCheck = false;
                            }
                            if (notUpdateResult.Contains("複数シート") == true)
                            {
                                resultData[i].multiPaper = true;
                            }
                            else
                            {
                                resultData[i].multiPaper = false;
                            }
                            if (notUpdateResult.Contains("注意:複数シートの更新に失敗しました") == true)
                            {
                                resultData[i].errorMultiSheet = true;
                            }
                            else
                            {
                                resultData[i].errorMultiSheet = false;
                            }
                            foundFlag = true;
                            break;
                        }
                    }
                    if (foundFlag != true)
                    {
                        unknownResultData.Add(notUpdateResult);
                    }
                }
            }
            foreach (ResultData data in resultData)
            {
                string fileName = data.fileName;
                string filePath = data.filePath;
                string exec = "×";
                if (data.execute == true)
                {
                    exec = "〇";   
                }
                string update = string.Empty;
                if (data.update == true)
                {
                    update = "〇";
                }
                string error3dScene = string.Empty;
                if (data.error3DScene == true)
                {
                    error3dScene = "×";
                }
                string errorDimCheck = string.Empty;
                if (data.errorDimCheck == true)
                {
                    errorDimCheck = "×";
                }
                string multiSheet = string.Empty;
                if (data.multiPaper == true)
                {
                    multiSheet = "〇";
                }
                if (data.errorMultiSheet == true)
                {
                    multiSheet = "×";
                }
                dataGridViewResult.Rows.Add(new object[] {fileName, exec, multiSheet, update, error3dScene, errorDimCheck, filePath });
            }
            if (unknownResultData.Count > 0)
            {
                tableLayoutPanelUnknownError.Visible = true;
                foreach(string data in unknownResultData)
                {
                    dataGridViewUnknownError.Rows.Add(data);
                }
            }
        }


        private void buttonSelectFileList_Click(object sender, EventArgs e)
        {
            List<string> filePathList = new List<string>();
            bool ret = OpenSelectFileDialog("設定ファイルを選択してください", ref filePathList);
            if (ret == false)
            {
                return;
            }
            linkLabelSelectFileList.Text = filePathList[0];
            this._selectFileListPath = filePathList[0];
            showResult();
        }

        private void buttonResultFile_Click(object sender, EventArgs e)
        {
            List<string> filePathList = new List<string>();
            bool ret = OpenSelectFileDialog("結果ファイルを選択してください", ref filePathList);
            if (ret == false)
            {
                return;
            }
            linkLabelResultFile.Text = filePathList[0];
            this._resultFilePath = filePathList[0];
            showResult();
        }


        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form_SelectFiles_Load(object sender, EventArgs e)
        {
            if ((File.Exists(this._selectFileListPath) == true) &&
                (File.Exists(this._resultFilePath) == true))
            {
                linkLabelSelectFileList.Text = this._selectFileListPath; ;
                linkLabelResultFile.Text = this._resultFilePath;
                showResult();
            }
        }

        private void linkLabelResultFile_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(linkLabelResultFile.Text);
        }

        private void linkLabelSelectFileList_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(linkLabelSelectFileList.Text);
        }
    }
}
