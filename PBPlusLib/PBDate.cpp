#include "StdAfx.h"
#include "PBDate.h"

//�������
const double PBDate::x_1900_1_6_2_5 = 693966.08680556;
const int PBDate::termInfo[] = {  
		0      ,21208 ,42467 ,63836 ,85337 ,107014,  
		128867,150921,173149,195551,218072,240693,  
		263343,285989,308563,331033,353350,375494,  
		397447,419210,440795,462224,483532,504758  
	}; 
const TCHAR* PBDate::solar_term_name[] = {  
		_T("С��"),_T("��"),_T("����"),_T("��ˮ"),  
		_T("����"),_T("����"),_T("����"),_T("����"),  
		_T("����"),_T("С��"),_T("â��"),_T("����"),  
		_T("С��"),_T("����"),_T("����"),_T("����"),  
		_T("��¶"),_T("���"),_T("��¶"),_T("˪��"),  
		_T("����"),_T("Сѩ"),_T("��ѩ"),_T("����")  
	}; 

DWORD PBDate::lunarInfo[]={
 0x04bd8,0x04ae0,0x0a570,0x054d5,0x0d260,0x0d950,0x16554,0x056a0,0x09ad0,0x055d2,
 0x04ae0,0x0a5b6,0x0a4d0,0x0d250,0x1d255,0x0b540,0x0d6a0,0x0ada2,0x095b0,0x14977,
 0x04970,0x0a4b0,0x0b4b5,0x06a50,0x06d40,0x1ab54,0x02b60,0x09570,0x052f2,0x04970,
 0x06566,0x0d4a0,0x0ea50,0x06e95,0x05ad0,0x02b60,0x186e3,0x092e0,0x1c8d7,0x0c950,
 0x0d4a0,0x1d8a6,0x0b550,0x056a0,0x1a5b4,0x025d0,0x092d0,0x0d2b2,0x0a950,0x0b557,
 0x06ca0,0x0b550,0x15355,0x04da0,0x0a5d0,0x14573,0x052d0,0x0a9a8,0x0e950,0x06aa0,
 0x0aea6,0x0ab50,0x04b60,0x0aae4,0x0a570,0x05260,0x0f263,0x0d950,0x05b57,0x056a0,
 0x096d0,0x04dd5,0x04ad0,0x0a4d0,0x0d4d4,0x0d250,0x0d558,0x0b540,0x0b5a0,0x195a6,
 0x095b0,0x049b0,0x0a974,0x0a4b0,0x0b27a,0x06a50,0x06d40,0x0af46,0x0ab60,0x09570,
 0x04af5,0x04970,0x064b0,0x074a3,0x0ea50,0x06b58,0x055c0,0x0ab60,0x096d5,0x092e0,
 0x0c960,0x0d954,0x0d4a0,0x0da50,0x07552,0x056a0,0x0abb7,0x025d0,0x092d0,0x0cab5,
 0x0a950,0x0b4a0,0x0baa4,0x0ad50,0x055d9,0x04ba0,0x0a5b0,0x15176,0x052b0,0x0a930,
 0x07954,0x06aa0,0x0ad50,0x05b52,0x04b60,0x0a6e6,0x0a4e0,0x0d260,0x0ea65,0x0d530,
 0x05aa0,0x076a3,0x096d0,0x04bd7,0x04ad0,0x0a4d0,0x1d0b6,0x0d250,0x0d520,0x0dd45,
 0x0b5a0,0x056d0,0x055b2,0x049b0,0x0a577,0x0a4b0,0x0aa50,0x1b255,0x06d20,0x0ada0
};
UINT PBDate::solarmonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

