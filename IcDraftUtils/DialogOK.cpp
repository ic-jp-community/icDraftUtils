// DialogOK.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DialogOK.h"
#include "afxdialogex.h"


// DialogOK ダイアログ

IMPLEMENT_DYNAMIC(DialogOK, CDialogEx)

DialogOK::DialogOK(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogOK::IDD, pParent)
{

}

DialogOK::~DialogOK()
{
}

void DialogOK::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogOK, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogOK::OnBnClickedOk)
END_MESSAGE_MAP()


// DialogOK メッセージ ハンドラー


void DialogOK::OnBnClickedOk()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnOK();
}
