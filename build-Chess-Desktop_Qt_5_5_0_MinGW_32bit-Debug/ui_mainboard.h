/********************************************************************************
** Form generated from reading UI file 'mainboard.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINBOARD_H
#define UI_MAINBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainBoard
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainBoard)
    {
        if (MainBoard->objectName().isEmpty())
            MainBoard->setObjectName(QStringLiteral("MainBoard"));
        MainBoard->resize(870, 565);
        centralWidget = new QWidget(MainBoard);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainBoard->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainBoard);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 25));
        MainBoard->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainBoard);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainBoard->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainBoard);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainBoard->setStatusBar(statusBar);

        retranslateUi(MainBoard);

        QMetaObject::connectSlotsByName(MainBoard);
    } // setupUi

    void retranslateUi(QMainWindow *MainBoard)
    {
        MainBoard->setWindowTitle(QApplication::translate("MainBoard", "MainBoard", 0));
    } // retranslateUi

};

namespace Ui {
    class MainBoard: public Ui_MainBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINBOARD_H
