#include "audio.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

Audio::Audio(QObject *parent) : QObject(parent)
{

}

void Audio::startAudio(QString fileName)
{
    QAudioDeviceInfo device = QAudioDeviceInfo::defaultInputDevice();
    if(device.isNull())//录音设备不存在
    {
        QMessageBox::warning(NULL,"QAudioDeviceInfo","录音设备不存在");
    }
    else
    {
        //音频编码要求
        QAudioFormat m_format;
        //设置采样频率
        m_format.setSampleRate(16000);//采样率为16k
        //设置通道
        m_format.setChannelCount(1);
        //设置位深
        m_format.setSampleSize(16);
        //设置编码格式
        m_format.setCodec("aduio/pcm");
        //判断设备是否支持该格式
        //设置字节序
        m_format.setByteOrder(QAudioFormat::LittleEndian);
        //设置样本数据类型
        m_format.setSampleType(QAudioFormat::SignedInt);
        if(!device.isFormatSupported(m_format))
        {
            m_format = device.nearestFormat(m_format);
        }
        //打开文件
        m_file = new QFile;
        m_file->setFileName(fileName);
        m_file->open(QIODevice::ReadWrite);//向里面写数据
        //创建录音对象
        m_audio = new QAudioInput(m_format,this);
        m_audio->start(m_file);


    }


}
void Audio::stopAudio()
{
    //停止录音
    m_audio->stop();
    //关闭文件
    m_file->close();
    //删除文件对象
    delete m_file;
    m_file = nullptr;
    delete m_audio;
    m_audio = nullptr;
}
