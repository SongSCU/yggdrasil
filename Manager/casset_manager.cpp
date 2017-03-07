/**************************************************************************
File:         casset_manager.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "casset_manager.h"
#include "expert/cfile_expert.h"
#include "unit/cdb_operator.h"
#include <QXmlStreamWriter>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CAssetManager* CAssetManager::getInstance() {
	static CAssetManager manager;
	return &manager;
}

bool CAssetManager::initAsset(const QString& p_name, const QString& p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	bool b1 = mInitAssetsDir();
	bool b2 = mInitAssetsDB();
	return b1 && b2;
}

bool CAssetManager::loadAsset(const QString& p_name, const QString& p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	return true;
}

bool CAssetManager::createFile(const QString &name, const QString &type) {
	if (type == "Scene") {
		if (!mCreateScene(name))
			return false;
		emit signal_insert_db("asset", m_currentPath + "/" + name + ".scene");
	}
	return true;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CAssetManager::slot_insert_db(const QString table_name, const QString data_path) {
	emit signal_insert_db(table_name, data_path);
}

void CAssetManager::slot_delete_db(const QString table_name, const QString data_path) {
	emit signal_delete_db(table_name, data_path);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CAssetManager::CAssetManager() {

}

CAssetManager::~CAssetManager() {

}

bool CAssetManager::mInitAssetsDB() {
	CDBOperator * dbp = CDBOperator::getInstance();
	if (!(dbp->createDB(m_strPath + "/" + m_strName, m_strName + ".db")))
		return false;
	if (!dbp->createTable()) {
		//return false;
	}
	emit signal_insert_db("asset", m_strPath + "/" + m_strName + "/assets");
	return true;
}

bool CAssetManager::mInitAssetsDir() {
	bool bOk = CFileExpert::copyRecursively("./projectInit", m_strPath + "//"
		+ m_strName + "//" + "assets");
	return bOk;
	//return true;
}

bool CAssetManager::mCreateScene(const QString &name) {
	QFile file(m_currentPath + "/" + name + ".scene");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;
	QXmlStreamWriter writer(&file);
	writer.setAutoFormatting(true);
	writer.writeStartDocument("1.0");
	writer.writeStartElement("config");
	writer.writeEndElement();
	writer.writeEndDocument();
	file.close();
	return true;
}