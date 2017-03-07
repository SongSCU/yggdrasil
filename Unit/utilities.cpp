/**************************************************************************
File:         utilities.cpp
Author:       Song Xiaofeng
Date:         2016-05-19
Description:
**************************************************************************/
#include "utilities.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CScrollButton::CScrollButton(QWidget * target, QString text, QWidget * parent) {

	this->setParent(parent);
	this->setTarget(target);
	this->setText(text);

	m_isScroll = false;
	m_layout = new QHBoxLayout(this);
	m_label_arrow = new QLabel(this);
	m_label_arrow->setPixmap(QPixmap(":/picture/ui_picture/com/scroll_right.png"));
	m_label_arrow->setFixedSize(40, 30);
	QLabel * label_text = new QLabel(this);
	label_text->setText(m_text);
	m_layout->addWidget(m_label_arrow);
	m_layout->addWidget(label_text);
	this->setFixedHeight(45);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CScrollButton::mousePressEvent(QMouseEvent * e) {
	if (e->button() != Qt::LeftButton) {
		return;
	}
	m_isScroll = !m_isScroll;
	if (m_isScroll){
		m_label_arrow->setPixmap(QPixmap(":/picture/ui_picture/com/scroll_right.png"));
		m_target->hide();
	}
	else {
		m_label_arrow->setPixmap(QPixmap(":/picture/ui_picture/com/scroll_down.png"));
		m_target->show();
	}
}