PBDate::PBDate(void)
	:year(1900),month(1),day(1)
{
}
PBDate::PBDate(int y,int m,int d)
	:year(y),month(m),day(d)//�����ڸ�ֵ���ж���Ч�����ڡ�
{
	if((y<=0)||(m<=0 || m>12)||(d<=0 || d>DayOfMonth(y,m)))
	{
		year = 1900;
		month = 1;
		day = 1;
	}
}
int PBDate::GetYear() const
{
	return year;
}
int PBDate::GetMonth()const
{
	return month;
}
int PBDate::GetDay() const
{
	return day;
}
int PBDate::DayOfWeek()
{
	/*
	�㷨���£� 
	��ķ����ɭ���㹫ʽ
	W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
	�ڹ�ʽ��d��ʾ�����е�������m��ʾ�·�����y��ʾ������
	ע�⣺�ڹ�ʽ���и���������ʽ��ͬ�ĵط���
	��һ�ºͶ��¿�������һ���ʮ���º�ʮ���£����������2004-1-10����ɣ�2003-13-10�����빫ʽ���㡣
	*/
	int y =year;
	int m = month;
	int d = day;
	if(m==1||m==2) {
	m+=12;
	y--;
	}
	return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7; 

	/*
	char *cWeekName[]  = {"������","����һ","���ڶ�","������","������","������","������"};

 if(date.month==1||date.month==2)
 {
  date.month+=12;
  date.year--;
 }
 return cWeekName[(date.day+1+2*date.month+3*(date.month+1)/5+date.year+date.year/4-date.year/100+date.year/400)%7];
	*/
}
int PBDate::DayOfMonth(int y,int m)const
{
	int d = 0; 
	switch(m) 
	{ 
	case 1: 
	case 3: 
	case 5: 
	case 7: 
	case 8: 
	case 10: 
	case 12: 
		d = 31; 
	break; 
	case 4: 
	case 6: 
	case 9: 
	case 11: 
		d = 30; 
	break; 
	case 2: 
		d = 28 + (IsLeapyear(y)== true ? 1:0); 
	break; 
	} 
	return d; 
}
bool PBDate::IsLeapyear() const
{
	return year%400?(year%100?(year%4?(false):(true)):(false)):true;
}
bool PBDate::IsLeapyear(int y) const
{
	return y%400?(y%100?(y%4?(false):(true)):(false)):true;
}
//std::string PBDate::ToString(const std::string formaterStr)
//{
//}
LONG PBDate::CLCDaysFrom1900(int y,int m,int d)
{

	LONG days;
	days=365*y+(y-1)/4-(y-1)/100+(y-1)/400-
			(365*1900+(1900-1)/4-(1900-1)/100+(1900-1)/400);

	for(int i=0;i<m-1;i++)
	{
		days+=solarmonth[i];
	}

	days+=d;

	if((y%4==0&&y%100!=0)||y%400==0)
	{
		if(m>2)
		{
			days++;
		}
	}
return days;
}
UINT PBDate::CLCYearDays(UINT y)
{
   UINT i, sum = 348;
   for(i=0x8000; i>0x8; i>>=1)
   {
		sum += (lunarInfo[y-1900] & i)? 1: 0;
   }
   return(sum+CLCLeapDays(y));
}
UINT PBDate::CLCLeapDays(UINT y)
{
   if(CLCLeapMonth(y))
   {
    return (lunarInfo[y-1900] & 0x10000)? 30: 29;
   }
   else
   {
    return 0;
   }
}
UINT PBDate::CLCLeapMonth(UINT y)
{
	if(y<1900)return 0;
	return lunarInfo[y-1900] & 0xf;
}
UINT PBDate::CLCMonthDays(UINT y,UINT m)
{
	if(y<1900)return 0;
	return (lunarInfo[y-1900] & (0x10000>>m))? 30: 29;
}
bool PBDate::CLCLunar(const int y,const int m,const int d,PBDate& retdate)
{
	LONG offset;
	int i, leap=0, temp=0;

	offset=CLCDaysFrom1900(y,m,d)-30;
	for(i=1900; i<2050 && offset>0; i++)
	{
		temp = CLCYearDays(i);
		offset -= temp;
	}

	if(offset<0)
	{
		offset += temp;
		i--;
	}
	retdate.year = i;
	
	leap = CLCLeapMonth(i);
	bool isLeap = false;
	for(i=1; i<13 && offset>0; i++)
	{
		if(leap>0 && i==(leap+1) && isLeap==false)
		{
			--i;
			isLeap = true;
			temp = CLCLeapDays(retdate.year);
		}
		else
		{
			temp = CLCMonthDays(retdate.year, i);
		}
		if(isLeap==true && i==(leap+1))
		{
			isLeap = false;
		}
		offset -= temp;
	}
	if(offset==0 && leap>0 && i==leap+1)
	{
		if(isLeap)
		{
			isLeap = false;
		}
		else
		{
			isLeap = true;
			--i;
		}
	}
	if(offset<=0)
	{
		offset += temp;
		--i;
	}
	retdate.month = i;
	retdate.day = offset ;
	retdate.isRunYue=isLeap;
	return isLeap;
}
void PBDate::CLCGetLunarString (const int y,const int m,const int d,bool runYue,TCHAR nongLiStr[])
{
	TCHAR szNongli[30], szNongliDay[10],szShuXiang[10];
	const TCHAR *cTianGan[]  = {_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),
								_T("��"),_T("��"),_T("��"),_T("��"),_T("��")}; /*�������*/
	const TCHAR *cDiZhi[]    = {_T("��"),_T("��"),_T("��"),_T("î"),_T("��"),_T("��"),
								_T("��"),_T("δ"),_T("��"),_T("��"),_T("��"),_T("��")}; /*��֧����*/
	const TCHAR *cShuXiang[] = {_T("��"),_T("ţ"),_T("��"),_T("��"),_T("��"),_T("��"),
								_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��")}; /*��������*/
	const TCHAR *cDayName[]  = { _T("*"),_T("��һ"),_T("����"),_T("����"),_T("����"),_T("����"), /*ũ��������*/
        _T("����"),_T("����"),_T("����"),_T("����"),_T("��ʮ"),
        _T("ʮһ"),_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),
        _T("ʮ��"),_T("ʮ��"),_T("ʮ��"),_T("ʮ��"),_T("��ʮ"),
        _T("إһ"),_T("إ��"),_T("إ��"),_T("إ��"),_T("إ��"),
        _T("إ��"),_T("إ��"),_T("إ��"),_T("إ��"),_T("��ʮ")};
	const TCHAR *cMonName[]  = {_T("*"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),_T("��"),
								_T("��"),_T("��"),_T("��"),_T("ʮ"),_T("ʮһ"),_T("��")};

 /*--����ũ����ɡ���֧������ ==> wNongli--*/

	int nShuXiang = ((y - 4) % 60) % 12;
	if ( nShuXiang < 0 || nShuXiang >= sizeof(cShuXiang)/sizeof(cShuXiang[0]) )
	{
		return  ;
	}
	wsprintf(szShuXiang,_T("%s"),cShuXiang[nShuXiang]);

	int nTianGan = ((y - 4) % 60) % 10;
	if ( nTianGan < 0 || nTianGan >= sizeof(cTianGan)/sizeof(cTianGan[0]) )
	{
		return ;
	}
	int nDiZhi = ((y - 4) % 60) % 12;
	if ( nDiZhi < 0 || nDiZhi >= sizeof(cDiZhi)/sizeof(cDiZhi[0]) )
	{
		return ;
	}
	wsprintf(szNongli,_T("%s(%s%s)��"),szShuXiang,cTianGan[nTianGan],cDiZhi[nDiZhi]);

	/*--����ũ���¡��� ==> wNongliDay--*/
	if ( m < 0 || m >= sizeof(cMonName)/sizeof(cMonName[0]) )
	{
		return ;
	}
	if (runYue)
	{
		wsprintf(szNongliDay,_T("��%s"),cMonName[m]);
	}
	else
	{
		_tcscpy_s (szNongliDay,cMonName[m]);
	}
	_tcscat_s(szNongliDay,_T("��"));
	if ( d < 0 || d >= sizeof(cDayName)/sizeof(cDayName[0]) )
	{
		return ;
	}
	_tcscat_s(szNongliDay,cDayName[d]);
	_tcscat_s(szNongli,szNongliDay);
	//wsprintf(m_slunar,szNongli);
	_tcscpy(nongLiStr,szNongli);
	//return m_slunar;
}

