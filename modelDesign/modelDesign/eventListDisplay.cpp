#include <QTextCodec>
#include "eventListDisplay.h"

eventListDisplay::eventListDisplay(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() &~ Qt::WindowCloseButtonHint);//关闭按钮失效
	codec = QTextCodec::codecForName("GB2312");//初始化字体
	isOk = false;
}

eventListDisplay::~eventListDisplay() {

}

void eventListDisplay::okAndExit() {
	if(ui.listWidget->currentItem()) {
		content = ui.listWidget->currentItem()->text();
		isOk = true;
	}
	ui.listWidget->clear();
	this->close();
}

void eventListDisplay::cancelAndExit() {
	ui.listWidget->clear();
	this->close();
}

