#pragma once


// CLoginFormView 폼 보기

class CLoginFormView : public CFormView
{
	DECLARE_DYNCREATE(CLoginFormView)

public:
	CLoginFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLoginFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Form_Login };
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
	CEdit m_edName;
	afx_msg void OnBnClickedButtonLogin();
	void setMainServer();
	void setGameServer();
	void setChatServer();
};


