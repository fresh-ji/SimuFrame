#include <QTextCodec>
#include "modelTypeInput.h"

modelTypeInput::modelTypeInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	//setFixedSize(this->width(),this->height());//��ֹ������С
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
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
