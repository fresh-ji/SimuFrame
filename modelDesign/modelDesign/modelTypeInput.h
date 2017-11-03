#ifndef MODELTYPEINPUT_H
#define MODELTYPEINPUT_H

#include <QDialog>
#include "ui_modelTypeInput.h"

class modelTypeInput : public QDialog 
{
	Q_OBJECT

public:
	modelTypeInput(QWidget *parent = 0);
	~modelTypeInput();
	Ui::modelTypeInput ui;
	bool isOk;//只有点击ok是才能传输数据
	QString nameContent;
	QString ipContent;
	QString portContent;

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//编码方式
};

#endif // MODELTYPEINPUT_H