/**************************************************************************
File:         cmain_win.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "cmain_win.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
//CMainWin::CMainWin(QWidget *parent)
//CMainWin::~CMainWin()
///////////////////////////////////////////////////////////////////
CMainWin::CMainWin(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	mCreateWindows();
	mSetStyle();
	mBuildAllConnects();

}

CMainWin::~CMainWin()
{

}
///////////////////////////////////////////////////////////////////
//all private functions are here
////void CMainWin::mSetStyle()
////void CMainWin::mCreateWindows()
///////////////////////////////////////////////////////////////////
void CMainWin::mSetStyle() {
	this->setWindowIcon(QIcon(":/icon_ygg"));
	this->setStyleSheet("font-size: 16px");
}

void CMainWin::mCreateWindows() {
	CAssetFrm *asset_frm = new CAssetFrm(this);
	CConsoleFrm *console_frm = new CConsoleFrm(this);
	CHierarchyFrm *hierarchy_frm = new CHierarchyFrm(this);
	CPropertyFrm *property_frm = new CPropertyFrm(this);
	CObjectFrm *object_frm = new CObjectFrm(this);
	CSceneFrm *scene_frm = new CSceneFrm(this);
	this->setCentralWidget(scene_frm);

	m_dockObjectFrm = new QDockWidget();
	m_dockObjectFrm->setWindowTitle(tr("Object"));
	m_dockObjectFrm->setFeatures(QDockWidget::AllDockWidgetFeatures);
	m_dockObjectFrm->setWidget(object_frm);

	m_dockPropertyFrm = new QDockWidget();
	m_dockPropertyFrm->setWindowTitle(tr("Property"));
	m_dockPropertyFrm->setFeatures(QDockWidget::AllDockWidgetFeatures);
	m_dockPropertyFrm->setWidget(property_frm);

	m_dockConsoleFrm = new QDockWidget();
	m_dockConsoleFrm->setWindowTitle(tr("Console"));
	m_dockConsoleFrm->setFeatures(QDockWidget::AllDockWidgetFeatures);
	m_dockConsoleFrm->setWidget(console_frm);

	m_dockAssetFrm = new QDockWidget();
	m_dockAssetFrm->setWindowTitle(tr("Asset"));
	m_dockAssetFrm->setFeatures(QDockWidget::AllDockWidgetFeatures);
	m_dockAssetFrm->setWidget(asset_frm);

	m_dockHierarchyFrm = new QDockWidget();
	m_dockHierarchyFrm->setWindowTitle(tr("Hierarchy"));
	m_dockHierarchyFrm->setFeatures(QDockWidget::AllDockWidgetFeatures);
	m_dockHierarchyFrm->setWidget(hierarchy_frm);




	this->addDockWidget(Qt::RightDockWidgetArea, m_dockPropertyFrm);
	this->addDockWidget(Qt::BottomDockWidgetArea, m_dockHierarchyFrm);
	this->addDockWidget(Qt::BottomDockWidgetArea, m_dockConsoleFrm);
	this->addDockWidget(Qt::LeftDockWidgetArea, m_dockObjectFrm);
	this->addDockWidget(Qt::LeftDockWidgetArea, m_dockAssetFrm);

}

void CMainWin::mBuildAllConnects() {
	m_controller = CProjectController::getInstance();
	connect(this, &CMainWin::signal_close_project, m_controller, &CProjectController::slot_close_project);
	connect(this, &CMainWin::signal_open_project, m_controller, &CProjectController::slot_open_project);
	connect(this, &CMainWin::signal_save_project, m_controller, &CProjectController::slot_save_project);

	connect(ui.action_save, &QAction::triggered, this, &CMainWin::on_action_save_project_triggered);
}
///////////////////////////////////////////////////////////////////
//all private slots are here
////void CMainWin::on_action_object_triggered(bool checked)
////void CMainWin::on_action_asset_triggered(bool checked)
////void CMainWin::on_action_hierarchy_triggered(bool checked)
////void CMainWin::on_action_property_triggered(bool checked)
////void CMainWin::on_action_console_triggered(bool checked)
////void CMainWin::on_action_newFile_triggered()
////void CMainWin::on_action_newProject_triggered()
///////////////////////////////////////////////////////////////////
void CMainWin::on_action_object_triggered(bool checked)
{
	m_dockObjectFrm->setVisible(checked);
}

void CMainWin::on_action_asset_triggered(bool checked)
{
	m_dockAssetFrm->setVisible(checked);
}

void CMainWin::on_action_hierarchy_triggered(bool checked)
{
	m_dockHierarchyFrm->setVisible(checked);
}

void CMainWin::on_action_property_triggered(bool checked)
{
	m_dockPropertyFrm->setVisible(checked);
}

void CMainWin::on_action_console_triggered(bool checked)
{
	m_dockConsoleFrm->setVisible(checked);
}

void CMainWin::on_action_newFile_triggered()
{
	CAssetManager * manager = CAssetManager::getInstance();
	manager->setCurrentPath(manager->assetPath());
	CNewFileDlg *fileDlg = new CNewFileDlg(this);
	fileDlg->show();
}

void CMainWin::on_action_openProject_triggered() {
	QString str = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		"",
		tr("ProjectFile (*.ygg)")
	);
	QString path = str;
	emit signal_open_project(path);
}

void CMainWin::on_action_closeProject_triggered()
{
	emit signal_close_project();
}

void CMainWin::on_action_newProject_triggered()
{
	CNewProjectDlg *dialog_project = new CNewProjectDlg(this);
	dialog_project->show();
}

void CMainWin::on_action_save_project_triggered(){
	emit signal_save_project("");
}
