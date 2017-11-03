#include <QTextCodec>
#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	codec = QTextCodec::codecForName("GB2312");//��ʼ������
	//1��
	ui.treeWidget->setHeaderLabel(codec->toUnicode("�¼���"));
	//2��
	ui.treeWidget_2->setHeaderLabels(QStringList()<<codec->toUnicode("ģ����")<<codec->toUnicode("ģ��IP")<<codec->toUnicode("ģ�Ͷ˿�"));
	QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<codec->toUnicode("�¼�������")<<"127.0.0.1" <<"12337");
	ui.treeWidget_2->addTopLevelItem(item);
	item = new QTreeWidgetItem(QStringList()<<codec->toUnicode("ʱ�������")<<"127.0.0.1" <<"12338");
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
		QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<mti.nameContent<<mti.ipContent<<mti.portContent);
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
			if((0 == ui.treeWidget_2->currentIndex().row()) && (codec->toUnicode("�¼�������") != mti.nameContent)) {
				WARNING.ui.label->setText(codec->toUnicode("�������޸ģ���"));
				WARNING.exec();
				return;
			}
			if((1 == ui.treeWidget_2->currentIndex().row()) && (codec->toUnicode("ʱ�������") != mti.nameContent)) {
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
	//�ж�ѡ�е��Ƕ��㣬������Ĭ���¼�����ģ������ͬ
	bool isHave = false;
	for(int i=0;i<ui.treeWidget_2->topLevelItemCount();++i) {
		if(item->text(0) == ui.treeWidget_2->topLevelItem(i)->text(0))
			isHave = true;
	}
	if(!isHave) {
		WARNING.ui.label->setText(codec->toUnicode("����ȷѡ��ģ�ͣ���"));
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
	//�ж�ѡ�еĲ��Ƕ��㣬������Ĭ���¼�����ģ������ͬ
	bool isHave = false;
	for(int i=0;i<ui.treeWidget_2->topLevelItemCount();++i) {
		if(item->text(0) == ui.treeWidget_2->topLevelItem(i)->text(0))
			isHave = true;
	}
	if(isHave) {
		WARNING.ui.label->setText(codec->toUnicode("����ȷѡ���¼�����"));
		WARNING.exec();
		return;
	}
	delete item;
}

void mainWindow::addFunctions() {

}

void mainWindow::generate() {

}