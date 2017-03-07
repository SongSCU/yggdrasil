/**************************************************************************
File:         casset_frm.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "casset_frm.h"
#include "controller/cproject_controller.h"
#include "expert/cfile_expert.h"
#include "expert/casset_viewer.h"
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <qdirmodel>
#include <QList>
#include <QFileDialog>
#include "cnew_file_dlg.h"
#include "Manager/casset_manager.h"
#include "Manager/cscene_manager.h"
#include "Unit/basic_data_structure.h"
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CAssetFrm::CAssetFrm(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	this->setFixedHeight(220);
	mSetStyle();
	mCreateMenu();
	this->setMouseTracking(true);
	/////////////////////////////////////////////
	m_tree = ui.treeWidget;
	m_item = 0;
	m_isActive = false;
	m_tree->setMouseTracking(true);
	m_tree->setHeaderLabel("Empty Project");
	m_tree->setDragEnabled(true);
	//////////////////////////////////////////

	/////////////////////////////////////////////
	mBuildAllConnects();

}

CAssetFrm::~CAssetFrm()
{

}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CAssetFrm::slot_project_born(const QString& p_name, const QString& p_path) {
	m_strName = p_name;
	m_strPath = p_path;
	m_isActive = true;
	//mCreateTreeView();
	mCreateTree();
}

void CAssetFrm::slot_project_close() {
	m_tree->setHeaderLabel("Empty Project");
	mDestroyTree();
	this->update();
	m_isActive = false;
}

void CAssetFrm::slot_new_file_accept(const QString &name, const QString &type) {
	/////////////////////////////////////////
	QTreeWidgetItem * item = m_tree->currentItem();
	if (item == 0) {
		item = m_item;
	}
	if (item->data(0, EnumDataType::DataType) != "folder") {
		item = item->parent();
	}
	QString path = item->data(0, EnumDataType::DataPath).toString();
	CAssetTreeNode* node = 0;
	//////////////////////////////////////////////////////
	QString tType;
	if (type == "Scene")
		tType = "scene";
	CFileExpert::readTreeRecursively(path + "//" + name + "." + tType, node);
	QTreeWidgetItem * tmp = m_tree->currentItem();
	mRecurCreateTree(node, tmp);
	item->addChild(tmp);
	m_tree->update();
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CAssetFrm::mSetStyle() {
	this->setMinimumSize(100, 100);
	this->setStyleSheet(
		"border: 2px solid gray;"
		"border-radius: 4px;"
		"font-size: 16px;"
	);
}

void CAssetFrm::mCreateTree() {
	m_tree->setHeaderLabel(m_strName);
	CAssetTreeNode* node = 0;
	QString path = m_strPath + "/" + m_strName + "/assets";
	CFileExpert::readTreeRecursively(path, node);
	//CFileExpert::readTreeRecursively("C:/Users/Administrator/Desktop/sss/assets",node);
	mRecurCreateTree(node, m_item);
	m_tree->addTopLevelItem(m_item);
}

void CAssetFrm::mCreateTreeView() {
	QDirModel *model = new QDirModel;
	m_treeView = new QTreeView(this);
	m_treeView->setModel(model);
	m_treeView->setRootIndex(model->index(m_strPath + "/" + m_strName + "/assets"));
}

void CAssetFrm::mCreateMenu() {
	m_menu = new QMenu(this);
	m_action_newFile = new QAction("new file", this);
	m_action_newFolder = new QAction("new folder", this);
	m_action_delte = new QAction("delete", this);
	m_action_importFolder = new QAction("import folder", this);
	m_action_importFile = new QAction("import file", this);
	m_action_openFolder = new QAction("open folder", this);
	m_action_rename = new QAction("rename", this);
	m_menu->addAction(m_action_newFile);
	m_menu->addAction(m_action_newFolder);
	m_menu->addAction(m_action_importFolder);
	m_menu->addAction(m_action_importFile);
	m_menu->addAction(m_action_openFolder);
	m_menu->addAction(m_action_delte);
	m_menu->addAction(m_action_rename);
}

void CAssetFrm::mDestroyTree() {
	if (m_item != 0)
		delete m_item;
	m_item = 0;
}

void CAssetFrm::mRecurCreateTree(CAssetTreeNode* node, QTreeWidgetItem* (&item)) {
	if (node == 0) {
		item = 0;
		return;
	}
	//////////////////////////////////////////////////
	item = new QTreeWidgetItem();
	item->setText(0, node->data.name);
	item->setData(0, EnumDataType::DataId, node->data.id);
	item->setData(0, EnumDataType::DataName, node->data.name);
	item->setData(0, EnumDataType::DataPath, node->data.path);
	item->setData(0, EnumDataType::DataType, node->data.type);
	//////////////////////////////////////////////
	QString s = node->data.type;
	if (s == "txt")
		node->data.type = "text";
	if ((s == "png") || (s == "jpg") || (s == "jpeg") || (s == "bmp"))
		node->data.type = "picture";

	/////////////////////////////////////////////////
	if (node->data.type == "folder")
		item->setIcon(0, QIcon(":/picture/ui_picture/folder.png"));
	else if (node->data.type == "picture")
		item->setIcon(0, QIcon(":/picture/ui_picture/objects/picture.png"));
	else if (node->data.type == "text")
		item->setIcon(0, QIcon(":/picture/ui_picture/objects/text.png"));
	else if (node->data.type == "scene")
		item->setIcon(0, QIcon(":/picture/ui_picture/file/scene.png"));
	////////////////////////////////////////////////////
	QTreeWidgetItem * lchild;
	mRecurCreateTree(node->lchild, lchild);
	item->addChild(lchild);
	//////////////////////////////////////////////////////
	CAssetTreeNode* tmp = node->lchild;
	if (tmp == 0)
		return;
	else {
		for (tmp = tmp->rsibling; tmp != 0; tmp = tmp->rsibling) {
			QTreeWidgetItem * rchilds;
			mRecurCreateTree(tmp, rchilds);
			item->addChild(rchilds);
		}
	}
	//////////////////////////////////////////////////////
}

void CAssetFrm::contextMenuEvent(QContextMenuEvent * event) {
	QCursor cur = this->cursor();
	m_menu->setEnabled(m_isActive);
	m_menu->exec(cur.pos());
}

void CAssetFrm::mBuildAllConnects()
{
	//connect(m_tree, &QTreeWidget::itemEntered, 
	//  this, &CAssetFrm::on_treeWidget_itemEntered);
	connect(m_tree, &QTreeWidget::itemDoubleClicked,
		this, &CAssetFrm::on_treeWidget_itemDoubleClicked);
	///////////////////////////////////////////////////
	CProjectController *controller = CProjectController::getInstance();
	//connect(controller, &CProjectController::signal_new_project, 
	//  this, &CAssetFrm::slot_project_born);
	connect(controller, &CProjectController::signal_project_born,
		this, &CAssetFrm::slot_project_born);
	connect(controller, &CProjectController::signal_project_close,
		this, &CAssetFrm::slot_project_close);
	connect(this, &CAssetFrm::signal_load_scene,
		controller, &CProjectController::slot_load_scene);
	connect(this, &CAssetFrm::signal_insert_db,
		controller, &CProjectController::slot_insert_db);
	connect(this, &CAssetFrm::signal_delete_db,
		controller, &CProjectController::slot_delete_db);
	connect(controller, &CProjectController::signal_new_file_accept,
		this, &CAssetFrm::slot_new_file_accept);
	//////////////////////////////////////////////////////
	connect(m_action_delte, &QAction::triggered,
		this, &CAssetFrm::on_action_delete_triggered);
	connect(m_action_importFolder, &QAction::triggered,
		this, &CAssetFrm::on_action_import_folder_triggered);
	connect(m_action_importFile, &QAction::triggered,
		this, &CAssetFrm::on_action_import_file_triggered);
	connect(m_action_newFile, &QAction::triggered,
		this, &CAssetFrm::on_action_newFile_triggered);
}

///////////////////////////////////////////////////////////////////
//all private slots are here
///////////////////////////////////////////////////////////////////
void CAssetFrm::on_treeWidget_itemEntered(QTreeWidgetItem * item, int col)
{

}

void CAssetFrm::on_treeWidget_itemDoubleClicked(QTreeWidgetItem * item, int col) {
	static bool click = true;
	click = !click;
	if (!click)
		return;
	QString path = item->data(col, EnumDataType::DataPath).toString();
	QString type = item->data(col, EnumDataType::DataType).toString();
	QPointF point;
	QCursor cur = this->cursor();
	point.setX(this->pos().x() + this->width());
	point.setY(cur.pos().y());

	if (type != "scene")
		CAssetViewer::sPreViewFile(path, type, point);
	else {
		emit signal_load_scene(path);
	}
}

void CAssetFrm::on_action_delete_triggered() {

	QTreeWidgetItem * item = m_tree->currentItem();
	if (item == m_item)
		return;
	QString path;
	path = item->data(0, EnumDataType::DataPath).toString();
	delete item;
	m_tree->update();
	/////////////////////////////
	emit signal_delete_db("asset", path);
	/////////////////////////////
	QFileInfo srcInfo(path);
	if (srcInfo.isDir())
		CFileExpert::deleteDir(path);
	else if (srcInfo.isFile()) {
		CFileExpert::deleteFile(path);
	}
}

void CAssetFrm::on_action_import_folder_triggered() {
	/////////////////////////////////////////
	QTreeWidgetItem * item = m_tree->currentItem();
	if (item->data(0, EnumDataType::DataType) != "folder") {
		item = item->parent();
	}
	QString desPath = item->data(0, EnumDataType::DataPath).toString();

	CAssetTreeNode* node = 0;
	QString path = QFileDialog::getExistingDirectory(
		this,
		tr("select path"),
		"",
		QFileDialog::DontResolveSymlinks
	);
	if (path == "")
		return;
	QFileInfo srcInfo(path);
	QString srcName = srcInfo.fileName();
	for (int i = 0; i < item->childCount(); i++) {
		QTreeWidgetItem* tmp = item->child(i);
		QString pathTmp = tmp->data(0, EnumDataType::DataPath).toString();
		if (path == pathTmp) {
			//QMessageBox::
			return;
		}
	}
	//////////////////////////////////////////////////////////
	bool b = CFileExpert::copyRecursively(path, desPath + "//" + srcName);
	/////////////////////////////////////////////////////
	CFileExpert::readTreeRecursively(desPath + "//" + srcName, node);
	QTreeWidgetItem * tmp = m_tree->currentItem();
	mRecurCreateTree(node, tmp);
	item->addChild(tmp);
	m_tree->update();
	/////////////////////////////////////////////////////////
	emit signal_insert_db("asset", desPath + "//" + srcName);
}

void CAssetFrm::on_action_import_file_triggered() {
	/////////////////////////////////////////
	QTreeWidgetItem * item = m_tree->currentItem();
	if (item->data(0, EnumDataType::DataType) != "folder") {
		item = item->parent();
	}
	QString desPath = item->data(0, EnumDataType::DataPath).toString();

	CAssetTreeNode* node = 0;
	QString path = QFileDialog::getOpenFileName(
		this,
		tr("select path"),
		"",
		tr("files (*.scene *.png *.mp3 *.wav *.jpg)")
	);
	if (path == "")
		return;

	QFileInfo srcInfo(path);
	QString srcName = srcInfo.fileName();
	for (int i = 0; i < item->childCount(); i++) {
		QTreeWidgetItem* tmp = item->child(i);
		QString pathTmp = tmp->data(0, EnumDataType::DataPath).toString();
		if (path == pathTmp) {
			//QMessageBox::
			return;
		}
	}
	//////////////////////////////////////////////////////////
	bool b = CFileExpert::copyRecursively(path, desPath + "//" + srcName);
	//////////////////////////////////////////////////////
	CFileExpert::readTreeRecursively(desPath + "//" + srcName, node);
	QTreeWidgetItem * tmp = m_tree->currentItem();
	mRecurCreateTree(node, tmp);
	item->addChild(tmp);
	m_tree->update();
	/////////////////////////////////////////////////////////
	emit signal_insert_db("asset", desPath + "//" + srcName);
}

void CAssetFrm::on_action_newFile_triggered() {
	QTreeWidgetItem * item = m_tree->currentItem();
	if (item->data(0, EnumDataType::DataType) != "folder") {
		item = item->parent();
	}
	QString curPath = item->data(0, EnumDataType::DataPath).toString();
	CAssetManager::getInstance()->setCurrentPath(curPath);
	CNewFileDlg *fileDlg = new CNewFileDlg();
	fileDlg->show();
}

