#pragma once

#include "resource.h"
// DialogOK �_�C�A���O

class DialogOK : public CDialogEx
{
	DECLARE_DYNAMIC(DialogOK)

public:
	DialogOK(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~DialogOK();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
