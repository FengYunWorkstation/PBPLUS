#pragma once
#include "pbext.h"
#include <string>
#include <sstream>

#ifdef _UNICODE
//�������������C4251����
template class  std::allocator<wchar_t>;
template class  std::basic_string<wchar_t>;  
//---------------
#define tstring std::wstring
#define tstringstream std::wstringstream

#else
//�������������C4251����
template class  std::allocator<char>;
template class  std::basic_string<char>;  
//------------------------
#define tstring std::string
#define tstringstream std::stringstream
#endif


//�ж��ַ��Ƿ���ͬ�������ִ�Сд��
bool  caseInsCompare(const std::string& s1,const std::string& s2);
//PBCallInfo* PBXCreateCallInfo(IPB_Session* s,pbclass cls,LPCTSTR methodName,LPCTSTR signature);

//��ָ�����ַ����滻���µ��ַ������������滻����ַ���
tstring ReplaceString(tstring&  str,const tstring&   old_value,const tstring& new_value);
