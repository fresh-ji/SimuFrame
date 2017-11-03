/********************************************************************************
** Form generated from reading UI file 'eventListDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTLISTDISPLAY_H
#define UI_EVENTLISTDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_eventListDisplay
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *eventListDisplay)
    {
        if (eventListDisplay->objectName().isEmpty())
            eventListDisplay->setObjectName(QStringLiteral("eventListDisplay"));
        eventListDisplay->resize(359, 273);
        verticalLayout = new QVBoxLayout(eventListDisplay);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(eventListDisplay);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QFont font;
        font.setPointSize(11);
        listWidget->setFont(font);

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(eventListDisplay);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(eventListDisplay);
        QObject::connect(buttonBox, SIGNAL(accepted()), eventListDisplay, SLOT(okAndExit()));
        QObject::connect(buttonBox, SIGNAL(rejected()), eventListDisplay, SLOT(cancelAndExit()));

        QMetaObject::connectSlotsByName(eventListDisplay);
    } // setupUi

    void retranslateUi(QDialog *eventListDisplay)
    {
        eventListDisplay->setWindowTitle(QApplication::translate("eventListDisplay", "eventListDisplay", 0));
    } // retranslateUi

};

namespace Ui {
    class eventListDisplay: public Ui_eventListDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTLISTDISPLAY_H
