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
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString nameContent;
	QString ipContent;
	QString portContent;

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//���뷽ʽ
};

#endif // MODELTYPEINPUT_H