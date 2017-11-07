#include <QTextCodec>
#include "eventFunctionInput.h"

eventFunctionInput::eventFunctionInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	isOk = false;
}

eventFunctionInput::~eventFunctionInput() {

}

void eventFunctionInput::okAndExit() {
	content = ui.textEdit->toPlainText();
	isOk = true;
	ui.textEdit->clear();
	this->close();
}

void eventFunctionInput::cancelAndExit() {
	ui.textEdit->clear();
	this->close();
}