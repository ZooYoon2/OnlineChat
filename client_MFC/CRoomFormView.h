#pragma once
#include "LobbyProtocol.h"


// CRoomFormView 폼 보기

class CRoomFormView : public CFormView
{
	DECLARE_DYNCREATE(CRoomFormView)

public:
	CRoomFormView();				// 동적 만들기에 사용되는 protected 생성자입니다.    
	virtual ~CRoomFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Form_Room };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	ptRoom* d_Room;
	void setRoom(unsigned int id);
	CDialogEx* pDlg;
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	CListCtrl m_lstUsers;
	afx_msg void OnBnClickedButtonReady();
	afx_msg void OnBnClickedButtonOut();
	CListBox m_lstChat;
	CEdit m_edMsg;
	CStatic m_stTitle;
};


