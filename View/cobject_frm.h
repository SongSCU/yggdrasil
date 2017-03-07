/**************************************************************************
File:         cobject_frm.h
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#ifndef COBJECT_FRM_H
#define COBJECT_FRM_H

#include <QFrame>
#include "ui_cobject_frm.h"
#include <QListWidget>
#include <QMimeData>
#include <QMouseEvent>
#include <QDragMoveEvent>
//////////////////////////////////////////////////////////////////
///    Class:  CListWidget
///    Brief:  
//////////////////////////////////////////////////////////////////
class CListWidget : public  QListWidget
{
	Q_OBJECT
public:
	CListWidget();
	~CListWidget() {};
private:
	//void dropEvent(QDropEvent *event);
	//void dragLeaveEvent(QDragLeaveEvent *e);
	void dragMoveEvent(QDragMoveEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *e);
	//QMimeData* mimeData();
	//void dragEnterEvent(QDragEnterEvent *event);
	void mPerformDrag();
	
private:
	QPoint m_startPos;
};
//////////////////////////////////////////////////////////////////
///    Class:  CObjectFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CObjectFrm : public QFrame
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CObjectFrm(QWidget *parent = 0);
	~CObjectFrm();
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mInitView();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CObjectFrm ui;
	CListWidget * m_objectWidget;
	CListWidget * m_uiWidget;
};

#endif // COBJECT_FRM_H
