/**************************************************************************
File:         cattribute_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-16
Description:
**************************************************************************/
#include "cattribute_frm.h"
#include <QPicture>
#include "Unit/basic_data_structure.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CAttributeFrm::CAttributeFrm(QWidget * parent) : QFrame(parent) {
	ui.setupUi(this);
	m_labelIcon = ui.label_iType;
	m_labelType = ui.label_type_con;
	m_lineEditName = ui.lineEdit_name;
	mSetStyle();
	mBuildConnects();
}

CAttributeFrm::~CAttributeFrm() {

}

void CAttributeFrm::updateCom(QGraphicsItem* item, int count) {
	if (item == 0) {
		QString s = QString("%1 items").arg(QString::number(count));
		m_lineEditName->setText("");
		m_labelType->setText("");
		m_labelIcon->setText(s);
		return;
	}
	m_item = item;
	QString type = item->data(EnumDataType::DataType).toString();
	QString name = item->data(EnumDataType::DataName).toString();

	m_lineEditName->setText(name);
	m_labelType->setText(type);

	if (type == "sprite") {
		QPixmap pix(item->data(EnumDataType::PixPath).toString());
		bool hasRect = item->data(EnumSpriteType::BHasRect).toBool();
		if (hasRect) {
			pix = pix.copy(item->data(EnumSpriteType::PixRect).toRect());
		}
		pix = pix.scaled(46, 46, Qt::KeepAspectRatio);
		m_labelIcon->setPixmap(pix);
	}
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CAttributeFrm::mSetStyle() {
	this->setFixedHeight(100);
}

void CAttributeFrm::mBuildConnects() {
	m_controller = CComController::getInstance();
	connect(this, &CAttributeFrm::signal_item_nameChanged, m_controller, &CComController::slot_item_nameChanged);
}
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CAttributeFrm::on_lineEdit_name_editingFinished() {
	m_item->setData(EnumDataType::DataName, m_lineEditName->text());
	int id = m_item->data(EnumSpriteType::DataId).toInt();
	QString name = m_lineEditName->text();
	emit signal_item_nameChanged(id, name);
}