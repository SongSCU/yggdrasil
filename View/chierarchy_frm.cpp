/**************************************************************************
File:         hierarchy_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "chierarchy_frm.h"
#include "Unit/basic_data_structure.h"
#include "Controller/ccom_controller.h"
#include "Controller/cunit_controller.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CHierarchyFrm::CHierarchyFrm(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	m_tree = ui.treeWidget;
	m_tree->setHeaderLabel("items");
	m_rootItem = new QTreeWidgetItem;
	m_tree->addTopLevelItem(m_rootItem);
	mBuildConnect();
	mSetStyle();
}

CHierarchyFrm::~CHierarchyFrm()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CHierarchyFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 16px;"
	);
}

void CHierarchyFrm::mLoadTree() {
	for (int i = 0; i < m_sceneItems.size(); i++) {
		QGraphicsItem * tmp = m_sceneItems[i];
		int id = tmp->data(EnumDataType::DataId).toInt();
		QString name = tmp->data(EnumDataType::DataName).toString();
		QString type = tmp->data(EnumDataType::DataType).toString();
		QTreeWidgetItem * treeItem = new QTreeWidgetItem();
		treeItem->setData(0, EnumDataType::DataId, id);
		treeItem->setData(0, EnumDataType::DataName, name);
		treeItem->setData(0, EnumDataType::DataType, type);
		treeItem->setText(0, name);
		treeItem->setIcon(0, mGetIcon(type));
		m_treeItems.push_back(treeItem);
		m_idMapItem.insert(id, treeItem);
	}
	m_rootItem->addChildren(m_treeItems);
}

void CHierarchyFrm::mClearTree() {
	m_idMapItem.clear();
	m_treeItems.clear();
	m_sceneItems.clear();
	m_rootItem->takeChildren();
}

void CHierarchyFrm::mBuildConnect() {
	connect(m_tree, &QTreeWidget::itemSelectionChanged,
		this, &CHierarchyFrm::slot_item_selected_changed);

	m_controller = CProjectController::getInstance();
	connect(m_controller, &CProjectController::signal_load_hierarchy,
		this, &CHierarchyFrm::slot_load_hierarchy);
	connect(m_controller, &CProjectController::signal_update_hierarchy,
		this, &CHierarchyFrm::slot_update_hierarchy);
	connect(m_controller, &CProjectController::signal_item_added,
		this, &CHierarchyFrm::slot_item_added);
	connect(m_controller, &CProjectController::signal_items_added,
		this, &CHierarchyFrm::slot_items_added);
	connect(m_controller, &CProjectController::signal_items_deleted,
		this, &CHierarchyFrm::slot_items_deleted);
	connect(this, &CHierarchyFrm::signal_item_selected,
		m_controller, &CProjectController::slot_item_selected);

	CUnitController *unitController = CUnitController::getInstance();
	connect(unitController, &CUnitController::signal_update_selected_item,
		this, &CHierarchyFrm::slot_update_selected_item);

	CComController * comController = CComController::getInstance();
	connect(comController, &CComController::signal_item_nameChanged,
		this, &CHierarchyFrm::slot_item_nameChanged);
}

QIcon CHierarchyFrm::mGetIcon(QString type) {
	if (type == "sprite") {
		return QIcon(":/picture/ui_picture/objects/sprite.png");
	}
	else if (type == "lock") {
		return QIcon(":/picture/ui_picture/lock.png");
	}
	else if (type == "eye") {
		return QIcon(":/picture/ui_picture/eye.png");
	}
	else {
		return QIcon("");
	}
}
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CHierarchyFrm::slot_load_hierarchy(QGraphicsScene* scene) {
	mClearTree();
	m_scene = scene;
	m_sceneItems = m_scene->items();
	mLoadTree();
}

void CHierarchyFrm::slot_update_hierarchy(QGraphicsItem* item, int type) {
	/*if (type == 0) {
		QGraphicsItem * tmp = item;
		int id = tmp->data(EnumDataType::DataId).toInt();
		QString name = tmp->data(EnumDataType::DataName).toString();
		QString type = tmp->data(EnumDataType::DataType).toString();
		QTreeWidgetItem * treeItem = new QTreeWidgetItem();
		treeItem->setData(0, EnumDataType::DataId, id);
		treeItem->setData(0, EnumDataType::DataName, name);
		treeItem->setData(0, EnumDataType::DataType, type);
		treeItem->setText(0, name);
		treeItem->setIcon(0, mGetIcon(type));
		treeItem->setIcon(1, mGetIcon("lock"));
		treeItem->setIcon(2, mGetIcon("eye"));
		m_treeItems.append(treeItem);
		m_tree->addTopLevelItem(treeItem);
	}*/
}

