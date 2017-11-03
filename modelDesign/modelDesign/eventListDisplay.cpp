#include <QTextCodec>
#include "eventListDisplay.h"

eventListDisplay::eventListDisplay(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	isOk = false;
}

eventListDisplay::~eventListDisplay() {

}

void eventListDisplay::okAndExit() {
	if(ui.listWidget->currentItem()) {
		content = ui.listWidget->currentItem()->text();
		isOk = true;
	}
	ui.listWidget->clear();
	this->close();
}

void eventListDisplay::cancelAndExit() {
	ui.listWidget->clear();
	this->close();
}

