/**************************************************************************
File:         cscene_frm.h
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#ifndef CSCENE_FRM_H
#define CSCENE_FRM_H

#include <QFrame>
#include "ui_cscene_frm.h"
#include <QtWidgets/qgraphicsview.h>
#include <QtWidgets/qgraphicsscene.h>
#include "Controller/cproject_controller.h"
#include "Unit/cscene.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QToolBar>
//////////////////////////////////////////////////////////////////
///    Class:  CSceneView
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSceneView : public QGraphicsView {
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CSceneView(QWidget* parent = 0);
///////////////////////////////////////////////////////////////////
//all signals are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_add_item(const QString &type, const QPointF &pos);
	void signal_delete_item();
	void signal_copy_item();
	void signal_paste_item();
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void wheelEvent(QWheelEvent* event);
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mBuildConnects();
///////////////////////////////////////////////////////////////////
//all properties are here
///////////////////////////////////////////////////////////////////
private:	
	bool m_isKeyCtrlPressed;
};

//////////////////////////////////////////////////////////////////
///    Class:  CSceneFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSceneFrm : public QFrame
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CSceneFrm(QWidget *parent = 0);
	~CSceneFrm();
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mInitScene();
	void mBuildAllConnects();
	void mInitUI();
	void mInitToolBar();
///////////////////////////////////////////////////////////////////
//all private slots  are here
///////////////////////////////////////////////////////////////////
private slots:
    void slot_show_scene(QGraphicsScene* scene);
	void on_action_select_triggered();
	void on_action_move_triggered();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CSceneFrm ui;
	CSceneView * m_view;
	CScene * m_scene;
	CProjectController* m_controller;
	QVBoxLayout * m_layout;
	QToolBar * m_toolBar;
};

#endif // CSCENE_FRM_H
