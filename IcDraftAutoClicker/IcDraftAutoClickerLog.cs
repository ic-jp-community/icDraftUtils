using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IcDraftAutoClicker
{
    public class IcDraftAutoClickerLog
    {
        private static log4net.ILog _logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        public enum LOG_TYPE
        {
            LOG_DEBUG,
            LOG_INFO,
            LOG_ERROR,
            LOG_WARNING,
        }

        public IcDraftAutoClickerLog(string configFile)
        {
            FileInfo fi = new FileInfo(configFile);
            log4net.Config.XmlConfigurator.Configure(fi);
        }

        public static void LogMessage(LOG_TYPE logType, string message, string logOnlyMessage, bool isShowMessage,
                      [System.Runtime.CompilerServices.CallerMemberName] string callerMemberName = "",
                      [System.Runtime.CompilerServices.CallerFilePath] string callerFilePath = "",
                      [System.Runtime.CompilerServices.CallerLineNumber] int callerLineNumber = 0)
        {
            string logStr = String.Format("[File] {0}   [Line] {1}   [Method] {2}   [Message] {3}  [LogOnly] {4}", callerFilePath, callerLineNumber, callerMemberName, message.Replace("\n", " "), logOnlyMessage);
            switch (logType)
            {
                case LOG_TYPE.LOG_DEBUG:
                    _logger.Debug(logStr);
                    break;
                case LOG_TYPE.LOG_INFO:
                    _logger.Info(logStr);
                    break;
                case LOG_TYPE.LOG_ERROR:
                    _logger.Error(logStr);
                    break;
                case LOG_TYPE.LOG_WARNING:
                    _logger.Warn(logStr);
                    break;
            }
            if (isShowMessage == true)
            {
                MessageBox.Show(message);
            }
        }

        public static void LogMessageT(LOG_TYPE logType, string message, string logOnlyMessage, bool isShowMessage,
              [System.Runtime.CompilerServices.CallerMemberName] string callerMemberName = "",
              [System.Runtime.CompilerServices.CallerFilePath] string callerFilePath = "",
              [System.Runtime.CompilerServices.CallerLineNumber] int callerLineNumber = 0)
        {
            string logStr = String.Format("[File] {0}   [Line] {1}   [Method] {2}   [Message] {3}  [LogOnly] {4}", callerFilePath, callerLineNumber, callerMemberName, message.Replace("\n", " "), logOnlyMessage);
            switch (logType)
            {
                case LOG_TYPE.LOG_DEBUG:
                    _logger.Debug(logStr);
                    break;
                case LOG_TYPE.LOG_INFO:
                    _logger.Info(logStr);
                    break;
                case LOG_TYPE.LOG_ERROR:
                    _logger.Error(logStr);
                    break;
                case LOG_TYPE.LOG_WARNING:
                    _logger.Warn(logStr);
                    break;
            }
            if (isShowMessage == true)
            {
                Task.Factory.StartNew(() =>
                     MessageBox.Show(message)
                );

            }
        }
        public static DialogResult LogMessage(LOG_TYPE logType, string message, string logOnlyMessage, bool isShowMessage, string title, MessageBoxButtons buttons,
                      [System.Runtime.CompilerServices.CallerMemberName] string callerMemberName = "",
                      [System.Runtime.CompilerServices.CallerFilePath] string callerFilePath = "",
                      [System.Runtime.CompilerServices.CallerLineNumber] int callerLineNumber = 0)
        {
            DialogResult dret = DialogResult.OK;
            string logStr = String.Format("[File] {0}   [Line] {1}   [Method] {2}   [Message] {3}  [LogOnly] {4}", callerFilePath, callerLineNumber, callerMemberName, message.Replace("\n", " "), logOnlyMessage);
            switch (logType)
            {
                case LOG_TYPE.LOG_DEBUG:
                    _logger.Debug(logStr);
                    break;
                case LOG_TYPE.LOG_INFO:
                    _logger.Info(logStr);
                    break;
                case LOG_TYPE.LOG_ERROR:
                    _logger.Error(logStr);
                    break;
                case LOG_TYPE.LOG_WARNING:
                    _logger.Warn(logStr);
                    break;
            }
            if (isShowMessage == true)
            {
                dret = MessageBox.Show(message, title, buttons);
            }
            return dret;
        }
    }
}
