#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QPushButton>
#include <QPainterPath>
#include <QPainter>
#include <QString>
#include <QNetworkInterface>
#include<QDebug>
#include<QMessageBox>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

login::login(QWidget *parent) :
    BaseWindow(parent),
    ui(new Ui::login)
{
    titleBar = new BaseWindow;
    ui->setupUi(this);


    initTitleBar();
    initControl();

}

login::~login()
{
    delete ui;
}

#if 1
void login::initTitleBar()
{
    m_titleBar->setTitleRoll();

    m_titleBar->move(0,0);
    m_titleBar->raise();
    m_titleBar->setBackgroundColor(0,0,0,true);
    m_titleBar->setButtonType(MIN_MAX_BUTTON);
    m_titleBar->setTitleWidth(this->width());

}
#endif

void login::initControl()
{


    //暗注释
    ui->headPortraitLabel->setStyleSheet(tr("border-image: url(:/icon/head.jpg);"));
    ui->nameLineEdit->setPlaceholderText(tr(" 用户名"));
    ui->ipLineEdit->setPlaceholderText(tr(" IP地址"));

    ui->ipLineEdit->setText(getIP());   //将ip显示到地址栏上

}

QString login::getIP()
{
    QList<QHostAddress>list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}


void login::on_createPushButton_clicked()
{
    users.name = ui->nameLineEdit->text();
    if(ui->nameLineEdit->text() == "")
    {QMessageBox::warning(nullptr,tr("警告"),tr("用户名不能为空"),QMessageBox::Ok);return;}
    users.hostaddress = getIP();
    users.address = getIP();
    //qDebug() << users.address << users.name << users.hostaddress;
    chat = new chatRoom(0,users);
    //chat->setUser(users);
    chat->show();

    this->hide();
}


