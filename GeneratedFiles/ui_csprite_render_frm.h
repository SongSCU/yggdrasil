/********************************************************************************
** Form generated from reading UI file 'csprite_render_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSPRITE_RENDER_FRM_H
#define UI_CSPRITE_RENDER_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSpriteRenderFrm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_pix;
    QPushButton *button_select;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QFrame *CSpriteRenderFrm)
    {
        if (CSpriteRenderFrm->objectName().isEmpty())
            CSpriteRenderFrm->setObjectName(QStringLiteral("CSpriteRenderFrm"));
        CSpriteRenderFrm->resize(438, 140);
        verticalLayout_2 = new QVBoxLayout(CSpriteRenderFrm);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CSpriteRenderFrm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(CSpriteRenderFrm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 46));

        horizontalLayout->addWidget(label_2);

        label_pix = new QLabel(CSpriteRenderFrm);
        label_pix->setObjectName(QStringLiteral("label_pix"));
        label_pix->setMinimumSize(QSize(0, 46));

        horizontalLayout->addWidget(label_pix);

        button_select = new QPushButton(CSpriteRenderFrm);
        button_select->setObjectName(QStringLiteral("button_select"));
        button_select->setMinimumSize(QSize(0, 30));
        button_select->setMaximumSize(QSize(50, 16777215));
        QFont font;
        font.setPointSize(10);
        button_select->setFont(font);
        button_select->setStyleSheet(QStringLiteral("color: white"));

        horizontalLayout->addWidget(button_select);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(CSpriteRenderFrm);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(CSpriteRenderFrm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CSpriteRenderFrm);

        QMetaObject::connectSlotsByName(CSpriteRenderFrm);
    } // setupUi

    void retranslateUi(QFrame *CSpriteRenderFrm)
    {
        CSpriteRenderFrm->setWindowTitle(QApplication::translate("CSpriteRenderFrm", "CSpriteRenderFrm", 0));
        label->setText(QApplication::translate("CSpriteRenderFrm", "Sprite Renderer", 0));
        label_2->setText(QApplication::translate("CSpriteRenderFrm", "Pixmap", 0));
        label_pix->setText(QString());
        button_select->setText(QApplication::translate("CSpriteRenderFrm", "select", 0));
        label_4->setText(QApplication::translate("CSpriteRenderFrm", "Color", 0));
        label_5->setText(QApplication::translate("CSpriteRenderFrm", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class CSpriteRenderFrm: public Ui_CSpriteRenderFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSPRITE_RENDER_FRM_H
