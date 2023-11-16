/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mousecombobox.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    mousecombobox *Port_comboBox;
    QTextEdit *accept_textEdit;
    QTextEdit *send_textEdit;
    QPushButton *send_pushButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *BaudRate_comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *Stop_comboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *Data_comboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *Check_comboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QPushButton *choice_pushButton;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *time_lineEdit;
    QLabel *label_9;
    QCheckBox *time_checkBox;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *hex_accept_checkBox;
    QPushButton *clear_send_pushButton;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *hex_send_checkBox;
    QPushButton *clear_accept_pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 547);
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 10, 261, 61));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(500, 72, 261, 71));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        Port_comboBox = new mousecombobox(widget);
        Port_comboBox->setObjectName("Port_comboBox");
        Port_comboBox->setEditable(false);

        verticalLayout_2->addWidget(Port_comboBox);

        accept_textEdit = new QTextEdit(Widget);
        accept_textEdit->setObjectName("accept_textEdit");
        accept_textEdit->setGeometry(QRect(20, 80, 451, 321));
        send_textEdit = new QTextEdit(Widget);
        send_textEdit->setObjectName("send_textEdit");
        send_textEdit->setGeometry(QRect(20, 420, 451, 111));
        send_pushButton = new QPushButton(Widget);
        send_pushButton->setObjectName("send_pushButton");
        send_pushButton->setGeometry(QRect(500, 420, 111, 111));
        widget1 = new QWidget(Widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(500, 160, 261, 171));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        BaudRate_comboBox = new QComboBox(widget1);
        BaudRate_comboBox->setObjectName("BaudRate_comboBox");

        horizontalLayout_2->addWidget(BaudRate_comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(widget1);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        Stop_comboBox = new QComboBox(widget1);
        Stop_comboBox->setObjectName("Stop_comboBox");

        horizontalLayout_4->addWidget(Stop_comboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget1);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        Data_comboBox = new QComboBox(widget1);
        Data_comboBox->setObjectName("Data_comboBox");

        horizontalLayout_5->addWidget(Data_comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_7 = new QLabel(widget1);
        label_7->setObjectName("label_7");

        horizontalLayout_6->addWidget(label_7);

        Check_comboBox = new QComboBox(widget1);
        Check_comboBox->setObjectName("Check_comboBox");

        horizontalLayout_6->addWidget(Check_comboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(widget1);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        choice_pushButton = new QPushButton(widget1);
        choice_pushButton->setObjectName("choice_pushButton");

        horizontalLayout_7->addWidget(choice_pushButton);


        verticalLayout->addLayout(horizontalLayout_7);

        widget2 = new QWidget(Widget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(640, 450, 101, 81));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        time_lineEdit = new QLineEdit(widget2);
        time_lineEdit->setObjectName("time_lineEdit");

        horizontalLayout->addWidget(time_lineEdit);

        label_9 = new QLabel(widget2);
        label_9->setObjectName("label_9");

        horizontalLayout->addWidget(label_9);


        verticalLayout_3->addLayout(horizontalLayout);

        time_checkBox = new QCheckBox(widget2);
        time_checkBox->setObjectName("time_checkBox");

        verticalLayout_3->addWidget(time_checkBox);

        widget3 = new QWidget(Widget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(680, 340, 81, 61));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        hex_accept_checkBox = new QCheckBox(widget3);
        hex_accept_checkBox->setObjectName("hex_accept_checkBox");

        verticalLayout_4->addWidget(hex_accept_checkBox);

        clear_send_pushButton = new QPushButton(widget3);
        clear_send_pushButton->setObjectName("clear_send_pushButton");

        verticalLayout_4->addWidget(clear_send_pushButton);

        widget4 = new QWidget(Widget);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(500, 340, 91, 61));
        verticalLayout_5 = new QVBoxLayout(widget4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        hex_send_checkBox = new QCheckBox(widget4);
        hex_send_checkBox->setObjectName("hex_send_checkBox");

        verticalLayout_5->addWidget(hex_send_checkBox);

        clear_accept_pushButton = new QPushButton(widget4);
        clear_accept_pushButton->setObjectName("clear_accept_pushButton");

        verticalLayout_5->addWidget(clear_accept_pushButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700;\">\344\270\262\345\217\243\345\212\251\346\211\213</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">\344\270\262\345\217\243\351\200\211\346\213\251\357\274\232</span></p></body></html>", nullptr));
        send_pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\346\223\215\344\275\234", nullptr));
        choice_pushButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        time_checkBox->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        hex_accept_checkBox->setText(QCoreApplication::translate("Widget", "HEX\346\216\245\346\224\266", nullptr));
        clear_send_pushButton->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        hex_send_checkBox->setText(QCoreApplication::translate("Widget", "HEX\345\217\221\351\200\201", nullptr));
        clear_accept_pushButton->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
