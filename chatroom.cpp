#include "chatroom.h"
#include "ui_chatroom.h"
#include "tcpserver.h"
#include "tcpclient.h"
#include <QFileDialog>
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QColorDialog>
#include <QTextCharFormat>
#include <QKeyEvent>
#include <QDebug>
#include <QMovie>
#include <QTimer>
#include <QQueue>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

chatRoom::chatRoom(QWidget *parent,User u) :
    QWidget(parent),
    privateChat(nullptr),
    privateChat1(nullptr),
    ui(new Ui::chatRoom)
{
    ui->setupUi(this);
    setUser(u);
    setWindowTitle("聊天室  "+user.address);
    QPixmap img1 = QPixmap("C:/Users/Administrator/Desktop/20B5A376C5617A347E30475078F9A97C .jpg");
//    img1=img1.scaled(img1.width()*2,img1.height()*2);
//    img1.save("C:/Users/Administrator/Desktop/20B5A376C5617A347E30475078F9A97C .jpg");
//    QString imgPath = QString("20B5A376C5617A347E30475078F9A97C .jpg");
//    imgPath = QString("<img src=\"%1\">").arg(imgPath);
//    ui->messageBrowser->insertHtml(imgPath);
    //背景图片第一次失败
//    setStyleSheet(tr("border-image: url(:/new/login/icon/bargroud.jpg);"));

    //第二次太透明了
//    ui->messageBrowser->setStyleSheet(tr("background:transparent"));
//    ui->messageTextEdit->setStyleSheet(tr("background:transparent;"));

    //使用前端知识瞎打竟然可以成功
    ui->messageBrowser->setStyleSheet("QTextBrowser{background-color: rgba(255, 255, 255, 0.7);}");
    ui->messageTextEdit->setStyleSheet("QTextEdit{background-color: rgba(255, 255, 255, 0.7);}");
    ui->userTableWidget->setStyleSheet("QTableWidget{background-color: rgba(255, 255, 255, 0.9);}");
    QPalette pal = this ->palette();
    QPixmap background = QPixmap(":icon/background.jpg");
    //先这样吧 我麻了

    pal.setBrush(QPalette::Background,QBrush(background.scaled(this->width(),this->height())));
    setPalette(pal);

    udpSocket = new QUdpSocket(this);
     //设置端口号
    port = 45454;
    //绑定端口
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);



    server = new TcpServer(this);
    connect(server,SIGNAL(sendFileName(QString)),
            this,SLOT(getFileName(QString)));
    connect(ui->messageTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),
            this,SLOT(currentFormatChanged(QTextCharFormat)));

    //设置消息过滤器
    ui->messageTextEdit->installEventFilter(this);
    //计时器
    QTimer *timer = new QTimer(this); //this 为parent类, 表示当前窗口

    connect(timer, SIGNAL(timeout()), this, SLOT(check())); // SLOT填入一个槽函数

    timer->start(1000);
}
bool flag;
QString res;
void chatRoom::check()
{
    QString MSG = ui->messageTextEdit->toPlainText();
    QString msg;
    if(MSG!="")msg= MSG.split('/').last().split('.').last();
    if(msg=="gif"||msg=="jpg"||msg=="png")
    {
        qDebug()<<MSG[1];
        if(MSG[0]=="f")
            ui->messageTextEdit->clear();
        else
            ui->messageTextEdit->setText(MSG.mid(1));
        addAnimation_edit(QUrl("xxx"), MSG.mid(8));
        flag = true;
        res = MSG.mid(8);
    }

}
chatRoom::~chatRoom()
{
    QHash<QMovie*, QUrl>::const_iterator i;
    for (i = m_hasUrls.constBegin(); i != m_hasUrls.constEnd(); ++i)
    {
        delete i.key();
    }
    delete ui;
}
// 插入图片
void chatRoom::addAnimation(const QUrl& url, const QString& fileName)
{
    //插入Html描述的图片
    ui->messageBrowser->insertHtml("<img src='" + url.toString() + "'/>");

    //判断是否是相同的图片
    if (m_lstUrls.contains(url))
    {
        return;
    }
    else
    {
        m_lstUrls.append(url);
    }

    //创建QMovie以显示Gif
    QMovie* movie = new QMovie(this);
    movie->setFileName(fileName);
    movie->setCacheMode(QMovie::CacheNone);

    m_hasUrls.insert(movie, url);

    //绑定帧切换信号槽
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(subAnimate(int)));
    movie->start();
}
// 实时图片显示
void chatRoom::addAnimation_edit(const QUrl& url, const QString& fileName)
{
    //插入Html描述的图片
    ui->messageTextEdit->insertHtml("<img src='" + url.toString() + "'/>");

    //判断是否是相同的图片
    if (m_lstUrls.contains(url))
    {
        return;
    }
    else
    {
        m_lstUrls.append(url);
    }

    //创建QMovie以显示Gif
    QMovie* movie = new QMovie(this);
    movie->setFileName(fileName);
    movie->setCacheMode(QMovie::CacheNone);

    m_hasUrls.insert(movie, url);

    //绑定帧切换信号槽
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(subAnimate_edit(int)));
    movie->start();
}
// 针对动图进行逐帧播放
void chatRoom::subAnimate(int a)
{
    //使用QMovie中的当前帧替换掉富文本中的图片元素
    QMovie* movie = qobject_cast<QMovie*>(sender());
    ui->messageBrowser->document()->addResource(QTextDocument::ImageResource,
            m_hasUrls.value(movie), movie->currentPixmap());
    ui->messageBrowser->setLineWrapColumnOrWidth(ui->messageBrowser->lineWrapColumnOrWidth());
}
// 实时图片显示
void chatRoom::subAnimate_edit(int a)
{
    //使用QMovie中的当前帧替换掉富文本中的图片元素
    QMovie* movie = qobject_cast<QMovie*>(sender());
    ui->messageTextEdit->document()->addResource(QTextDocument::ImageResource,
            m_hasUrls.value(movie), movie->currentPixmap());
    ui->messageTextEdit->setLineWrapColumnOrWidth(ui->messageBrowser->lineWrapColumnOrWidth());
}
//成员加入处理函数
void chatRoom::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
    //使用主机名判断用户是否已经加入
    bool isEmpty = ui->userTableWidget
            ->findItems(localHostName,Qt::MatchExactly).isEmpty();

    //如果用户未加入则向界面右侧的用户列表加入新用户的信息
    if(isEmpty) {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0,0,user);
        ui->userTableWidget->setItem(0,1,host);
        ui->userTableWidget->setItem(0,2,ip);

        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        ui->messageBrowser->append(tr("%1 在线").arg(userName));
        ui->userNumLabel->setText(tr("在线人数： %1").arg(ui->userTableWidget->rowCount()));
        //发送新用户登录消息
        sendMessage(NewParticipant);
    }
}

