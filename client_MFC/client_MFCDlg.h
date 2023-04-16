
// client_MFCDlg.h: 헤더 파일
//

#pragma once
#include "CMainFormView.h"
#include "CCreateFormView.h"
#include "CSelectFormView.h"
#include "CLoginFormView.h"
#include "CRoomFormView.h"
#include "main.h"
#include "game.h"


enum eForm {
	LOGIN=1,
	MAIN,
	CREATE,
	SELECT,
	ROOM
};
// CclientMFCDlg 대화 상자
class CclientMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CclientMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
public:
	CLoginFormView* lForm = nullptr;
	CMainFormView* mForm = nullptr;
	CCreateFormView* cForm = nullptr;
	CSelectFormView* sForm = nullptr;
	CRoomFormView* rForm = nullptr;
	
	void allocForms();
	void ShowForm(int idx);

protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic t_ConnectState;
	CStatic m_stGameServerState;
	CStatic m_stChatServerState;
};
