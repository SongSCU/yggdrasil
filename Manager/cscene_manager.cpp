/**************************************************************************
File:         cscene_manager.cpp
Author:       Song Xiaofeng
Date:         2016-05-14
Description:
**************************************************************************/
#include "cscene_manager.h"
#include <QGraphicsPixmapItem>
#include "Unit/basic_data_structure.h"
#include "Unit/utilities.h"
#include <QXmlStreamWriter>

const QString Default_PixPath = ":/picture/ui_picture/objects/sprite_big.png";
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CSceneManager * CSceneManager::getInstance() {
	static CSceneManager manager;
	return &manager;
}

CScene * CSceneManager::loadScene(const QString& path) {

	m_scene = new CScene();

	QXmlStreamReader reader;
	QFile file(path);
	if (!file.open(QFile::ReadOnly)) {
		return m_scene;
	}
	reader.setDevice(&file);
	QStringRef eName;
	CSpriteItem * item;
	while (!reader.atEnd()) {
		reader.readNext();
		if (reader.isStartElement()) {
			eName = reader.name();
			if (eName == "item") {
				item = new CSpriteItem;
				m_scene->addItem(item);
			}
			else if (eName == "basic") {
				QString type = reader.attributes().value("type").toString();
				QString path = reader.attributes().value("path").toString();
				QString name = reader.attributes().value("name").toString();
				QString id = reader.attributes().value("id").toString();
				double depth = reader.attributes().value("depth").toDouble();
				item->setData(EnumDataType::DataName, name);
				item->setData(EnumDataType::DataId, id);
				item->setData(EnumDataType::DataPath, path);
				item->setData(EnumDataType::DataType, type);
				item->setZValue(depth);
			}
			else if (eName == "transform") {
				QString posX = reader.attributes().value("posX").toString();
				QString posY = reader.attributes().value("posY").toString();
				double rot = reader.attributes().value("rot").toDouble();
				item->setPos(posX.toDouble(), posY.toDouble());
				item->setRotation(rot);
			}
			else if (eName == "sprite_render") {
				QString pixPath = reader.attributes().value("pixPath").toString();
				QString hasRect = reader.attributes().value("hasRect").toString();
				item->setData(EnumDataType::PixPath, pixPath);
				if (hasRect == "true") {
					int rectX = reader.attributes().value("rectX").toInt();
					int rectY = reader.attributes().value("rectY").toInt();
					int rectW = reader.attributes().value("rectW").toInt();
					int rectH = reader.attributes().value("rectH").toInt();
					QPixmap pix(pixPath);
					pix = pix.copy(rectX, rectY, rectW, rectH);
					item->setPixmap(pix);
					item->setData(EnumSpriteType::PixRect, QVariant(QRect(rectX, rectY, rectW, rectH)));
					item->setData(EnumSpriteType::BHasRect, QVariant(true));
				}
				else {
					item->setPixmap(QPixmap(pixPath));
					item->setData(EnumSpriteType::BHasRect, QVariant(false));
				}
			}


		}
		else if (reader.hasError()) {
			return false;
		}
	}
	file.close();
	m_isSceneLoaded = true;
	return m_scene;
}

bool CSceneManager::saveScene(const QString& path) {
	if (!m_isSceneLoaded)
		return true;
	QList<QGraphicsItem*> items = m_scene->items();
	QFile file(m_path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		return false;
	}
	QXmlStreamWriter writer(&file);
	writer.setAutoFormatting(true);
	writer.writeStartDocument("1.0");
	writer.writeStartElement("scene");
	writer.writeStartElement("items");
	for (int i = 0; i < items.length(); i++) {
		QGraphicsItem * tmp = items[i];
		QString type = tmp->data(EnumDataType::DataType).toString();
		QString path = tmp->data(EnumDataType::DataPath).toString();
		QString name = tmp->data(EnumDataType::DataName).toString();
		QString id = tmp->data(EnumDataType::DataId).toString();
		QString depth = QString::number(tmp->zValue());
		QPointF pos = tmp->pos();
		double rot = tmp->rotation();
		QString pixPath = tmp->data(EnumDataType::PixPath).toString();
		bool hasRect = tmp->data(EnumSpriteType::BHasRect).toBool();
		writer.writeStartElement("item");

		writer.writeStartElement("basic");
		writer.writeAttribute("name", name);
		writer.writeAttribute("path", path);
		writer.writeAttribute("type", type);
		writer.writeAttribute("id", id);
		writer.writeAttribute("depth", depth);
		writer.writeEndElement();

		writer.writeStartElement("transform");
		writer.writeAttribute("posX", QString::number(pos.x()));
		writer.writeAttribute("posY", QString::number(pos.y()));
		writer.writeAttribute("rot", QString::number(rot));
		writer.writeEndElement();

		writer.writeStartElement("sprite_render");
		writer.writeAttribute("pixPath", pixPath);
		if (hasRect) {
			writer.writeAttribute("hasRect", "true");
		}
		else {
			writer.writeAttribute("hasRect", "false");
		}

		if (hasRect) {
			QRect pixRect = tmp->data(EnumSpriteType::PixRect).toRect();
			writer.writeAttribute("rectX", QString::number(pixRect.x()));
			writer.writeAttribute("rectY", QString::number(pixRect.y()));
			writer.writeAttribute("rectW", QString::number(pixRect.width()));
			writer.writeAttribute("rectH", QString::number(pixRect.height()));
		}
		writer.writeEndElement();
		writer.writeEndElement();
	}
	writer.writeEndElement();
	writer.writeEndElement();
	writer.writeEndDocument();
	file.close();

	m_logManager->printLog("Scene is saved!", 0);
	return true;
}