void CHierarchyFrm::slot_item_added(const QGraphicsItem* item) {
	const QGraphicsItem * tmp = item;
	int id = tmp->data(EnumDataType::DataId).toInt();
	QString name = tmp->data(EnumDataType::DataName).toString();
	QString type = tmp->data(EnumDataType::DataType).toString();
	QTreeWidgetItem * treeItem = new QTreeWidgetItem();
	treeItem->setData(0, EnumDataType::DataId, id);
	treeItem->setData(0, EnumDataType::DataName, name);
	treeItem->setData(0, EnumDataType::DataType, type);
	treeItem->setText(0, name);
	treeItem->setIcon(0, mGetIcon(type));
	treeItem->setIcon(1, mGetIcon("lock"));
	treeItem->setIcon(2, mGetIcon("eye"));
	m_treeItems.append(treeItem);
	m_idMapItem.insert(id, treeItem);
	m_rootItem->addChild(treeItem);
}

void CHierarchyFrm::slot_update_selected_item(const QList<int> &list) {
	for (QMap<int, QTreeWidgetItem*>::iterator it = m_idMapItem.begin(); it != m_idMapItem.end(); it++) {
		QTreeWidgetItem* tmp = it.value();
		tmp->setSelected(false);
	}
	for (QList<int>::const_iterator it = list.begin(); it != list.end(); it++) {
		int id = *it;
		QTreeWidgetItem* tmp = m_idMapItem.value(id);
		tmp->setSelected(true);
	}
}

void CHierarchyFrm::slot_items_added(const QList<QGraphicsItem*> &list) {
	for (QList<QGraphicsItem*>::const_iterator it = list.begin(); it != list.end(); it++) {
		QGraphicsItem * tmp = *it;;
		int id = tmp->data(EnumDataType::DataId).toInt();
		QString name = tmp->data(EnumDataType::DataName).toString();
		QString type = tmp->data(EnumDataType::DataType).toString();
		QTreeWidgetItem * treeItem = new QTreeWidgetItem();
		treeItem->setData(0, EnumDataType::DataId, id);
		treeItem->setData(0, EnumDataType::DataName, name);
		treeItem->setData(0, EnumDataType::DataType, type);
		treeItem->setText(0, name);
		treeItem->setIcon(0, mGetIcon(type));
		treeItem->setIcon(1, mGetIcon("lock"));
		treeItem->setIcon(2, mGetIcon("eye"));
		m_treeItems.append(treeItem);
		m_idMapItem.insert(id, treeItem);
		m_rootItem->addChild(treeItem);
	}
}

void CHierarchyFrm::slot_items_deleted(const QList<int> &list) {
	for (QList<int>::const_iterator it = list.begin(); it != list.end(); it++) {
		int id = *it;
		mRemoveItem(id);
	}
	m_tree->update();
}

void CHierarchyFrm::slot_item_nameChanged(const int id, const QString name) {
	QTreeWidgetItem * tmp = m_idMapItem.value(id);
	tmp->setText(0, name);
}

void CHierarchyFrm::mRemoveItem(int id) {
	for (QList<QTreeWidgetItem*>::iterator it = m_treeItems.begin(); it != m_treeItems.end(); it++) {
		QTreeWidgetItem * tmp = *it;
		if (tmp->data(0, EnumDataType::DataId).toInt() == id) {
			m_treeItems.removeOne(tmp);
			m_rootItem->removeChild(tmp);
			m_idMapItem.remove(id);
			return;
		}
	}
}

void CHierarchyFrm::slot_item_selected_changed() {
	QTreeWidgetItem * tmp = m_tree->currentItem();
	if (tmp == 0 || tmp == m_rootItem)
		return;
	int id = tmp->data(0, EnumDataType::DataId).toInt();
	emit signal_item_selected(id);
}