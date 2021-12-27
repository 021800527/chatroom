/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *nameLable;
    QLabel *ipLabel;
    QPushButton *createPushButton;
    QLabel *headPortraitLabel;
    QLabel *backgroundLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *ipLineEdit;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(400, 327);
        login->setStyleSheet(QString::fromUtf8(""));
        nameLable = new QLabel(login);
        nameLable->setObjectName(QString::fromUtf8("nameLable"));
        nameLable->setGeometry(QRect(70, 210, 41, 31));
        QFont font;
        font.setPointSize(11);
        nameLable->setFont(font);
        nameLable->setStyleSheet(QString::fromUtf8("image: url(:/icon/name.png);"));
        ipLabel = new QLabel(login);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        ipLabel->setGeometry(QRect(70, 250, 41, 31));
        ipLabel->setFont(font);
        ipLabel->setStyleSheet(QString::fromUtf8("image: url(:/icon/IP.png);"));
        createPushButton = new QPushButton(login);
        createPushButton->setObjectName(QString::fromUtf8("createPushButton"));
        createPushButton->setGeometry(QRect(130, 290, 161, 31));
        headPortraitLabel = new QLabel(login);
        headPortraitLabel->setObjectName(QString::fromUtf8("headPortraitLabel"));
        headPortraitLabel->setGeometry(QRect(160, 120, 91, 81));
        headPortraitLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/head.jpg);"));
        backgroundLabel = new QLabel(login);
        backgroundLabel->setObjectName(QString::fromUtf8("backgroundLabel"));
        backgroundLabel->setGeometry(QRect(0, 0, 401, 201));
        backgroundLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/bargroud.jpg);"));
        nameLineEdit = new QLineEdit(login);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(120, 210, 221, 31));
        ipLineEdit = new QLineEdit(login);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(120, 250, 221, 31));
        backgroundLabel->raise();
        nameLable->raise();
        ipLabel->raise();
        createPushButton->raise();
        nameLineEdit->raise();
        ipLineEdit->raise();
        headPortraitLabel->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        ipLabel->setText(QString());
        createPushButton->setText(QCoreApplication::translate("login", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        headPortraitLabel->setText(QString());
        backgroundLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
