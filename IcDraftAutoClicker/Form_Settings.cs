using IcDraftAutoClicker.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static IcDraftAutoClicker.IcDraftAutoClickerSetting;
using static IcDraftAutoClicker.IcDraftAutoClickerCommon;

namespace IcDraftAutoClicker
{
    public partial class Form_Settings : Form
    {
        public Form_Settings()
        {
            InitializeComponent();
        }

        private void Form_Settings_Load(object sender, EventArgs e)
        {

        }

        private void Form_Settings_Shown(object sender, EventArgs e)
        {
            IcDraftAutoClickerSetting.ReadIcDraftUtilsCommonSetting(IcDraftAutoClickerSetting.GetCommonConfigFilePath());
            IcDraftAutoClickerSetting.IcDraftUtilsConfig config =  IcDraftAutoClickerSetting.GetConfig();
            AutoClickerConfig autoClickerConfig = config.CommonConfig.AutoClickerConfig;

            /* 間隔設定 */
            textBoxSaveWindowTimerMs.Text = autoClickerConfig.saveWindowCheckTimerMs.ToString();
            textBoxUpdataWindowTimerMs.Text = autoClickerConfig.updateWindowCheckTimerMs.ToString();
            textBoxPaperUpdateTimerMs.Text = autoClickerConfig.updatePaperTimeOutMs.ToString();

            foreach (ClickWindowSetting setting in autoClickerConfig.saveWindowsClickSetting)
            {
                string clickYesNo = string.Empty;
                if(setting.clickYes == true)
                {
                    clickYesNo = "はい";
                }else
                {
                    clickYesNo = "いいえ";
                }
                dataGridViewSave.Rows.Add(setting.windowTitle, setting.windowText, clickYesNo); 
            }

            foreach (ClickWindowSetting setting in autoClickerConfig.updateWindowsClickSetting)
            {
                string clickYesNo = string.Empty;
                if (setting.clickYes == true)
                {
                    clickYesNo = "はい";
                }
                else
                {
                    clickYesNo = "いいえ";
                }
                dataGridViewUpdate.Rows.Add(setting.windowTitle, setting.windowText, clickYesNo);
            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            IcDraftAutoClickerSetting.ReadIcDraftUtilsCommonSetting(IcDraftAutoClickerSetting.GetCommonConfigFilePath());
            IcDraftAutoClickerSetting.IcDraftUtilsConfig config = IcDraftAutoClickerSetting.GetConfig();
            AutoClickerConfig autoClickerConfig =　new AutoClickerConfig();

            /* 間隔設定 */
            autoClickerConfig.saveWindowCheckTimerMs = Int32.Parse(textBoxSaveWindowTimerMs.Text);
            autoClickerConfig.updateWindowCheckTimerMs = Int32.Parse(textBoxUpdataWindowTimerMs.Text);
            autoClickerConfig.updatePaperTimeOutMs = Int32.Parse(textBoxPaperUpdateTimerMs.Text);

            for (int rowIndex = 0; rowIndex < dataGridViewUpdate.Rows.Count; rowIndex++)
            {
                ClickWindowSetting clickSetting = new ClickWindowSetting();
                if((dataGridViewUpdate["UpdateWindowTitle", rowIndex].Value == null) ||
                    (dataGridViewUpdate["UpdateWindowText", rowIndex].Value == null) ||
                    (dataGridViewUpdate["UpdateClickButton", rowIndex].Value == null))
                {
                    continue;
                }
                clickSetting.windowTitle = dataGridViewValueGet(dataGridViewUpdate, rowIndex, "UpdateWindowTitle");
                clickSetting.windowText = dataGridViewValueGet(dataGridViewUpdate, rowIndex, "UpdateWindowText");
                if(dataGridViewUpdate["UpdateClickButton", rowIndex].Value.ToString() == "はい")
                {
                    clickSetting.clickYes = true;
                }
                else
                {
                    clickSetting.clickYes = false;
                }
                autoClickerConfig.updateWindowsClickSetting.Add(clickSetting);
            }
            for (int rowIndex = 0; rowIndex < dataGridViewSave.Rows.Count; rowIndex++)
            {
                if ((dataGridViewSave["SaveWindowTitle", rowIndex].Value == null) ||
                    (dataGridViewSave["SaveWindowText", rowIndex].Value == null) ||
                     (dataGridViewSave["SaveClickButton", rowIndex].Value == null))
                {
                    continue;
                }
                ClickWindowSetting clickSetting = new ClickWindowSetting();
                clickSetting.windowTitle = dataGridViewValueGet(dataGridViewSave, rowIndex, "SaveWindowTitle");
                clickSetting.windowText = dataGridViewValueGet(dataGridViewSave, rowIndex, "SaveWindowText");
                if (dataGridViewSave["SaveClickButton", rowIndex].Value.ToString() == "はい")
                {
                    clickSetting.clickYes = true;
                }
                else
                {
                    clickSetting.clickYes = false;
                }
                autoClickerConfig.saveWindowsClickSetting.Add(clickSetting);
            }
            config.CommonConfig.AutoClickerConfig = autoClickerConfig;
            IcDraftAutoClickerSetting.SetCommonConfig(config.CommonConfig);
            IcDraftAutoClickerSetting.WriteIcDraftUtilsCommonSetting(IcDraftAutoClickerSetting.GetCommonConfigFilePath());
            this.Close();
        }

        private void buttonUpdateAdd_Click(object sender, EventArgs e)
        {
            string windowTitle = string.Empty;
            string windowText = string.Empty;
            string clickYesNo = string.Empty;
            windowTitle = textBoxUpdateWindowTitle.Text;
            windowText = textBoxUpdateWindowText.Text;
            if (radioButtonUpdateYes.Checked == true)
            {
                clickYesNo = "はい";
            }
            else
            {
                clickYesNo = "いいえ";
            }
            dataGridViewUpdate.Rows.Add(windowTitle, windowText, clickYesNo);
        }

        private void buttonSaveAdd_Click(object sender, EventArgs e)
        {
            string windowTitle = string.Empty;
            string windowText = string.Empty;
            string clickYesNo = string.Empty;
            windowTitle = textBoxSaveWindowTitle.Text;
            windowText = textBoxSaveWindowText.Text;
            if (radioButtonSaveYes.Checked == true)
            {
                clickYesNo = "はい";
            }
            else
            {
                clickYesNo = "いいえ";
            }
            dataGridViewSave.Rows.Add(windowTitle, windowText, clickYesNo);
        }
    }
}