//有人离开了
void chatRoom::participantLeft(QString username, QString localHostName, QString time)
{
    int rowNum = ui->userTableWidget->findItems(localHostName,
                                                Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1 于 %2 离开！").arg(username).arg(time));
    ui->userNumLabel->setText(tr("在线人数： %1").arg(ui->userTableWidget->rowCount()));
}

//广播消息，type是我自己定义的用于区分的变量名
void chatRoom::sendMessage(messageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();   //获取用户名、主机名
    QString address = getIP();
    out << type << getUserName() << localHostName;

    QString clientAddress;
    int row;

    //判断发送消息的类型
    switch(type)
    {
    case Message:
        //发送的是消息
        if(ui->messageTextEdit->toPlainText() == "")
        {
            QMessageBox::warning(nullptr,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        out << address << getMessage();
        ui->messageBrowser->verticalScrollBar()->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;

    case NewParticipant:
        //广播新用户加入的消息
        out << address;
        break;

    case LeftParticipant:
        //广播用户离开的消息
        break;

    case FileName:
        //发送传输的文件名
        row = ui->userTableWidget->currentRow();
        clientAddress= ui->userTableWidget->item(row,2)->text();
        out << address << clientAddress << fileName;
        break;

    case Refuse:
        //发送拒绝接受文件消息
        out << serverAddress;
        break;
    }
    //进行udp广播
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
}

//判断是否接收、发送文件
void chatRoom::hasPendingFile(QString userName, QString serverAddress,
                            QString clientAddress, QString fileName)
{

    QString ipAddress = getIP();
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,tr("接收文件"),tr("来自%1(%2)的文件：%3,是否接收?").arg(userName).arg(serverAddress).arg(fileName),QMessageBox::Yes,QMessageBox::No);
        if(btn == QMessageBox::Yes) {QString name = QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);
            if(!name.isEmpty())
            {
                TcpClient *client = new TcpClient(this);
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
            }
        }
        else {
            sendMessage(Refuse,serverAddress);
        }
    }
}

