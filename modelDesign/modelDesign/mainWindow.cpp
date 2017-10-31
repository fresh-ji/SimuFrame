#include <QTextCodec>
#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	setFixedSize(this->width(),this->height());//禁止调整大小
	codec = QTextCodec::codecForName("GB2312");//初始化字体
}

mainWindow::~mainWindow() {

}

void mainWindow::openTextInput() {
	ti.isOk = false;
	ti.exec();
	if(ti.isOk) {
		ui.textBrowser->insertPlainText("\r\n");
		ui.textBrowser->insertPlainText(ti.content);
	}
}

void mainWindow::openMessageInput() {
	mi.isOk = false;
	mi.exec();
	if(mi.isOk) {
		int len = mi.content.length();
		ui.textBrowser->insertPlainText("\r\n");
		for(int i=0;i<(35-len);++i)
			ui.textBrowser->insertPlainText(" ");
		ui.textBrowser->insertPlainText(mi.content);
	}
}
