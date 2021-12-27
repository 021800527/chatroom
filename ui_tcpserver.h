/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QLabel *serverStatuslabel;
    QProgressBar *progressBar;
    QPushButton *serverOpenBtn;
    QPushButton *serverSendBtn;
    QPushButton *serverCloseBtn;

    void setupUi(QDialog *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(350, 180);
        serverStatuslabel = new QLabel(TcpServer);
        serverStatuslabel->setObjectName(QString::fromUtf8("serverStatuslabel"));
        serverStatuslabel->setGeometry(QRect(19, 9, 311, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        serverStatuslabel->setFont(font);
        serverStatuslabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(TcpServer);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 90, 271, 20));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        serverOpenBtn = new QPushButton(TcpServer);
        serverOpenBtn->setObjectName(QString::fromUtf8("serverOpenBtn"));
        serverOpenBtn->setGeometry(QRect(30, 150, 75, 23));
        serverSendBtn = new QPushButton(TcpServer);
        serverSendBtn->setObjectName(QString::fromUtf8("serverSendBtn"));
        serverSendBtn->setGeometry(QRect(130, 150, 75, 23));
        serverCloseBtn = new QPushButton(TcpServer);
        serverCloseBtn->setObjectName(QString::fromUtf8("serverCloseBtn"));
        serverCloseBtn->setGeometry(QRect(240, 150, 75, 23));

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QDialog *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201\347\253\257", nullptr));
        serverStatuslabel->setText(QCoreApplication::translate("TcpServer", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266\357\274\232", nullptr));
        serverOpenBtn->setText(QCoreApplication::translate("TcpServer", "\346\211\223\345\274\200", nullptr));
        serverSendBtn->setText(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201", nullptr));
        serverCloseBtn->setText(QCoreApplication::translate("TcpServer", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
