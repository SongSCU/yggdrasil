/**************************************************************************
File:         main.cpp
Author:       Song Xiaofeng
Date:         2016-05-04
Description:
**************************************************************************/
#include "view/cmain_win.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include "view/cview_style.h"
#include <windows.h>
int main(int argc, char *argv[])
{
	//create app
	QApplication a(argc, argv);
	CViewStyle::sSetAppStyle(a); //set global app style

	//start logo screen
	QPixmap pix(":/picture/ui_picture/logo.png");
	//QSplashScreen splash(pix);
	//splash.resize(pix.size());
	//splash.show();
	//a.processEvents();

	//create main window
	//Sleep(3000);
	CMainWin w;
	w.showMaximized();
	//finish logo screen
	//splash.finish(&w);

	return a.exec();
}
	
