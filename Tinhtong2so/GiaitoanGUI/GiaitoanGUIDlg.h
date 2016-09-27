
// GiaitoanGUIDlg.h : header file
//

#pragma once
#include "Giaitoan.h"
#include "afxwin.h"

// CGiaitoanGUIDlg dialog
class CGiaitoanGUIDlg : public CDialogEx
{
// Construction
public:
	CGiaitoanGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GIAITOANGUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	int a;
	int b;
	Giaitoan objGiaitoan;
	int mTong;
public:
	afx_msg void OnBnClickedBtntinhtoan();
	CStatic mctrKetqua;
};
