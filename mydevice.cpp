#include "MyDevice.h"
#include <QFile>
#include <QDebug>

MyDevice::MyDevice(QByteArray pcm) : data_pcm(pcm)
{
    this->open(QIODevice::ReadOnly); // 为了解决QIODevice::read (QIODevice): device not open.
    len_written = 0;
}

MyDevice::~MyDevice()
{
    this->close();
}
// data为声卡的数据缓冲区地址， maxlen为声卡缓冲区最大能存放的字节数.
qint64 MyDevice::readData(char *data, qint64 maxlen)
{
    if (len_written >= data_pcm.size())
        return 0;
    int len;

    //计算未播放的数据的长度.
    len = (len_written+maxlen) > data_pcm.size() ? (data_pcm.size() - len_written) : maxlen;

    memcpy(data, data_pcm.data()+len_written, len); //把要播放的pcm数据存入声卡缓冲区里.
    len_written += len; //更新已播放的数据长度.
    return len;
}

qint64 MyDevice::writeData(const char *data, qint64 len)
{
    return len;
}
//qint64 getAudioTime(const QString &filePath)
//{
//    QFile file(filePath);
//    if (file.open(QIODevice::ReadOnly)) {
//        qint64 fileSize = file.size();
//        qint64 time = fileSize / (16000.0 * 2.0);
//        file.close();
//        return time;
//    }
//    return -1;
//}

