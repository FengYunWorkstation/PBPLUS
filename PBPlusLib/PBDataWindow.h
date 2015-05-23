/*
* PBDataWindow.h
*
*  Created on: 2015.05.23
*      Author: wxj
*		EMAIL: wxj_wz@qq.com
*/
#pragma once
#include "pbdragobject.h"
#include "PBSystem.h"
#include "PBTransAction.h"
#include "PBDWObject.h"
#include <tuple>
#include "PBDate.h"
#include "PBDateTime.h"
//#include <atlwin.h>
BEGIN_PBPLUS_NASPACE
class PBDataWindow :
	public PBDragObject
{
private:
	ATL::CWndProcThunk m_DWThunk;
public:
	HWND m_hWnd;
private:
	WNDPROC pOldProc;
public:
	PBDataWindow(IPB_Session* s);
	PBDataWindow(const PBDataWindow& dw);
	~PBDataWindow(void);

#pragma region ��Ӧ����
public:
	DECLAREPBPROPERTY(bool,Border)
	DECLAREPBPROPERTY(bool,ControlMenu)
	DECLAREPBPROPERTY(bool,Enabled)
	DECLAREPBPROPERTY(bool,HScrollBar)
	DECLAREPBPROPERTY(bool,HSplitScroll)
	DECLAREPBPROPERTY(bool,LiveScroll)
	DECLAREPBPROPERTY(bool,MaxBox)
	DECLAREPBPROPERTY(bool,MinBox)
	DECLAREPBPROPERTY(bool,Resizable)
	DECLAREPBPROPERTY(bool,RightToLeft)
	DECLAREPBPROPERTY(bool,TitleBar)
	DECLAREPBPROPERTY(bool,VScrollBar)
	DECLAREPBPROPERTY(PBBorderStyle,BorderStyle)
	//DWObject δʵ��
	DECLAREPBPROPERTY(PBRichTextToolbarActivation,RichTextToolbarActivation)
	DECLAREPBPROPERTY(tstring,DataObject)
	DECLAREPBPROPERTY(tstring,Icon)
	DECLAREPBPROPERTY(tstring,Title)
#pragma endregion ��Ӧ����
#pragma region ��Ӧ����
public:
	SHORT AcceptText(void);
	bool CanUndo(void);
	SHORT CategoryCount( tstring grCtl );
	tstring CategoryName( tstring grCtl,SHORT c );
	SHORT Clear(void); 
	long Clear(bool gridFlag); 
	SHORT ClearAll(void);
	SHORT ClearValues( SHORT c );
	SHORT ClearValues( tstring c );
	SHORT Clipboard ( tstring data );
	SHORT Collapse(long row, long groupLevel);
	SHORT CollapseAll(void);
	SHORT CollapseLevel(long groupLevel);
	SHORT Copy(void);
	tstring CopyRTF(bool selected=true);
	tstring CopyRTF(bool selected,PBBand band);
	SHORT Create(tstring syn);
	SHORT Create(tstring syn,tstring errorbuffer);//errorbuffer��δʵ��
	SHORT CrossTabDialog(void);
	SHORT Cut(void);
	long DataCount( tstring graphcontrol, tstring seriesname );
	SHORT DBCancel(void);
	long DBErrorCode(void); 
	tstring DBErrorMessage(void);
	long DeletedCount(void);
	SHORT DeleteRow( long row );
	tstring Describe(tstring propertylist);
	SHORT Expand(long row, long groupLevel);
	SHORT ExpandAll();
	SHORT ExpandAllChildren(long row, long groupLevel);
	SHORT ExpandLevel (long groupLevel);
	SHORT Filter(void);
	long FilteredCount(void);
	long Find (tstring expression, long start, long end, PBDWBuffer buffer=Primary);
	long Find (tstring searchtext, bool forward,bool insensitive,bool wholeword,bool cursor );
	//FindCategory
	long FindGroupChange(long row,SHORT level );
	SHORT FindNext(void);
	SHORT FindRequired(PBDWBuffer dwbuffer,long& row,SHORT& colnbr,tstring& colname,bool updateonly); 
	SHORT FindSeries(tstring graphcontrol,tstring seriesname);
	SHORT GenerateHTMLForm (tstring& syntax,tstring& style,tstring action);
	SHORT GenerateHTMLForm (tstring& syntax,tstring& style,tstring action ,long startrow,long endrow,SHORT startcolumn,SHORT endcolumn , PBDWBuffer buffer=Primary );
	SHORT GenerateResultSet(PBDWBuffer buffer=Primary );
	tstring GetBandAtPointer();
	PBBorderStyle GetBorderStyle(SHORT column);
	PBBorderStyle GetBorderStyle(tstring column);
	long GetChanges(byte* changeblob,size_t& bytes);//����֮�󣬵�bytes>0ʱ��Ҫdelete []changeblob��bytesΪ�ֽ���
	long GetChanges(tstring changeblob);
	//...
	//...
	long GetFullState (byte* &dwasblob,size_t& bytes);//����֮�󣬵�bytes>0ʱ��Ҫdelete []dwasblob��bytesΪ�ֽ���
	long GetFullState (tstring& dwasstring);
	//...
	//...
	long InsertRow( long row );
	bool IsExpanded(long row, long groupLevel);
	bool IsSelected( long row ); 
	SHORT LineCount(void); 
	long ModifiedCount(void);
	tstring Modify( tstring modstring);
	//...
	//...
	SHORT Print( bool canceldialog=true ,bool showprintdialog=false);
	SHORT PrintCancel(void);

#ifdef ReplaceText 
#undef ReplaceText
#endif
	long ReplaceText(tstring str);
#ifdef UNICODE
#define ReplaceText  ReplaceTextW
#else
#define ReplaceText  ReplaceTextA
#endif // !UNICODE
//#ifdef USING_CPPCLI_PROJ
//	long ReplaceText_CLI(tstring str);//{return 0;/*ReplaceText(str);*/}
//#endif
	SHORT ReselectRow(long row); 
	SHORT Reset(void);
	//...
	//...
	SHORT ResetUpdate(void);
	long Retrieve(void);
	template<typename P1>long Retrieve(P1 t)
	{
		return 0;
	}
	template<typename P1,typename P2>long Retrieve(P1 t,P2 p2)
	{
		return 0;
	}
	//...
	//...
	long RowCount(void);
	//...
	//...
	SHORT RowsDiscard (long startrow, long endrow, PBDWBuffer buffer );
	//...
	//...
	SHORT Scroll(SHORT number);
	long ScrollNextPage (void );
	long ScrollNextRow(void );
	long ScrollPriorPage ( void);
	long ScrollPriorRow (void );
	SHORT ScrollToRow ( long row );
	SHORT SelectedLength (void );
	SHORT SelectedLine (void );
	SHORT SelectedStart(void );
	tstring SelectedText (void );
	SHORT SelectRow ( long row, bool select );
	//...
	//...
	/*template<typename V>*/SHORT SetItemString(long row, SHORT column,/*V*/tstring value);
	//{
	//	return PBXInvokeFunc<SHORT>(session,this->cls,this->obj,_T("SetItem"),_T("ILXIA"),row,column,value);
	//}
	//SHORT SetItemDate(long row, SHORT column,/*V*/PBDate& value);
	//SHORT SetItemDateTime(long row, SHORT column,/*V*/PBDateTime& value);*/
	//...
	//...
	SHORT SetFullState(byte dwasblob[],size_t len);
	SHORT SetFullState(tstring dwasstring);
	//...
	//...
	SHORT SetTransObject(PBTransAction& atr);
	//...
	//...
	SHORT Sort(void);
	tstring TextLine(void);
	SHORT Undo(void);
	SHORT Update (bool accept =true, bool resetflag=true );

	
#pragma endregion ��Ӧ����

#pragma region ��Ӧ�¼�
public:
	//����ֵ��0-�����¼�������������1ִ�е����¼�Ϊֹ
	virtual long OnClicked(int xpos,int ypos,long row,PBDWObject& dwo);//��굥��
	//����ֵ��ֻ��0
	virtual long OnDoubleClicked(int xpos,int ypos,long row,PBDWObject& dwo);//���˫��
	//����ֵ��0-��ʾ������Ϣ�����Ҵ�����������DBError�¼������ж�����¼�ʱ��
	//		  1-����ʾ������Ϣ�����Ҵ�����������DBError�¼������ж�����¼�ʱ��
	//		  2-��ʾ������Ϣ��������������DBError�¼������ж�����¼�ʱ��
	//		  3-����ʾ������Ϣ��������������DBError�¼������ж�����¼�ʱ��
	virtual long OnDBError(long sqldbcode,tstring sqlerrtext,tstring sqlSyntax,PBDWBuffer buffer,long row);//DBError
	//����ֵ��ֻ��0
	virtual long OnEditChanged(long row,PBDWObject& dwo,tstring data);
	//����ֵ��ֻ��0,��������
	virtual long OnGetFocus();
	
	//����ֵ��0-�������ݣ�1�ܾ���������ݲ����������뿪��2-�ܾ���������ݵ��������뿪
	virtual long OnItemChanged(long row,PBDWObject& dwo,tstring data);
	//����ֵ��ֻ��0
	virtual long OnItemFocusChanged(long row,PBDWObject& dwo);
	//����ֵ��0-�ܾ���������ݲ���ʾ������Ϣ��1-�ܾ���������ݲ���ʾ������Ϣ��
	//		  2-�������ݣ�3-�ܾ����ݣ��������л�
	virtual long OnItemError(long row,PBDWObject& dwo,tstring data);
	//����ֵ��ֻ��0,��������
	virtual long OnLoseFocus();
	//����ֵ��ֻ��0,��������
	virtual long OnPrintEnd(long printPages);
	//����ֵ��ֻ��0,��������
	virtual long OnPrintMarginChange();
	//����ֵ��0-��Ҫ����ҳ�룬1-����ҳ��
	virtual long OnPrintPage(long printNumber,long copy);
	//����ֵ��ֻ��0,��������
	virtual long OnPrintStart(long pagesMax);
	//����ֵ��ֻ��0,��������
	virtual long OnResize (ULONG sizetype,USHORT newwidth,USHORT newheight);
	//����ֵ��ֻ��0,��������
	virtual long OnRetrieveEnd(long rowcount);
	//����ֵ��0-��������,1-��ִ�м�����2-�����ݿ����ʱ�����ԭ������
	virtual long OnRetrieveStart();
	//����ֵ��ֻ��0
	virtual long OnRowFocusChanged(long currentrow);
	//����ֵ��0-����������ǰ�б����ģ���1-��ֹ��ǰ���޸�
	virtual long OnRowFocusChanging(long currentrow,long newRow);
	//����ֵ��ֻ��0
	virtual long OnRButtonDown(int xpos,int ypos,long row,PBDWObject& dwo);//����ֻ�
	//����ֵ��ֻ��0
	virtual long OnScrollHorizontal (long scrollpos,SHORT pane);
	//����ֵ��ֻ��0
	virtual long OnScrollVertical (long scrollpos);
	//����ֵ��0��������1-ֹͣ����2-��������request�����¸�request
	virtual long OnSQLPreview(PBSQLPreviewFunction request,PBSQLPreviewType sqltype,tstring sqlsyntax,PBDWBuffer buffer,long row);
	//����ֵ��ֻ��0,��������
	virtual long OnUpdateEnd (long rowsinserted,long rowsupdated,long rowsdeleted);
	//����ֵ��0-��������1-��ִ��UPDATE����
	virtual long OnUpdateStart(void);
#pragma endregion ��Ӧ�¼�
private:
	void SetPBEventReturnValue(long val);
	bool SetWxjOwnerProc();
	static LRESULT CALLBACK CustDWMsgProc(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam);
	virtual WNDPROC GetWindowProc()
	{
		return CustDWMsgProc ;//WindowProc;
	}
};

END_PBPLUS_NASPACE