#include <QTextCodec>
#include "eventFunctionInput.h"

eventFunctionInput::eventFunctionInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//关闭按钮失效
	codec = QTextCodec::codecForName("GB2312");//初始化字体
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