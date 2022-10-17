
// CourseworkDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Coursework.h"
#include "CourseworkDlg.h"
#include "afxdialogex.h"
#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int  iSelList=0;


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{

public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CCourseworkDlg



CCourseworkDlg::CCourseworkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COURSEWORK_DIALOG, pParent)
	, fio(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCourseworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB2, tab1);
	DDX_Control(pDX, IDC_LIST2, mylist);
	DDX_Control(pDX, IDC_EDIT1, edit1);
	DDX_Control(pDX, IDC_EDIT2, edit2);

	DDX_Control(pDX, IDC_EDIT3, edit3);
	DDX_Control(pDX, IDC_EDIT4, edit4);
	DDX_Control(pDX, IDC_EDIT5, edit5);
	DDX_Control(pDX, IDC_EDIT6, edit6);
	DDX_Control(pDX, IDC_SPIN1, Spin);
	DDX_Control(pDX, IDC_COMBO1, combo1);
	DDX_Control(pDX, IDC_EDIT7, edit7);
	DDX_Control(pDX, IDC_EDIT8, edit8);

	DDX_Control(pDX, IDC_EDIT11, edit11);
	DDX_Control(pDX, IDC_EDIT12, edit12);
	DDX_Control(pDX, IDC_EDIT13, edit13);
	DDX_Control(pDX, IDC_EDIT14, edit14);
	DDX_Control(pDX, IDC_EDIT9, edit9);
	DDX_Text(pDX, IDC_EDIT9, fio);
}

BEGIN_MESSAGE_MAP(CCourseworkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, &CCourseworkDlg::OnTcnSelchangeTab2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CCourseworkDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_RADIO2, &CCourseworkDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON2, &CCourseworkDlg::OnBnClickedButton2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CCourseworkDlg::OnDeltaposSpin1)
	ON_EN_CHANGE(IDC_EDIT11, &CCourseworkDlg::OnEnChangeEdit11)
	ON_BN_CLICKED(IDC_RADIO1, &CCourseworkDlg::OnBnClickedRadio1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CCourseworkDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCourseworkDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT9, &CCourseworkDlg::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT8, &CCourseworkDlg::OnEnChangeEdit8)
	ON_WM_CREATE()
	ON_EN_CHANGE(IDC_EDIT7, &CCourseworkDlg::OnEnChangeEdit7)
END_MESSAGE_MAP()

 
// Обработчики сообщений CCourseworkDlg

BOOL CCourseworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	Spin.SetRange(0, 1000);
	combo1.AddString(L"Месяцев");
	combo1.AddString(L"лет");
	combo1.SetCurSel(0);
	
	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	tab1.InsertItem(0, L"По стоимости покупки");
	tab1.InsertItem(1, L"По сумме кредита");
	edit1.ShowWindow(1);
	edit2.ShowWindow(1);
	

	

	CRect rect;

	mylist.GetClientRect(rect);
	mylist.InsertColumn(0, L"Месяц", 0, rect.Width() / 5);
	mylist.InsertColumn(1, L"Сумма платежа", 0, rect.Width() / 5);
	mylist.InsertColumn(2, L"Погашение кредита", 0, rect.Width() / 5);
	mylist.InsertColumn(3, L"Погашение процентов", 0, rect.Width() / 5);
	mylist.InsertColumn(4, L"Остаток задолжностей", 0, rect.Width() / 5);
	


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCourseworkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCourseworkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCourseworkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCourseworkDlg::OnTcnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult)
{
	SetDlgItemText(IDC_EDIT11, L" Стоимость покупки ");
	SetDlgItemText(IDC_EDIT12, L" Первоначальный взнос ");
	SetDlgItemText(IDC_EDIT13, L" руб. ");
	SetDlgItemText(IDC_EDIT14, L" руб. ");
	
	int i = tab1.GetCurSel();

	switch (i)
	{

	case 0:
		edit1.ShowWindow(1);
		edit2.ShowWindow(1);
		edit11.ShowWindow(1);
		edit12.ShowWindow(1);
		edit13.ShowWindow(1);
		edit14.ShowWindow(1);
			break;
	case 1:
		edit2.ShowWindow(0);
		edit1.ShowWindow(0);
		edit11.ShowWindow(0);
		edit12.ShowWindow(0);
		edit13.ShowWindow(0);
		edit14.ShowWindow(0);
		break;

	
	}
	*pResult = 0; 

  
}