//保存接受的文件
bool chatRoom::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text)) {
        QMessageBox::warning(this,tr("保存文件"),
                             tr("无法保存文件 %1:\n %2").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->messageBrowser->toPlainText();
    return true;
}


//关闭事件：在关闭程序时发送用户离开的广播，让其他端点在其用户列表中删除用户
void chatRoom::closeEvent(QCloseEvent *event)
{
    sendMessage(LeftParticipant);
    QWidget::closeEvent(event);
}

//快捷键ctrl+enter发送消息
bool chatRoom::eventFilter(QObject *obj, QEvent *event)
{
#if 1
    if(obj == ui->messageTextEdit){

        if(event->type() == QEvent::KeyPress){
            QKeyEvent *k = static_cast<QKeyEvent *>(event);
            //按下ctrl+enter发消息
            if(k->key() == Qt::Key_Return &&(k->modifiers() & Qt::ControlModifier))
            {
                on_sendButton_clicked();
                return true;
            }
        }
    }
    return false;
#endif
}

//获取IP地址
QString chatRoom::getIP()
{
    return user.address;
}

//获取用户名
QString chatRoom::getUserName()
{
    return user.name;
}

//获取用户输入的消息并设置
QString chatRoom::getMessage()
{
    QString msg = ui->messageTextEdit->toHtml();
    QString MSG = ui->messageTextEdit->toPlainText();
    MSG = MSG.split('/').last().split('.').last();
    qDebug()<<MSG;
    ui->messageTextEdit->clear();   //将文本编辑器内容清空
    ui->messageTextEdit->setFocus();
    return msg;
}

//处理接收到的广播消息
void chatRoom::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());   //调整为接收到数据的大小
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString clientAddress,fileName;
        QString userName,localHostName,ipAddress,message;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");
        switch(messageType)
        {
        //显示发送的消息
        case Message:
            in >> userName >> localHostName >> ipAddress >> message;
            ui->messageBrowser->setTextColor(Qt::blue);
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->messageBrowser->append("[" + userName + "]" + time);
            ui->messageBrowser->append("\n");
            if(flag==true){
                addAnimation(QUrl("yyy"), res);
                flag = false;
                res = "";
                ui->messageBrowser->verticalScrollBar()->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
            }
            else {
                 ui->messageBrowser->append(message);
            }
            break;

        //有新成员加入
        case NewParticipant:
            in >> userName >> localHostName >> ipAddress;
            newParticipant(userName,localHostName,ipAddress);  //加入处理
            break;

        //有成员离开
        case LeftParticipant:
            in >> userName >> localHostName;
            participantLeft(userName,localHostName,time);  //进行离开处理

        //要发送的文件名
        case FileName:
            in >> userName >> localHostName >> ipAddress;
            in >> clientAddress >> fileName;
            hasPendingFile(userName,ipAddress,clientAddress,fileName);
            break;

        //拒绝接受的文件
        case Refuse:
            in >> userName >> localHostName;
            QString serverAddress;
            in >> serverAddress;
            QString ipAddress = getIP();
            if(ipAddress == serverAddress)
            {
                server->refused();
            }
            break;
        }
    }
}

//发送按钮
void chatRoom::on_sendButton_clicked()
{
    sendMessage(Message);
}

//给出文件名
void chatRoom::getFileName(QString name)
{
    fileName = name;
    sendMessage(FileName);   //upd广播要发送的文件名
}

//传输文件按钮
void chatRoom::on_sendToolBtn_clicked()
{
    if(ui->userTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(nullptr,tr("选择用户"),
                             tr("请先从用户列表选择要传送的用户!"),QMessageBox::Ok);
        return;
    }
    server->show();
    server->initServer();
}
//换肤
void chatRoom::on_skinToolBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("文件对话框！"),
                                                        "F:",
                                                        tr("图片文件(*png *jpg);;"));
    if(fileName!=""){
        ui->messageBrowser->setStyleSheet("QTextBrowser{background-color: rgba(255, 255, 255, 0.7);}");
        ui->messageTextEdit->setStyleSheet("QTextEdit{background-color: rgba(255, 255, 255, 0.7);}");
        ui->fontComboBox->setStyleSheet("QFontComboBox{background-color: rgba(255, 255, 255, 0.9);}");
        ui->userTableWidget->setStyleSheet("QTableWidget{background-color: rgba(255, 255, 255, 0.9);}");
        QPalette pal = this ->palette();
        QPixmap background = QPixmap(fileName);

        pal.setBrush(QPalette::Background,QBrush(background.scaled(this->width(),this->height())));
        setPalette(pal);}
}
//更改字体大小
void chatRoom::on_SizeComboBox_currentIndexChanged(const QString &arg1)
{
    ui->messageTextEdit->setFontPointSize(arg1.toDouble());
    ui->messageTextEdit->setFocus();
}

//加粗
void chatRoom::on_boldToolBtn_clicked(bool checked)
{
    if(checked)
    {
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    }
    else
    {
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    }
    ui->messageTextEdit->setFocus();
}


