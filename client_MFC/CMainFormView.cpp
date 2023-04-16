// CMainFormView.cpp: 구현 파일
//

#include "pch.h"
#include "client_MFC.h"
#include "CMainFormView.h"
#include "client_MFCDlg.h"

// CMainFormView

IMPLEMENT_DYNCREATE(CMainFormView, CFormView)

CMainFormView::CMainFormView()
	: CFormView(IDD_Form_Main)
{

}

CMainFormView::~CMainFormView()
{
}

void CMainFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMainFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CMainFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
}

BEGIN_MESSAGE_MAP(CMainFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_SelectRoom, &CMainFormView::OnBnClickedButtonSelectroom)
	ON_BN_CLICKED(IDC_BUTTON_CreateRoom, &CMainFormView::OnBnClickedButtonCreateroom)
END_MESSAGE_MAP()


// CMainFormView 진단

#ifdef _DEBUG
void CMainFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMainFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

// CMainFormView 메시지 처리기


void CMainFormView::OnBnClickedButtonSelectroom()
{
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	pTmp->ShowForm(eForm::SELECT);
	pTmp->sForm->write_RoomList();
}


void CMainFormView::OnBnClickedButtonCreateroom()
{
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	pTmp->ShowForm(eForm::CREATE);
}