void CCourseworkDlg::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
	

}


void CCourseworkDlg::OnBnClickedRadio2()
{
	int a, b,  n;
	double itog, o,c, p,z,t,h,m,dolg;
	float v;
	CString Str;
	edit1.GetWindowTextW(Str);
	a = _wtoi(Str);
	edit2.GetWindowTextW(Str);
	b = _wtoi(Str);
	edit3.GetWindowTextW(Str);
	c = _wtoi(Str);
	edit4.GetWindowTextW(Str);
	v = _wtoi(Str);
	edit5.GetWindowTextW(Str);
	n = _wtoi(Str);
	edit6.GetWindowTextW(Str);
	itog = _wtoi(Str);
	edit7.GetWindowTextW(Str);
	p = _wtoi(Str);
	edit8.GetWindowTextW(Str);
	o = _wtoi(Str);

	if (combo1.GetCurSel() == 0)
	{
		n = n * 12;
		Str.Format(L"%d", n);

	}

	if (c == 0) {
		c = a - b;
		Str.Format(L"%d", c);
		edit3.SetWindowTextW(Str);
	}
	else
	{
		c;
	}

	dolg=c / n;


	v = v / 100;
	Str.Format(L"%.2f", v);
	edit7.SetWindowTextW(Str);


	for (int i = 0; i < n; i++) {
		CString Str;
		Str.Format(L"%d", i + 1);
		int Int = mylist.InsertItem(mylist.GetItemCount(), Str, -1);
		
	}
	
	

	double sum = c;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		double plat;
		
		int B[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		
		if (j == 12) {
			j = 0;
		}
		plat = c * v * B[j] / 365;
		j++;
	

		m = dolg;// погашение кредита
		Str.Format(L"%.2f", m);
		edit6.SetWindowTextW(Str);
		CString q1;
		GetDlgItemTextW(IDC_EDIT6, q1);
		mylist.SetItemText(i, 2, q1);

		z = plat;// погашение процентов &-дней в месяце
		Str.Format(L"%.2f", z);
		edit8.SetWindowTextW(Str);
		CString q3;
		GetDlgItemTextW(IDC_EDIT8, q3);
		mylist.SetItemText(i, 3, q3);

		t = dolg + plat;// сумма платеж
		Str.Format(L"%.2f", t);
		edit2.SetWindowTextW(Str);
		CString q5;
		GetDlgItemTextW(IDC_EDIT2, q5);
		mylist.SetItemText(i, 1, q5);
		

		h = c - dolg;// остаток суммы кредита 
		if (h < 0)
			h = h * -1;
		Str.Format(L"%.2f", h);
		edit7.SetWindowTextW(Str);
		CString q2;
		GetDlgItemTextW(IDC_EDIT7, q2);
		mylist.SetItemText(i, 4, q2);
		
		c = h;


		itog += t ;//итоговая стоимость
		
		o = t; // ежемесяч платеж
		Str.Format(L"%.2f", o);
		edit8.SetWindowTextW(Str);
	}
	p = itog-sum;// переплата
	Str.Format(L"%.2f", p);
	edit7.SetWindowTextW(Str);
	
	
	Str.Format(L"%.2f", itog);
	edit6.SetWindowTextW(Str);
	Str.Format(L"%.2f", p);
	edit7.SetWindowTextW(Str);
	Str.Format(L"%.2f", o);
	edit8.SetWindowTextW(Str);
	Str.Format(L"%d", b);
	edit2.SetWindowTextW(Str);




	if (mylist.GetSelectionMark() >= 0) {
		mylist.DeleteItem(mylist.GetSelectionMark());
	
	}


	
	// TODO: добавьте свой код обработчика уведомлений
}



