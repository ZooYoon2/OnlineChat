// CRoomFormView.cpp: 구현 파일
//

#include "pch.h"
#include "client_MFC.h"
#include "CRoomFormView.h"
#include "client_MFCDlg.h"


// CRoomFormView

IMPLEMENT_DYNCREATE(CRoomFormView, CFormView)
CRoomFormView::CRoomFormView()
	: CFormView(IDD_Form_Room)
{

}

CRoomFormView::~CRoomFormView()
{
}

void CRoomFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Users, m_lstUsers);
	DDX_Control(pDX, IDC_LIST_Chat, m_lstChat);
	DDX_Control(pDX, IDC_EDIT_Msg, m_edMsg);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_stTitle);
}

BEGIN_MESSAGE_MAP(CRoomFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_Ready, &CRoomFormView::OnBnClickedButtonReady)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CRoomFormView::OnBnClickedButtonOut)
END_MESSAGE_MAP()


// CRoomFormView 진단

#ifdef _DEBUG
void CRoomFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRoomFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CRoomFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CRoomFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_edMsg.SetLimitText(20);
	CRect rect;
	m_lstUsers.GetClientRect(&rect);
	m_lstUsers.InsertColumn(0, _T(" "), LVCFMT_CENTER, 20);
	m_lstUsers.InsertColumn(1, _T("닉네임"), LVCFMT_CENTER, 30);
	m_lstUsers.InsertColumn(2, _T("번호"), LVCFMT_CENTER, rect.Width() - 50);
}

void CRoomFormView::setRoom(unsigned id) {
	if (d_Room != nullptr) {
		this->d_Room = d_Room;
		this->m_stTitle.SetWindowTextW(CA2W(d_Room->name));
	}
	
}
// CRoomFormView 메시지 처리기


void CRoomFormView::OnBnClickedButtonReady()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRoomFormView::OnBnClickedButtonOut()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
