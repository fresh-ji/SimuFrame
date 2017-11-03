/********************************************************************************
** Form generated from reading UI file 'modelTypeInput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELTYPEINPUT_H
#define UI_MODELTYPEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_modelTypeInput
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit;
    QLabel *label_3;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *modelTypeInput)
    {
        if (modelTypeInput->objectName().isEmpty())
            modelTypeInput->setObjectName(QStringLiteral("modelTypeInput"));
        modelTypeInput->resize(643, 201);
        gridLayout = new QGridLayout(modelTypeInput);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(modelTypeInput);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);

        buttonBox = new QDialogButtonBox(modelTypeInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 5, Qt::AlignRight);

        label_2 = new QLabel(modelTypeInput);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignLeft);

        textEdit_2 = new QTextEdit(modelTypeInput);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy);
        textEdit_2->setMaximumSize(QSize(16777215, 40));
        textEdit_2->setFont(font);

        gridLayout->addWidget(textEdit_2, 1, 2, 1, 1);

        textEdit = new QTextEdit(modelTypeInput);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 40));
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 2, 1, 1);

        label_3 = new QLabel(modelTypeInput);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        textEdit_3 = new QTextEdit(modelTypeInput);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setMaximumSize(QSize(16777215, 40));
        textEdit_3->setFont(font);

        gridLayout->addWidget(textEdit_3, 2, 2, 1, 1);


        retranslateUi(modelTypeInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), modelTypeInput, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), modelTypeInput, SLOT(cancelAndExit()));

        QMetaObject::connectSlotsByName(modelTypeInput);
    } // setupUi

    void retranslateUi(QDialog *modelTypeInput)
    {
        modelTypeInput->setWindowTitle(QApplication::translate("modelTypeInput", "modelTypeInput", 0));
        label->setText(QApplication::translate("modelTypeInput", "\346\250\241\345\236\213\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("modelTypeInput", "\346\250\241\345\236\213IP\357\274\232", 0));
        textEdit_2->setHtml(QApplication::translate("modelTypeInput", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        textEdit->setHtml(QApplication::translate("modelTypeInput", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_3->setText(QApplication::translate("modelTypeInput", "\346\250\241\345\236\213\347\253\257\345\217\243\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class modelTypeInput: public Ui_modelTypeInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELTYPEINPUT_H
