#ifndef MESSAGEINPUT_H
#define MESSAGEINPUT_H

#include <QDialog>
#include "ui_messageInput.h"

class messageInput : public QDialog
{
	Q_OBJECT

public:
	messageInput(QWidget *parent = 0);
	~messageInput();
	bool isOk;//只有点击ok是才能传输数据
	QString content;//输入内容

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	Ui::messageInput ui;

	QTextCodec *codec;//编码方式
};

#endif // MESSAGEINPUT_H
