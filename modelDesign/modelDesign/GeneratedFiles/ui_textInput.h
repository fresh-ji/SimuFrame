/********************************************************************************
** Form generated from reading UI file 'textInput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTINPUT_H
#define UI_TEXTINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_textInput
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *textInput)
    {
        if (textInput->objectName().isEmpty())
            textInput->setObjectName(QStringLiteral("textInput"));
        textInput->resize(628, 409);
        verticalLayout = new QVBoxLayout(textInput);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(textInput);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(textInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(textInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), textInput, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), textInput, SLOT(cancelAndExit()));

        QMetaObject::connectSlotsByName(textInput);
    } // setupUi

    void retranslateUi(QDialog *textInput)
    {
        textInput->setWindowTitle(QApplication::translate("textInput", "textInput", 0));
    } // retranslateUi

};

namespace Ui {
    class textInput: public Ui_textInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTINPUT_H
