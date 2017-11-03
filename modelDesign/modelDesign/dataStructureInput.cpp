#include <QTextCodec>
#include "dataStructureInput.h"

dataStructureInput::dataStructureInput(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//关闭按钮失效
	codec = QTextCodec::codecForName("GB2312");//初始化字体
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
