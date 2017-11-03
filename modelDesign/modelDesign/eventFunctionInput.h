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
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString content;//ѡ������

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//���뷽ʽ
};

#endif // EVENTFUNCTIONINPUT_H
