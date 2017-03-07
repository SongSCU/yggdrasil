/**************************************************************************
File:         utilities.h
Author:       Song Xiaofeng
Date:         2016-05-19
Description:
**************************************************************************/
#pragma once
#include <QFrame>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QLabel>
//////////////////////////////////////////////////////////////////
///    Class:  CScrollButton
///    Brief:  
//////////////////////////////////////////////////////////////////
class CScrollButton : public QFrame{
	Q_OBJECT
	///////////////////////////////////////////////////////////////////
	//all public functions are here
	///////////////////////////////////////////////////////////////////
public:
	CScrollButton( QWidget * target, QString text, QWidget * parent = Q_NULLPTR );
	void setText(QString text) { m_text = text; }
	void setTarget(QWidget * target) { m_target = target; }
	///////////////////////////////////////////////////////////////////
	//all private functions are here
	///////////////////////////////////////////////////////////////////
private:
	void mousePressEvent(QMouseEvent *);
	///////////////////////////////////////////////////////////////////
	//all properties are here
	///////////////////////////////////////////////////////////////////
private:
	QHBoxLayout * m_layout;
	QString m_text;
	QWidget * m_target;
	bool m_isScroll;
	QLabel * m_label_arrow;
};
//////////////////////////////////////////////////////////////////
///    Class:  CUUIDCreator
///    Brief:  
//////////////////////////////////////////////////////////////////
class CUUIDCreator {
public:
	static CUUIDCreator* getInstance() {
		static CUUIDCreator creator;
		return &creator;
	}
	int getUUID() {
		m_uuid++;
		return m_uuid;
	}
private:
	CUUIDCreator():m_uuid(0) {}
private:
	int m_uuid;
};
//////////////////////////////////////////////////////////////////
///    Class:  CSceneIDCreator
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSceneIDCreator {
public:
	static CSceneIDCreator* getInstance() {
		static CSceneIDCreator creator;
		return &creator;
	}
	int getSceneID() {
		m_sceneid++;
		return m_sceneid;
	}
	void resetID() { m_sceneid = 0; }
private:
	CSceneIDCreator() : m_sceneid(0) {}
private:
	int m_sceneid;
};

