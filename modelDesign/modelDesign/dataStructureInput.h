#ifndef DATASTRUCTUREINPUT_H
#define DATASTRUCTUREINPUT_H

#include <QDialog>
#include "ui_dataStructureInput.h"

class dataStructureInput : public QDialog 
{
	Q_OBJECT

public:
	dataStructureInput(QWidget *parent = 0);
	~dataStructureInput();
	bool isOk;//只有点击ok是才能传输数据
	QString content;//输入内容

	Ui::dataStructureInput ui;

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//编码方式
};

#endif // DATASTRUCTUREINPUT_H
