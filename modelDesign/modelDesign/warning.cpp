#include <QTextCodec>
#include "warning.h"

warning::warning(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	//setFixedSize(this->width(),this->height());//��ֹ������С
	codec = QTextCodec::codecForName("GB2312");//��ʼ������
}

warning::~warning() {
}
