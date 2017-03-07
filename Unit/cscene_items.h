/**************************************************************************
File:         cscene_items.h
Author:       Song Xiaofeng
Date:         2016-05-17
Description:
**************************************************************************/
#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
//////////////////////////////////////////////////////////////////
///    Class:  CSpriteItem
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSpriteItem : public QGraphicsPixmapItem
{
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CSpriteItem();
private:

};

//////////////////////////////////////////////////////////////////
///    Class:  CEllipseItem
///    Brief:  
//////////////////////////////////////////////////////////////////
class CEllipseItem : public QGraphicsPixmapItem
{
	///////////////////////////////////////////////////////////////////
	//all public functions are here
	///////////////////////////////////////////////////////////////////
public:
	CEllipseItem();
private:

};

//////////////////////////////////////////////////////////////////
///    Class:  CRectItem
///    Brief:  
//////////////////////////////////////////////////////////////////
class CRectItem : public QGraphicsPixmapItem
{
	///////////////////////////////////////////////////////////////////
	//all public functions are here
	///////////////////////////////////////////////////////////////////
public:
	CRectItem();
private:

};

//////////////////////////////////////////////////////////////////
///    Class:  CPolygonItem
///    Brief:  
//////////////////////////////////////////////////////////////////
class CPolygonItem : public QGraphicsPixmapItem
{
	///////////////////////////////////////////////////////////////////
	//all public functions are here
	///////////////////////////////////////////////////////////////////
public:
	CPolygonItem();
private:

};