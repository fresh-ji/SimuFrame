#include <QTextCodec>
#include "dataStructureInput.h"

dataStructureInput::dataStructureInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//�رհ�ťʧЧ
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	isOk = false;
}

dataStructureInput::~dataStructureInput() {

}

void dataStructureInput::okAndExit() {
	content = ui.textEdit->toPlainText();
	isOk = true;
	//ui.textEdit->clear();
	this->close();
}

void dataStructureInput::cancelAndExit() {
	//ui.textEdit->clear();
	this->close();
}
