#pragma once
#include "main.h"


// CSelectFormView 폼 보기

class CSelectFormView : public CFormView
{
	DECLARE_DYNCREATE(CSelectFormView)

public:
	CSelectFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CSelectFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Form_SelectRoom };
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
	CDialogEx* pDlg;
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButtonCancel();
	CListCtrl m_List;

	void write_RoomList();
	afx_msg void OnBnClickedButtonReload();
};


