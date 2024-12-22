
// MAGA_Tomography.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMAGATomographyApp:
// Сведения о реализации этого класса: MAGA_Tomography.cpp
//

class CMAGATomographyApp : public CWinApp
{
public:
	CMAGATomographyApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMAGATomographyApp theApp;
