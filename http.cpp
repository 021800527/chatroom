#include "http.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

Http::Http(QObject *parent) : QObject(parent)
{

}

bool Http::post_sync(QString Url, QMap<QString, QString> header, QByteArray requestData, QByteArray &replyData)
{
    //发送请求对象
    QNetworkAccessManager manager;
    //请求对象
    QNetworkRequest request;
    request.setUrl(Url);

    //迭代器
    QMapIterator<QString,QString> it(header);
    //遍历
    while (it.hasNext())
    {
        it.next();
        request.setRawHeader(it.key().toLatin1(),it.value().toLatin1());
    }
    QNetworkReply *reply =  manager.post(request,requestData);
    //服务器返回，reply会发出信号
    QEventLoop l;
    connect(reply,&QNetworkReply::finished,&l,&QEventLoop::quit);
     //模仿main函数 死循环，reply发出信号才结束循环
    l.exec();

    if(reply != nullptr && reply->error() == QNetworkReply::NoError)
    {
        replyData = reply->readAll();//读取服务器返回的数据
        qDebug() << replyData;
        return true;
    }
    else
    {
        qDebug()<<"请求失败";
        return false;
    }


}
