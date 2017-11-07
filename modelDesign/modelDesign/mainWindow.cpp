#include <qfile.h>
#include"qtextstream.h"
#include"Qtextstream"
#include <QTextCodec>
#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	//1��
	ui.treeWidget->setHeaderLabel(codec->toUnicode("�¼���"));
	//2��
	ui.treeWidget_2->setHeaderLabels(QStringList()<<codec->toUnicode("ģ����")
		<<codec->toUnicode("ģ��IP")<<codec->toUnicode("ģ�Ͷ˿�"));
	QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()
		<<codec->toUnicode("�¼�������")<<"127.0.0.1" <<"12337");
	ui.treeWidget_2->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<codec->toUnicode("ʱ�������")
		<<"127.0.0.1" <<"12338");
	ui.treeWidget_2->addTopLevelItem(item);
	//3��
	ui.treeWidget_3->setHeaderLabel(codec->toUnicode("��Ա��"));
}

mainWindow::~mainWindow() {

}

//�������ݽṹ��ģ
void mainWindow::openDataStructureInput() {
	dsi.isOk = false;
	dsi.ui.textEdit->setText(ui.textBrowser->toPlainText());
	dsi.exec();
	if(dsi.isOk)
		ui.textBrowser->setText(dsi.content);
}

//�ӿڽ�ģ������
void mainWindow::addEventType() {
	eti.isOk = false;
	eti.exec();
	if(eti.isOk) {
		if(eti.content == NULL) {
			WARNING.ui.label->setText(codec->toUnicode("û������Ԫ�أ���"));
			WARNING.exec();
			return;
		}
		QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<eti.content);
		for(int i=0;i<ui.treeWidget->topLevelItemCount();++i) {
			if(item->text(0) == ui.treeWidget->topLevelItem(i)->text(0)) {
				WARNING.ui.label->setText(codec->toUnicode("�ظ���Ԫ�أ���"));
				WARNING.exec();
				return;
			}
		}
		ui.treeWidget->addTopLevelItem(item);
	}
}

void mainWindow::deleteEventType() {
	QTreeWidgetItem * item = ui.treeWidget->topLevelItem(ui.treeWidget->currentIndex().row());
	//ɾ��ȫ��
	QTreeWidget * wid = ui.treeWidget_3;
	for(int i=0;i<wid->topLevelItemCount();++i) {
		for(int j=0;j<wid->topLevelItem(i)->childCount();++j) {
			if(wid->topLevelItem(i)->child(j)->text(0) == item->text(0))
				delete wid->topLevelItem(i)->child(j);
		}
	}
	delete item;
}

void mainWindow::editEventType() {
	eti.isOk = false;
	QTreeWidgetItem * item = ui.treeWidget->currentItem();
	if(item) {
		eti.ui.textEdit->setText(item->text(0));
		eti.exec();
		if(eti.isOk) {
			QTreeWidget * wid = ui.treeWidget_3;
			for(int i=0;i<wid->topLevelItemCount();++i) {
				for(int j=0;j<wid->topLevelItem(i)->childCount();++j) {
					if(wid->topLevelItem(i)->child(j)->text(0) == item->text(0))
						wid->topLevelItem(i)->child(j)->setText(0, eti.content);
				}
			}
			item->setText(0, eti.content);
		}
	}
}

//��Ա��ģ������
void mainWindow::addModelType() {
	mti.isOk = false;
	mti.exec();
	if(mti.isOk) {
		//�жϿհ�����
		if(mti.nameContent == NULL || mti.ipContent == NULL || mti.portContent == NULL) {
			WARNING.ui.label->setText(codec->toUnicode("���ڿհ�Ԫ�أ���"));
			WARNING.exec();
			return;
		}
		//�ж��ظ�����
		QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<mti.nameContent
			<<mti.ipContent<<mti.portContent);
		for(int i=0;i<ui.treeWidget_2->topLevelItemCount();++i) {
			if(item->text(0) == ui.treeWidget_2->topLevelItem(i)->text(0)) {
				WARNING.ui.label->setText(codec->toUnicode("�ظ���Ԫ�أ���"));
				WARNING.exec();
				return;
			}
		}
		//���
		ui.treeWidget_2->addTopLevelItem(item);
		//ͬ����ӵ�3��
		item = new QTreeWidgetItem(QStringList()<<mti.nameContent);
		ui.treeWidget_3->addTopLevelItem(item);
	}
}

