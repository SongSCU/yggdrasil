/**************************************************************************
File:         cproject_controller.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cproject_controller.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CProjectController* CProjectController::getInstance() {
	static CProjectController controller;
	return &controller;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CProjectController::slot_new_project(const QString& p_name, const QString& p_path) {
	emit signal_new_project(p_name, p_path);
}

void CProjectController::slot_open_project(const QString & path) {
	emit signal_open_project(path);
}

void CProjectController::slot_close_project() {
	emit signal_project_close();
}

void CProjectController::slot_project_born(const QString& p_name, const QString& p_path) {
	emit signal_project_born(p_name, p_path);
}

void CProjectController::slot_save_project(const QString &path) {
	emit signal_save_project(path);
	emit signal_save_scene(path);
}

void CProjectController::slot_project_err(ProjectError errType) {
	emit signal_project_err(errType);
}

void CProjectController::slot_new_file(const QString &name, const QString &type) {
	emit signal_new_file(name, type);
}

void CProjectController::slot_load_scene(const QString &path) {
	emit signal_load_scene(path);
}

void CProjectController::slot_add_item(const QString &type, const QPointF &pos) {
	emit signal_add_item(type, pos);
}

void CProjectController::slot_delete_item() {
	emit signal_delete_item();
}

void CProjectController::slot_copy_item() {
	emit signal_copy_item();
}

void CProjectController::slot_paste_item() {
	emit signal_paste_item();
}

void CProjectController::slot_show_scene(QGraphicsScene* scene) {
	emit signal_show_scene(scene);
}

void CProjectController::slot_show_com(QGraphicsItem* item, int num) {
	emit signal_show_com(item, num);
}

void CProjectController::slot_insert_db(const QString table_name, const QString data_path) {
	emit signal_insert_db(table_name, data_path);
}

void CProjectController::slot_delete_db(const QString table_name, const QString data_path) {
	emit signal_delete_db(table_name, data_path);
}

void CProjectController::slot_new_file_accept(const QString &name, const QString &type) {
	emit signal_new_file_accept(name, type);
}

void CProjectController::slot_load_hierarchy(QGraphicsScene* scene) {
	emit signal_load_hierarchy(scene);
}

void CProjectController::slot_update_hierarchy(QGraphicsItem* item, int type) {
	emit signal_update_hierarchy(item, type);
}

void CProjectController::slot_item_added(const QGraphicsItem* item) {
	emit signal_item_added(item);
}

void CProjectController::slot_items_added(const QList<QGraphicsItem*> &list) {
	emit signal_items_added(list);
}

void CProjectController::slot_items_deleted(const QList<int> &list) {
	emit signal_items_deleted(list);
}

void CProjectController::slot_item_selected(int id) {
	emit signal_item_selected(id);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CProjectController::CProjectController() {
	m_projectManager = CProjectManager::getInstance();
	connect(this, &CProjectController::signal_new_project,
		m_projectManager, &CProjectManager::slot_new_project);
	connect(m_projectManager, &CProjectManager::signal_project_born,
		this, &CProjectController::slot_project_born);
	connect(this, &CProjectController::signal_open_project,
		m_projectManager, &CProjectManager::slot_open_project);
	connect(m_projectManager, &CProjectManager::signal_project_close,
		this, &CProjectController::slot_close_project);
	connect(this, &CProjectController::signal_new_file,
		m_projectManager, &CProjectManager::slot_new_file);
	connect(m_projectManager, &CProjectManager::signal_new_file_accept,
		this, &CProjectController::slot_new_file_accept);
	connect(this, &CProjectController::signal_save_project,
		m_projectManager, &CProjectManager::slot_save_project);

	m_sceneManager = CSceneManager::getInstance();
	connect(this, &CProjectController::signal_load_scene,
		m_sceneManager, &CSceneManager::slot_load_scene);
	connect(m_sceneManager, &CSceneManager::signal_show_scene,
		this, &CProjectController::slot_show_scene);
	connect(this, &CProjectController::signal_add_item,
		m_sceneManager, &CSceneManager::slot_add_item);
	connect(m_sceneManager, &CSceneManager::signal_load_hierarchy,
		this, &CProjectController::slot_load_hierarchy);
	connect(m_sceneManager, &CSceneManager::signal_update_hierarchy,
		this, &CProjectController::slot_update_hierarchy);
	connect(this, &CProjectController::signal_save_scene,
		m_sceneManager, &CSceneManager::slot_save_scene);
	connect(this, &CProjectController::signal_delete_item,
		m_sceneManager, &CSceneManager::slot_delete_item);
	connect(this, &CProjectController::signal_copy_item,
		m_sceneManager, &CSceneManager::slot_copy_item);
	connect(this, &CProjectController::signal_paste_item,
		m_sceneManager, &CSceneManager::slot_paste_item);
	connect(m_sceneManager, &CSceneManager::signal_item_added,
		this, &CProjectController::slot_item_added);
	connect(m_sceneManager, &CSceneManager::signal_items_added,
		this, &CProjectController::slot_items_added);
	connect(m_sceneManager, &CSceneManager::signal_items_deleted,
		this, &CProjectController::slot_items_deleted);
	connect(this, &CProjectController::signal_item_selected,
		m_sceneManager, &CSceneManager::slot_item_selected);

	m_comManager = CComponentManager::getInstance();
	connect(m_comManager, &CComponentManager::signal_show_com,
		this, &CProjectController::slot_show_com);

	m_assetManager = CAssetManager::getInstance();
	connect(this, &CProjectController::signal_insert_db,
		m_assetManager, &CAssetManager::slot_insert_db);
	connect(this, &CProjectController::signal_delete_db,
		m_assetManager, &CAssetManager::slot_delete_db);
}

CProjectController::~CProjectController() {

}