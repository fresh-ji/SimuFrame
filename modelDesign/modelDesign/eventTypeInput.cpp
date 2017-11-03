#include <QTextCodec>
#include "eventTypeInput.h"

eventTypeInput::eventTypeInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	//setFixedSize(this->width(),this->height());//��ֹ������С
	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
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
