/********************************************************************************
** Form generated from reading UI file 'cobject_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COBJECT_FRM_H
#define UI_COBJECT_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CObjectFrm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget_object;
    QLabel *label_2;
    QWidget *widget_UI;

    void setupUi(QFrame *CObjectFrm)
    {
        if (CObjectFrm->objectName().isEmpty())
            CObjectFrm->setObjectName(QStringLiteral("CObjectFrm"));
        CObjectFrm->resize(491, 257);
        CObjectFrm->setMinimumSize(QSize(0, 220));
        CObjectFrm->setFrameShape(QFrame::StyledPanel);
        CObjectFrm->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(CObjectFrm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CObjectFrm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        widget_object = new QWidget(CObjectFrm);
        widget_object->setObjectName(QStringLiteral("widget_object"));
        widget_object->setStyleSheet(QStringLiteral("background-color:gray"));

        verticalLayout->addWidget(widget_object);

        label_2 = new QLabel(CObjectFrm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        widget_UI = new QWidget(CObjectFrm);
        widget_UI->setObjectName(QStringLiteral("widget_UI"));
        widget_UI->setStyleSheet(QStringLiteral("background-color:gray"));

        verticalLayout->addWidget(widget_UI);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 3);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CObjectFrm);

        QMetaObject::connectSlotsByName(CObjectFrm);
    } // setupUi

    void retranslateUi(QFrame *CObjectFrm)
    {
        CObjectFrm->setWindowTitle(QApplication::translate("CObjectFrm", "\345\257\271\350\261\241", 0));
        label->setText(QApplication::translate("CObjectFrm", "2D \345\257\271\350\261\241", 0));
        label_2->setText(QApplication::translate("CObjectFrm", "UI \346\216\247\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class CObjectFrm: public Ui_CObjectFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COBJECT_FRM_H
