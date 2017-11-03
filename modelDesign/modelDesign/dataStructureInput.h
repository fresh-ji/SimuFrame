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
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString content;//��������

	Ui::dataStructureInput ui;

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//���뷽ʽ
};

#endif // DATASTRUCTUREINPUT_H
