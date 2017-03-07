/**************************************************************************
File:         csprite_render_frm.h
Author:       Song Xiaofeng
Date:         2016-05-25
Description:
**************************************************************************/
#pragma once
#include <QFrame>
#include "ui_csprite_render_frm.h"
#include <QGraphicsItem>
#include "Unit/cscene_items.h"
#include "Utility/cpixture_tailor.h"
#include <QPushButton>
//////////////////////////////////////////////////////////////////
///    Class:  CSpriteRenderFrm
///    Brief:  
//////////////////////////////////////////////////////////////////
class CSpriteRenderFrm : public QFrame {
	Q_OBJECT
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
public:
	CSpriteRenderFrm(QWidget * parent = Q_NULLPTR);
	~CSpriteRenderFrm();
	void updateCom(QGraphicsItem * item, int count);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private:
	void mSetStyle();
	void mBuildConnect();
	void mInitUI();
	void mSelectPixArea( const QString& path);
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
private slots:
	void on_button_sel_clicked();
	void slot_tailed_done(QPixmap pix);
///////////////////////////////////////////////////////////////////
//all properties are here
///////////////////////////////////////////////////////////////////
private:
	Ui::CSpriteRenderFrm ui;
	QLabel * m_labelPix;
	QPushButton * m_btnSel;
	CSpriteItem * m_item;
	CPixtureTailor * m_tailor;
};
