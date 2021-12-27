#pragma once
#include <spe.h>
#include <QWidget>
#include "chat.h"
/*
 * 使用UDP协议进行聊天
 * 使用TCP协议进行文件传输
 */

namespace Ui {
class chatRoom;
}

class QUdpSocket;
class TcpServer;
class QTextCharFormat;


struct User{
    QString name;
    QString hostaddress;
    QString address;
};

class chatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit chatRoom(QWidget *parent = 0,User u = {"","",""});
    ~chatRoom();
    //用于从登陆端接收用户信息
    void setUser(User u);
    void addAnimation(const QUrl& url, const QString& fileName);
    void addAnimation_edit(const QUrl& url, const QString& fileName);

protected:
    //窗口展示
    void showXchat(QString localHostName,QString ipAddress);
    //新成员加入
    void newParticipant(QString userName,
                        QString localHostName,QString ipAddress);
    //成员离开
    void participantLeft(QString username,
                         QString localHostName,QString time);
    //广播用户登录信息
    void sendMessage(messageType type,QString serverAddress = "");
    //判断是否接收、发送文件
    void hasPendingFile(QString userName, QString serverAddress,
                        QString clientAddress,QString fileName);
    //保存接受的文件
    bool saveFile(const QString &fileName);
    //关闭事件
    void closeEvent(QCloseEvent *event);
    //事件过滤器，按下回车发送信息
    bool eventFilter(QObject *obj, QEvent *event);

    //获取IP地址
    QString getIP();
    //获取用户名
    QString getUserName();
    //获取消息
    QString getMessage();
private:
    Ui::chatRoom *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QString fileName;
    TcpServer *server;
    spe *speto;
    Chat *privateChat;
    Chat *privateChat1;
    QColor color;
    User user;
    QList<QUrl> m_lstUrls;
    QHash<QMovie*, QUrl> m_hasUrls;

private slots:
    // 纯色按钮
    void on_colorToolBtn1_clicked();
    //语音输入按钮
    void on_speechToolBtn_clicked();
    //双击事件
    void on_userTableWidget_doubleClicked(const QModelIndex &index);
    //检测textedit
    void check();
    //1
    void subAnimate(int);
    //2
    void subAnimate_edit(int);
    //换肤
    void on_skinToolBtn_clicked();
    //接收广播消息
    void processPendingDatagrams();
    //发送按钮
    void on_sendButton_clicked();
    //获取发送过来的文件名
    void getFileName(QString);
    //传输文件按钮
    void on_sendToolBtn_clicked();
    //设置字体
    void on_fontComboBox_currentFontChanged(const QFont &f);
    //更改字体大小
    void on_SizeComboBox_currentIndexChanged(const QString &arg1);
    //字体加粗
    void on_boldToolBtn_clicked(bool checked);
    //斜体
    void on_italicToolBtn_clicked(bool checked);
    //下划线
    void on_underlineToolBtn_clicked(bool checked);
    //字体颜色
    void on_colorToolBtn_clicked();
    //设置字体时可切换到相应状态
    void currentFormatChanged(const QTextCharFormat &format);
    //保存聊天记录
    void on_saveToolBtn_clicked();
    //清空聊天记录
    void on_clearToolBtn_clicked();
    //退出按钮
    void on_exitButton_clicked();
    // 语音消息设置
    void setStr(QString&);
};

