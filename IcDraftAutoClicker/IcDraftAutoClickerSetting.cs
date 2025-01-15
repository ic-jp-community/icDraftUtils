using System;
using System.Collections.Generic;
using System.Data;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;


namespace IcDraftAutoClicker
{
     public class IcDraftAutoClickerSetting
    {
        /// <summary>
        /// 共通のコンフィグファイルのパスを取得する
        /// </summary>
        /// <returns></returns>
        public static string GetCommonConfigFilePath()
        {
            return Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData), @"IRONCAD JP Community\IcDraftUtils\IcDraftUtilsCommon.config");
        }

        /// <summary>
        /// ユーザのコンフィグファイルのパスを取得する
        /// </summary>
        /// <returns></returns>
        public static string GetUserConfigFilePath()
        {
            return Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), @"IRONCAD JP Community\IcDraftUtils\IcDraftUtilsUser.config");
        }

        /// <summary>
        /// 言語設定を変更する
        /// </summary>
        /// <returns></returns>
        public static void SetCurrentLanguage(string culture)
        {
            if (string.IsNullOrEmpty(culture) != true)
            {
                Thread.CurrentThread.CurrentCulture = new CultureInfo(culture);
                Thread.CurrentThread.CurrentUICulture = new CultureInfo(culture);
            }
        }

        private static IcDraftAutoClickerSetting _instance;
        private static IcDraftUtilsConfig _config;
        public static IcDraftAutoClickerSetting GetInstance()
        {
            if (_instance == null)
            {
                _instance = new IcDraftAutoClickerSetting();
                return _instance;
            }
            return _instance;
        }

        public static IcDraftUtilsConfig GetConfig()
        {
            if (_config == null)
            {
                _config = new IcDraftUtilsConfig();
                return _config;
            }
            return _config;
        }

        public static IcDraftUtilsCommonConfig GetCommonConfig()
        {
            if (_config == null)
            {
                _config = new IcDraftUtilsConfig();
            }
            if (_config.CommonConfig == null)
            {
                _config.CommonConfig = new IcDraftUtilsCommonConfig();
            }
            return _config.CommonConfig;
        }

        public static IcDraftUtilsUserConfig GetUserConfig()
        {
            if (_config == null)
            {
                _config = new IcDraftUtilsConfig();
            }
            if (_config.UserConfig == null)
            {
                _config.UserConfig = new IcDraftUtilsUserConfig();
            }
            return _config.UserConfig;
        }

        public static void SetCommonConfig(IcDraftUtilsCommonConfig setConfig)
        {
            GetConfig().CommonConfig = setConfig;
        }
        public static void SetUserConfig(IcDraftUtilsUserConfig setConfig)
        {
            GetConfig().UserConfig = setConfig;
        }
        /// <summary>
        /// コンストラクタ
        /// </summary>
        public IcDraftAutoClickerSetting()
        {

        }

        #region コンフィグファイルのデータ構造
        /// <summary>
        /// IcDraftUtilsのすべての設定
        /// </summary>
        [Serializable]
        public class IcDraftUtilsConfig
        {
            public IcDraftUtilsUserConfig UserConfig = new IcDraftUtilsUserConfig();
            public IcDraftUtilsCommonConfig CommonConfig = new IcDraftUtilsCommonConfig();
        }

        /// <summary>
        /// IcDraftUtils共通アプリケーションの設定
        /// </summary>CommonAppConfig
        [Serializable]
        public class IcDraftUtilsCommonConfig
        {
            public AutoClickerConfig AutoClickerConfig;
            public IcDraftUtilsCommonConfig()
            {
                this.AutoClickerConfig = new AutoClickerConfig();
            }
        }

        /// <summary>
        /// IcDraftUtilsユーザ別アプリケーションの設定
        /// </summary>CommonAppConfig
        [Serializable]
        public class IcDraftUtilsUserConfig
        {
            public string dummy;
            public IcDraftUtilsUserConfig()
            {
                this.dummy = string.Empty;
            }
        }

        /// <summary>
        /// ウィンドウクリック設定
        /// </summary>
        [Serializable]
        public class ClickWindowSetting
        {
            public string windowTitle;
            public string windowText;
            public bool clickYes;
            public ClickWindowSetting()
            {
                this.windowTitle = string.Empty;
                this.windowText = string.Empty; 
                this.clickYes = false;
            }
        }

        /// <summary>
        /// 自動変換設定
        /// </summary>
        [Serializable]
        public class AutoClickerConfig
        {
            public int updateWindowCheckTimerMs;
            public int saveWindowCheckTimerMs;
            public int updatePaperTimeOutMs;
            public List<ClickWindowSetting> updateWindowsClickSetting;
            public List<ClickWindowSetting> saveWindowsClickSetting;
            public AutoClickerConfig()
            {
                this.updateWindowCheckTimerMs = 10000;
                this.saveWindowCheckTimerMs = 10000;
                this.updatePaperTimeOutMs = 120000;
                this.updateWindowsClickSetting = new List<ClickWindowSetting>();
                this.saveWindowsClickSetting = new List<ClickWindowSetting>();
            }
        }

        #endregion

        #region 設定ファイルの読み書き処理
        /// <summary>
        /// IcDraftUtilsのConfigファイルを出力する
        /// </summary>
        /// <param name="filePath">出力ファイルパス</param>
        /// <param name="config">設定データ</param>
        public static void WriteIcDraftUtilsCommonSetting(string filePath)
        {
            string dir = Path.GetDirectoryName(filePath);
            if (Directory.Exists(dir) != true)
            {
                Directory.CreateDirectory(dir);
            }
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(IcDraftUtilsCommonConfig));
            using (var streamWriter = new StreamWriter(filePath, false, Encoding.UTF8))
            {
                // シリアライズする
                xmlSerializer.Serialize(streamWriter, GetCommonConfig());
                streamWriter.Flush();
            }
        }

        /// <summary>
        /// IcDraftUtilsのConfigファイルを出力する
        /// </summary>
        /// <param name="filePath">出力ファイルパス</param>
        /// <param name="config">設定データ</param>
        public static void WriteIcDraftUtilsUserSetting(string filePath)
        {
            string dir = Path.GetDirectoryName(filePath);
            if (Directory.Exists(dir) != true)
            {
                Directory.CreateDirectory(dir);
            }
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(IcDraftUtilsUserConfig));
            using (var streamWriter = new StreamWriter(filePath, false, Encoding.UTF8))
            {
                // シリアライズする
                xmlSerializer.Serialize(streamWriter, GetUserConfig());
                streamWriter.Flush();
            }
        }

        public static void ReadIcDraftUtilsCommonSetting(string filePath)
        {
            IcDraftUtilsCommonConfig readConfig = new IcDraftUtilsCommonConfig();
            ReadIcDraftUtilsCommonSetting(filePath, ref readConfig, true);
        }
        public static void ReadIcDraftUtilsCommonSetting(string filePath, bool shorErrorMessage)
        {
            IcDraftUtilsCommonConfig readConfig = new IcDraftUtilsCommonConfig();
            ReadIcDraftUtilsCommonSetting(filePath, ref readConfig, shorErrorMessage);
        }
        public static void ReadIcDraftUtilsUserSetting(string filePath)
        {
            IcDraftUtilsUserConfig readConfig = new IcDraftUtilsUserConfig();
            ReadIcDraftUtilsUserSetting(filePath, ref readConfig, true);
        }
        public static void ReadIcDraftUtilsUserSetting(string filePath, bool shorErrorMessage)
        {
            IcDraftUtilsUserConfig readConfig = new IcDraftUtilsUserConfig();
            ReadIcDraftUtilsUserSetting(filePath, ref readConfig, shorErrorMessage);
        }

        /// <summary>
        /// IcDraftUtilsのConfigファイルを読み込む(共通データ CommonApp)
        /// </summary>
        /// <param name="filePath">設定ファイルのパス</param>
        /// <param name="config">読み込んだ設定データ</param>
        public static bool ReadIcDraftUtilsCommonSetting(string filePath, ref IcDraftUtilsCommonConfig readConfig, bool showErrorMessage)
        {
            bool readResult = false;
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(IcDraftUtilsCommonConfig));
            XmlReaderSettings xmlSettings = new XmlReaderSettings() { CheckCharacters = false };

            StreamReader streamReader = null;
            try
            {
                if (File.Exists(filePath) == false)
                {
                    IcDraftAutoClickerLog.LogMessage(IcDraftAutoClickerLog.LOG_TYPE.LOG_WARNING, "設定ファイルがありません。\nデフォルト設定を読み込みます。", filePath, showErrorMessage);
                    readConfig = new IcDraftUtilsCommonConfig();
                    return false;
                }
                // ファイルを読み込む
                streamReader = new StreamReader(filePath, Encoding.UTF8);
                // デシリアライズする
                XmlReader xmlReader = XmlReader.Create(streamReader, xmlSettings);
                readConfig = (IcDraftUtilsCommonConfig)xmlSerializer.Deserialize(xmlReader);
                readResult = true;
            }
            catch (Exception ex)
            {
                IcDraftAutoClickerLog.LogMessage(IcDraftAutoClickerLog.LOG_TYPE.LOG_WARNING, ex.Message, "FilePath: " + filePath, false);
                IcDraftAutoClickerLog.LogMessage(IcDraftAutoClickerLog.LOG_TYPE.LOG_WARNING, "設定ファイルの読み込みに失敗しました。\nデフォルト設定を読み込みます。", string.Empty, showErrorMessage);
                readConfig = new IcDraftUtilsCommonConfig();
                readResult = false;
            }
            finally
            {
                if (streamReader != null)
                {
                    streamReader.Close();
                }
            }
            /* 読んだデータは現在のConfigに反映させる */
            SetCommonConfig(readConfig);

            return readResult;
        }

        /// <summary>
        /// IcDraftUtilsのConfigファイルを読み込む(ユーザデータ UserApp)
        /// </summary>
        /// <param name="filePath">設定ファイルのパス</param>
        /// <param name="config">読み込んだ設定データ</param>
        public static bool ReadIcDraftUtilsUserSetting(string filePath, ref IcDraftUtilsUserConfig readConfig, bool showErrorMessage)
        {
            bool readResult = false;
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(IcDraftUtilsUserConfig));
            XmlReaderSettings xmlSettings = new XmlReaderSettings() { CheckCharacters = false };

            StreamReader streamReader = null;
            try
            {
                if (File.Exists(filePath) == false)
                {
                    IcDraftAutoClickerLog.LogMessage(IcDraftAutoClickerLog.LOG_TYPE.LOG_WARNING, "ユーザ設定ファイルがありません。\nデフォルト設定を読み込みます。", "filePath: " + filePath, showErrorMessage);
                    readConfig = new IcDraftUtilsUserConfig();
                    return false;
                }
                // ファイルを読み込む
                streamReader = new StreamReader(filePath, Encoding.UTF8);
                // デシリアライズする
                XmlReader xmlReader = XmlReader.Create(streamReader, xmlSettings);
                readConfig = (IcDraftUtilsUserConfig)xmlSerializer.Deserialize(xmlReader);
                readResult = true;
            }
            catch (Exception ex)
            {
                IcDraftAutoClickerLog.LogMessage(IcDraftAutoClickerLog.LOG_TYPE.LOG_WARNING, ex.Message, "FilePath: " + filePath, false);
                IcDraftAutoClickerLog.LogMessage(IcDraftAutoClickerLog.LOG_TYPE.LOG_WARNING, "ユーザ設定ファイルの読み込みに失敗しました。\nデフォルト設定を読み込みます。", string.Empty, showErrorMessage);
                readConfig = new IcDraftUtilsUserConfig();
                readResult = false;
            }
            finally
            {
                if (streamReader != null)
                {
                    streamReader.Close();
                }
            }
            /* 読んだデータは現在のConfigに反映させる */
            SetUserConfig(readConfig);

            return readResult;
        }

        #endregion

    }
}

