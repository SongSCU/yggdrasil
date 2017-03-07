/**************************************************************************
File:         chierarchy_frm.h
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#ifndef CHIERARCHY_FRM_H
#define CHIERARCHY_FRM_H

#include <QFrame>
#include "ui_chierarchy_frm.h"
#include "Controller/cproject_controller.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QMap>
//////////////////////////////////////////////////////////////////
///    Class:  CHierarchyFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CHierarchyFrm : public QFrame
{
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CHierarchyFrm(QWidget *parent = 0);
	~CHierarchyFrm();
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
public slots:

///////////////////////////////////////////////////////////////////
//all public signals are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_item_selected(int id);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mLoadTree();
	void mBuildConnect();
	QIcon mGetIcon(QString type);
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
private slots:
	void slot_load_hierarchy(QGraphicsScene* scene);
	void slot_update_hierarchy(QGraphicsItem* item, int type);
	void slot_update_selected_item(const QList<int> &list);
	void slot_item_added(const QGraphicsItem* item);
	void slot_items_added(const QList<QGraphicsItem*> &list);
	void slot_items_deleted(const QList<int> &list);
	void slot_item_nameChanged(const int id, const QString name);
	void slot_item_selected_changed();
	void mRemoveItem(int id);
	void mClearTree();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CHierarchyFrm ui;
	QTreeWidget * m_tree;
	QTreeWidgetItem * m_rootItem;
	QGraphicsScene * m_scene;
	QList<QGraphicsItem*> m_sceneItems;
	QList<QTreeWidgetItem*> m_treeItems;
	CProjectController * m_controller;
	QMap<int,QTreeWidgetItem*> m_idMapItem;
};

#endif // CHIERARCHY_FRM_H
