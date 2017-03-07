/**************************************************************************
File:         ctransform_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-16
Description:
**************************************************************************/
#include "ctransform_frm.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CTransformFrm::CTransformFrm(QWidget * parent) : QFrame(parent) {
	ui.setupUi(this);
	mSetStyle();
	m_edit_pX = ui.lineEdit_px;
	m_edit_pY = ui.lineEdit_py;
	m_edit_rX = ui.lineEdit_rx;
	m_edit_rY = ui.lineEdit_ry;
	m_edit_sW = ui.lineEdit_sw;
	m_edit_sH = ui.lineEdit_sh;
	m_edit_rot = ui.lineEdit_rot;
	m_edit_dep = ui.lineEdit_depth;
	m_isActive = false;
	mBuildConnects();
}

CTransformFrm::~CTransformFrm() {

}

void CTransformFrm::updateCom(QGraphicsItem * item, int count) {
	mSetItemPointer(item);
	if (count != 1) {
		m_isActive = false;
		mSetValue("", "", "", "", "", "", "", "");
		return;
	}
	QString px = QString::number(item->pos().x());
	QString py = QString::number(item->pos().y());
	QString rot = QString::number(item->rotation());
	QString rx = QString::number(m_item->offset().x());
	QString ry = QString::number(m_item->offset().y());
	QString sw = QString::number(item->sceneBoundingRect().width());
	QString sh = QString::number(item->sceneBoundingRect().height());
	QString dep = QString::number(item->zValue());
	m_isActive = true;
	mSetValue(px, py, rx, ry, sw, sh, rot, dep);
}

void CTransformFrm::mSetStyle() {
	this->setFixedHeight(150);
}

void CTransformFrm::mBuildConnects() {
	connect(m_edit_pX, &QLineEdit::textChanged, this, &CTransformFrm::on_edit_pX_changed);
	connect(m_edit_pY, &QLineEdit::textChanged, this, &CTransformFrm::on_edit_pY_changed);
	connect(m_edit_rX, &QLineEdit::textChanged, this, &CTransformFrm::on_edit_rX_changed);
	connect(m_edit_rY, &QLineEdit::textChanged, this, &CTransformFrm::on_edit_rY_changed);
	connect(m_edit_sW, &QLineEdit::textEdited, this, &CTransformFrm::on_edit_sW_changed);
	connect(m_edit_sH, &QLineEdit::textEdited, this, &CTransformFrm::on_edit_sH_changed);
	connect(m_edit_rot, &QLineEdit::textChanged, this, &CTransformFrm::on_edit_rot_changed);
	connect(m_edit_dep, &QLineEdit::textChanged, this, &CTransformFrm::on_edit_dep_changed);
}

void CTransformFrm::mSetItemPointer(QGraphicsItem* item) {
	//QString type = item->data(Qt::UserRole).toString();
	m_item = (QGraphicsPixmapItem*)item;
}
///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CTransformFrm::on_edit_pX_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double x = m_edit_pX->text().toDouble(&ok);
	if (!ok) return;
	m_item->setX(x);
}
void CTransformFrm::on_edit_pY_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double y = m_edit_pY->text().toDouble(&ok);
	if (!ok) return;
	m_item->setY(y);
}
void CTransformFrm::on_edit_rX_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double x = m_edit_rX->text().toDouble(&ok);
	if (!ok) return;
	m_item->setOffset(x, m_item->offset().y());
}
void CTransformFrm::on_edit_rY_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double y = m_edit_rY->text().toDouble(&ok);
	if (!ok) return;
	m_item->setOffset(m_item->offset().x(), y);
}
void CTransformFrm::on_edit_sH_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double h = m_edit_sH->text().toDouble(&ok);
	double w = m_edit_sW->text().toDouble(&ok);
	if (!ok) return;
	double scaleW = w / (m_item->sceneBoundingRect().width());
	double scaleH = h / (m_item->sceneBoundingRect().height());
	QTransform transform;
	transform.scale(scaleW, scaleH);
	m_item->setTransform(transform);
}
void CTransformFrm::on_edit_sW_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double h = m_edit_sH->text().toDouble(&ok);
	double w = m_edit_sW->text().toDouble(&ok);
	if (!ok) return;
	double scaleW = w / (m_item->sceneBoundingRect().width());
	double scaleH = h / (m_item->sceneBoundingRect().height());
	QTransform transform;
	transform.scale(scaleW, scaleH);
	m_item->setTransform(transform);
}

void CTransformFrm::on_edit_rot_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double r = m_edit_rot->text().toDouble(&ok);
	if (!ok) return;
	m_item->setRotation(r);
}

void CTransformFrm::on_edit_dep_changed() {
	if (!m_isActive) return;
	bool ok = true;
	double dep = m_edit_dep->text().toDouble(&ok);
	if (!ok) return;
	m_item->setZValue(dep);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CTransformFrm::mSetValue(QString px, QString py, QString rx,
	QString ry, QString sw, QString sh, QString rot, QString dep) {
	m_edit_pX->setText(px);
	m_edit_pY->setText(py);
	m_edit_rX->setText(rx);
	m_edit_rY->setText(ry);
	m_edit_sW->setText(sw);
	m_edit_sH->setText(sh);
	m_edit_rot->setText(rot);
	m_edit_dep->setText(dep);
}