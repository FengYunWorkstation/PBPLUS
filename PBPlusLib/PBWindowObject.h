#pragma once
#include "pbgraphicobject.h"
BEGIN_PBPLUS_NASPACE
class PBWindowObject :
	public PBGraphicObject
{
public:
	PBWindowObject(IPB_Session* s);
	~PBWindowObject(void);
//����(��)
//����
public:
	SHORT Move(SHORT x,SHORT y);
	SHORT Resize(SHORT w,SHORT h);
};
END_PBPLUS_NASPACE