//斜体
void chatRoom::on_italicToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontItalic(checked);
    ui->messageTextEdit->setFocus();
}

//下划线
void chatRoom::on_underlineToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontUnderline(checked);
    ui->messageTextEdit->setFocus();
}

//字体颜色
void chatRoom::on_colorToolBtn_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid()) {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();
    }
}

//设置字体时可切换到相应状态
void chatRoom::currentFormatChanged(const QTextCharFormat &format)
{
    ui->fontComboBox->setCurrentFont(format.font());
    if(format.fontPointSize() < 9) {
        ui->SizeComboBox->setCurrentIndex(3);
    }
    else {
        ui->SizeComboBox->setCurrentIndex(ui->SizeComboBox
                                          ->findText(QString::number(format.fontPointSize())));
    }
    ui->boldToolBtn->setChecked(format.font().bold());
    ui->italicToolBtn->setChecked(format.font().italic());
    ui->underlineToolBtn->setChecked(format.font().underline());
    color = format.foreground().color();
}

//保存聊天记录
void chatRoom::on_saveToolBtn_clicked()
{
    if(ui->messageBrowser->document()->isEmpty()) {
        QMessageBox::warning(0,tr("警告"),
                             tr("聊天记录为空,无法保存!"),QMessageBox::Ok);
    }else {
        QString fileName = QFileDialog::getSaveFileName(this,tr("保存聊天记录"),
                                                        tr("聊天记录"),tr("文本(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

//清空聊天记录
void chatRoom::on_clearToolBtn_clicked()
{
    ui->messageBrowser->clear();
}

//退出按钮
void chatRoom::on_exitButton_clicked()
{
    close();
}

//改变字体
void chatRoom::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}


void chatRoom::setUser(User u)
{
    user.name = u.name;
    user.address = u.address;
    user.hostaddress = u.hostaddress;
//    qDebug() << user.name<<user.hostaddress<<user.address;
}

//打开私聊窗口
void chatRoom::on_userTableWidget_doubleClicked(const QModelIndex &index)
{
    if(ui->userTableWidget->item(index.row(),0)->text() == getUserName() &&
       ui->userTableWidget->item(index.row(),2)->text() == getIP())
    {
        QMessageBox::warning(0,tr("警告"),tr("不可以和自己聊天！！！"),QMessageBox::Ok);
        return ;
    }
    else
    {
    qDebug()<<privateChat;
        if(!privateChat)
        {
            qDebug() << "进入了";
            privateChat = new Chat(ui->userTableWidget->item(index.row(),1)->text(),//主机名
                                   ui->userTableWidget->item(index.row(),2)->text());

        }
        qDebug() << 1;
        QByteArray data;
        QDataStream out(&data,QIODevice::WriteOnly);
        QString localHostName = QHostInfo::localHostName();
        QString address = getIP();
        out << Xchat << getUserName() << localHostName << address;
        //udpSocket->writeDatagram(data,data.length(),QHostAddress::QHostAddress(ui->userTableWidget->item(index.row(),2)->text()),port);
        udpSocket->writeDatagram(data,data.length(),QHostAddress(ui->userTableWidget->item(index.row(),2)->text()),port);
        privateChat->show();
        privateChat->is_opend = true;
       qDebug() <<  Xchat << getUserName() << localHostName << address;
    }

}

void chatRoom::showXchat(QString localHostName, QString ipAddress)
{

   /* if(!privateChat1)
    {
        privateChat1 = new Chat(localHostName,ipAddress);
        privateChat1->show();
        privateChat1->is_opend = true;
    }
    */
    if(!privateChat1)
        privateChat1 = new Chat(localHostName,ipAddress);

}
//展示语音输入窗口
void chatRoom::on_speechToolBtn_clicked()
{
    speto = new spe(nullptr);
    speto->show();
    connect(speto,SIGNAL(getStr(QString&)), this, SLOT(setStr(QString&)));

}

//关闭语音输入窗口
//void chatRoom::exitspe(){
//    if(speto1!=nullptr)
//        speto1->close();
//}
//信号传输
void chatRoom::setStr(QString &str)
{
    ui->messageTextEdit->setText(str);
    sendMessage(Message);
    speto -> close();

}
// 纯色按钮
void chatRoom::on_colorToolBtn1_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid()) {
        ui->messageBrowser->setStyleSheet("QTextBrowser{background-color: rgba(255, 255, 255, 0.7);}");
        ui->messageTextEdit->setStyleSheet("QTextEdit{background-color: rgba(255, 255, 255, 0.7);}");
        ui->userTableWidget->setStyleSheet("QTableWidget{background-color: rgba(255, 255, 255, 0.9);}");
        setPalette(QPalette(color));
    }
}

