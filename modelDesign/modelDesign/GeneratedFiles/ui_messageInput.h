/********************************************************************************
** Form generated from reading UI file 'messageInput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEINPUT_H
#define UI_MESSAGEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_messageInput
{
public:
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *messageInput)
    {
        if (messageInput->objectName().isEmpty())
            messageInput->setObjectName(QStringLiteral("messageInput"));
        messageInput->resize(616, 61);
        textEdit = new QTextEdit(messageInput);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 421, 41));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(16);
        textEdit->setFont(font);
        buttonBox = new QDialogButtonBox(messageInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(450, 9, 156, 41));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(messageInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), messageInput, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), messageInput, SLOT(cancleAndExit()));

        QMetaObject::connectSlotsByName(messageInput);
    } // setupUi

    void retranslateUi(QDialog *messageInput)
    {
        messageInput->setWindowTitle(QApplication::translate("messageInput", "messageInput", 0));
        textEdit->setHtml(QApplication::translate("messageInput", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class messageInput: public Ui_messageInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEINPUT_H
