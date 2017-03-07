#include "ccom_controller.h"
/**************************************************************************
File:         ccom_controller.cpp
Author:       Song Xiaofeng
Date:         2016-06-08
Description:
**************************************************************************/

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CComController* CComController::getInstance() {
	static CComController controller;
	return &controller;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CComController::slot_item_nameChanged(const int id, const QString name) {
	emit signal_item_nameChanged(id, name);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CComController::CComController() {

}