/********************************************************************************
** Form generated from reading UI file 'cpixture_tailor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPIXTURE_TAILOR_H
#define UI_CPIXTURE_TAILOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CPixtureTailor
{
public:
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_select;
    QFrame *frame;

    void setupUi(QDialog *CPixtureTailor)
    {
        if (CPixtureTailor->objectName().isEmpty())
            CPixtureTailor->setObjectName(QStringLiteral("CPixtureTailor"));
        CPixtureTailor->resize(800, 600);
        CPixtureTailor->setMinimumSize(QSize(800, 600));
        CPixtureTailor->setMaximumSize(QSize(800, 600));
        pushButton_ok = new QPushButton(CPixtureTailor);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(570, 550, 75, 23));
        QFont font;
        font.setPointSize(10);
        pushButton_ok->setFont(font);
        pushButton_cancel = new QPushButton(CPixtureTailor);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(680, 550, 75, 23));
        pushButton_cancel->setFont(font);
        pushButton_select = new QPushButton(CPixtureTailor);
        pushButton_select->setObjectName(QStringLiteral("pushButton_select"));
        pushButton_select->setGeometry(QRect(120, 550, 91, 31));
        pushButton_select->setFont(font);
        frame = new QFrame(CPixtureTailor);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-1, 0, 801, 531));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(CPixtureTailor);
        QObject::connect(pushButton_ok, SIGNAL(clicked()), CPixtureTailor, SLOT(accept()));
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), CPixtureTailor, SLOT(reject()));

        QMetaObject::connectSlotsByName(CPixtureTailor);
    } // setupUi

    void retranslateUi(QDialog *CPixtureTailor)
    {
        CPixtureTailor->setWindowTitle(QApplication::translate("CPixtureTailor", "CPixtureTailor", 0));
        pushButton_ok->setText(QApplication::translate("CPixtureTailor", "Ok", 0));
        pushButton_cancel->setText(QApplication::translate("CPixtureTailor", "Cancel", 0));
        pushButton_select->setText(QApplication::translate("CPixtureTailor", "SelectAll", 0));
    } // retranslateUi

};

namespace Ui {
    class CPixtureTailor: public Ui_CPixtureTailor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPIXTURE_TAILOR_H