void CCourseworkDlg::OnBnClickedButton2()
{
	int a, b, c, v, n;
	double i, o, p;
	CString Str;
	edit1.GetWindowTextW(Str);
	a = _wtoi(Str);
	edit2.GetWindowTextW(Str);
	b = _wtoi(Str);
	edit3.GetWindowTextW(Str);
	c = _wtoi(Str);
	edit4.GetWindowTextW(Str);
	v = _wtoi(Str);
	edit5.GetWindowTextW(Str);
	n = _wtoi(Str);
	edit6.GetWindowTextW(Str);
	i = _wtoi(Str);
	edit7.GetWindowTextW(Str);
	p = _wtoi(Str);
	edit8.GetWindowTextW(Str);
	o = _wtoi(Str);

	a = 0;
	Str.Format(L"%d", a);
	edit1.SetWindowTextW(Str);

	b = 0;
	Str.Format(L"%d", b);
	edit2.SetWindowTextW(Str);

	c = 0;
	Str.Format(L"%d", c);
	edit3.SetWindowTextW(Str);

	v = 0;
	Str.Format(L"%d", v);
	edit4.SetWindowTextW(Str);
	n = 0;
	Str.Format(L"%d", n);
	edit5.SetWindowTextW(Str);

	i = 0;
	Str.Format(L"%d", i);
	edit6.SetWindowTextW(Str);
	p = 0;
	Str.Format(L"%d", p);
	edit7.SetWindowTextW(Str);

	o = 0;
	Str.Format(L"%d", o);
	edit8.SetWindowTextW(Str);

	c = a - b;
	Str.Format(L"%d", c);
	edit3.SetWindowTextW(Str);

	Str.Format(L"%d", c);
	edit3.SetWindowTextW(Str);


	mylist.DeleteAllItems();

	// TODO: добавьте свой код обработчика уведомлений
}


void CCourseworkDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	CString Str;
	Str.Format(L"%d", Spin.GetPos32());
	edit5.SetWindowTextW(Str);
	*pResult = 0;
}


void CCourseworkDlg::OnEnChangeEdit11()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
int count = 0;

void CCourseworkDlg::OnBnClickedRadio1()
{
	int a, b, c, n;
	double i, o, p,j,h,z;
	float v;
	CString Str;
	edit1.GetWindowTextW(Str);
	a = _wtoi(Str);
	edit2.GetWindowTextW(Str);
	b = _wtoi(Str);
	edit3.GetWindowTextW(Str);
	c = _wtoi(Str);
	edit4.GetWindowTextW(Str);
	v = _wtoi(Str);
	edit5.GetWindowTextW(Str);
	n = _wtoi(Str);
	edit6.GetWindowTextW(Str);
	i = _wtoi(Str);
	edit7.GetWindowTextW(Str);
	p = _wtoi(Str);
	edit8.GetWindowTextW(Str);
	o = _wtoi(Str);

	if (combo1.GetCurSel() == 0) {
		n= n * 12;
		Str.Format(L"%d", n);
	}


	if (c == 0) {
		c = a - b;
		Str.Format(L"%d", c);
		edit3.SetWindowTextW(Str);
	}
	else
	{
		 c;
	}
	

	v = v/100.0/12.0; // проценты
	Str.Format(L"%.2f", v);
	edit7.SetWindowTextW(Str);

	o = c * (v * pow((1 + v), n)) / (pow((1 + v), n) - 1);; // Ежемесяч платеж
	Str.Format(L"%.2f", o);
	edit8.SetWindowTextW(Str);

	p = (o * n) - c; // переплата
	Str.Format(L"%.2f", p);
	edit7.SetWindowTextW(Str);
	i = o * n; // итоговая стоимость
	Str.Format(L"%.2f", i);
	edit6.SetWindowTextW(Str);

	for (int i = 0; i < n; i++) {
		CString Str;
		Str.Format(L"%d", i + 1);
		int Int = mylist.InsertItem(mylist.GetItemCount(), Str, -1);

		CString cs;
		GetDlgItemTextW(IDC_EDIT8, cs);
		mylist.SetItemText(i, 1, cs);

		count++;
	}


	h = c;
	for (int i = 0; i < n; i++) 
	{

		j = o - (h * v);// погашение кредита
		Str.Format(L"%.2f", j);
		edit6.SetWindowTextW(Str);
		CString q1;
		GetDlgItemTextW(IDC_EDIT6, q1);
		mylist.SetItemText(i, 2, q1); 

		z = o - j;// погашение процентов
		Str.Format(L"%.2f", z);
		edit8.SetWindowTextW(Str);
		CString q3;
		GetDlgItemTextW(IDC_EDIT8, q3);
		mylist.SetItemText(i, 3, q3);

		h = h - j;// остаток суммы кредита
		if (h < 0)
			h = h * -1;
		Str.Format(L"%.2f", h);
		edit7.SetWindowTextW(Str);
		CString q2;
		GetDlgItemTextW(IDC_EDIT7, q2);
		mylist.SetItemText(i, 4, q2);
		count++;
	}
	
	Str.Format(L"%.2f", i);
	edit6.SetWindowTextW(Str);
	Str.Format(L"%.2f", p);
	edit7.SetWindowTextW(Str);
	Str.Format(L"%.2f", o);
	edit8.SetWindowTextW(Str);




	
	// TODO: добавьте свой код обработчика уведомлений
}


