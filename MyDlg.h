
// MyDlg.h: файл заголовка
//

#pragma once
#include"DES.h"
#include"vector"


// Диалоговое окно MyDlg
class MyDlg : public CDialogEx
{
// Создание
public:
	MyDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFBEZ1_DIALOG };
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


	//задает начальные параметры файла, используется один раз в hInit
	void MyDlg::SetOpenFileParams(HWND hWnd);
	//непосредственно сохраняет надпись из окна
	void saveData(LPCWSTR path, CEdit& source);
	//загружает в окно
	void loadData(LPCWSTR path, CEdit& source);

	
	OPENFILENAME ofn1; //файл
	wchar_t filename1[260]; //его имя


	DECLARE_MESSAGE_MAP()
public:
	DES des;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CEdit input;
	CEdit output;
	CEdit key;
	BOOL Code;
	
	BOOL Decode;
	CEdit fname1;
	afx_msg void OnBnClickedSave1();
	afx_msg void OnBnClickedLoad1();
	afx_msg void OnBnClickedSave2();
	afx_msg void OnBnClickedLoad2();
	CEdit fname2;
	CEdit fname3;
	afx_msg void OnBnClickedSave3();
	afx_msg void OnBnClickedLoad3();


	LPSTR in;
	LPSTR out;
	LPSTR k;
	CString keyval;
	CString o;
	CString i;
};


