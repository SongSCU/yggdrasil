/**************************************************************************
File:         cnew_file_dlg.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cnew_file_dlg.h"
#include <QDebug>
#include "Controller/cproject_controller.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CNewFileDlg::CNewFileDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.listWidget->setCurrentRow(0);
	this->setAttribute(Qt::WA_DeleteOnClose);
	CProjectController * controller = CProjectController::getInstance();
	connect(this, &CNewFileDlg::signal_new_file, controller, &CProjectController::slot_new_file);
	mSetStyle();
}

CNewFileDlg::~CNewFileDlg()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CNewFileDlg::mSetStyle() {
	this->setStyleSheet(
		//"border: 2px solid gray;"
		//"border-radius: 4px;"
		"font-size: 16px;"
		);
}

///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CNewFileDlg::on_label_scenePix_linkHovered(const QString &link)
{
	qDebug() << "****hover*****";
}

void CNewFileDlg::on_listWidget_clicked(const QModelIndex &index)
{
	QString str_scene;
	str_scene = "this is scene!! this is scene!! this is scene!!";
	QString str_UI;
	str_UI = "this is UI!! this is UI!! this is UI!!";
	QString str_map;
	str_map = "this is map!! this is map!! this is map!!";
	QString str_script;
	str_script = "this is script!! this is script!! this is script!!";
	if (index.row() == 0)
		ui.textBrowser_describe->setText(str_scene);
	if (index.row() == 1)
		ui.textBrowser_describe->setText(str_script);
	if (index.row() == 2)
		ui.textBrowser_describe->setText(str_UI);
	if (index.row() == 3)
		ui.textBrowser_describe->setText(str_map);
}

void CNewFileDlg::on_pushButton_ok_clicked() {
	QString name = ui.lineEdit_name->text();
	if (name == "") {
		return;
	}
	QString type = ui.listWidget->currentItem()->text();
	emit signal_new_file(name, type);
	QDialog::accept();
}