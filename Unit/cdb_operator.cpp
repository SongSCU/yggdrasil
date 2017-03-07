/**************************************************************************
File:         cdb_operator.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cdb_operator.h"
#include <fstream>
#include "Manager/casset_manager.h"
#include <QFileInfo>
#include <QList>
#include "Expert/cfile_expert.h"
#include "Unit/utilities.h"
///////////////////////////////////////////////////////////////////
//all public functions of CDBOperator are here
///////////////////////////////////////////////////////////////////
CDBOperator* CDBOperator::getInstance() {
	static CDBOperator unit;
	return &unit;
}

bool CDBOperator::createDB(const QString & p_dbPath, const QString & p_dbName) {
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(p_dbPath + "/" + p_dbName);
	return true;
}

bool CDBOperator::createTable() {
	m_db.open();
	QSqlQuery query(m_db);
	//QString create_sql = "create table" + table_asset;
	QString create_sql = "create table asset (id int primary key, name varchar(30), type varchar(10), path varchar(128))";
	if (!query.exec(create_sql)) {
		m_db.close();
		return false;
	}
	m_db.close();
	return true;
}

void CDBOperator::run()
{
	CDBOperThread thread(&m_db);
	CAssetManager *manager = CAssetManager::getInstance();
	connect(manager, &CAssetManager::signal_insert_db, &thread, &CDBOperThread::insertIntoTable);
	connect(manager, &CAssetManager::signal_delete_db, &thread, &CDBOperThread::deleteFromTable);
	exec();
}
///////////////////////////////////////////////////////////////////
//all private functions of CDBOperator are here
///////////////////////////////////////////////////////////////////
CDBOperator::CDBOperator() {
	this->start();
}

CDBOperator::~CDBOperator() {

}
///////////////////////////////////////////////////////////////////
//all public functions of CDBOperThread are here
///////////////////////////////////////////////////////////////////
void CDBOperThread::insertIntoTable(const QString table_name, const QString data_path) {
	///////////////////////////////////////////////////////////////
	if (!m_pDB->isOpen())
		m_pDB->open();
	QSqlQuery query(*m_pDB);
	QString sql_insert;
	if (table_name == "asset") {
		sql_insert = "insert into asset values (%1,'%2','%3','%4')";
	}
	/////////////////////////////////////////////////////////////////////////
	QFileInfo info(data_path);
	/////////////////////////////////////////////////////////////////////////
	if (!info.isDir()) {
		Data_Asset da;
		da.id = CUUIDCreator::getInstance()->getUUID();
		da.name = info.fileName();
		da.path = info.absoluteFilePath();
		da.type = CFileExpert::convertFileTpye(info.suffix());
		sql_insert = sql_insert.arg(QString::number(da.id), da.name,da.type , da.path);
		query.exec(sql_insert);
		return;
	}
	///////////////////////////////////////////////////////////////////////////
	QList<Data_Asset> list;
	QString strTmp;
	CFileExpert::readRecursively(data_path, list);
	for (QList<Data_Asset>::iterator it = list.begin(); it != list.end(); it++) {
		it->id = CUUIDCreator::getInstance()->getUUID();
		strTmp= sql_insert.arg(QString::number(it->id), it->name, it->type, it->path);
		query.exec(strTmp);
	}	
}

void CDBOperThread::deleteFromTable(const QString table_name, const QString data_path) {
	///////////////////////////////////////////////////////////////
	if (!m_pDB->isOpen())
		m_pDB->open();
	QSqlQuery query(*m_pDB);
	QString sql_delete;
	if (table_name == "asset") {
		sql_delete = "delete from asset where path= '%1'";
	}
	/////////////////////////////////////////////////////////////////////////
	QFileInfo info(data_path);
	/////////////////////////////////////////////////////////////////////////
	if (!info.isDir()) {
		sql_delete = sql_delete.arg(data_path);
		query.exec(sql_delete);
		return;
	}
	///////////////////////////////////////////////////////////////////////////
	QList<Data_Asset> list;
	QString strTmp;
	CFileExpert::readRecursively(data_path, list);

	for (QList<Data_Asset>::iterator it = list.begin(); it != list.end(); it++) {
		strTmp = sql_delete.arg(it->path);
		query.exec(strTmp);
	}
}
