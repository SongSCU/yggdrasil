#include "cunit_controller.h"
/**************************************************************************
File:         cunit_controller.cpp
Author:       Song Xiaofeng
Date:         2016-06-09
Description:
**************************************************************************/

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CUnitController* CUnitController::getInstance() {
	static CUnitController controller;
	return &controller;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CUnitController::slot_update_selected_item(const QList<int> &list) {
	emit signal_update_selected_item(list);
}

void CUnitController::slot_update_component(QList<QGraphicsItem*> itemList) {
	emit signal_update_component(itemList);
}

///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CUnitController::CUnitController() {
	m_comManager = CComponentManager::getInstance();
	connect(this, &CUnitController::signal_update_component,
		m_comManager, &CComponentManager::slot_update_component);

}