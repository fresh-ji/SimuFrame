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
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString content;//��������

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	Ui::messageInput ui;

	QTextCodec *codec;//���뷽ʽ
};

#endif // MESSAGEINPUT_H
