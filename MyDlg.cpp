
// MyDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "InfBez1.h"
#include "MyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// Диалоговое окно MyDlg



MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INFBEZ1_DIALOG, pParent)
	, Code(FALSE)
	, Decode(TRUE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, input);
	DDX_Control(pDX, IDC_EDIT2, output);
	DDX_Control(pDX, IDC_EDIT3, key);

	DDX_Radio(pDX, IDC_RADIO1, Code);
}

BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &MyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_SAVE1, &MyDlg::OnBnClickedSave1)
	ON_BN_CLICKED(IDC_LOAD1, &MyDlg::OnBnClickedLoad1)
	ON_BN_CLICKED(IDC_SAVE2, &MyDlg::OnBnClickedSave2)
	ON_BN_CLICKED(IDC_LOAD2, &MyDlg::OnBnClickedLoad2)
	ON_BN_CLICKED(IDC_SAVE3, &MyDlg::OnBnClickedSave3)
	ON_BN_CLICKED(IDC_LOAD3, &MyDlg::OnBnClickedLoad3)
END_MESSAGE_MAP()


// Обработчики сообщений MyDlg

BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	SetOpenFileParams(this->GetSafeHwnd());
	mainWnd = this->GetSafeHwnd();


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void MyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void MyDlg::OnPaint()
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
HCURSOR MyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void MyDlg::OnBnClickedOk()
{
	des.test();

	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	if (key.GetWindowTextLengthW() == 0)
	{
		MessageBox(L"Введите ключ", L"Ошибка", MB_OK);
		return;
	}


	CString intext, k;
	key.GetWindowTextW(k);


	if (!Code)
	{
		if (input.GetWindowTextLengthW() == 0)
		{
			MessageBox(L"Введите кодируемый текст", L"Ошибка", MB_OK);
			return;
		}


		input.GetWindowTextW(intext);


	}
	else
	{
		if (output.GetWindowTextLengthW() == 0)
		{
			MessageBox(L"Введите шифруемый текст", L"Ошибка", MB_OK);
			return;
		}


		output.GetWindowTextW(intext);


	}
}


void MyDlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	PostQuitMessage(0);
}


void MyDlg::SetOpenFileParams(HWND hWnd)
{
	ZeroMemory(&ofn1, sizeof(ofn1));
	ofn1.lStructSize = sizeof(ofn1);
	ofn1.hwndOwner = hWnd;
	ofn1.lpstrFile = filename1;
	ofn1.nMaxFile = sizeof(filename1);
	ofn1.lpstrFilter = L"*.txt";
	ofn1.lpstrFileTitle = NULL;
	ofn1.nMaxFileTitle = 0;
	ofn1.lpstrInitialDir = L"C:\\Users\\asevu\\source\\repos\\InfBez1";//начальная директория
	ofn1.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
}


void MyDlg::saveData(LPCWSTR path, CEdit& source)
{
	HANDLE FileToSave = CreateFile(
		path,//путь 
		GENERIC_WRITE,//только запись
		0,
		NULL,
		CREATE_ALWAYS,//если файла нет - создать, иначе перезаписать
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);



	int size = source.GetWindowTextLengthW() + 1;
	char* Buffer = new char[size];
	int got = GetWindowTextA(source.GetSafeHwnd(), Buffer, size);
	

	char csize[10];
	_itoa_s(size - 1, csize, 10);
	for (int i = strlen(csize); i < 9; i++)csize[i] = ' ';
	csize[9] = '\0';
	

	DWORD bytesIterated;
	WriteFile(FileToSave,csize , strlen(csize), &bytesIterated, NULL);
	WriteFile(FileToSave, Buffer, strlen(Buffer), &bytesIterated, NULL);


	CloseHandle(FileToSave);
	delete[] Buffer;
}


void MyDlg::loadData(LPCWSTR path, CEdit& source)
{
	HANDLE FileToLoad = CreateFile(
		path,//путь 
		GENERIC_READ,//только запись
		0,
		NULL,
		OPEN_EXISTING,//если файла нет - создать, иначе перезаписать
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	
	DWORD bytesIterated;
	
	
	char csize[10];
	csize[9] = '\0';
	ReadFile(FileToLoad, csize, 9, &bytesIterated, NULL);
	int size = atoi(csize);

	char* buffer = new char[size + 1];
	buffer[size] = '\0';

	ReadFile(FileToLoad, buffer, size, &bytesIterated, NULL);


	SetWindowTextA(source.GetSafeHwnd(), buffer);
	CloseHandle(FileToLoad);
	delete[]buffer;
}

void MyDlg::OnBnClickedSave1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (input.GetWindowTextLengthW() == 0)
	{
		MessageBox(L"Введите кодируемый текст", L"Ошибка", MB_OK);
		return;
	}


	if (GetSaveFileNameW(&ofn1))
	{
		fname1.SetWindowTextW(filename1);
		saveData(filename1, input);
	}
	else MessageBox(L"Файл не открыт", L"Ошибка открытия файла", MB_OK);
}


void MyDlg::OnBnClickedLoad1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!GetOpenFileName(&ofn1))MessageBox(L"Файл не открыт", L"Ошибка открытия файла", MB_OK);
	fname1.SetWindowTextW(filename1);
	loadData(filename1, input);
}


void MyDlg::OnBnClickedSave2()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (output.GetWindowTextLengthW() == 0)
	{
		MessageBox(L"Введите зашифрованный текст", L"Ошибка", MB_OK);
		return;
	}

	
	if (GetSaveFileNameW(&ofn1))
	{
		fname2.SetWindowTextW(filename1);
		saveData(filename1, output);
	}
	else MessageBox(L"Файл не открыт", L"Ошибка открытия файла", MB_OK);
}


void MyDlg::OnBnClickedLoad2()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!GetOpenFileName(&ofn1))MessageBox(L"Файл не открыт", L"Ошибка открытия файла", MB_OK);
	fname2.SetWindowTextW(filename1);
	loadData(filename1, output);
}


void MyDlg::OnBnClickedSave3()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (key.GetWindowTextLengthW() == 0)
	{
		MessageBox(L"Введите ключ", L"Ошибка", MB_OK);
		return;
	}


	if (GetSaveFileNameW(&ofn1))
	{
		fname3.SetWindowTextW(filename1);
		saveData(filename1, key);
	}
	else MessageBox(L"Файл не открыт", L"Ошибка открытия файла", MB_OK);
}


void MyDlg::OnBnClickedLoad3()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (!GetOpenFileName(&ofn1))MessageBox(L"Файл не открыт", L"Ошибка открытия файла", MB_OK);
	fname3.SetWindowTextW(filename1);
	loadData(filename1, key);
}
