// CLoginFormView.cpp: 구현 파일
//

#include "pch.h"
#include "client_MFC.h"
#include "CLoginFormView.h"
#include "client_MFCDlg.h"
#include "main.h"
#include "game.h"
#include "chat.h"

// CLoginFormView

IMPLEMENT_DYNCREATE(CLoginFormView, CFormView)

CLoginFormView::CLoginFormView()
	: CFormView(IDD_Form_Login)
{

}

CLoginFormView::~CLoginFormView()
{
}

void CLoginFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Name, m_edName);
}

BEGIN_MESSAGE_MAP(CLoginFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_Login, &CLoginFormView::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CLoginFormView 진단

#ifdef _DEBUG
void CLoginFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLoginFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CLoginFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CLoginFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_edName.SetLimitText(10);
}
void CLoginFormView::setMainServer() {
	CString t;
	m_edName.GetWindowText(t);
	char* name = LPSTR(LPCTSTR(t));
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;

	if (main_server_init() == 0)
		return;
	if (main_server_connet() == 0) {
		return;
	}
	if (main_server_login(name) == 0) {
		return;
	}
	std::thread th_mainServer(check_connect_state, &pTmp->t_ConnectState);
	th_mainServer.detach();
}
void CLoginFormView::setGameServer() {
	CString t;
	m_edName.GetWindowText(t);
	char* name = LPSTR(LPCTSTR(t));
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	if (game_server_init()==0)
		return;
	if (game_server_connet() == 0) {
		return;
	}
	if (game_server_access(name) == 0) {
		return;
	}
	std::thread th_gameServer(check_game_server_state, &pTmp->m_stGameServerState);
	th_gameServer.detach();
}
void CLoginFormView::setChatServer() {
	CString t;
	m_edName.GetWindowText(t);
	char* name = LPSTR(LPCTSTR(t));
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	if (chat_server_init() == 0)
		return;
	if (chat_server_connet() == 0) {
		return;
	}
	if (chat_server_access(name) == 0) {
		return;
	}
	std::thread th_chatServer(check_chat_server_state, &pTmp->m_stChatServerState);
	th_chatServer.detach();
}
// CLoginFormView 메시지 처리기


void CLoginFormView::OnBnClickedButtonLogin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	WORD wVersionRequired;//원속버전
	WSADATA wasData; //원속정보
	wVersionRequired = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequired, &wasData) != 0) {
		printf("WSAStartup Error");
		WSACleanup();
	}
	setMainServer();
	setGameServer();
	setChatServer();
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	pTmp->allocForms();
	pTmp->ShowForm(eForm::MAIN);
}
