/********************************************************************************
** Form generated from reading UI file 'ctransform_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRANSFORM_FRM_H
#define UI_CTRANSFORM_FRM_H

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

class Ui_CTransformFrm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_px;
    QLabel *label_7;
    QLineEdit *lineEdit_py;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_rx;
    QLabel *label_10;
    QLineEdit *lineEdit_ry;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_sw;
    QLabel *label_13;
    QLineEdit *lineEdit_sh;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_rot;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_depth;
    QLineEdit *lineEdit_depth;

    void setupUi(QFrame *CTransformFrm)
    {
        if (CTransformFrm->objectName().isEmpty())
            CTransformFrm->setObjectName(QStringLiteral("CTransformFrm"));
        CTransformFrm->resize(371, 250);
        CTransformFrm->setMaximumSize(QSize(16777215, 250));
        CTransformFrm->setStyleSheet(QStringLiteral("background-color: #404040"));
        verticalLayout_2 = new QVBoxLayout(CTransformFrm);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(CTransformFrm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(CTransformFrm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        label_6 = new QLabel(CTransformFrm);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEdit_px = new QLineEdit(CTransformFrm);
        lineEdit_px->setObjectName(QStringLiteral("lineEdit_px"));
        lineEdit_px->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(lineEdit_px);

        label_7 = new QLabel(CTransformFrm);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        lineEdit_py = new QLineEdit(CTransformFrm);
        lineEdit_py->setObjectName(QStringLiteral("lineEdit_py"));
        lineEdit_py->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(lineEdit_py);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(CTransformFrm);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        label_9 = new QLabel(CTransformFrm);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        lineEdit_rx = new QLineEdit(CTransformFrm);
        lineEdit_rx->setObjectName(QStringLiteral("lineEdit_rx"));
        lineEdit_rx->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(lineEdit_rx);

        label_10 = new QLabel(CTransformFrm);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_6->addWidget(label_10);

        lineEdit_ry = new QLineEdit(CTransformFrm);
        lineEdit_ry->setObjectName(QStringLiteral("lineEdit_ry"));
        lineEdit_ry->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(lineEdit_ry);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(CTransformFrm);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        label_12 = new QLabel(CTransformFrm);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_7->addWidget(label_12);

        lineEdit_sw = new QLineEdit(CTransformFrm);
        lineEdit_sw->setObjectName(QStringLiteral("lineEdit_sw"));
        lineEdit_sw->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(lineEdit_sw);

        label_13 = new QLabel(CTransformFrm);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_7->addWidget(label_13);

        lineEdit_sh = new QLineEdit(CTransformFrm);
        lineEdit_sh->setObjectName(QStringLiteral("lineEdit_sh"));
        lineEdit_sh->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(lineEdit_sh);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CTransformFrm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_rot = new QLineEdit(CTransformFrm);
        lineEdit_rot->setObjectName(QStringLiteral("lineEdit_rot"));
        lineEdit_rot->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit_rot);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_depth = new QLabel(CTransformFrm);
        label_depth->setObjectName(QStringLiteral("label_depth"));

        horizontalLayout_2->addWidget(label_depth);

        lineEdit_depth = new QLineEdit(CTransformFrm);
        lineEdit_depth->setObjectName(QStringLiteral("lineEdit_depth"));
        lineEdit_depth->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(lineEdit_depth);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CTransformFrm);

        QMetaObject::connectSlotsByName(CTransformFrm);
    } // setupUi

    void retranslateUi(QFrame *CTransformFrm)
    {
        CTransformFrm->setWindowTitle(QApplication::translate("CTransformFrm", "Transform", 0));
        label_3->setText(QApplication::translate("CTransformFrm", "Transform", 0));
        label_5->setText(QApplication::translate("CTransformFrm", "Position ", 0));
        label_6->setText(QApplication::translate("CTransformFrm", "X ", 0));
        lineEdit_px->setText(QApplication::translate("CTransformFrm", "2.0", 0));
        label_7->setText(QApplication::translate("CTransformFrm", "Y", 0));
        lineEdit_py->setText(QApplication::translate("CTransformFrm", "2.0", 0));
        label_8->setText(QApplication::translate("CTransformFrm", "Offset   ", 0));
        label_9->setText(QApplication::translate("CTransformFrm", "X ", 0));
        lineEdit_rx->setText(QApplication::translate("CTransformFrm", "30", 0));
        label_10->setText(QApplication::translate("CTransformFrm", "Y", 0));
        lineEdit_ry->setText(QApplication::translate("CTransformFrm", "30", 0));
        label_11->setText(QApplication::translate("CTransformFrm", "Scale    ", 0));
        label_12->setText(QApplication::translate("CTransformFrm", "W", 0));
        lineEdit_sw->setText(QApplication::translate("CTransformFrm", "2.0", 0));
        label_13->setText(QApplication::translate("CTransformFrm", "H", 0));
        lineEdit_sh->setText(QApplication::translate("CTransformFrm", "2.0", 0));
        label->setText(QApplication::translate("CTransformFrm", "Rotation", 0));
        label_depth->setText(QApplication::translate("CTransformFrm", "Depth", 0));
    } // retranslateUi

};

namespace Ui {
    class CTransformFrm: public Ui_CTransformFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRANSFORM_FRM_H
