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
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString content;//��������

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//���뷽ʽ
};

#endif // EVENTTYPEINPUT_H
