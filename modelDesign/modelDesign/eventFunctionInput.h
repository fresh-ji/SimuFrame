#ifndef EVENTFUNCTIONINPUT_H
#define EVENTFUNCTIONINPUT_H

#include <QDialog>
#include "ui_eventFunctionInput.h"

class eventFunctionInput : public QDialog {

	Q_OBJECT

public:
	eventFunctionInput(QWidget *parent = 0);
	~eventFunctionInput();
	Ui::eventFunctionInput ui;
	bool isOk;//只有点击ok是才能传输数据
	QString content;//选择内容

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//编码方式
};

#endif // EVENTFUNCTIONINPUT_H
