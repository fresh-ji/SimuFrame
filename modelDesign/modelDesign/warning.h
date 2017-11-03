#ifndef WARNING_H
#define WARNING_H

#include <QDialog>
#include "ui_warning.h"

class warning : public QDialog 
{
	Q_OBJECT

public:
	warning(QWidget *parent = 0);
	~warning();
	Ui::warning ui;

private:
	QTextCodec *codec;//±àÂë·½Ê½
};

#endif // WARNING_H