void mainWindow::deleteModelType() {
	//�жϲ�����ɾ��
	if(ui.treeWidget_2->currentIndex().row() < 2) {
		WARNING.ui.label->setText(codec->toUnicode("������ɾ������"));
		WARNING.exec();
		return;
	}
	QTreeWidgetItem * item = ui.treeWidget_2->topLevelItem(ui.treeWidget_2->currentIndex().row());
	QTreeWidgetItem * item2;
	//����ɾ��3��
	for(int i=0;i<ui.treeWidget_3->topLevelItemCount();++i) {
		if(item->text(0) == ui.treeWidget_3->topLevelItem(i)->text(0)) {
			item2 = ui.treeWidget_3->topLevelItem(i);
			break;
		}
	}
	delete item;
	delete item2;
}

void mainWindow::editModelType() {
	eti.isOk = false;
	QTreeWidgetItem * item = ui.treeWidget_2->currentItem();
	if(item) {
		mti.ui.textEdit->setText(item->text(0));
		mti.ui.textEdit_2->setText(item->text(1));
		mti.ui.textEdit_3->setText(item->text(2));
		mti.exec();
		if(mti.isOk) {
			//�жϲ������޸�
			if((0 == ui.treeWidget_2->currentIndex().row()) &&
				(codec->toUnicode("�¼�������") != mti.nameContent)) {
				WARNING.ui.label->setText(codec->toUnicode("�������޸ģ���"));
				WARNING.exec();
				return;
			}
			if((1 == ui.treeWidget_2->currentIndex().row()) &&
				(codec->toUnicode("ʱ�������") != mti.nameContent)) {
				WARNING.ui.label->setText(codec->toUnicode("�������޸ģ���"));
				WARNING.exec();
				return;
			}
			//�����޸�3��
			for(int i=0;i<ui.treeWidget_3->topLevelItemCount();++i) {
				if(item->text(0) == ui.treeWidget_3->topLevelItem(i)->text(0)) {
					ui.treeWidget_3->topLevelItem(i)->setText(0, mti.nameContent);
					break;
				}
			}
			item->setText(0, mti.nameContent);
			item->setText(1, mti.ipContent);
			item->setText(2, mti.portContent);
		}
	}
}

//���ģ�����У�����
void mainWindow::addSubscribe() {
	QTreeWidgetItem * item = ui.treeWidget_3->currentItem();
	//�ж�ûѡ��
	if(!item) {
		WARNING.ui.label->setText(codec->toUnicode("û�г�Աѡ�У���"));
		WARNING.exec();
		return;
	}
	//�ж�ѡ�е��Ƕ���
	if(item->parent()) {
		WARNING.ui.label->setText(codec->toUnicode("����ȷѡ���Ա����"));
		WARNING.exec();
		return;
	}	
	//�ж����¼�
	if(0 == ui.treeWidget->topLevelItemCount()) {
		WARNING.ui.label->setText(codec->toUnicode("û�г�ʼ���¼�����"));
		WARNING.exec();
		return;
	}
	for(int i=0;i<ui.treeWidget->topLevelItemCount();++i)
		etd.ui.listWidget->addItem(ui.treeWidget->topLevelItem(i)->text(0));
	etd.isOk = false;
	etd.exec();
	if(etd.isOk) {
		//�ж��ظ�����
		for(int i=0;i<item->childCount();++i) {
			if(etd.content == item->child(i)->text(0)) {
				WARNING.ui.label->setText(codec->toUnicode("�ظ������¼�����"));
				WARNING.exec();
				return;
			}
		}
		QTreeWidgetItem * child = new QTreeWidgetItem(QStringList()<<etd.content);
		item->addChild(child);
	}
}

void mainWindow::deleteSubscribe() {
	QTreeWidgetItem * item = ui.treeWidget_3->currentItem();
	//����յ�
	if(!item)
		return;
	//�ж�ѡ�еĲ��Ƕ���
	if(!item->parent()) {
		WARNING.ui.label->setText(codec->toUnicode("����ȷѡ���¼�����"));
		WARNING.exec();
		return;
	}
	delete item;
}

void mainWindow::addFunctions() {
	efi.isOk = false;
	QTreeWidgetItem * item = ui.treeWidget_3->currentItem();
	//����յ�
	if(!item)
		return;
	//�ж�ѡ�еĲ����¼�
	if(!item->parent()) {
		WARNING.ui.label->setText(codec->toUnicode("����ȷѡ���¼�����"));
		WARNING.exec();
		return;
	}
	QString key = item->parent()->text(0);
	key += ":";
	key += item->text(0);
	if(functionMap.contains(key))
		efi.ui.textEdit->setText(functionMap[key]);
	else {
		functionMap[key] = "";
	}
	efi.exec();
	if(efi.isOk)
		functionMap[key] = efi.content;
}

