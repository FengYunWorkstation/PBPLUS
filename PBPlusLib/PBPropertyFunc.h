#pragma once
#include "pbext.h"
#include "PBUtil.h"
//#include "PBSystem.h"
//BEGIN_PBPLUS_NASPACE
//=====================================================================================================================
//���Ե����úͻ�ȡ
//--------------------------------<<
//���Եĸ�������ʵ��,ע���ԱΪfriend(����ʱ�������������ͼ��)
template <typename T>
struct strPBSetProperty
{
	static PBXRESULT PBSetField(IPB_Session* s,pbobject obj,pbfieldID fid,pbboolean data)
	{
	}
};
template <>struct strPBSetProperty<bool>
{
	friend static PBXRESULT PBSetField(IPB_Session* s,pbobject obj,pbfieldID fid,bool data)
	{
		pbboolean bVal = (data == true) ? 1 : 0;
		PBXRESULT result = s->SetBoolField(obj,fid,bVal);
		return result;
	}
};
template <>struct strPBSetProperty<SHORT>
{
	friend static PBXRESULT PBSetField(IPB_Session* s,pbobject obj,pbfieldID fid,SHORT data)//pbint��ӦC++��short
	{
		PBXRESULT result =s->SetIntField(obj,fid,data);
		return result;
	}
};
template <>struct strPBSetProperty<long>
{
	friend static PBXRESULT PBSetField(IPB_Session* s,pbobject obj,pbfieldID fid,long data)//pbint��ӦC++��short
	{
		PBXRESULT result =s->SetLongField(obj,fid,data);
		return result;
	}
};
template <>struct strPBSetProperty<tstring>
{
	friend static PBXRESULT PBSetField(IPB_Session* s,pbobject obj,pbfieldID fid,tstring data)
	{
		PBXRESULT result =s->SetStringField(obj,fid,data.c_str());
		return result;
	}
};
//���϶�ÿ���������͵�ʵ��
//--------------------------------------------<<

template <typename T>
PBXRESULT PBSetPropertyValue(IPB_Session* s,pbclass cls,pbobject obj,LPCTSTR propertyName,T& propertyValue,bool isVisualObj=true)
{
	PBXRESULT result = S_OK;
	pbfieldID fid=s->GetFieldID(cls,propertyName);
	PBSetField(s,obj,fid,propertyValue);
	if(isVisualObj == true)result = s->UpdateField(obj,fid);//�ǿ���PowerBuilder��������Ҫˢ��
	return result;
}

//=================================================================================================
//����Ϊ��ȡ���Ե�ֵ
template <typename T>
struct strPBGetProperty
{
	static void PBGetField(IPB_Session* s,pbobject obj,pbfieldID fid,T& data)
	{
	}
};
template <>struct strPBGetProperty<bool>
{
	friend static void PBGetField(IPB_Session* s,pbobject obj,pbfieldID fid,bool& propertyValue)
	{
		pbboolean isNull;
		pbboolean psBool = s->GetBoolField(obj, fid, isNull);
		propertyValue = (psBool ==1)? true :false ;
	}
};
template <>struct strPBGetProperty<SHORT>
{
	friend static void PBGetField(IPB_Session* s,pbobject obj,pbfieldID fid,SHORT& propertyValue)
	{
		pbboolean isNull;
		propertyValue = s->GetIntField(obj, fid, isNull);
	}
};
template <>struct strPBGetProperty<long>
{
	friend static void PBGetField(IPB_Session* s,pbobject obj,pbfieldID fid,long& propertyValue)
	{
		pbboolean isNull;
		propertyValue = s->GetLongField(obj, fid, isNull);
	}
};
template <>struct strPBGetProperty<tstring>
{
	friend static void PBGetField(IPB_Session* s,pbobject obj,pbfieldID fid,tstring&  propertyValue)
	{
		pbboolean isNull;
		pbstring pstr = s->GetStringField(obj, fid, isNull);
		if(NULL == pstr)
			propertyValue.assign(_T(""));
		else
			propertyValue.assign(s->GetString(pstr));
	}
};
//-----------------------<<

template <typename T>
PBXRESULT PBGetPropertyValue(IPB_Session* s,pbclass cls,pbobject obj,LPCTSTR propertyName,T& propertyValue)
{
	PBXRESULT result = S_OK;
	pbfieldID fid=s->GetFieldID(cls,propertyName);
	PBGetField(s,obj,fid,propertyValue);
	return result;
}
//===============================================================================================================================
//���Զ���
#define DECLAREPBPROPERTY(DataType,ProName) \
	DataType Get##ProName();\
	void Set##ProName(DataType resizeble);\
	__declspec(property(get=Get##ProName,put=Set##ProName)) DataType ProName;

//ֻ����GET����
#define DECLAREPBPROPERTY_GET(DataType,ProName) \
	DataType Get##ProName();\
	__declspec(property(get=Get##ProName)) DataType ProName;
//=============================================================================================================================

//Thinking in REDUIȺ���һ�����Ժ꣬��Ŀ��δ�õ�
#define PROPERTY(t,n) \
	__declspec( property(get=i_get_##n, put=i_set_##n)) t n; \
	t i_get_##n() { \
		__if_exists(get_##n) { return get_##n(); } \
		__if_not_exists(get_##n) { throw "member " #n " cannot be got."; } \
	} \
	void i_set_##n(const t& newval) { \
		__if_exists(set_##n) { set_##n(newval); } \
		__if_not_exists(set_##n) { throw "member " #n " cannot be set."; } \
	} \
	typedef t ptype_##n

#define GET(n) ptype_##n get_##n()
#define SET(n) void set_##n(const ptype_##n& value)

//class Test
//{
//public:
//	PROPERTY(int, n);
//	GET(n)
//	{
//		return 12;
//	}
//	SET(n)
//	{
//		value;
//	}
//};
//------------------------------------------------------------------------------------------------------------------
//END_PBPLUS_NASPACE