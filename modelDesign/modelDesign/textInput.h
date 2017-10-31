#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <QDialog>
#include "ui_textInput.h"

class textInput : public QDialog {
	
	Q_OBJECT

public:
	textInput(QWidget *parent = 0);
	~textInput();
	bool isOk;//只有点击ok是才能传输数据
	QString content;//输入内容

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	Ui::textInput ui;

	QTextCodec *codec;//编码方式
};

#endif // TEXTINPUT_H
