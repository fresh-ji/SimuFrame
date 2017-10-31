#include <QTextCodec>
#include "messageInput.h"

messageInput::messageInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	setFixedSize(this->width(),this->height());//禁止调整大小
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//关闭按钮失效
	codec = QTextCodec::codecForName("GB2312");//初始化字体
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
