#pragma once
template<typename DstClassType>
class XEventT
{
	DstClassType *pThis;
	typedef void (DstClassType:: *Class_MemberFuncType)();
	Class_MemberFuncType Class_MemberFunc;
  public:
	  XEventT(DstClassType *This,Class_MemberFuncType ClassMemberFunction)
	  {
		  this->pThis=This;
		  this->Class_MemberFunc=ClassMemberFunction;
	  }
	  void Fire()
	  { 
		  //��֤����ָ����Ч��
		  (pThis->*Class_MemberFunc)();
	  }
};
