/********************************************************************************
** Form generated from reading UI file 'dataStructureInput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASTRUCTUREINPUT_H
#define UI_DATASTRUCTUREINPUT_H

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

class Ui_dataStructureInput
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dataStructureInput)
    {
        if (dataStructureInput->objectName().isEmpty())
            dataStructureInput->setObjectName(QStringLiteral("dataStructureInput"));
        dataStructureInput->resize(874, 522);
        verticalLayout = new QVBoxLayout(dataStructureInput);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(dataStructureInput);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(dataStructureInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dataStructureInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), dataStructureInput, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dataStructureInput, SLOT(cancelAndExit()));

        QMetaObject::connectSlotsByName(dataStructureInput);
    } // setupUi

    void retranslateUi(QDialog *dataStructureInput)
    {
        dataStructureInput->setWindowTitle(QApplication::translate("dataStructureInput", "dataStructureInput", 0));
    } // retranslateUi

};

namespace Ui {
    class dataStructureInput: public Ui_dataStructureInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASTRUCTUREINPUT_H
