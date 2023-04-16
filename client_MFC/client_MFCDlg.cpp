
// client_MFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "client_MFC.h"
#include "client_MFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CclientMFCDlg 대화 상자



CclientMFCDlg::CclientMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CclientMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MainServerState, t_ConnectState);
	DDX_Control(pDX, IDC_STATIC_GameServerState, m_stGameServerState);
	DDX_Control(pDX, IDC_STATIC_ChatServerState, m_stChatServerState);
}

BEGIN_MESSAGE_MAP(CclientMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CclientMFCDlg 메시지 처리기
void CclientMFCDlg::ShowForm(int idx)
{
	switch (idx) {
	case eForm::MAIN: {
		if (mForm != nullptr) mForm->ShowWindow(SW_SHOW);
		if (cForm != nullptr) cForm->ShowWindow(SW_HIDE);
		if (sForm != nullptr) sForm->ShowWindow(SW_HIDE);
		if (lForm != nullptr) lForm->ShowWindow(SW_HIDE);
		if (rForm != nullptr) rForm->ShowWindow(SW_HIDE);
		break;
	}
	case eForm::CREATE: {
		if (mForm != nullptr) mForm->ShowWindow(SW_HIDE);
		if (cForm != nullptr) cForm->ShowWindow(SW_SHOW);
		if (sForm != nullptr) sForm->ShowWindow(SW_HIDE);
		if (lForm != nullptr) lForm->ShowWindow(SW_HIDE);
		if (rForm != nullptr) rForm->ShowWindow(SW_HIDE);
		break;
	}
	case eForm::SELECT: {
		if (mForm != nullptr) mForm->ShowWindow(SW_HIDE);
		if (cForm != nullptr) cForm->ShowWindow(SW_HIDE);
		if (sForm != nullptr) sForm->ShowWindow(SW_SHOW);
		if (lForm != nullptr) lForm->ShowWindow(SW_HIDE);
		if(rForm !=nullptr) rForm->ShowWindow(SW_HIDE);
		break;
	}
	case eForm::LOGIN: {
		if (mForm != nullptr) mForm->ShowWindow(SW_HIDE);
		if (cForm != nullptr) cForm->ShowWindow(SW_HIDE);
		if (sForm != nullptr) sForm->ShowWindow(SW_HIDE);
		if (lForm != nullptr) lForm->ShowWindow(SW_SHOW);
		if (rForm != nullptr) rForm->ShowWindow(SW_HIDE);
		break;
	}
	case eForm::ROOM: {
		if (mForm != nullptr) mForm->ShowWindow(SW_HIDE);
		if (cForm != nullptr) cForm->ShowWindow(SW_HIDE);
		if (sForm != nullptr) sForm->ShowWindow(SW_HIDE);
		if (lForm != nullptr) lForm->ShowWindow(SW_HIDE);
		if (rForm != nullptr) rForm->ShowWindow(SW_SHOW);
		break;
	}
	}
}
void CclientMFCDlg::allocForms() {
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;

	GetDlgItem(IDC_STATIC_View)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	mForm = new CMainFormView;
	mForm->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_Form_Main, &context);
	mForm->OnInitialUpdate();
	mForm->ShowWindow(SW_SHOW);
	mForm->pDlg = this;

	cForm = new CCreateFormView;
	cForm->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_Form_CreateRoom, &context);
	cForm->OnInitialUpdate();
	cForm->ShowWindow(SW_HIDE);
	cForm->pDlg = this;

	sForm = new CSelectFormView;
	sForm->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_Form_SelectRoom, &context);
	sForm->OnInitialUpdate();
	sForm->ShowWindow(SW_HIDE);
	sForm->pDlg = this;

	rForm = new CRoomFormView;
	rForm->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_Form_Room, &context);
	rForm->OnInitialUpdate();
	rForm->ShowWindow(SW_HIDE);
	rForm->pDlg = this;

	GetDlgItem(IDC_STATIC_View)->DestroyWindow();
}

BOOL CclientMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;

	GetDlgItem(IDC_STATIC_View)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	lForm = new CLoginFormView;
	lForm->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_Form_Login, &context);
	lForm->OnInitialUpdate();
	lForm->ShowWindow(SW_SHOW);
	lForm->pDlg = this;
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}



void CclientMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CclientMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CclientMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclientMFCDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowForm(0);
}


void CclientMFCDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowForm(1);
}