void mainWindow::generate() {
	QFile file("model.xml");
	if(file.exists()) {
		WARNING.ui.label->setText(codec->toUnicode("���Ḳ�ǣ���"));
		WARNING.exec();
		file .remove();
	}
	file.open(QIODevice::WriteOnly);
	QTextStream stream(&file);
	stream << QString("<?xml version=\"1.0\" encoding=\"gb2312\"?>\r\n");
	stream << QString("<frame>\r\n");
	stream << QString("  <manager>\r\n");
	stream << QString("    <eManager>-h " + ui.treeWidget_2->topLevelItem(0)->text(1) +
		" -p " + ui.treeWidget_2->topLevelItem(0)->text(2) + "</eManager>\r\n");
	stream << QString("    <tManager>-h " + ui.treeWidget_2->topLevelItem(1)->text(1) +
		" -p " + ui.treeWidget_2->topLevelItem(1)->text(2) + "</tManager>\r\n");
	stream << QString("    <sTime>0.0</sTime>\r\n");
	stream << QString("    <step>0.1</step>\r\n");
	stream << QString("  </manager>\r\n");
	stream << QString("  <variableDef>\r\n");
	stream << QString("  " + ui.textBrowser->toPlainText() + "\r\n");
	stream << QString("  </variableDef>\r\n");

	for(int i=0;i<ui.treeWidget_3->topLevelItemCount();++i) {
		stream << QString("  <model name=\"" + ui.treeWidget_3->topLevelItem(i)->text(0) +
			"\" location=\"-h " + ui.treeWidget_2->topLevelItem(i+2)->text(1) + " -p "+
			ui.treeWidget_2->topLevelItem(i+2)->text(2) + "\">\r\n");
		for(int j=0;j<ui.treeWidget_3->topLevelItem(i)->childCount();++j) {
			stream << QString("      <event name=\"" + ui.treeWidget_3->topLevelItem(i)->child(j)->text(0) +
				"\">HANDLEev" + ui.treeWidget_3->topLevelItem(i)->child(j)->text(0) + "</event>\r\n");
		}
		stream << QString("  </model>\r\n");
	}

	stream << QString("</frame>");

	WARNING.ui.label->setText(codec->toUnicode("����ģ�ͳɹ�����"));
	WARNING.exec();
}

void mainWindow::openExample() {
	QString stru = "struct {\n\tint a;\n\tint b;\n\tint c;\n};";
	ui.textBrowser->setText(stru);

	QTreeWidgetItem* item;

	item = new QTreeWidgetItem(QStringList()<<"event1");
	ui.treeWidget->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"event2");
	ui.treeWidget->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"event3");
	ui.treeWidget->addTopLevelItem(item);

	item = new QTreeWidgetItem(QStringList()<<"modelA"<<"127.0.0.1"<<"43261");
	ui.treeWidget_2->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"modelB"<<"127.0.0.1"<<"43262");
	ui.treeWidget_2->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"modelC"<<"127.0.0.1"<<"43263");
	ui.treeWidget_2->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"modelA");
	ui.treeWidget_3->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"modelB");
	ui.treeWidget_3->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<"modelC");
	ui.treeWidget_3->addTopLevelItem(item);

	QTreeWidgetItem* child;
	item = ui.treeWidget_3->topLevelItem(0);
	child = new QTreeWidgetItem(QStringList()<<"event1");
	item->addChild(child);
	child = new QTreeWidgetItem(QStringList()<<"event2");
	item->addChild(child);
	child = new QTreeWidgetItem(QStringList()<<"event3");
	item->addChild(child);
	item = ui.treeWidget_3->topLevelItem(1);
	child = new QTreeWidgetItem(QStringList()<<"event1");
	item->addChild(child);
	child = new QTreeWidgetItem(QStringList()<<"event2");
	item->addChild(child);
	item = ui.treeWidget_3->topLevelItem(2);
	child = new QTreeWidgetItem(QStringList()<<"event2");
	item->addChild(child);
	child = new QTreeWidgetItem(QStringList()<<"event3");
	item->addChild(child);
}

void mainWindow::openHelp() {
	WARNING.ui.label->setText("Version1.0.Developed by jh.");
	WARNING.exec();
}