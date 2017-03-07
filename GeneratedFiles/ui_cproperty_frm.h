/********************************************************************************
** Form generated from reading UI file 'cproperty_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPROPERTY_FRM_H
#define UI_CPROPERTY_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CPropertyFrm
{
public:
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QLabel *label_13;
    QLineEdit *lineEdit_8;

    void setupUi(QFrame *CPropertyFrm)
    {
        if (CPropertyFrm->objectName().isEmpty())
            CPropertyFrm->setObjectName(QStringLiteral("CPropertyFrm"));
        CPropertyFrm->resize(350, 300);
        CPropertyFrm->setMinimumSize(QSize(350, 0));
        CPropertyFrm->setMaximumSize(QSize(350, 16777215));
        CPropertyFrm->setStyleSheet(QStringLiteral(""));
        CPropertyFrm->setFrameShape(QFrame::StyledPanel);
        CPropertyFrm->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(CPropertyFrm);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(CPropertyFrm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/picture/ui_picture/objects/sprite.png")));

        horizontalLayout_4->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CPropertyFrm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(CPropertyFrm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(CPropertyFrm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(CPropertyFrm);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_3 = new QLabel(CPropertyFrm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 100));
        label_3->setStyleSheet(QStringLiteral(""));

        verticalLayout_6->addWidget(label_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(CPropertyFrm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        label_6 = new QLabel(CPropertyFrm);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEdit_3 = new QLineEdit(CPropertyFrm);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_5->addWidget(lineEdit_3);

        label_7 = new QLabel(CPropertyFrm);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        lineEdit_4 = new QLineEdit(CPropertyFrm);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_5->addWidget(lineEdit_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(CPropertyFrm);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        label_9 = new QLabel(CPropertyFrm);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        lineEdit_5 = new QLineEdit(CPropertyFrm);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_6->addWidget(lineEdit_5);

        label_10 = new QLabel(CPropertyFrm);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_6->addWidget(label_10);

        lineEdit_6 = new QLineEdit(CPropertyFrm);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_6->addWidget(lineEdit_6);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(CPropertyFrm);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        label_12 = new QLabel(CPropertyFrm);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_7->addWidget(label_12);

        lineEdit_7 = new QLineEdit(CPropertyFrm);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_7->addWidget(lineEdit_7);

        label_13 = new QLabel(CPropertyFrm);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_7->addWidget(label_13);

        lineEdit_8 = new QLineEdit(CPropertyFrm);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_7->addWidget(lineEdit_8);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(CPropertyFrm);

        QMetaObject::connectSlotsByName(CPropertyFrm);
    } // setupUi

    void retranslateUi(QFrame *CPropertyFrm)
    {
        CPropertyFrm->setWindowTitle(QApplication::translate("CPropertyFrm", "Frame", 0));
        label_4->setText(QString());
        label->setText(QApplication::translate("CPropertyFrm", "Name", 0));
        lineEdit->setText(QApplication::translate("CPropertyFrm", "Player", 0));
        label_2->setText(QApplication::translate("CPropertyFrm", "Type", 0));
        lineEdit_2->setText(QApplication::translate("CPropertyFrm", "Sprite", 0));
        label_3->setText(QApplication::translate("CPropertyFrm", "Transform", 0));
        label_5->setText(QApplication::translate("CPropertyFrm", "Position ", 0));
        label_6->setText(QApplication::translate("CPropertyFrm", "X ", 0));
        lineEdit_3->setText(QApplication::translate("CPropertyFrm", "2.0", 0));
        label_7->setText(QApplication::translate("CPropertyFrm", "Y", 0));
        lineEdit_4->setText(QApplication::translate("CPropertyFrm", "2.0", 0));
        label_8->setText(QApplication::translate("CPropertyFrm", "Rotatio n", 0));
        label_9->setText(QApplication::translate("CPropertyFrm", "X ", 0));
        lineEdit_5->setText(QApplication::translate("CPropertyFrm", "30", 0));
        label_10->setText(QApplication::translate("CPropertyFrm", "Y", 0));
        lineEdit_6->setText(QApplication::translate("CPropertyFrm", "30", 0));
        label_11->setText(QApplication::translate("CPropertyFrm", "Scale    ", 0));
        label_12->setText(QApplication::translate("CPropertyFrm", "X ", 0));
        lineEdit_7->setText(QApplication::translate("CPropertyFrm", "2.0", 0));
        label_13->setText(QApplication::translate("CPropertyFrm", "Y", 0));
        lineEdit_8->setText(QApplication::translate("CPropertyFrm", "2.0", 0));
    } // retranslateUi

};

namespace Ui {
    class CPropertyFrm: public Ui_CPropertyFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPROPERTY_FRM_H