void CSceneManager::closeScene() {
	this->destroyed(m_scene);
	m_scene = 0;
	m_isSceneLoaded = false;
}
///////////////////////////////////////////////////////////////////
//all public slots are here
///////////////////////////////////////////////////////////////////
void CSceneManager::slot_load_scene(const QString &path) {
	saveScene("");
	closeScene();
	m_scene = loadScene(path);
	m_path = path;
	emit signal_show_scene(m_scene);
	emit signal_load_hierarchy(m_scene);
	//m_logManager->printLog("Scene is opened!", 0);
}

void CSceneManager::slot_add_item(const QString &type, const QPointF &pos) {

	if (type == "Sprite") {
		CSpriteItem *item = new CSpriteItem;
		int id = CSceneIDCreator::getInstance()->getSceneID();
		item->setData(EnumDataType::DataType, "sprite");
		item->setData(EnumDataType::DataId, id);
		item->setData(EnumDataType::DataName, QString("sprite%1").arg(QString::number(id)));
		item->setData(EnumDataType::PixPath, Default_PixPath);
		item->setData(EnumSpriteType::BHasRect, QVariant(bool(false)));
		item->setPos(pos);
		m_scene->addItem(item);
		//emit signal_update_hierarchy(item, 0);
		emit signal_item_added(item);
	}
}

void CSceneManager::slot_delete_item() {
	QList<int> hList;
	QList<QGraphicsItem *> list = m_scene->selectedItems();
	for (int i = 0; i < list.length(); i++) {
		hList.push_back(list[i]->data(EnumDataType::DataId).toInt());
		m_scene->removeItem(list[i]);
	}
	emit signal_items_deleted(hList);
}

void CSceneManager::slot_copy_item() {
	QList<QGraphicsItem* > list = m_scene->selectedItems();
	m_toCopiedIetmList = list;
}

void CSceneManager::slot_paste_item() {
	QList<QGraphicsItem*> hList;
	for (QList<QGraphicsItem *>::iterator it = m_toCopiedIetmList.begin(); it != m_toCopiedIetmList.end(); it++) {
		QGraphicsItem * tmp = *it;
		QPointF pos(tmp->x() + 50, tmp->y() + 50);
		QString pixPath = tmp->data(EnumDataType::PixPath).toString();
		bool hasRect = tmp->data(EnumSpriteType::BHasRect).toBool();

		CSpriteItem *item = new CSpriteItem;
		int id = CSceneIDCreator::getInstance()->getSceneID();
		item->setData(EnumDataType::DataType, "sprite");
		item->setData(EnumDataType::DataId, id);
		item->setData(EnumDataType::DataName, QString("sprite%1").arg(QString::number(id)));
		item->setData(EnumDataType::PixPath, pixPath);
		if (!hasRect)
			item->setData(EnumSpriteType::BHasRect, QVariant(false));
		else {
			item->setData(EnumSpriteType::BHasRect, QVariant(true));
			item->setData(EnumSpriteType::PixRect, tmp->data(EnumSpriteType::PixRect));
		}
		item->setPos(pos);
		QPixmap pix(pixPath);
		if (hasRect) {
			pix = pix.copy(item->data(EnumSpriteType::PixRect).toRect());
		}
		item->setPixmap(pix);
		m_scene->addItem(item);
		hList.push_back(item);
	}
	emit signal_items_added(hList);
}

void CSceneManager::slot_save_scene(const QString &path) {
	saveScene(path);
}

void CSceneManager::slot_item_selected(int _id) {
	/*QList<QGraphicsItem*> items = m_scene->items();
	for (QList<QGraphicsItem*>::iterator it = items.begin(); it != items.end(); it++) {
		QGraphicsItem * tmp = *it;
		tmp->setSelected(false);
		int id = tmp->data(EnumSpriteType::DataId).toInt();
		if (id == _id) {
			tmp->setSelected(true);
		}
	}*/
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
CSceneManager::CSceneManager(QObject * parent) : QObject(parent), m_path(""), m_scene(NULL), m_isSceneLoaded(false) {
	m_logManager = CLogManager::getInstance();
}

CSceneManager::~CSceneManager() {

}
