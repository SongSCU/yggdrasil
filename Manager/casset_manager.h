/**************************************************************************
File:         casset_manager.h
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#pragma once
#include <QObject>
//////////////////////////////////////////////////////////////////
///    Class:  CAssetManager
///    Brief:  
//////////////////////////////////////////////////////////////////
class CAssetManager : public QObject {
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	static CAssetManager * getInstance();
	bool initAsset(const QString& p_name, const QString& p_path);
	bool loadAsset(const QString& p_name, const QString& p_path);
	bool createFile(const QString &name, const QString &type);
	void setCurrentPath(const QString & path) { m_currentPath = path; }
	void setPath(const QString & path) { m_strPath = path; }
	void setName(const QString & name) { m_strName = name; }
	QString path() { return m_strPath; }
	QString name() { return m_strName; }
	QString assetPath() { return QString(m_strPath + "/" + m_strName + "/assets"); }
	
///////////////////////////////////////////////////////////////////
//all signals  are here
///////////////////////////////////////////////////////////////////
signals:
	void signal_insert_db(const QString table_name, const QString data_path);
	void signal_delete_db(const QString table_name, const QString data_path);
///////////////////////////////////////////////////////////////////
//all public slots  are here
///////////////////////////////////////////////////////////////////
public slots:
    void slot_insert_db(const QString table_name, const QString data_path);
	void slot_delete_db(const QString table_name, const QString data_path);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	CAssetManager();
	~CAssetManager();
	bool mInitAssetsDir();
	bool mInitAssetsDB();
	bool mCreateScene(const QString &name);
///////////////////////////////////////////////////////////////////
//all properties  are here
///////////////////////////////////////////////////////////////////
private:
	QString m_strPath;
	QString m_strName;
	QString m_currentPath;

};