void CCourseworkDlg::OnCbnSelchangeCombo1()
{
	
	// TODO: добавьте свой код обработчика уведомлений
}

//структура данных предметной области


void CCourseworkDlg::OnBnClickedButton3()
{
	

	CFileDialog fileDialog(FALSE, 0, L"*.txt"); //объект класса выбора файла
	int result = fileDialog.DoModal(); //запустить диалоговое окно
	if (result == IDOK) //если файл выбран
	

	{
		

		//setlocale(LC_ALL, "Russian");
		// Создаем файл
		std::wofstream fileo;
		fileo.open(fileDialog.GetPathName());
		//цикл записи в файл
		if (fileo.is_open())

			fileo << "График платежей" << std::endl;
		fileo << "Дата кредита-01.01.2022" << std::endl;

		CString itog1;
		GetDlgItemTextW(IDC_EDIT6, itog1);
		LPCWSTR it = itog1.operator LPCWSTR();
		fileo << "Итоговая стоимость-" << it << std::endl;

		CString pereplat1;
		GetDlgItemTextW(IDC_EDIT7, pereplat1);
		LPCWSTR pr = pereplat1.operator LPCWSTR();
		fileo << "Переплата - " << pr << std::endl;

		CString plat1;
		GetDlgItemTextW(IDC_EDIT8, plat1);
		LPCWSTR plat = plat1.operator LPCWSTR();
		fileo << "Платеж-" << plat << std::endl;

		CString fio1;
		GetDlgItemTextW(IDC_EDIT9, fio1);
		LPCWSTR hhh = fio1.operator LPCWSTR();
		fileo << "Кредит оформил-" << hhh << std::endl;

			fileo << "Месяц" << '\t' << "Сумма платежа" << '\t' << "Погашение кредита" << '\t' << "Погашение процентов" << '\t' << "Остаток задолжностей";
		fileo << std::endl;
		{
			for (int i = 0; i < mylist.GetItemCount(); i++) {
				
			
				fileo << mylist.GetItemText(i, 0).operator LPCWSTR()  << '\t' << mylist.GetItemText(i, 1).operator LPCWSTR()  << '\t' << '\t' << mylist.GetItemText(i, 2).operator LPCWSTR() << '\t' << '\t' << '\t' << mylist.GetItemText(i, 3).operator LPCWSTR() << '\t' << '\t' << '\t' << mylist.GetItemText(i, 4).operator LPCWSTR() << std::endl;
			}	
			fileo << std::endl;
		}
		fileo.close();
	}
	
}


void CCourseworkDlg::OnEnChangeEdit9()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCourseworkDlg::OnEnChangeEdit8()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


int CCourseworkDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CCourseworkDlg::OnEnChangeEdit7()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
