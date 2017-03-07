/********************************************************************************
** Form generated from reading UI file 'cattribute_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATTRIBUTE_FRM_H
#define UI_CATTRIBUTE_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAttributeFrm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_iType;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_type;
    QLabel *label_type_con;

    void setupUi(QFrame *CAttributeFrm)
    {
        if (CAttributeFrm->objectName().isEmpty())
            CAttributeFrm->setObjectName(QStringLiteral("CAttributeFrm"));
        CAttributeFrm->resize(474, 150);
        CAttributeFrm->setMaximumSize(QSize(16777215, 150));
        CAttributeFrm->setStyleSheet(QStringLiteral("background-color: #404040"));
        gridLayout = new QGridLayout(CAttributeFrm);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(CAttributeFrm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_iType = new QLabel(CAttributeFrm);
        label_iType->setObjectName(QStringLiteral("label_iType"));

        verticalLayout->addWidget(label_iType);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_name = new QLabel(CAttributeFrm);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(CAttributeFrm);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit_name);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_type = new QLabel(CAttributeFrm);
        label_type->setObjectName(QStringLiteral("label_type"));

        horizontalLayout_2->addWidget(label_type);

        label_type_con = new QLabel(CAttributeFrm);
        label_type_con->setObjectName(QStringLiteral("label_type_con"));
        label_type_con->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_type_con);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);

        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(CAttributeFrm);

        QMetaObject::connectSlotsByName(CAttributeFrm);
    } // setupUi

    void retranslateUi(QFrame *CAttributeFrm)
    {
        CAttributeFrm->setWindowTitle(QApplication::translate("CAttributeFrm", "CAttributeFrm", 0));
        label->setText(QApplication::translate("CAttributeFrm", "Basic Attribute", 0));
        label_iType->setText(QApplication::translate("CAttributeFrm", "NULL", 0));
        label_name->setText(QApplication::translate("CAttributeFrm", "Name", 0));
        lineEdit_name->setText(QApplication::translate("CAttributeFrm", "NULL", 0));
        label_type->setText(QApplication::translate("CAttributeFrm", "Type", 0));
        label_type_con->setText(QApplication::translate("CAttributeFrm", "NULL", 0));
    } // retranslateUi

};

namespace Ui {
    class CAttributeFrm: public Ui_CAttributeFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATTRIBUTE_FRM_H
