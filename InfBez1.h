
// InfBez1.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CInfBez1App:
// Сведения о реализации этого класса: InfBez1.cpp
//

class CInfBez1App : public CWinApp
{
public:
	CInfBez1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CInfBez1App theApp;
