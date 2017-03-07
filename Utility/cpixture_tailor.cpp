/**************************************************************************
File:         cpixture_tailor.cpp
Author:       Song Xiaofeng
Date:         2016-05-16
Description:
**************************************************************************/
#include "cpixture_tailor.h"
#include <QVBoxLayout>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CPixtureTailor::CPixtureTailor(QWidget * parent) : QDialog(parent) {
	ui.setupUi(this);
	m_done = false;
	mInitUI();

}

CPixtureTailor::~CPixtureTailor() {

}

void CPixtureTailor::setPixmap(QPixmap pix) {
	m_pix = pix;
	m_pixItem->setPixmap(m_pix);
}

CPixView::CPixView(QWidget* parent) {
	this->setParent(parent);
	//this->setSceneRect(-5000, -5000, 10000, 10000);
	this->setDragMode(QGraphicsView::RubberBandDrag);
	this->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

	//this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setAcceptDrops(true);
	this->setMouseTracking(true);
	this->show();
	m_isStart = false;
	m_hasTailed = false;
	m_rect = new QGraphicsRectItem;
}

CPixScene::CPixScene(QWidget* parent) {
	this->setParent(parent);
	this->setBackgroundBrush(QBrush(QColor("#A0A0A0")));
	//mBuildConnects();
	//this->setForegroundBrush();
}

///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CPixtureTailor::accept() {
	if (m_view->hasTailed()) {
		m_pixRect = m_view->tailedRect();
		m_pix = m_pix.copy(m_pixRect);
	}
	else {
		m_pixRect.setRect(0, 0, m_pix.width(), m_pix.height());
	}
	emit signal_tailed_done(m_pix);
	QDialog::accept();
}

void CPixtureTailor::mInitUI() {
	QVBoxLayout * layout = new QVBoxLayout;
	ui.frame->setLayout(layout);
	this->setFixedSize(800, 600);

	m_view = new CPixView(this);
	layout->addWidget(m_view);
	m_scene = new CPixScene(this);
	m_view->setScene(m_scene);
	m_view->setPixScene(m_scene);
	m_pixItem = new QGraphicsPixmapItem;
	m_scene->addItem(m_pixItem);
	m_pixItem->setPos(0, 0);
}

void CPixView::wheelEvent(QWheelEvent *event) {
	int numDegrees = event->delta() / 8;
	int numSteps = numDegrees / 15;
	float s = 1 + ((float)numSteps) / 10;
	this->scale(s, s);
}

void CPixView::mousePressEvent(QMouseEvent *event) {
	m_scene->removeItem(m_rect);
	if (event->button() != Qt::LeftButton) return;
	m_isStart = true;
	QPointF pos = this->mapToScene(event->pos());
	m_startPoint = pos;
	m_scene->addItem(m_rect);
}

void CPixView::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() != Qt::LeftButton) return;
	m_isStart = false;
}

void CPixView::mouseMoveEvent(QMouseEvent *event) {
	if (!m_isStart) return;
	m_endPoint = this->mapToScene(event->pos());
	m_rect->setRect(m_startPoint.x(), m_startPoint.y(), m_endPoint.x() - m_startPoint.x(),
		m_endPoint.y() - m_startPoint.y());
	m_hasTailed = true;
}