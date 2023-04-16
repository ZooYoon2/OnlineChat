// CSelectFormView.cpp: 구현 파일
//

#include "pch.h"
#include "client_MFC.h"
#include "CSelectFormView.h"
#include "client_MFCDlg.h"

// CSelectFormView

IMPLEMENT_DYNCREATE(CSelectFormView, CFormView)

CSelectFormView::CSelectFormView()
	: CFormView(IDD_Form_SelectRoom)
{

}

CSelectFormView::~CSelectFormView()
{
}

void CSelectFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Room, m_List);
}

BEGIN_MESSAGE_MAP(CSelectFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CSelectFormView::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_Reload, &CSelectFormView::OnBnClickedButtonReload)
END_MESSAGE_MAP()


// CSelectFormView 진단

#ifdef _DEBUG
void CSelectFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CSelectFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CSelectFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CRect rect;
	m_List.GetClientRect(&rect);
	m_List.InsertColumn(0, _T("번호"), LVCFMT_CENTER, 50);
	m_List.InsertColumn(1, _T("제목"), LVCFMT_CENTER, 300);
	m_List.InsertColumn(2, _T("방장"), LVCFMT_CENTER, rect.Width()-350);
}

void CSelectFormView::write_RoomList() {
	
	ptRoomList d = recv_channel_list();
	if (d.cnt != 0){
		m_List.DeleteAllItems();
		for (int i = 0; i < d.cnt; i++) {
			CString t;
			t.Format(_T("%d"), d.rooms[i].id);
			m_List.InsertItem(i, t);
			m_List.SetItemText(i, 1, CA2W(d.rooms[i].name));
			m_List.SetItemText(i, 2, CA2W(d.rooms[i].host_name));
		}
	}
}
// CSelectFormView 메시지 처리기


void CSelectFormView::OnBnClickedButtonCancel()
{
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	pTmp->ShowForm(eForm::MAIN);
}


void CSelectFormView::OnBnClickedButtonReload()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	write_RoomList();
}
