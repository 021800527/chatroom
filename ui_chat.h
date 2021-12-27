/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QToolButton *boldToolButton;
    QToolButton *italicToolButton;
    QToolButton *underToolButton;
    QToolButton *colorToolButton;
    QToolButton *sendToolButton;
    QToolButton *saveToolButton;
    QToolButton *clearToolButton;
    QTextEdit *messageTextEdit;
    QPushButton *closePushButton;
    QPushButton *sendPushButton;
    QToolButton *colorToolButton1;
    QToolButton *speakToolButton;
    QToolButton *skinToolButton;

    void setupUi(QDialog *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(543, 435);
        label = new QLabel(Chat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 441, 31));
        textBrowser = new QTextBrowser(Chat);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 60, 481, 161));
        fontComboBox = new QFontComboBox(Chat);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(40, 230, 61, 31));
        fontComboBox->setMaxVisibleItems(8);
        comboBox = new QComboBox(Chat);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 230, 71, 31));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        boldToolButton = new QToolButton(Chat);
        boldToolButton->setObjectName(QString::fromUtf8("boldToolButton"));
        boldToolButton->setGeometry(QRect(310, 230, 30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolButton->setIcon(icon);
        boldToolButton->setIconSize(QSize(20, 20));
        boldToolButton->setCheckable(true);
        italicToolButton = new QToolButton(Chat);
        italicToolButton->setObjectName(QString::fromUtf8("italicToolButton"));
        italicToolButton->setGeometry(QRect(340, 230, 30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolButton->setIcon(icon1);
        italicToolButton->setIconSize(QSize(20, 20));
        italicToolButton->setCheckable(true);
        underToolButton = new QToolButton(Chat);
        underToolButton->setObjectName(QString::fromUtf8("underToolButton"));
        underToolButton->setGeometry(QRect(370, 230, 30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underToolButton->setIcon(icon2);
        underToolButton->setIconSize(QSize(20, 20));
        underToolButton->setCheckable(true);
        colorToolButton = new QToolButton(Chat);
        colorToolButton->setObjectName(QString::fromUtf8("colorToolButton"));
        colorToolButton->setGeometry(QRect(400, 230, 30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolButton->setIcon(icon3);
        colorToolButton->setIconSize(QSize(20, 20));
        sendToolButton = new QToolButton(Chat);
        sendToolButton->setObjectName(QString::fromUtf8("sendToolButton"));
        sendToolButton->setGeometry(QRect(430, 230, 30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolButton->setIcon(icon4);
        sendToolButton->setIconSize(QSize(20, 20));
        saveToolButton = new QToolButton(Chat);
        saveToolButton->setObjectName(QString::fromUtf8("saveToolButton"));
        saveToolButton->setGeometry(QRect(460, 230, 30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolButton->setIcon(icon5);
        saveToolButton->setIconSize(QSize(20, 20));
        clearToolButton = new QToolButton(Chat);
        clearToolButton->setObjectName(QString::fromUtf8("clearToolButton"));
        clearToolButton->setGeometry(QRect(490, 230, 30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolButton->setIcon(icon6);
        clearToolButton->setIconSize(QSize(20, 20));
        messageTextEdit = new QTextEdit(Chat);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(40, 270, 481, 121));
        closePushButton = new QPushButton(Chat);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(310, 400, 91, 25));
        closePushButton->setIconSize(QSize(25, 31));
        sendPushButton = new QPushButton(Chat);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));
        sendPushButton->setGeometry(QRect(420, 400, 91, 25));
        colorToolButton1 = new QToolButton(Chat);
        colorToolButton1->setObjectName(QString::fromUtf8("colorToolButton1"));
        colorToolButton1->setGeometry(QRect(280, 230, 30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/color1.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolButton1->setIcon(icon7);
        colorToolButton1->setIconSize(QSize(20, 20));
        colorToolButton1->setCheckable(true);
        speakToolButton = new QToolButton(Chat);
        speakToolButton->setObjectName(QString::fromUtf8("speakToolButton"));
        speakToolButton->setGeometry(QRect(250, 230, 30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/speak.png"), QSize(), QIcon::Normal, QIcon::Off);
        speakToolButton->setIcon(icon8);
        speakToolButton->setIconSize(QSize(20, 20));
        speakToolButton->setCheckable(true);
        skinToolButton = new QToolButton(Chat);
        skinToolButton->setObjectName(QString::fromUtf8("skinToolButton"));
        skinToolButton->setGeometry(QRect(220, 230, 30, 30));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        skinToolButton->setIcon(icon9);
        skinToolButton->setIconSize(QSize(20, 20));
        skinToolButton->setCheckable(true);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QDialog *Chat)
    {
        Chat->setWindowTitle(QCoreApplication::translate("Chat", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Chat", "TextLabel", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Chat", "9", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Chat", "10", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Chat", "11", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Chat", "12", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Chat", "13", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Chat", "14", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Chat", "15", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Chat", "16", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Chat", "17", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("Chat", "9", nullptr));
        boldToolButton->setText(QCoreApplication::translate("Chat", "\345\212\240\347\262\227", nullptr));
        italicToolButton->setText(QCoreApplication::translate("Chat", "\346\226\234\344\275\223", nullptr));
        underToolButton->setText(QCoreApplication::translate("Chat", "\344\270\213\345\210\222\347\272\277", nullptr));
        colorToolButton->setText(QCoreApplication::translate("Chat", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
        sendToolButton->setText(QCoreApplication::translate("Chat", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
        saveToolButton->setText(QCoreApplication::translate("Chat", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        clearToolButton->setText(QCoreApplication::translate("Chat", "\346\270\205\351\231\244\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        closePushButton->setText(QCoreApplication::translate("Chat", "\345\205\263\351\227\255", nullptr));
        sendPushButton->setText(QCoreApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
        colorToolButton1->setText(QCoreApplication::translate("Chat", "\345\212\240\347\262\227", nullptr));
        speakToolButton->setText(QCoreApplication::translate("Chat", "\350\257\255\351\237\263", nullptr));
        skinToolButton->setText(QCoreApplication::translate("Chat", "\346\215\242\350\202\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
