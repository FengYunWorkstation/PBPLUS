/*
* PBDateTime.h
*
*  Created on: 2015.05.23
*      Author: wxj
*		EMAIL: wxj_wz@qq.com
*/
#pragma once
#include <time.h>

class PBDateTime
{
public:    
	PBDateTime(time_t seconds);
	PBDateTime(int year,int month,int day);
	PBDateTime(int year,int month,int day,int hour,int minute,int second);
	PBDateTime(std::string datetimeStr);//�����ַ�����ʽ ��/��/�� ʱ:��:�� ��:2008/02/03 9:30:20 ������ 01/01/1970 00:00:00
	PBDateTime(std::string datetimeStr,std::string formaterStr);
private:
	time_t seconds;//��1970�������
	tm date;
public:
	void AddYears(const int years); //��ָ����������ӵ���ʵ����ֵ�ϡ�  
	void AddMonths(const time_t Months);//��ָ�����·����ӵ���ʵ����ֵ�ϡ�  
	void AddDays(const time_t days); //��ָ���������ӵ���ʵ����ֵ�ϡ� 
	void AddHours(const time_t hours);//��ָ����Сʱ���ӵ���ʵ����ֵ�ϡ� 
	void AddMinutes(const time_t minutes);//��ָ���ķ������ӵ���ʵ����ֵ�ϡ�  
	void AddSeconds(const time_t seconds); //��ָ���������ӵ���ʵ����ֵ�ϡ�
	void AddWeeks(const time_t weeks);//��ָ���������ӵ�Щʵ�ϵ�ֵ�ϡ�
	static int Compare(const PBDateTime *value1,const PBDateTime *value2);//������ DateTime ��ʵ�����бȽϣ�������һ��ָʾ��һ��ʵ�������ڡ����ڻ������ڵڶ���ʵ����������  ����ֵ��С���� value1 С�� value2�� �� value1 ���� value2�� ������ value1 ���� value2�� 
	//int CompareTo(const Object *value);//�����ء� ����ʵ����ֵ��ָ���� DateTime ֵ��Ƚϣ���ָʾ��ʵ�������ڡ����ڻ�������ָ���� DateTime ֵ��  
	int CompareTo(const PBDateTime *value);//С���� ��ʵ��С�� value�� �� ��ʵ������ value�� ������ ��ʵ������ value�� 

	int DaysInMonth(const int year,const int months);//����ָ��������е�������    
	//bool Equals(const Object *object);
	bool Equals(const PBDateTime *dateTime);
	static bool Equals(const PBDateTime *value1,const PBDateTime *value2);
	static PBDateTime Parse(std::string datetimeStr);//�����ַ�����ʽ ��/��/�� ʱ:��:�� ��:02/03/2008 9:30:20 ������ 01/01/1970 00:00:00
	static PBDateTime Parse(std::string dateTimeStr,std::string formaterStr);
	std::string ToShortDateString();//����ǰ DateTime �����ֵת��Ϊ���Ч�Ķ������ַ�����ʾ��ʽ��  
	std::string ToString();
	std::string ToString(const std::string formaterStr);//formaterStr = "%Y-%m-%d %H:%M:%S" %Y=�� %m=�� %d=�� %H=ʱ %M=�� %S=��
public:        
	int GetYear();//��ȡ��ʵ������ʾ���ڵ���ݲ��֡�
	int GetMonth();//��ȡ��ʵ������ʾ���ڵ���ݲ��֡�
	int GetDay();// ��ȡ��ʵ������ʾ������Ϊ�����еĵڼ��졣
	int GetHour();//��ȡ��ʵ������ʾ���ڵ�Сʱ���֡� 
	int GetMinute();//��ȡ��ʵ������ʾ���ڵķ��Ӳ���
	int GetSecond();//��ȡ��ʵ������ʾ���ڵ��벿�֡� 
	int DayOfWeek(); //��ȡ��ʵ������ʾ�����������ڼ���
	int DayOfYear();//��¼������һ������ĵڼ���,��1��1����,0-365
	static PBDateTime GetNow(); //���ص�ǰ�����Ǽ�
public:
	bool operator == (PBDateTime &dateTime);
	bool operator > (PBDateTime &dateTime);
	bool operator < (PBDateTime &DateTime);
	bool operator >= (PBDateTime &DateTime);
	bool operator <= (PBDateTime &DateTime);
	bool operator != (PBDateTime &DateTime);
private:
	void InitByStr(std::string dateTimeStr,std::string formaterStr);
public:
	~PBDateTime(void);
};

