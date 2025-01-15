﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IcDraftAutoClicker
{
    public class IcDraftAutoClickerRetCode
    {
        public const int RETCODE_WINDOW_UNDEF_SET_NO = 0x10000000;
        public const int RETCODE_WINDOW_DIM_CHECK_SET_CANCEL = 0x01 << 5;
        public const int RETCODE_WINDOW_3DNOTFOUND_SET_NO = 0x01 << 4;
        public const int RETCODE_WINDOW_UPDATE_SET_YES = 0x01 << 3;
        public const int RETCODE_WINDOW_SAVE_SET_NO = 0x01 << 2;
        public const int RETCODE_WINDOW_SAVE_SET_YES = 0x01 << 1;
        public const int RETCODE_PAPERCLICK_CLICK_OK = 0x01 << 1;
        /* 処理ファイル */
        public const int RETCODE_SETFILE_ERROR_SETFILE_PATH_NONE = 0x01 << 16;
        public const int RETCODE_SETFILE_CANCEL = 0x01 << 3;
        public const int RETCODE_SETFILE_OK_FILE_NONE = 0x01 << 2;
        public const int RETCODE_SETFILE_OK = 0x01 << 1;

        public const int RETCODE_NONE = 0;

        /* 内部エラーC++側で使用済み*/
        public const uint RETCODE_NG_INNER_ERROR = 0x80000000;
    }
}