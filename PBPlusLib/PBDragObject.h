#pragma once
//#include "pbext.h"
#include "PBWindowObject.h"
//#include "PBSystem.h"
////��¼ԭ��������
//	static WNDPROC OldMsgProc;
//	//����Ϣ������
//	static LRESULT CALLBACK CustMsgProc(HWND hwnd,UINT message, WPARAM wParam, LPARAM lParam);
//	static HHOOK hhook;
BEGIN_PBPLUS_NASPACE
class PBDragObject:public PBWindowObject
{

public:
	PBDragObject(IPB_Session* s);
	~PBDragObject(void);
private:
	HWND handle;
	//WNDPROC OldMsgProc1;
	
//����
public:
	DECLAREPBPROPERTY(PBAccessibleRole,AccessibleRole)
	DECLAREPBPROPERTY(bool,BringToTop)
	DECLAREPBPROPERTY(bool,DragAuto)
	DECLAREPBPROPERTY(SHORT,Height)
	DECLAREPBPROPERTY(SHORT,TabOrder)
	//͸����0-��͸����100��ȫ͸��
	DECLAREPBPROPERTY(SHORT,Transparency)
	DECLAREPBPROPERTY(SHORT,Width)
	DECLAREPBPROPERTY(SHORT,X)
	DECLAREPBPROPERTY(SHORT,Y)
	DECLAREPBPROPERTY(tstring,AccessibleDescription)
	DECLAREPBPROPERTY(tstring,AccessibleName)
	DECLAREPBPROPERTY(tstring,DragIcon)
	////�������Լ���չ��
	////���
	//DECLAREPBPROPERTY(HWND,XHandle)
//����
public:
	//Drag dragmodesδ֪����ʱδʵ��
	SHORT PointerX(void);
	SHORT PointerY(void);
	SHORT Print(long j,SHORT x, SHORT y); 
	SHORT Print(long j,SHORT x, SHORT y,SHORT w,SHORT h); 
	SHORT SetActionCode(long c);
	SHORT Setfocus(void);
	//setposition ( setpostype p )  returns integer δʵ��
	//setposition ( setpostype p, dragobject a )  returns integer
	SHORT SetRedraw(bool f);
	//�������Լ���չ
	virtual bool SetWxjOwnerProc();
};
END_PBPLUS_NASPACE