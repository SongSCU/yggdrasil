/**************************************************************************
File:         cproject_controller.h
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#pragma once
#include <QObject>
#include "manager/cproject_manager.h"
#include "Manager/cscene_manager.h"
#include "Manager/ccomponent_manager.h"
#include "Manager/casset_manager.h"
#include <QGraphicsScene>
//////////////////////////////////////////////////////////////////
///    Class:  CProjectController
///    Brief:  
//////////////////////////////////////////////////////////////////
class CProjectController : public QObject {
	Q_OBJECT

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	static CProjectController* getInstance();
///////////////////////////////////////////////////////////////////
//all signals  are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_new_project(const QString& p_name, const QString& p_path);
	void signal_project_born(const QString& p_name, const QString& p_path);
	void signal_project_err(ProjectError errType);
	void signal_project_close();
	void signal_save_project(const QString &path);
	void signal_save_scene(const QString &path);
	void signal_open_project(const QString & path);
	void signal_new_file(const QString &name, const QString &type);
	void signal_load_scene(const QString &path);
	void signal_show_scene(QGraphicsScene* scene);
	void signal_add_item(const QString &type, const QPointF &pos);
	void signal_delete_item();
	void signal_copy_item();
	void signal_paste_item();
	void signal_show_com(QGraphicsItem* item, int num);
	void signal_insert_db(const QString table_name, const QString data_path);
	void signal_delete_db(const QString table_name, const QString data_path);
	void signal_new_file_accept(const QString &name, const QString &type);
	void signal_load_hierarchy(QGraphicsScene* scene);
	void signal_update_hierarchy(QGraphicsItem* item, int type);
	void signal_item_added(const QGraphicsItem* item);
	void signal_items_added(const QList<QGraphicsItem*> &list);
	void signal_items_deleted(const QList<int> &list);
	void signal_item_selected(int id);
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
public slots:
	void slot_new_project(const QString& p_name, const QString& p_path);
	void slot_close_project();
	void slot_save_project(const QString &path);
	void slot_project_born(const QString& p_name, const QString& p_path);
	void slot_project_err(ProjectError errType);
	void slot_open_project(const QString & path);
	void slot_new_file(const QString &name, const QString &type);
	void slot_load_scene(const QString &path);
	void slot_show_scene(QGraphicsScene* scene);
	void slot_add_item(const QString &type, const QPointF &pos);
	void slot_delete_item();
	void slot_copy_item();
	void slot_paste_item();
	void slot_show_com(QGraphicsItem* item, int num);
	void slot_insert_db(const QString table_name, const QString data_path);
	void slot_delete_db(const QString table_name, const QString data_path);
	void slot_new_file_accept(const QString &name, const QString &type);
	void slot_load_hierarchy(QGraphicsScene* scene);
	void slot_update_hierarchy(QGraphicsItem* item, int type);
	void slot_item_added(const QGraphicsItem* item);
	void slot_items_added(const QList<QGraphicsItem*> &list);
	void slot_items_deleted(const QList<int> &list);
	void slot_item_selected(int id);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	CProjectController();
	~CProjectController();
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	CProjectManager* m_projectManager;
	CSceneManager *  m_sceneManager;
	CComponentManager * m_comManager;
	CAssetManager* m_assetManager;
};
