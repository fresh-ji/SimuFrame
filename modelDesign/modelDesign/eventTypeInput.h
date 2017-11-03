#ifndef EVENTTYPEINPUT_H
#define EVENTTYPEINPUT_H

#include <QDialog>
#include "ui_eventTypeInput.h"

class eventTypeInput : public QDialog {

	Q_OBJECT

public:
	eventTypeInput(QWidget *parent = 0);
	~eventTypeInput();
	Ui::eventTypeInput ui;
	bool isOk;//只有点击ok是才能传输数据
	QString content;//输入内容

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//编码方式
};

#endif // EVENTTYPEINPUT_H
