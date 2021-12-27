/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QLabel *tcpClientStatuslabel;
    QProgressBar *progressBar;
    QPushButton *tcpClientBtn;
    QPushButton *tcpClientCloseBtn;

    void setupUi(QDialog *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(350, 180);
        tcpClientStatuslabel = new QLabel(TcpClient);
        tcpClientStatuslabel->setObjectName(QString::fromUtf8("tcpClientStatuslabel"));
        tcpClientStatuslabel->setGeometry(QRect(20, 9, 321, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        tcpClientStatuslabel->setFont(font);
        tcpClientStatuslabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(TcpClient);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 80, 331, 23));
        progressBar->setValue(0);
        tcpClientBtn = new QPushButton(TcpClient);
        tcpClientBtn->setObjectName(QString::fromUtf8("tcpClientBtn"));
        tcpClientBtn->setGeometry(QRect(70, 120, 75, 23));
        tcpClientCloseBtn = new QPushButton(TcpClient);
        tcpClientCloseBtn->setObjectName(QString::fromUtf8("tcpClientCloseBtn"));
        tcpClientCloseBtn->setGeometry(QRect(200, 120, 75, 23));

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QDialog *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "\346\216\245\346\224\266\347\253\257", nullptr));
        tcpClientStatuslabel->setText(QCoreApplication::translate("TcpClient", "\347\255\211\345\276\205\346\216\245\346\224\266\346\226\207\344\273\266......", nullptr));
        tcpClientBtn->setText(QCoreApplication::translate("TcpClient", "\345\217\226\346\266\210", nullptr));
        tcpClientCloseBtn->setText(QCoreApplication::translate("TcpClient", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
