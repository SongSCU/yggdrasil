/**************************************************************************
File:         cproject_manager.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cproject_manager.h"
#include <QtCore/QDir>
#include "casset_manager.h"
#include "expert/cfile_expert.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <cassert>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CProjectManager* CProjectManager::getInstance() {
	static CProjectManager manager;
	return &manager;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CProjectManager::slot_new_project(QString p_name, QString p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	m_isOpen = true;
	//init project
	if (!mInitProject()) {
		emit signal_project_error(ProjectError::init_project_err);
		return;
	}
	//init asset 
	CAssetManager * manager = CAssetManager::getInstance();
	bool ok = manager->initAsset(m_strName, m_strPath);
	if (!ok) {
		emit signal_project_error(ProjectError::init_asset_err);
		mRemoveProDir();
		return;
	}
	emit signal_project_close();
	emit signal_project_born(m_strName, m_strPath);

	m_logManager->printLog("A new project is created: " + m_strName, 0);
}

void CProjectManager::slot_close_project() {

}

void CProjectManager::slot_save_project(const QString &path) {
	if (m_isOpen) {

	}
	m_logManager->printLog("Project is saved: " + m_strName, 0);
}

void CProjectManager::slot_open_project(const QString &path) {
	bool b1 = mReadProfile(path);
	if (!b1) {
		emit signal_project_error(ProjectError::read_profile_err);
		return;
	}
	bool b2 = mOpenProject();
	if (!b2) {
		emit signal_project_error(ProjectError::open_project_err);
		return;
	}
	emit signal_project_close();
	emit signal_project_born(m_strName, m_strPath);
	CAssetManager * manager = CAssetManager::getInstance();
	manager->setPath(m_strPath);
	manager->setName(m_strName);

	m_logManager->printLog("A old project is opened: " + m_strName, 0);
}

void CProjectManager::slot_new_file(const QString &name, const QString &type) {
	CAssetManager * manager = CAssetManager::getInstance();
	bool ok = manager->createFile(name, type);
	if (!ok) {
		emit signal_project_error(ProjectError::create_file_err);
		return;
	}
	emit signal_new_file_accept(name, type);

	m_logManager->printLog("A new file is created: " + name + "." + type, 0);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CProjectManager::CProjectManager() {
	m_logManager = CLogManager::getInstance();
}

CProjectManager::~CProjectManager() {

}

bool CProjectManager::mInitProject() {
	QDir dir;
	QString path = m_strPath;
	QString name = m_strName;
	bool b = dir.mkdir(path + "//" + name);
	if (!b) {
		return false;
	}
	if (!mWriteProfile())
		return false;
	return true;
}

bool CProjectManager::mOpenProject() {

	return true;
}

bool CProjectManager::mWriteProfile() {
	QFile file(m_strPath + "//" + m_strName + "//" + m_strName + ".ygg");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;
	QXmlStreamWriter writer(&file);
	writer.setAutoFormatting(true);
	writer.writeStartDocument("1.0");
	writer.writeStartElement("config");
	writer.writeAttribute("name", m_strName);
	writer.writeAttribute("path", m_strPath);
	writer.writeEndElement();
	writer.writeEndElement();
	writer.writeEndElement();
	file.close();

	return true;
}

bool CProjectManager::mReadProfile(const QString & path) {
	QXmlStreamReader reader;
	QFile file(path);
	if (!file.open(QFile::ReadOnly)) {
		return false;
	}
	reader.setDevice(&file);
	QStringRef eName;
	while (!reader.atEnd()) {
		reader.readNext();
		if (reader.isStartElement()) {
			eName = reader.name();
			if (eName == "config") {
				m_strName = reader.attributes().value("name").toString();
				m_strPath = reader.attributes().value("path").toString();
			}
		}
		else if (reader.hasError()) {
			return false;
		}
	}
	file.close();
	return true;
}

void CProjectManager::mRemoveProDir() {
	CFileExpert::deleteDir(m_strPath + "//" + m_strName);
}