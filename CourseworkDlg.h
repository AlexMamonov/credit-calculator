
// CourseworkDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCourseworkDlg
class CCourseworkDlg : public CDialogEx
{
// Создание
public:
	CCourseworkDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	CTabCtrl tab1;
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl mylist;
	afx_msg void OnBnClickedRadio2();
	CEdit edit1;
	CEdit edit2;
	
	afx_msg void OnBnClickedButton1();
	CEdit edit3;
	CEdit edit4;
	CEdit edit5;
	CEdit edit6;
	afx_msg void OnBnClickedButton2();
	CSpinButtonCtrl Spin;
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	CComboBox combo1;
	CEdit edit7;
	CEdit edit8;

	CEdit edit11;
	CEdit edit12;
	afx_msg void OnEnChangeEdit11();
	CEdit edit13;
	CEdit edit14;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton3();

	
	afx_msg void OnEnChangeEdit9();
	CEdit edit9;
	CString fio;
	afx_msg void OnEnChangeEdit8();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnChangeEdit7();
};
