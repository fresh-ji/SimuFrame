#ifndef EVENTLISTDISPLAY_H
#define EVENTLISTDISPLAY_H

#include <QDialog>
#include "ui_eventListDisplay.h"

class eventListDisplay : public QDialog {

	Q_OBJECT

public:
	eventListDisplay(QWidget *parent = 0);
	~eventListDisplay();
	Ui::eventListDisplay ui;
	bool isOk;//ֻ�е��ok�ǲ��ܴ�������
	QString content;//ѡ������

	public slots:
		void okAndExit();
		void cancelAndExit();

private:
	QTextCodec *codec;//���뷽ʽ
	
};

#endif // EVENTLISTDISPLAY_H
