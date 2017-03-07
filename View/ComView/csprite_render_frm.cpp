/**************************************************************************
File:         csprite_render_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-25
Description:
**************************************************************************/
#include "csprite_render_frm.h"
#include <QFileDialog>
#include "Manager/cproject_manager.h"
#include "Unit/basic_data_structure.h"

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CSpriteRenderFrm::CSpriteRenderFrm(QWidget * parent) : QFrame(parent) {
	mInitUI();
	mBuildConnect();
}

CSpriteRenderFrm::~CSpriteRenderFrm() {

}

void CSpriteRenderFrm::updateCom(QGraphicsItem * item, int count) {
	if (item == 0)
		return;
	CSpriteItem * sprite = (CSpriteItem*)item;
	m_item = sprite;
	QPixmap pix = sprite->pixmap().scaled(46, 46, Qt::KeepAspectRatio); ;
	m_labelPix->setPixmap(pix);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CSpriteRenderFrm::mSetStyle() {
	this->setFixedHeight(120);
	this->setStyleSheet(
		"color: white"
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 16px;"
	);
}

void CSpriteRenderFrm::mBuildConnect() {
	connect(m_btnSel, &QPushButton::clicked, this, &CSpriteRenderFrm::on_button_sel_clicked);
}

void CSpriteRenderFrm::mInitUI() {
	ui.setupUi(this);
	mSetStyle();
	m_labelPix = ui.label_pix;
	m_btnSel = ui.button_select;
}

void CSpriteRenderFrm::mSelectPixArea(const QString& path) {
	m_tailor = new CPixtureTailor(this);
	connect(m_tailor, &CPixtureTailor::signal_tailed_done, this, &CSpriteRenderFrm::slot_tailed_done);
	////////////////////////////////////////////////////////////////
	QPixmap pix(path);
	m_tailor->setPixmap(pix);
	m_item->setData(EnumDataType::PixPath, path);
	m_tailor->show();
}
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CSpriteRenderFrm::on_button_sel_clicked() {
	QString path = CProjectManager::getInstance()->getPath();
	QString name = CProjectManager::getInstance()->getName();
	QString src = path + "//" + name + "//" + "assets";
	QString filePath = QFileDialog::getOpenFileName(
		this,
		tr("select path"),
		src,
		tr("picture (*.png *.jpg)")
	);
	if (filePath == "")
		return;
	mSelectPixArea(filePath);

}

void CSpriteRenderFrm::slot_tailed_done(QPixmap pix) {
	m_item->setPixmap(pix);
	pix = pix.scaled(46, 46, Qt::KeepAspectRatio);
	m_labelPix->setPixmap(pix);
	m_item->setData(EnumSpriteType::BHasRect, QVariant(true));
	m_item->setData(EnumSpriteType::PixRect, QVariant(QRect(m_tailor->pixRect())));
}