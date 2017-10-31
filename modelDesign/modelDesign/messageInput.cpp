#include <QTextCodec>
#include "messageInput.h"

messageInput::messageInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	setFixedSize(this->width(),this->height());//��ֹ������С
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	isOk = false;
}

messageInput::~messageInput() {

}

void messageInput::okAndExit() {
	content = ui.textEdit->toPlainText();
	isOk = true;
	ui.textEdit->clear();
	this->close();
}

void messageInput::cancelAndExit() {
	ui.textEdit->clear();
	this->close();
}
