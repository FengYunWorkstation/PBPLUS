#pragma once

#include "PBConstants.h"
#include "PBUtil.h"
#include "PBPropertyFunc.h"
#include "PBFuncTemplate.h"
BEGIN_PBPLUS_NASPACE
class PBObject
{
//public:
//	pbclass cSys;//ϵͳ������class
public:
	pbobject obj;
	pbclass cls;
public:
	IPB_Session* session;
public:
	PBObject(IPB_Session* sess);
	virtual ~PBObject(void);
//����
public:
	//classdefinition δʵ��

//����
public:
	tstring ClassName(void);
	//getcontextservice δʵ��
	//getparent δʵ��
	bool PostEvent(tstring e);
	bool PostEvent(tstring e,long w,long l);
	bool PostEvent(tstring e,long w,tstring l);
	//trigeventö�����;���ֵ��δ֪����ʱ��ʵ��

	SHORT TriggerEvent(tstring e);
	SHORT TriggerEvent(tstring e,long w,long l);
	SHORT TriggerEvent(tstring e,long w,tstring l);
	//trigeventö�����;���ֵ��δ֪����ʱ��ʵ��

	//typeof ( ) δʵ��
};

END_PBPLUS_NASPACE