UINT PBDate::CLCSolarDays(UINT y,UINT m)

{

 if(m==1)//2��
 {
  return(((y%4 == 0) && (y%100 != 0) || (y%400 == 0))? 29: 28);
 }
 else
 {
  return(solarmonth[m]);
 }
}

double PBDate::get_solar_term( int y , int n )
{ 
	n = n- 1;//���������Ǵ�0��ʼ��1�����������1-1=0
	return x_1900_1_6_2_5+365.2422*(y-1900)+termInfo[n]/(60.*24);  
}
void PBDate::parse_jq_date( unsigned _days , int& y,int& m,int& d )
{
	static const int mdays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int diff;
    unsigned days;    
    days = 100 * (_days - _days/(3652425L/(3652425L-3652400L)) );
    y    = days / 36524; days %= 36524;
    m    = 1 + days/3044;        /* [1..12] */
    d    = 1 + (days%3044)/100;    /* [1..31] */
    diff =y*365+y/4-y/100+y/400+mdays[m-1]+d-((m<=2&&((y&3)==0)&&((y%100)!=0||y%400==0))) - _days;
    if( diff > 0 && diff >= d )    /* ~0.5% */
    {
        if( m == 1 )
        {
            --y; m = 12;
            d = 31 - ( diff - d );
        }
        else 
        {            
            d = mdays[m-1] - ( diff - d );
            if( --m == 2 )
                d += ((y&3)==0) && ((y%100)!=0||y%400==0);
        }
    }
    else
    {
        if( (d -= diff) > mdays[m] )    /* ~1.6% */
        {
            if( m == 2 )
            {
                if(((y&3)==0) && ((y%100)!=0||y%400==0))
                {
                    if( d != 29 )
                        m = 3 , d -= 29;
                }
                else
                {
                    m = 3 , d -= 28;
                }
            }
            else
            {
                d -= mdays[m];
                if( m++ == 12 )
                    ++y , m = 1;
            }
        }
    }    
}
void PBDate::JQ_Parse_Date(int _y , int n,int& y,int& m,int& d)
{
	unsigned int _days = (unsigned)get_solar_term( _y , n );
	parse_jq_date(_days, y, m, d );  
}
PBDate::~PBDate(void)
{
}
