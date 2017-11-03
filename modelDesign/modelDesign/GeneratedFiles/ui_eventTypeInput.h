/********************************************************************************
** Form generated from reading UI file 'eventTypeInput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTTYPEINPUT_H
#define UI_EVENTTYPEINPUT_H

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

class Ui_eventTypeInput
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *eventTypeInput)
    {
        if (eventTypeInput->objectName().isEmpty())
            eventTypeInput->setObjectName(QStringLiteral("eventTypeInput"));
        eventTypeInput->resize(697, 108);
        gridLayout = new QGridLayout(eventTypeInput);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(eventTypeInput);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(eventTypeInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        label = new QLabel(eventTypeInput);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(eventTypeInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), eventTypeInput, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), eventTypeInput, SLOT(cancelAndExit()));

        QMetaObject::connectSlotsByName(eventTypeInput);
    } // setupUi

    void retranslateUi(QDialog *eventTypeInput)
    {
        eventTypeInput->setWindowTitle(QApplication::translate("eventTypeInput", "eventTypeInput", 0));
        label->setText(QApplication::translate("eventTypeInput", "\344\272\213\344\273\266\345\220\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class eventTypeInput: public Ui_eventTypeInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTTYPEINPUT_H
