/********************************************************************************
** Form generated from reading UI file 'chierarchy_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIERARCHY_FRM_H
#define UI_CHIERARCHY_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CHierarchyFrm
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QFrame *CHierarchyFrm)
    {
        if (CHierarchyFrm->objectName().isEmpty())
            CHierarchyFrm->setObjectName(QStringLiteral("CHierarchyFrm"));
        CHierarchyFrm->resize(400, 300);
        CHierarchyFrm->setFrameShape(QFrame::StyledPanel);
        CHierarchyFrm->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CHierarchyFrm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(CHierarchyFrm);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(380, 0));
        treeWidget->setStyleSheet(QStringLiteral("background:#606060;color:white"));

        verticalLayout->addWidget(treeWidget);


        retranslateUi(CHierarchyFrm);

        QMetaObject::connectSlotsByName(CHierarchyFrm);
    } // setupUi

    void retranslateUi(QFrame *CHierarchyFrm)
    {
        CHierarchyFrm->setWindowTitle(QApplication::translate("CHierarchyFrm", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class CHierarchyFrm: public Ui_CHierarchyFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIERARCHY_FRM_H
