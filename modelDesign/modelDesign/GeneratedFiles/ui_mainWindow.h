/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindowClass
{
public:
    QAction *action;
    QAction *actionA;
    QAction *actionB;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QTreeWidget *treeWidget_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QTreeWidget *treeWidget_2;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainWindowClass)
    {
        if (mainWindowClass->objectName().isEmpty())
            mainWindowClass->setObjectName(QStringLiteral("mainWindowClass"));
        mainWindowClass->resize(910, 694);
        mainWindowClass->setMinimumSize(QSize(0, 0));
        mainWindowClass->setMaximumSize(QSize(16777215, 16777215));
        action = new QAction(mainWindowClass);
        action->setObjectName(QStringLiteral("action"));
        actionA = new QAction(mainWindowClass);
        actionA->setObjectName(QStringLiteral("actionA"));
        actionB = new QAction(mainWindowClass);
        actionB->setObjectName(QStringLiteral("actionB"));
        action_2 = new QAction(mainWindowClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(mainWindowClass);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(mainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox_4->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        treeWidget_3 = new QTreeWidget(groupBox_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget_3->setHeaderItem(__qtreewidgetitem);
        treeWidget_3->setObjectName(QStringLiteral("treeWidget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget_3->sizePolicy().hasHeightForWidth());
        treeWidget_3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(11);
        treeWidget_3->setFont(font1);

        gridLayout_5->addWidget(treeWidget_3, 0, 0, 1, 4);

        pushButton_8 = new QPushButton(groupBox_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(100, 30));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        pushButton_8->setFont(font2);

        gridLayout_5->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(100, 30));
        pushButton_9->setFont(font2);

        gridLayout_5->addWidget(pushButton_9, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(groupBox_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(100, 30));
        pushButton_10->setFont(font2);

        gridLayout_5->addWidget(pushButton_10, 1, 2, 1, 1);

        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(100, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Leelawadee UI"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        pushButton_11->setFont(font3);

        gridLayout_5->addWidget(pushButton_11, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setWeight(50);
        textBrowser->setFont(font4);

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(100, 30));
        pushButton->setMaximumSize(QSize(100, 30));
        pushButton->setFont(font2);

        gridLayout_2->addWidget(pushButton, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(100, 30));
        pushButton_2->setMaximumSize(QSize(100, 30));
        pushButton_2->setFont(font2);

        gridLayout_3->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(100, 30));
        pushButton_3->setMaximumSize(QSize(100, 30));
        pushButton_3->setFont(font2);

        gridLayout_3->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(100, 30));
        pushButton_4->setFont(font2);

        gridLayout_3->addWidget(pushButton_4, 1, 3, 1, 1);

        treeWidget = new QTreeWidget(groupBox_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem1);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setUnderline(false);
        font5.setWeight(50);
        treeWidget->setFont(font5);
        treeWidget->setMouseTracking(false);
        treeWidget->setAutoFillBackground(false);
        treeWidget->setInputMethodHints(Qt::ImhNone);
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setLineWidth(1);
        treeWidget->setMidLineWidth(0);

        gridLayout_3->addWidget(treeWidget, 0, 0, 1, 4);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_7 = new QPushButton(groupBox_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(100, 30));
        pushButton_7->setMaximumSize(QSize(100, 30));
        pushButton_7->setFont(font2);

        gridLayout_4->addWidget(pushButton_7, 1, 3, 1, 1);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(100, 30));
        pushButton_5->setMaximumSize(QSize(100, 30));
        pushButton_5->setFont(font2);

        gridLayout_4->addWidget(pushButton_5, 1, 1, 1, 1);

        treeWidget_2 = new QTreeWidget(groupBox_3);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem2);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        sizePolicy.setHeightForWidth(treeWidget_2->sizePolicy().hasHeightForWidth());
        treeWidget_2->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(11);
        font6.setBold(false);
        font6.setWeight(50);
        treeWidget_2->setFont(font6);

        gridLayout_4->addWidget(treeWidget_2, 0, 0, 1, 4);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(100, 30));
        pushButton_6->setMaximumSize(QSize(100, 30));
        pushButton_6->setFont(font2);

        gridLayout_4->addWidget(pushButton_6, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 1, 1, 1);

        mainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 910, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        mainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action_2);
        menu_2->addAction(action_3);

        retranslateUi(mainWindowClass);
        QObject::connect(pushButton, SIGNAL(clicked()), mainWindowClass, SLOT(openDataStructureInput()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mainWindowClass, SLOT(addEventType()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), mainWindowClass, SLOT(deleteEventType()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), mainWindowClass, SLOT(editEventType()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), mainWindowClass, SLOT(addModelType()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), mainWindowClass, SLOT(deleteModelType()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), mainWindowClass, SLOT(editModelType()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), mainWindowClass, SLOT(addSubscribe()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), mainWindowClass, SLOT(deleteSubscribe()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), mainWindowClass, SLOT(addFunctions()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), mainWindowClass, SLOT(generate()));
        QObject::connect(action_2, SIGNAL(triggered()), mainWindowClass, SLOT(openExample()));
        QObject::connect(action_3, SIGNAL(triggered()), mainWindowClass, SLOT(openHelp()));

        QMetaObject::connectSlotsByName(mainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindowClass)
    {
        mainWindowClass->setWindowTitle(QApplication::translate("mainWindowClass", "mainWindow", 0));
        action->setText(QApplication::translate("mainWindowClass", "\347\244\272\344\276\213", 0));
        actionA->setText(QApplication::translate("mainWindowClass", "a", 0));
        actionB->setText(QApplication::translate("mainWindowClass", "b", 0));
        action_2->setText(QApplication::translate("mainWindowClass", "\347\244\272\344\276\213", 0));
        action_3->setText(QApplication::translate("mainWindowClass", "\345\205\263\344\272\216", 0));
        groupBox_4->setTitle(QApplication::translate("mainWindowClass", "\350\201\224\351\202\246\345\273\272\346\250\241", 0));
        pushButton_8->setText(QApplication::translate("mainWindowClass", "\346\267\273\345\212\240\350\256\242\351\230\205", 0));
        pushButton_9->setText(QApplication::translate("mainWindowClass", "\345\210\240\351\231\244\350\256\242\351\230\205", 0));
        pushButton_10->setText(QApplication::translate("mainWindowClass", "\346\267\273\345\212\240\344\272\213\344\273\266\345\244\204\347\220\206\345\207\275\346\225\260", 0));
        pushButton_11->setText(QApplication::translate("mainWindowClass", "\347\224\237\346\210\220", 0));
        groupBox->setTitle(QApplication::translate("mainWindowClass", "\345\237\272\347\241\200\346\225\260\346\215\256\347\273\223\346\236\204\345\273\272\346\250\241", 0));
        textBrowser->setHtml(QApplication::translate("mainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", 0));
        pushButton->setText(QApplication::translate("mainWindowClass", "\347\274\226\350\276\221", 0));
        groupBox_2->setTitle(QApplication::translate("mainWindowClass", "\346\216\245\345\217\243\345\273\272\346\250\241", 0));
        pushButton_2->setText(QApplication::translate("mainWindowClass", "\346\267\273\345\212\240", 0));
        pushButton_3->setText(QApplication::translate("mainWindowClass", "\345\210\240\351\231\244", 0));
        pushButton_4->setText(QApplication::translate("mainWindowClass", "\347\274\226\350\276\221", 0));
        groupBox_3->setTitle(QApplication::translate("mainWindowClass", "\346\210\220\345\221\230\345\273\272\346\250\241", 0));
        pushButton_7->setText(QApplication::translate("mainWindowClass", "\347\274\226\350\276\221", 0));
        pushButton_5->setText(QApplication::translate("mainWindowClass", "\346\267\273\345\212\240", 0));
        pushButton_6->setText(QApplication::translate("mainWindowClass", "\345\210\240\351\231\244", 0));
        menu->setTitle(QApplication::translate("mainWindowClass", "\346\211\223\345\274\200", 0));
        menu_2->setTitle(QApplication::translate("mainWindowClass", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class mainWindowClass: public Ui_mainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
