#include <QTextCodec>
#include "modelTypeInput.h"

modelTypeInput::modelTypeInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	//setFixedSize(this->width(),this->height());//禁止调整大小
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//关闭按钮失效
	codec = QTextCodec::codecForName("GB2312");//初始化字体
	isOk = false;
}

modelTypeInput::~modelTypeInput() {

}

void modelTypeInput::okAndExit() {
	nameContent = ui.textEdit->toPlainText();
	ipContent = ui.textEdit_2->toPlainText();
	portContent = ui.textEdit_3->toPlainText();
	isOk = true;
	ui.textEdit->clear();
	ui.textEdit_2->clear();
	ui.textEdit_3->clear();
	this->close();
}

void modelTypeInput::cancelAndExit() {
	ui.textEdit->clear();
	ui.textEdit_2->clear();
	this->close();
}
