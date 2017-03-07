/**************************************************************************
File:         cscene_items.cpp
Author:       Song Xiaofeng
Date:         2016-05-17
Description:
**************************************************************************/
#include "cscene_items.h"
#include <QPen>

///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CSpriteItem::CSpriteItem() {
	this->setPixmap(QPixmap(":/picture/ui_picture/objects/sprite_big.png"));
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

CRectItem::CRectItem() {
	//this->setRect(0, 0, 100, 100);
	//this->setPen(QPen(QBrush(Qt::black), 4));
	//this->setPixmap(QPixmap(":/picture/ui_picture/objects/rect_big.png"));
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

CEllipseItem::CEllipseItem() {
	//this->setRect(0, 0, 100, 100);
	//this->setPen(QPen(QBrush(Qt::black), 4));
	//this->setPixmap(QPixmap(":/picture/ui_picture/objects/circle_big.png"));
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

CPolygonItem::CPolygonItem() {

	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
}
