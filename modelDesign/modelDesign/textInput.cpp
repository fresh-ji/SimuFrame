#include <QTextCodec>
#include "textInput.h"

textInput::textInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	isOk = false;
}

textInput::~textInput() {

}

void textInput::okAndExit() {
	content = ui.textEdit->toPlainText();
	isOk = true;
	ui.textEdit->clear();
	this->close();
}

void textInput::cancelAndExit() {
	ui.textEdit->clear();
	this->close();
}
