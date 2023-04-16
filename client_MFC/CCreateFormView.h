#pragma once


// CCreateFormView 폼 보기

class CCreateFormView : public CFormView
{
	DECLARE_DYNCREATE(CCreateFormView)

public:
	CCreateFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CCreateFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Form_CreateRoom };
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
	afx_msg void OnEnChangeEditMaxuser();
	CEdit m_edMaxUser;
	CSpinButtonCtrl m_spMaxUser;
	afx_msg void OnDeltaposSpinMaxuser(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit m_edTitle;
	afx_msg void OnBnClickedButtonOk();
};


