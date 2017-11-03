/********************************************************************************
** Form generated from reading UI file 'eventFunctionInput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTFUNCTIONINPUT_H
#define UI_EVENTFUNCTIONINPUT_H

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

class Ui_eventFunctionInput
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *eventFunctionInput)
    {
        if (eventFunctionInput->objectName().isEmpty())
            eventFunctionInput->setObjectName(QStringLiteral("eventFunctionInput"));
        eventFunctionInput->resize(636, 455);
        verticalLayout = new QVBoxLayout(eventFunctionInput);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(eventFunctionInput);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setPointSize(11);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(eventFunctionInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(eventFunctionInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), eventFunctionInput, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), eventFunctionInput, SLOT(cancelAndExit()));

        QMetaObject::connectSlotsByName(eventFunctionInput);
    } // setupUi

    void retranslateUi(QDialog *eventFunctionInput)
    {
        eventFunctionInput->setWindowTitle(QApplication::translate("eventFunctionInput", "eventFunctionInput", 0));
    } // retranslateUi

};

namespace Ui {
    class eventFunctionInput: public Ui_eventFunctionInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTFUNCTIONINPUT_H
