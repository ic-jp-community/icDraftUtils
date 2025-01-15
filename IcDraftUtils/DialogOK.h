#pragma once

#include "resource.h"
// DialogOK ダイアログ

class DialogOK : public CDialogEx
{
	DECLARE_DYNAMIC(DialogOK)

public:
	DialogOK(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~DialogOK();

// ダイアログ データ
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
