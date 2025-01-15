//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#pragma once
#include "crxChar.h"
#include "CrxUiCx.h"

class CRxToobar;
class CRxPopupMenu;
class CRxPopupMenuItem;
class CRxRibbonTabItem;
class CRxRibbonTab;
class CRxRibbonPanel;
class CRxRibbonButton;
class CRxRibbonBar;



class CRxToolbarItem
{
public:
	virtual CRxToobar* getParent() = 0;
};

class CRxToobar
{
public:
	virtual const CxCHAR* getName() = 0;
	virtual unsigned int getCount() = 0;
	virtual CRxToolbarItem* addCRxToolBarButton(unsigned int index,
												const CxCHAR* name,
												const CxCHAR* tooltip,
												const CxCHAR* macro,
												bool dropdown = false,
												HBITMAP hBmpSmall = NULL,
												HBITMAP hBmpLarge = NULL) = 0;
	virtual CRxToolbarItem* addSeparator(unsigned int index) = 0;
	virtual void RemoveCRxToolbarItem(unsigned int index) = 0;
	virtual void setVisible(bool visible = true) = 0;
};

class CRxToolBars
{
public:
	virtual CRxToobar* getCRxToolbar(const CxCHAR* id) = 0;
	virtual CRxToobar* addCRxToolBar(const CxCHAR* id,const CxCHAR* name) = 0;
	virtual void removeCRxToolBar(const CxCHAR* id) = 0;
	virtual void removeCRxToolBar(CRxToobar* toolBar) = 0;
};

class CRxPopupMenuItem
{
public:
	virtual CRxPopupMenu* getParent() = 0;
};

class CRxPopupMenu 
{
public:
	virtual CRxPopupMenuItem* addMenuItem(unsigned int index, const CxCHAR* Label, const CxCHAR* Macro) = 0;
	virtual CRxPopupMenuItem* addSeparator(unsigned int index) = 0;
	virtual CRxPopupMenu* addSubMenu(unsigned int index, const CxCHAR* Label) = 0;
};


class CRxMenuBar 
{
public:
	virtual unsigned int getCount() = 0;

	virtual CRxPopupMenu* getPopupMenu(const CxCHAR* name) = 0;
	virtual CRxPopupMenu* getPopupMenu(unsigned int index) = 0;

	virtual CRxPopupMenu* addPopupMenu(unsigned int index,const CxCHAR* name) = 0;
};

//RibbonBar的消息处理
class CRxRibbonBar
{
public:
	virtual CRxRibbonTab* AppendRibbonTab( const CxCHAR* i_sRibbonTabID, const CxCHAR* i_sContextName, BOOL i_bAppend ) = 0;
};

class CRxRibbonTabItem
{
public:
	virtual CRxRibbonTab* getParent() = 0;
};

class CRxRibbonTab
{
public:
	virtual CRxRibbonPanel* AppendRibbonPanel( const CxCHAR* i_sRibbonPanelID, const CxCHAR* i_sContextName, ULONG_PTR i_RibbonIndex) = 0;
	
};


class CRxRibbonPanel
{
public:

	virtual CRxRibbonButton* AppendRibbonButton(const CxCHAR* i_sRibbonButtonID, const CxCHAR* i_sContextName, HBITMAP i_hBtnBitSmall, HBITMAP i_hBtnBitLarge, ULONG_PTR i_RibbonIndex, const CxCHAR* Command, const CxCHAR* tooltip = 0) = 0;

};

class CRxRibbonButton
{
public:



};
//ADD BY FLN

class CRxUIManager
{
public:
	virtual CRxToolBars* getCRxToolBars() = 0;
	virtual CRxMenuBar*  getCRxMenuBar() = 0;
	virtual CRxRibbonBar*  getCRxRibbonBar() = 0;
};

CRXUI_API CRxUIManager* crxUIManagerPtr();
#define crxUIManager crxUIManagerPtr()
