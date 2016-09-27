
// GiaitoanGUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GiaitoanGUI.h"
#include "GiaitoanGUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGiaitoanGUIDlg dialog



CGiaitoanGUIDlg::CGiaitoanGUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGiaitoanGUIDlg::IDD, pParent)
	, a(0)
	, b(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGiaitoanGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_A, a);
	DDX_Text(pDX, IDC_EDIT_B, b);
	DDX_Control(pDX, IDC_TEXTKETQUA, mctrKetqua);
}

BEGIN_MESSAGE_MAP(CGiaitoanGUIDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNTINHTOAN, &CGiaitoanGUIDlg::OnBnClickedBtntinhtoan)
END_MESSAGE_MAP()


// CGiaitoanGUIDlg message handlers

BOOL CGiaitoanGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGiaitoanGUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGiaitoanGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGiaitoanGUIDlg::OnBnClickedBtntinhtoan()
{
	CString strA, strB;

	// Lay duoc 2 so tu 2 o nhap
	GetDlgItemText(IDC_EDIT_A, strA);
	GetDlgItemText(IDC_EDIT_B, strB);

	//chuyen tu kieu cstring thanh kieu int
	a = _wtoi(strA);
	b = _wtoi(strB);

	if (a == 0 && b == 0)
	{
		MessageBox(_T("Ban nen nhap cai gi day khac 0"), _T("Error"),
			MB_ICONERROR | MB_OK);
	}

	mTong = objGiaitoan.tinhtonghaiso(a, b);
	
	CString strKetqua;
	strKetqua.Format(L"%d", mTong);

	mctrKetqua.SetWindowText(strKetqua);

}
