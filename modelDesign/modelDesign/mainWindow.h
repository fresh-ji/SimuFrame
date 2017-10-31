#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"
#include "textInput.h"
#include "messageInput.h"

class mainWindow : public QMainWindow  
{
	Q_OBJECT

public:
	mainWindow(QWidget *parent = 0);
	~mainWindow();

	public slots:
		void openTextInput();
		void openMessageInput();

private:
	Ui::mainWindowClass ui;

	QTextCodec *codec;//���뷽ʽ

	textInput ti;
	messageInput mi;
};

#endif // MAINWINDOW_H
