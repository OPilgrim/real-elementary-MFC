
// AGAIN_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAGAIN_MFCApp: 
// �йش����ʵ�֣������ AGAIN_MFC.cpp
//

class CAGAIN_MFCApp : public CWinApp
{
public:
	CAGAIN_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAGAIN_MFCApp theApp;
