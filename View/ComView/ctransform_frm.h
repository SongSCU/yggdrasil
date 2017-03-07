/**************************************************************************
File:         ctransform_frm.h
Author:       Song Xiaofeng
Date:         2016-05-16
Description:
**************************************************************************/
#pragma once
#include <QFrame>
#include "ui_ctransform_frm.h"
#include "Unit/cscene_items.h"
#include <QGraphicsItem>
//////////////////////////////////////////////////////////////////
///    Class:  CTransformFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CTransformFrm : public QFrame {
	Q_OBJECT
		///////////////////////////////////////////////////////////////////
		//all public functions are here
		///////////////////////////////////////////////////////////////////
public:
	CTransformFrm(QWidget * parent = Q_NULLPTR);
	~CTransformFrm();
	void updateCom(QGraphicsItem * item, int count);
	///////////////////////////////////////////////////////////////////
	//all private functions are here
	///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mSetValue(QString px, QString py, QString rx, QString ry,
		QString sw, QString sh, QString rot,QString dep);
	void mBuildConnects();
	void mSetItemPointer(QGraphicsItem* item);
	///////////////////////////////////////////////////////////////////
	//all private slots are here
	///////////////////////////////////////////////////////////////////
private slots:
	void on_edit_pX_changed();
	void on_edit_pY_changed();
	void on_edit_rX_changed();
	void on_edit_rY_changed();
	void on_edit_sW_changed();
	void on_edit_sH_changed();
	void on_edit_rot_changed();
	void on_edit_dep_changed();
	///////////////////////////////////////////////////////////////////
	//all properties are here
	///////////////////////////////////////////////////////////////////
private:
	Ui::CTransformFrm ui;
	QLineEdit * m_edit_pX;
	QLineEdit * m_edit_pY;
	QLineEdit * m_edit_rX;
	QLineEdit * m_edit_rY;
	QLineEdit * m_edit_sW;
	QLineEdit * m_edit_sH;
	QLineEdit * m_edit_rot;
	QLineEdit * m_edit_dep;
	QGraphicsPixmapItem * m_item;
	bool m_isActive;

};
