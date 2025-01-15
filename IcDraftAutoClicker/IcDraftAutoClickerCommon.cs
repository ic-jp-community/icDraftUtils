using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IcDraftAutoClicker
{
    public class IcDraftAutoClickerCommon
    {
        private static readonly log4net.ILog _logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        public enum LOG_TYPE
        {
            LOG_DEBUG,
            LOG_INFO,
            LOG_ERROR,
            LOG_WARNING,
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

        public static string dataGridViewValueGet(DataGridView dgv, int rowIndex, string columnName)
        {
            string retStr = string.Empty;
            if (rowIndex >= dgv.Rows.Count)
            {
                return retStr;
            }
            if (dgv.Columns.Contains(columnName) != true)
            {
                return retStr;
            }
            if (dgv.Rows[rowIndex].Cells[columnName].Value == null)
            {
                return retStr;
            }
            retStr = dgv.Rows[rowIndex].Cells[columnName].Value.ToString();
            return retStr;

        }
    }
}
