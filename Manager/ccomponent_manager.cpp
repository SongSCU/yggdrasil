/**************************************************************************
File:         ccomponent_manager.cpp
Author:       Song Xiaofeng
Date:         2016-05-17
Description:
**************************************************************************/
#include "ccomponent_manager.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CComponentManager * CComponentManager::getInstance() {
	static CComponentManager manager;
	return &manager;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CComponentManager::slot_update_component(QList<QGraphicsItem*> itemList) {
	int num = itemList.length();
	if (num == 0) {
		emit signal_show_com(0, 0);
	}
	else if (num == 1) {
		QGraphicsItem* item = *itemList.begin();
		emit signal_show_com(item, 1);
	}
	else if (num > 1) {
		emit signal_show_com(0, num);
	}
}

///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CComponentManager::CComponentManager(QObject * parent) : QObject(parent) {

}

CComponentManager::~CComponentManager() {

}
