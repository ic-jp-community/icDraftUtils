// DialogOK.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "DialogOK.h"
#include "afxdialogex.h"


// DialogOK �_�C�A���O

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


// DialogOK ���b�Z�[�W �n���h���[


void DialogOK::OnBnClickedOk()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CDialogEx::OnOK();
}
