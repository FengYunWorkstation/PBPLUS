/*
* PBDate.h
*
*  Created on: 2015.05.23
*      Author: wxj
*		EMAIL: wxj_wz@qq.com
*/
#pragma once
//������http://c.chinaitlab.com/cc/example/200903/779989.html
//Chinese lunisolar calendar ��дCLC
//��Ϣ��Դ���л�ũ������http://www.nongli.com/doc/0701/0614330.htm

//c++ date http://www.douban.com/note/174074422/
class PBDate
{
public:
	PBDate(void); //���캯������ʼ��Ĭ�ϵ�����
	PBDate(int y,int m,int d);
	~PBDate(void);
public:
	int GetYear() const;//��ȡ��ʵ������ʾ���ڵ���ݲ��֡�
	int GetMonth()const;//��ȡ��ʵ������ʾ���ڵ���ݲ��֡�
	int GetDay() const;// ��ȡ��ʵ������ʾ������Ϊ�����еĵڼ��졣
	int DayOfWeek(); //��ȡ��ʵ������ʾ�����������ڼ���0��ʾ�����죬��������
	bool IsLeapyear() const; //�ж��Ƿ�Ϊ���ꡣ
	bool IsLeapyear(int y) const; //�ж��Ƿ�Ϊ���ꡣ
	//std::string ToString(const std::string formaterStr);//ת��Ϊ�ַ���

	//����Ϊũ����Ϣ
	static LONG CLCDaysFrom1900(int year,int month,int day);//date��1900����������
	static UINT CLCYearDays(UINT y);//ũ��y���������
	static UINT CLCLeapDays(UINT y);//����ũ�� y�����µ�����
	static UINT CLCLeapMonth(UINT y);// ����ũ�� y�����ĸ��� 1-12 , û�򴫻� 0
	static UINT CLCMonthDays(UINT y,UINT m);//����ũ�� y��m�µ�������
	static bool CLCLunar(const int y,const int m,const int d,PBDate& date);//�����������ڣ�������������
	//char* dayOfWeek(const int y,const int m,const int d);//�����������ڣ��������ڼ�
	static void CLCGetLunarString (const int y,const int m,const int d,bool runYue,TCHAR nongLiStr[]);// ������������,�õ���ʾũ�����ִ�
	static UINT CLCSolarDays(UINT y,UINT m);//���ع��� y��ĳm+1�µ�����
private:
	int year,month,day;//
	bool isRunYue;
private:
	int DayOfMonth(int y,int m)const;//����һ���µ�������
	int ToInt()const;//
	static DWORD   lunarInfo[];//��������Ϣ
	static UINT    solarmonth[];


	//����,http://blog.csdn.net/fengrx/article/details/4331043
	static const double x_1900_1_6_2_5;
	static const int termInfo[];
	static const TCHAR* solar_term_name[];
	static double get_solar_term( int y , int n );//����y���n������
	static void parse_jq_date( unsigned _days , int& y,int& m,int& d );
public:
	static void JQ_Parse_Date(int _y , int n,int& y,int& m,int& d);//����y���n���������ص�ʱ��
};

