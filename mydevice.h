#pragma once
#include <QIODevice>

class MyDevice : public QIODevice
{
private:
    //存放pcm数据
    QByteArray data_pcm;
    //记录已写入多少字节
    int        len_written;
public:
    //创建对象传递pcm数据
    MyDevice(QByteArray pcm);
    ~MyDevice();
    //重新实现的虚函数
    qint64 readData(char *data, qint64 maxlen);
    //它是个纯虚函数， 不得不实现
    qint64 writeData(const char *data, qint64 len);
};
