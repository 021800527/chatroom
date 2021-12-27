﻿#pragma once
#include <QObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QMapIterator>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDebug>
class Http : public QObject
{
    Q_OBJECT
public:
    explicit Http(QObject *parent = nullptr);
    bool post_sync(QString Url,QMap<QString,QString> header,QByteArray requestData,QByteArray &replyData);

signals:

};