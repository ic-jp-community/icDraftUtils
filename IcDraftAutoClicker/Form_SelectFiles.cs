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

namespace IcDraftAutoClicker
{
    public partial class Form_SelectFiles : Form
    {
        private int _exitCode = 0;
        private string _setFileListPath = string.Empty;
        public Form_SelectFiles(string setFileListPath)
        {
            InitializeComponent();
            this._setFileListPath = setFileListPath;
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
            /* 保存先のダイアログを表示する */
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.FileName = String.Empty;
            ofd.Title = title;
            ofd.Filter = "CaxaDraft Exbファイル|*.exb;";
            ofd.ValidateNames = false;
            ofd.Multiselect = true;
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
        private void buttonSelectFiles_Click(object sender, EventArgs e)
        {
            List<string> filePathList = new List<string>();
            bool ret = OpenSelectFileDialog("一括更新するファイルを指定してください", ref filePathList);
            if (ret == false)
            {
                return;
            }
            addDataGridViewFileList(filePathList);
        }

        private void addDataGridViewFileList(List<string> filePathList)
        {
            foreach (string filePath in filePathList)
            {
                bool alreadyAdded = CheckAlreadyAddedFilePath(filePath);
                if(alreadyAdded == true)
                {
                    MessageBox.Show(string.Format("{0}は既に処理するファイルに含まれています。", filePath));
                    continue;
                }
                string fileName = Path.GetFileName(filePath);
                dataGridViewFileList.Rows.Add(fileName, filePath);
            }
        }

        private bool CheckAlreadyAddedFilePath(string filePath)
        {
            for (int i = 0; i < dataGridViewFileList.Rows.Count; i++)
            {
                string rowFilePath = dataGridViewValueGet(dataGridViewFileList, i, "FilePath");
                if (string.Equals(rowFilePath.ToLower(), filePath.ToLower()) == true)
                {
                    return true;
                }
            }
            return false;
        }

        private void buttonSelectFolder_Click(object sender, EventArgs e)
        {
            List<string> filePathList = new List<string>();
            string path = string.Empty;
            bool ret = OpenDirectoryDialog("一括更新するフォルダのパスを指定してください", ref path);
            if (ret == false)
            {
                return;
            }
            filePathList = GetAllFiles(path, checkBoxAddChildFolder.Checked);
            addDataGridViewFileList(filePathList);
        }


        private void buttonCancel_Click(object sender, EventArgs e)
        {
            SetExitCode(RETCODE_SETFILE_CANCEL);
            this.Close();
        }

        private void buttonExecute_Click(object sender, EventArgs e)
        {
            string dir = Path.GetDirectoryName(_setFileListPath);
            if (Directory.Exists(dir) == false)
            {
                Directory.CreateDirectory(dir);
            }
            StreamWriter sw = new StreamWriter(this._setFileListPath);
            
            for (int rowIndex = 0; rowIndex < dataGridViewFileList.Rows.Count; rowIndex++)
            {
                string filePath = dataGridViewValueGet(dataGridViewFileList, rowIndex, "FilePath");
                if(string.IsNullOrEmpty(filePath) == true)
                {
                    continue;
                }
                if (File.Exists(filePath) != true)
                {
                    continue;
                }
                sw.WriteLine(filePath);
            }
            sw.Close();
            SetExitCode(RETCODE_SETFILE_OK);
            this.Close();
        }

        private void Form_SelectFiles_Load(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(this._setFileListPath) == true)
            {
                SetExitCode(RETCODE_SETFILE_ERROR_SETFILE_PATH_NONE);
                this.Close();
            }
        }
        private void Form_SelectFiles_FormClosing(object sender, FormClosingEventArgs e)
        {
            IcDraftAutoClickerCommon.LogMessage(IcDraftAutoClickerCommon.LOG_TYPE.LOG_INFO, string.Format("End "), string.Empty, false);
            Environment.ExitCode = this._exitCode;
        }

        private void SetExitCode(int exitCode)
        {
            this._exitCode = exitCode;
        }
    }
}
