/**************************************************************************
File:         cproperty_frm.h
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#ifndef CPROPERTY_FRM_H
#define CPROPERTY_FRM_H

#include <QFrame>
#include <QScrollArea>
#include "ui_cproperty_frm.h"
#include "Controller/cproject_controller.h"
#include <QVBoxLayout>
#include "ComView/cattribute_frm.h"
#include "ComView/ctransform_frm.h"
#include "ComView/csprite_render_frm.h"
#include "Unit/utilities.h"
#include "Unit/basic_data_structure.h"
//////////////////////////////////////////////////////////////////
///    Class:  CPropertyFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CPropertyFrm : public QScrollArea
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CPropertyFrm(QWidget *parent = 0);
	~CPropertyFrm();
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mInitUI();
	void mHideAll();
	void mShowAll();
	void mCheckCom(QGraphicsItem* item);
///////////////////////////////////////////////////////////////////
//all private slots  are here
///////////////////////////////////////////////////////////////////
private:
	void slot_show_com(QGraphicsItem* item, int num);
	///////////////////////////////////////////////////////////////////
	//all properties  are here
	///////////////////////////////////////////////////////////////////
private:
	Ui::CPropertyFrm ui;
	CProjectController * m_controller;
	QVBoxLayout * m_layout;
	CAttributeFrm * m_attributeFrm;
	CTransformFrm * m_transformFrm;
	CSpriteRenderFrm* m_spriteFrm;
	CScrollButton * m_attributeSB;
	CScrollButton * m_transformSB;
	CScrollButton * m_spriteSB;
	QFrame * m_frame;

};

#endif // CPROPERTY_FRM_H
