/**************************************************************************
File:         cattribute_frm.h
Author:       Song Xiaofeng
Date:         2016-05-16
Description:
**************************************************************************/
#pragma once
#include <QFrame>
#include "ui_cattribute_frm.h"
#include <QGraphicsItem>
#include "Controller/ccom_controller.h"
//////////////////////////////////////////////////////////////////
///    Class:  CAttributeFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CAttributeFrm : public QFrame {
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CAttributeFrm(QWidget * parent = Q_NULLPTR);
	~CAttributeFrm();
	void updateCom(QGraphicsItem * item,int count);

signals:
	void signal_item_nameChanged(const int id, const QString name);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mBuildConnects();
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
private slots:
	void on_lineEdit_name_editingFinished();
///////////////////////////////////////////////////////////////////
//all properties functions are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CAttributeFrm ui;
	QLabel * m_labelIcon;
	QLabel * m_labelType;
	QLineEdit * m_lineEditName;
	QGraphicsItem * m_item;
	CComController * m_controller;
};
