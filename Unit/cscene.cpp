/**************************************************************************
File:         cscene.cpp
Author:       Song Xiaofeng
Date:         2016-05-17
Description:
**************************************************************************/
#include "cscene.h"
#include <QBrush>
#include "Unit/basic_data_structure.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////

CScene::CScene(QWidget* parent) {
	this->setParent(parent);
	this->setBackgroundBrush(QBrush(QColor("#A0A0A0"), Qt::CrossPattern));
	mBuildConnects();
	//this->setForegroundBrush();
}

///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CScene::mousePressEvent(QMouseEvent * event) {

}

void CScene::slot_selected_item_changed() {
	QList<QGraphicsItem*> itemList = this->selectedItems();
	emit signal_update_component(itemList);

	QList<int> list;
	for (QList<QGraphicsItem*>::iterator it = itemList.begin(); it != itemList.end(); it++) {
		int id = (*it)->data(EnumDataType::DataId).toInt();
		list.push_back(id);
	}
	emit signal_update_selected_item(list);
}

void CScene::mBuildConnects() {
	connect(this, &CScene::changed, this, &CScene::slot_selected_item_changed);

	m_unitController = CUnitController::getInstance();
	connect(this, &CScene::signal_update_selected_item, m_unitController, &CUnitController::slot_update_selected_item);
	connect(this, &CScene::signal_update_component, m_unitController, &CUnitController::slot_update_component);
}