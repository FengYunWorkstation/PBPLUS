// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#if _MSC_VER < 1600
#define nullptr  NULL
#endif
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <atlbase.h>
#include <atlstr.h>
#include <atlwin.h>
//#include <ATLComTime.h>
#include <vector>
#include <sstream>
#include "pbext.h"


#define NAMESPACE namespace
#define APP_NAMSPACE WXJ_LIB

#ifdef USINGUSERNAMESPACE
#define BEGIN_PBPLUS_NASPACE \
	NAMESPACE APP_NAMSPACE{

#define END_PBPLUS_NASPACE\
	}

#define USING_APP_NAMESPACE\
	using namespace APP_NAMSPACE;
#else
#define BEGIN_PBPLUS_NASPACE 
#define END_PBPLUS_NASPACE
#define USING_APP_NAMESPACE
#endif

#define IFDEFSTATEMENT #ifdef
#define UNDEFSTATEMENT #undef
#define ENDIFSTATEMENT #endif
#define DEFINESTATEMENT #define
#define ELSESTATEMENT #else
#define LF _T("\n")
//���ú�չ��
#define DISABLE_PPEPROCESSOR(name) \
IFDEFSTATEMENT name \
	\
UNDEFSTATEMENT name \
ENDIFSTATEMENT

//�ظ���չ��
#define RESTORE_PPEPROCESSOR(name) \
IFDEFSTATEMENT UNICODE \
	DEFINESTATEMENT name  name##W \
ELSESTATEMENT \
	DEFINESTATEMENT name  name##A \
ENDIFSTATEMENT 

//#include "PBPlusLib.h"
//#define BEGIN_PBPLUS_NASPACE \
//	namespace PBPlus \
//	{
//
//#define END_PBPLUS_NASPACE }