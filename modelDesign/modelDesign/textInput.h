#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <QDialog>
#include "ui_textInput.h"

class textInput : public QDialog {
	
	Q_OBJECT

public:
	textInput(QWidget *parent = 0);
	~textInput();
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString content;//��������

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	Ui::textInput ui;

	QTextCodec *codec;//���뷽ʽ
};

#endif // TEXTINPUT_H
