#pragma once
#include "pbobject.h"
BEGIN_PBPLUS_NASPACE
class PBGraphicObject :
	public PBObject
{
public:
	PBGraphicObject(IPB_Session* s);
	~PBGraphicObject(void);
//����
public:
	DECLAREPBPROPERTY(bool,Visible)
	DECLAREPBPROPERTY(tstring,Tag)
//����
public:
	SHORT Hide();
	SHORT Show();
};
END_PBPLUS_NASPACE
