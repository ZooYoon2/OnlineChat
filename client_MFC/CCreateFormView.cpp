// CCreateFormView.cpp: 구현 파일
//

#include "pch.h"
#include "client_MFC.h"
#include "CCreateFormView.h"
#include "client_MFCDlg.h"


// CCreateFormView

IMPLEMENT_DYNCREATE(CCreateFormView, CFormView)

CCreateFormView::CCreateFormView()
	: CFormView(IDD_Form_CreateRoom)
{

}

CCreateFormView::~CCreateFormView()
{
}

void CCreateFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_MaxUser, m_edMaxUser);
	DDX_Control(pDX, IDC_SPIN_MaxUser, m_spMaxUser);
	DDX_Control(pDX, IDC_EDIT_Title, m_edTitle);
}

BEGIN_MESSAGE_MAP(CCreateFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CCreateFormView::OnBnClickedButtonCancel)
	ON_EN_CHANGE(IDC_EDIT_MaxUser, &CCreateFormView::OnEnChangeEditMaxuser)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MaxUser, &CCreateFormView::OnDeltaposSpinMaxuser)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CCreateFormView::OnBnClickedButtonOk)
END_MESSAGE_MAP()


// CCreateFormView 진단

#ifdef _DEBUG
void CCreateFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCreateFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

BOOL CCreateFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CCreateFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_edMaxUser.SetWindowText(_T("8"));
	m_spMaxUser.SetRange(4, 8);
	m_spMaxUser.SetPos(8);
}

// CCreateFormView 메시지 처리기

void CCreateFormView::OnBnClickedButtonCancel()
{
	CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
	pTmp->ShowForm(eForm::MAIN);
}

void CCreateFormView::OnBnClickedButtonOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString title;
	m_edTitle.GetWindowText(title);
	CStringA titleA = CStringA(title);
	CString t;
	m_edMaxUser.GetWindowText(t);
	unsigned int id = send_create_room(titleA.GetBuffer(), _ttoi(t));;
	if (id != 0) {
		CclientMFCDlg* pTmp = (CclientMFCDlg*)pDlg;
		pTmp->ShowForm(eForm::ROOM);
		pTmp->rForm->setRoom(id);
	}
	else {

	}
}

void CCreateFormView::OnEnChangeEditMaxuser()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edTitle.SetLimitText(10);
	CString t;
	m_edMaxUser.GetWindowText(t);
	int num = _ttoi(t);
	if (num > 8) {
		m_edMaxUser.SetWindowText(_T("8"));
	}
	else if(num < 4) {
		m_edMaxUser.SetWindowText(_T("4"));
	}
}


void CCreateFormView::OnDeltaposSpinMaxuser(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int val = pNMUpDown->iPos + pNMUpDown->iDelta;
	if ((val >= 4) && (val <= 8)) {
		CString t;
		t.Format(_T("%d"), val);
		m_edMaxUser.SetWindowText(t);
	}
	*pResult = 0;
}
