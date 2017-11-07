#include <QTextCodec>
#include "warning.h"

warning::warning(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	//setFixedSize(this->width(),this->height());//禁止调整大小
	codec = QTextCodec::codecForName("GB2312");//初始化字体
}

warning::~warning() {
}
