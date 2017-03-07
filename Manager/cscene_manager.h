/**************************************************************************
File:         cscene_manager.h
Author:       Song Xiaofeng
Date:         2016-05-14
Description:
**************************************************************************/
#pragma once
#include <QObject>
#include <QGraphicsScene>
#include "Unit/cscene_items.h"
#include "Unit/cscene.h"
#include "Manager/clog_manager.h"
//////////////////////////////////////////////////////////////////
///    Class:  CSceneManager
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSceneManager : public QObject {
	Q_OBJECT
		///////////////////////////////////////////////////////////////////
		//all public functions are here
		///////////////////////////////////////////////////////////////////
public:
	static CSceneManager * getInstance();
	CScene* loadScene(const QString& path);
	void closeScene();
	bool saveScene(const QString& path);
	///////////////////////////////////////////////////////////////////
	//all signals are here
	///////////////////////////////////////////////////////////////////
signals:
	void signal_show_scene(QGraphicsScene* scene);
	void signal_load_hierarchy(QGraphicsScene* scene);
	void signal_update_hierarchy(QGraphicsItem* item, int type);
	void signal_item_added(const QGraphicsItem* item);
	void signal_items_added(const QList<QGraphicsItem*> &list);
	void signal_items_deleted(const QList<int> &list);
	///////////////////////////////////////////////////////////////////
	//all public slots are here
	///////////////////////////////////////////////////////////////////
	public slots:
	void slot_load_scene(const QString &path);
	void slot_add_item(const QString &type, const QPointF &pos);
	void slot_delete_item();
	void slot_copy_item();
	void slot_paste_item();
	void slot_save_scene(const QString &path);
	void slot_item_selected(int id);
	///////////////////////////////////////////////////////////////////
	//all private functions are here
	///////////////////////////////////////////////////////////////////
private:
	CSceneManager(QObject * parent = Q_NULLPTR);
	~CSceneManager();
	///////////////////////////////////////////////////////////////////
	//all properties are here
	///////////////////////////////////////////////////////////////////
private:
	CScene * m_scene;
	QString m_path;
	QList<QGraphicsItem *> m_toCopiedIetmList;
	bool m_isSceneLoaded;
	CLogManager * m_logManager;
};
