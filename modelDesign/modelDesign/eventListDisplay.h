#ifndef EVENTLISTDISPLAY_H
#define EVENTLISTDISPLAY_H

#include <QDialog>
#include "ui_eventListDisplay.h"

class eventListDisplay : public QDialog {

	Q_OBJECT

public:
	eventListDisplay(QWidget *parent = 0);
	~eventListDisplay();
	Ui::eventListDisplay ui;
	bool isOk;//只有点击ok是才能传输数据
	QString content;//选择内容

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//编码方式
	
};

#endif // EVENTLISTDISPLAY_H
