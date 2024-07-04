/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *mainLineEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *cleanButton;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QPushButton *delButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *mulButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *divButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *leftButton;
    QPushButton *theroButton;
    QPushButton *rightButton;
    QPushButton *equButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(203, 301);
        mainLineEdit = new QLineEdit(Widget);
        mainLineEdit->setObjectName("mainLineEdit");
        mainLineEdit->setGeometry(QRect(10, 20, 181, 41));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 70, 180, 226));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cleanButton = new QPushButton(layoutWidget);
        cleanButton->setObjectName("cleanButton");
        cleanButton->setMinimumSize(QSize(40, 40));
        cleanButton->setMaximumSize(QSize(40, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        cleanButton->setFont(font);

        gridLayout->addWidget(cleanButton, 0, 0, 1, 1);

        plusButton = new QPushButton(layoutWidget);
        plusButton->setObjectName("plusButton");
        plusButton->setMinimumSize(QSize(40, 40));
        plusButton->setMaximumSize(QSize(40, 40));
        plusButton->setFont(font);

        gridLayout->addWidget(plusButton, 0, 1, 1, 1);

        minusButton = new QPushButton(layoutWidget);
        minusButton->setObjectName("minusButton");
        minusButton->setMinimumSize(QSize(40, 40));
        minusButton->setMaximumSize(QSize(40, 40));
        minusButton->setFont(font);

        gridLayout->addWidget(minusButton, 0, 2, 1, 1);

        delButton = new QPushButton(layoutWidget);
        delButton->setObjectName("delButton");
        delButton->setMinimumSize(QSize(40, 40));
        delButton->setMaximumSize(QSize(40, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setItalic(false);
        delButton->setFont(font1);
        delButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(delButton, 0, 3, 1, 1);

        sevenButton = new QPushButton(layoutWidget);
        sevenButton->setObjectName("sevenButton");
        sevenButton->setMinimumSize(QSize(40, 40));
        sevenButton->setMaximumSize(QSize(40, 40));
        sevenButton->setFont(font);

        gridLayout->addWidget(sevenButton, 1, 0, 1, 1);

        eightButton = new QPushButton(layoutWidget);
        eightButton->setObjectName("eightButton");
        eightButton->setMinimumSize(QSize(40, 40));
        eightButton->setMaximumSize(QSize(40, 40));
        eightButton->setFont(font);

        gridLayout->addWidget(eightButton, 1, 1, 1, 1);

        nineButton = new QPushButton(layoutWidget);
        nineButton->setObjectName("nineButton");
        nineButton->setMinimumSize(QSize(40, 40));
        nineButton->setMaximumSize(QSize(40, 40));
        nineButton->setFont(font);

        gridLayout->addWidget(nineButton, 1, 2, 1, 1);

        mulButton = new QPushButton(layoutWidget);
        mulButton->setObjectName("mulButton");
        mulButton->setMinimumSize(QSize(40, 40));
        mulButton->setMaximumSize(QSize(40, 40));
        mulButton->setFont(font);

        gridLayout->addWidget(mulButton, 1, 3, 1, 1);

        fourButton = new QPushButton(layoutWidget);
        fourButton->setObjectName("fourButton");
        fourButton->setMinimumSize(QSize(40, 40));
        fourButton->setMaximumSize(QSize(40, 40));
        fourButton->setFont(font);

        gridLayout->addWidget(fourButton, 2, 0, 1, 1);

        fiveButton = new QPushButton(layoutWidget);
        fiveButton->setObjectName("fiveButton");
        fiveButton->setMinimumSize(QSize(40, 40));
        fiveButton->setMaximumSize(QSize(40, 40));
        fiveButton->setFont(font);

        gridLayout->addWidget(fiveButton, 2, 1, 1, 1);

        sixButton = new QPushButton(layoutWidget);
        sixButton->setObjectName("sixButton");
        sixButton->setMinimumSize(QSize(40, 40));
        sixButton->setMaximumSize(QSize(40, 40));
        sixButton->setFont(font);

        gridLayout->addWidget(sixButton, 2, 2, 1, 1);

        divButton = new QPushButton(layoutWidget);
        divButton->setObjectName("divButton");
        divButton->setMinimumSize(QSize(40, 40));
        divButton->setMaximumSize(QSize(40, 40));
        divButton->setFont(font);

        gridLayout->addWidget(divButton, 2, 3, 1, 1);

        oneButton = new QPushButton(layoutWidget);
        oneButton->setObjectName("oneButton");
        oneButton->setMinimumSize(QSize(40, 40));
        oneButton->setMaximumSize(QSize(40, 40));
        oneButton->setFont(font);

        gridLayout->addWidget(oneButton, 3, 0, 1, 1);

        twoButton = new QPushButton(layoutWidget);
        twoButton->setObjectName("twoButton");
        twoButton->setMinimumSize(QSize(40, 40));
        twoButton->setMaximumSize(QSize(40, 40));
        twoButton->setFont(font);

        gridLayout->addWidget(twoButton, 3, 1, 1, 1);

        threeButton = new QPushButton(layoutWidget);
        threeButton->setObjectName("threeButton");
        threeButton->setMinimumSize(QSize(40, 40));
        threeButton->setMaximumSize(QSize(40, 40));
        threeButton->setFont(font);

        gridLayout->addWidget(threeButton, 3, 2, 1, 1);

        leftButton = new QPushButton(layoutWidget);
        leftButton->setObjectName("leftButton");
        leftButton->setMinimumSize(QSize(40, 40));
        leftButton->setMaximumSize(QSize(40, 40));
        leftButton->setFont(font);

        gridLayout->addWidget(leftButton, 4, 0, 1, 1);

        theroButton = new QPushButton(layoutWidget);
        theroButton->setObjectName("theroButton");
        theroButton->setMinimumSize(QSize(40, 40));
        theroButton->setMaximumSize(QSize(40, 40));
        theroButton->setFont(font);

        gridLayout->addWidget(theroButton, 4, 1, 1, 1);

        rightButton = new QPushButton(layoutWidget);
        rightButton->setObjectName("rightButton");
        rightButton->setMinimumSize(QSize(40, 40));
        rightButton->setMaximumSize(QSize(40, 40));
        rightButton->setFont(font);

        gridLayout->addWidget(rightButton, 4, 2, 1, 1);

        equButton = new QPushButton(layoutWidget);
        equButton->setObjectName("equButton");
        equButton->setMinimumSize(QSize(40, 40));
        equButton->setMaximumSize(QSize(40, 90));
        equButton->setFont(font);

        gridLayout->addWidget(equButton, 3, 3, 2, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        cleanButton->setText(QCoreApplication::translate("Widget", "C", nullptr));
        plusButton->setText(QCoreApplication::translate("Widget", "+", nullptr));
        minusButton->setText(QCoreApplication::translate("Widget", "-", nullptr));
        delButton->setText(QString());
        sevenButton->setText(QCoreApplication::translate("Widget", "7", nullptr));
        eightButton->setText(QCoreApplication::translate("Widget", "8", nullptr));
        nineButton->setText(QCoreApplication::translate("Widget", "9", nullptr));
        mulButton->setText(QCoreApplication::translate("Widget", "*", nullptr));
        fourButton->setText(QCoreApplication::translate("Widget", "4", nullptr));
        fiveButton->setText(QCoreApplication::translate("Widget", "5", nullptr));
        sixButton->setText(QCoreApplication::translate("Widget", "6", nullptr));
        divButton->setText(QCoreApplication::translate("Widget", "/", nullptr));
        oneButton->setText(QCoreApplication::translate("Widget", "1", nullptr));
        twoButton->setText(QCoreApplication::translate("Widget", "2", nullptr));
        threeButton->setText(QCoreApplication::translate("Widget", "3", nullptr));
        leftButton->setText(QCoreApplication::translate("Widget", "(", nullptr));
        theroButton->setText(QCoreApplication::translate("Widget", "0", nullptr));
        rightButton->setText(QCoreApplication::translate("Widget", ")", nullptr));
        equButton->setText(QCoreApplication::translate("Widget", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
