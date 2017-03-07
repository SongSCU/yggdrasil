/**************************************************************************
File:         cproperty_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cproperty_frm.h"
#include <QPushButton>
#include <QScrollBar>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CPropertyFrm::CPropertyFrm(QWidget *parent)
	: QScrollArea(parent)
{
	//ui.setupUi(this);
	mSetStyle();
	mInitUI();
	m_controller = CProjectController::getInstance();
	connect(m_controller, &CProjectController::signal_show_com,
		this, &CPropertyFrm::slot_show_com);
}

CPropertyFrm::~CPropertyFrm()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CPropertyFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 0.5px solid gray;"
		"border-radius: 1px;"
	);
}

void CPropertyFrm::mHideAll() {
	m_attributeSB->hide();
	m_attributeFrm->hide();
	m_transformSB->hide();
	m_transformFrm->hide();
	if (m_spriteSB != 0 && m_spriteFrm != 0) {
		m_spriteSB->hide();
		m_spriteFrm->hide();
	}
}

void CPropertyFrm::mShowAll() {
	m_attributeSB->show();
	m_attributeFrm->show();
	m_transformSB->show();
	m_transformFrm->show();
	if (m_spriteSB != 0 && m_spriteFrm != 0) {
		m_spriteSB->show();
		m_spriteFrm->show();
	}
}

void CPropertyFrm::mInitUI() {
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_frame = new QFrame();
	m_layout = new QVBoxLayout(m_frame);
	m_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
	m_frame->setFixedWidth(360);
	m_transformFrm = new CTransformFrm(m_frame);
	m_attributeFrm = new CAttributeFrm(m_frame);

	m_attributeSB = new CScrollButton(m_attributeFrm, tr("Attribute"), m_frame);
	m_transformSB = new CScrollButton(m_transformFrm, tr("Transform"), m_frame);

	m_spriteFrm = 0;
	m_spriteSB = 0;
	

	m_layout->addWidget(m_attributeSB);
	m_layout->addWidget(m_attributeFrm);
	m_layout->addWidget(m_transformSB);
	m_layout->addWidget(m_transformFrm);
	
	mHideAll();

	this->setWidget(m_frame);
	m_frame->show();
}

void CPropertyFrm::mCheckCom(QGraphicsItem* item) {
	QString type = item->data(EnumDataType::DataType).toString();
	if (type == "sprite") {
		if (m_spriteFrm == 0 && m_spriteSB == 0) {
			m_spriteFrm = new CSpriteRenderFrm(m_frame);
			m_spriteSB = new CScrollButton(m_spriteFrm, tr("Sprite Renderer"), m_frame);
			m_layout->addWidget(m_spriteSB);
			m_layout->addWidget(m_spriteFrm);
			this->update();
		}
	}
}
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CPropertyFrm::slot_show_com(QGraphicsItem* item, int num) {
	
	if (num == 0) {
		mHideAll();
	}
	else if (num == 1) {
		mCheckCom(item);
		m_attributeFrm->updateCom(item, num);
		m_transformFrm->updateCom(item, num);
		if (m_spriteFrm != 0)
			m_spriteFrm->updateCom(item, num);
		mShowAll();
	}
	else if (num > 1) {
		m_transformFrm->updateCom(item, num);
		m_attributeFrm->updateCom(0, num);
		mShowAll();
	}
}