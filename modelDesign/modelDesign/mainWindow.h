#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"
#include "dataStructureInput.h"
#include "eventTypeInput.h"
#include "modelTypeInput.h"
#include "eventListDisplay.h"
#include "warning.h"

class mainWindow : public QMainWindow {

	Q_OBJECT

public:
	mainWindow(QWidget *parent = 0);
	~mainWindow();

	public slots:
		void openDataStructureInput();
		void addEventType();
		void deleteEventType();
		void editEventType();
		void addModelType();
		void deleteModelType();
		void editModelType();
		void addSubscribe();
		void deleteSubscribe();
		void addFunctions();
		void generate();

private:
	Ui::mainWindowClass ui;

	QTextCodec *codec;//±àÂë·½Ê½

	dataStructureInput dsi;
	eventTypeInput eti;
	modelTypeInput mti;
	eventListDisplay etd;
	warning WARNING;
};

#endif // MAINWINDOW_H
