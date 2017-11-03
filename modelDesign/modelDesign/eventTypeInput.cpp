#include <QTextCodec>
#include "eventTypeInput.h"

eventTypeInput::eventTypeInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	//setFixedSize(this->width(),this->height());//禁止调整大小
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//关闭按钮失效
	codec = QTextCodec::codecForName("GB2312");//初始化字体
	isOk = false;
}

eventTypeInput::~eventTypeInput() {

}

void eventTypeInput::okAndExit() {
	content = ui.textEdit->toPlainText();
	isOk = true;
	ui.textEdit->clear();
	this->close();
}

void eventTypeInput::cancelAndExit() {
	ui.textEdit->clear();
	this->close();
}
