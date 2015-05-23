/*
* PBHost.h
*
*  Created on: 2015.05.23
*      Author: wxj
*		EMAIL: wxj_wz@qq.com
*/
#pragma once
#include "PBPlusLib.h"
BEGIN_PBPLUS_NASPACE
class PBHost
{
public:
	PBHost(void);
	~PBHost(void);
	operator HINSTANCE()
	{
		return hinst;
	}
	IPB_Session* PBPointer()
	{
		return session;
	}
	BOOL EnablePrivilege(HANDLE hToken,LPCTSTR szPrivName);//����Ȩ��
	bool GetCurrentProcessDirectory(TCHAR dir[]);
	void SetPBEnvitentPath(HINSTANCE hInstance);
	bool CreatePBHost(tstring& dir);//����PB��������
	//bool AddToLibraryList(tstring& libList);//���PBL(PBD)
	//void GetLibraryList(tstring& list);
	DECLAREPBPROPERTY(tstring,LibraryList)
private:
	IPB_Session* session;
	IPB_VM* pbvm;
	HINSTANCE hinst;
	tstring pbdFile;
};
END_PBPLUS_NASPACE
