/**************************************************************************
File:         cobject_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cobject_frm.h"
#include <QDrag>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CObjectFrm::CObjectFrm(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	mInitView();
	mSetStyle();
}

CObjectFrm::~CObjectFrm()
{

}

CListWidget::CListWidget() {
	this->setViewMode(QListView::IconMode);
	this->setDragDropMode(QAbstractItemView::NoDragDrop);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CObjectFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 16px;"
	);
}

void CObjectFrm::mInitView() {
	this->setFixedHeight(220);
	m_objectWidget = new CListWidget();
	m_uiWidget = new CListWidget;

	QListWidgetItem * item_sprite = new QListWidgetItem;
	QListWidgetItem * item_ellipse = new QListWidgetItem;
	QListWidgetItem * item_polygon = new QListWidgetItem;
	QListWidgetItem * item_button = new QListWidgetItem;
	QListWidgetItem * item_text = new QListWidgetItem;
	QListWidgetItem * item_picture = new QListWidgetItem;

	item_sprite->setIcon(QIcon(":/picture/ui_picture/objects/sprite.png"));
	item_sprite->setText("Sprite");
	item_ellipse->setIcon(QIcon(":/picture/ui_picture/objects/circle.png"));
	item_ellipse->setText("Ellipse");
	item_polygon->setIcon(QIcon(":/picture/ui_picture/objects/rect.png"));
	item_polygon->setText("Rect");
	item_button->setIcon(QIcon(":/picture/ui_picture/objects/button.png"));
	item_button->setText("Button");
	item_text->setIcon(QIcon(":/picture/ui_picture/objects/text.png"));
	item_text->setText("Text");
	item_picture->setIcon(QIcon(":/picture/ui_picture/objects/picture.png"));
	item_picture->setText("Picture");

	m_objectWidget->addItem(item_sprite);
	m_objectWidget->addItem(item_ellipse);
	m_objectWidget->addItem(item_polygon);
	m_uiWidget->addItem(item_picture);
	m_uiWidget->addItem(item_text);
	m_uiWidget->addItem(item_button);

	m_objectWidget->setParent(ui.widget_object);
	m_uiWidget->setParent(ui.widget_UI);

}

void CListWidget::mouseMoveEvent(QMouseEvent *event) {
	if (this->itemAt(event->pos()) == 0)
		return;
	if (event->buttons() & Qt::LeftButton) {
		int distance = (event->pos() - m_startPos).manhattanLength();
		if (distance >= QApplication::startDragDistance())
			mPerformDrag();
	}
	QListWidget::mouseMoveEvent(event);
}

void CListWidget::mousePressEvent(QMouseEvent *event) {
	QPoint p = event->pos();
	if (this->itemAt(p) == 0)
		return;
	if (event->button() == Qt::LeftButton)
		m_startPos = event->pos();
	QListWidget::mousePressEvent(event);
}

void CListWidget::dragMoveEvent(QDragMoveEvent *event) {
	CListWidget *source =
		qobject_cast<CListWidget *>(event->source());
	if (source && source != this) {
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}
}

void CListWidget::mPerformDrag() {
	QListWidgetItem *item = currentItem();
	if (item) {
		QMimeData *mimeData = new QMimeData;
		mimeData->setText(item->text());
		QDrag *drag = new QDrag(this);
		drag->setMimeData(mimeData);
		QPixmap pix = item->icon().pixmap(QSize(46,46));
		drag->setPixmap(pix);
		if (drag->exec(Qt::CopyAction) == Qt::CopyAction) {
			//delete item;
		}
	}
}