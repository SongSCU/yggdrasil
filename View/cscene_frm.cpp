/**************************************************************************
File:         cscene_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cscene_frm.h"
#include <QtWidgets/QGraphicsPixmapItem>
#include <QMimeData>
#include <fstream>
bool g_isActive = false;
///////////////////////////////////////////////////////////////////
//all public functions are here 
///////////////////////////////////////////////////////////////////
CSceneView::CSceneView(QWidget* parent) :m_isKeyCtrlPressed(false) {
	this->setParent(parent);
	this->setSceneRect(-5000, -5000, 10000, 10000);
	this->setDragMode(QGraphicsView::RubberBandDrag);
	this->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setAcceptDrops(true);
	this->setMouseTracking(true);
	this->show();

	mBuildConnects();
}


CSceneFrm::CSceneFrm(QWidget *parent)
	: QFrame(parent) {
	//ui.setupUi(this);
	mSetStyle();
	mBuildAllConnects();
	mInitUI();
}

CSceneFrm::~CSceneFrm() {

}
///////////////////////////////////////////////////////////////////
//all private slots  are here
///////////////////////////////////////////////////////////////////
void CSceneFrm::slot_show_scene(QGraphicsScene* scene) {
	m_scene = (CScene*)scene;
	m_view->setScene(scene);
	g_isActive = true;
}

void CSceneFrm::on_action_move_triggered() {
	m_view->setDragMode(QGraphicsView::ScrollHandDrag);
}

void CSceneFrm::on_action_select_triggered() {
	m_view->setDragMode(QGraphicsView::RubberBandDrag);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CSceneFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 1px solid gray;"
		"border-radius: 1px;"
		"font-size: 16px;"
	);
}

void CSceneFrm::mInitScene() {
	m_scene = new CScene(this);
	m_view->setScene(m_scene);
}

void CSceneFrm::mBuildAllConnects() {
	m_controller = CProjectController::getInstance();
	connect(m_controller, &CProjectController::signal_show_scene,
		this, &CSceneFrm::slot_show_scene);
}

void CSceneFrm::mInitUI() {
	g_isActive = false;
	m_view = new CSceneView(this);
	m_layout = new QVBoxLayout(this);
	m_toolBar = new QToolBar(this);

	m_layout->addWidget(m_toolBar);
	m_layout->addWidget(m_view);

	mInitToolBar();
	mInitScene();
}

void CSceneFrm::mInitToolBar() {
	QAction * action_select = new QAction(this);
	action_select->setIcon(QIcon(":/picture/ui_picture/toolBar/arrow.png"));

	QAction * action_move = new QAction(m_toolBar);
	action_move->setIcon(QIcon(":/picture/ui_picture/toolBar/hand.png"));

	m_toolBar->addAction(action_move);
	m_toolBar->addAction(action_select);

	connect(action_move, &QAction::triggered, this, &CSceneFrm::on_action_move_triggered);
	connect(action_select, &QAction::triggered, this, &CSceneFrm::on_action_select_triggered);
}

void CSceneView::wheelEvent(QWheelEvent *event) {
	int numDegrees = event->delta() / 8;
	int numSteps = numDegrees / 15;
	float s = 1 + ((float)numSteps) / 10;
	this->scale(s, s);
}

void CSceneView::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		this->setDragMode(QGraphicsView::ScrollHandDrag);
		QMouseEvent e(event->type(), event->localPos(), event->windowPos(), event->screenPos(), Qt::LeftButton,
			event->buttons(), event->modifiers(), event->source());
		QGraphicsView::mousePressEvent(&e);
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}

void CSceneView::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::RightButton) {
		QMouseEvent e(event->type(), event->localPos(), event->windowPos(), event->screenPos(), Qt::LeftButton,
			event->buttons(), event->modifiers(), event->source());
		QGraphicsView::mouseReleaseEvent(&e);
		this->setDragMode(QGraphicsView::RubberBandDrag);
	}
	else {
		QGraphicsView::mouseReleaseEvent(event);
	}
}

void CSceneView::mouseMoveEvent(QMouseEvent *event) {
	QGraphicsView::mouseMoveEvent(event);
}

void CSceneView::dragEnterEvent(QDragEnterEvent *event) {
	event->acceptProposedAction();
}

void CSceneView::dropEvent(QDropEvent *event) {

	QPoint p = event->pos();
	QPointF ps = QGraphicsView::mapToScene(p);
	QString type = event->mimeData()->text();
	if (g_isActive)
		emit signal_add_item(type, ps);
	event->accept();
}

void CSceneView::dragMoveEvent(QDragMoveEvent *event) {
	event->accept();
}

void CSceneView::keyReleaseEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Delete) {
		emit signal_delete_item();
		return;
	}
	if (event->key() == Qt::Key_Control) {
		m_isKeyCtrlPressed = false;
		return;
	}
	if (event->key() == Qt::Key_C) {
		if (m_isKeyCtrlPressed) {
			emit signal_copy_item();
		}
		else
			return;
	}
	if (event->key() == Qt::Key_V) {
		if (m_isKeyCtrlPressed) {
			emit signal_paste_item();
		}
		else
			return;
	}
	QGraphicsView::keyReleaseEvent(event);
}

void CSceneView::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Control) {
		m_isKeyCtrlPressed = true;
		return;
	}
	QGraphicsView::keyReleaseEvent(event);
}

void CSceneView::mBuildConnects() {
	CProjectController * controller = CProjectController::getInstance();
	connect(this, &CSceneView::signal_add_item,
		controller, &CProjectController::slot_add_item);
	connect(this, &CSceneView::signal_delete_item,
		controller, &CProjectController::slot_delete_item);
	connect(this, &CSceneView::signal_copy_item,
		controller, &CProjectController::slot_copy_item);
	connect(this, &CSceneView::signal_paste_item,
		controller, &CProjectController::slot_paste_item);
}