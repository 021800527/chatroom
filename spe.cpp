#include "spe.h"
#include "ui_spe.h"
#include "mydevice.h"
#include <QTimer>
#include <QDateTime>
#include <QDir>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

spe::spe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

        ui->setupUi(this);
        ui->pushButton->setText("按住说话");
        QDir dir;
        if(!dir.exists("./audio"))dir.mkpath("./audio");

}

spe::~spe()
{
    delete ui;
}


void spe::on_pushButton_pressed()
{

    ui->pushButton->setText("松开识别");
    //开始录音
    audio = new Audio;
    QDateTime time = QDateTime::currentDateTime();   //获取当前时间
    uint timeT = time.toTime_t();   //将当前时间转为时间戳
    filename = QString::number(timeT);
    audio->startAudio("./audio/"+filename+".pcm");


}

void spe::on_pushButton_released()
{
//    qDebug()<<"6561651";
    //停止录音
    audio->stopAudio();
    //修改按钮文字
    ui->pushButton->setText("开始识别");
    //开始识别
    Speech m_speech;
    QString text =  m_speech.speechIdentify("./audio/"+filename+".pcm");
    ui->textEdit->setText(text);

    ui->pushButton->setText("按住说话");


}

void spe::on_clearButton_clicked()
{
    ui->textEdit->clear();
}
// 发送消息
void spe::on_sendButton_clicked()
{
    QString str = ui->textEdit->toPlainText();
    emit getStr(str);
}
// 播放语音
void spe::on_PlayButton_clicked()
{
    /* 必须给这个bug版面
     * 5.30 3:38
     * 这个问你题五年前就出现过了
     * 翻遍了所有能查到的资料
     * QT demo的方法就是这种
     * 但是只适用与main函数
     * 放在这里直接程序崩溃
     * 在Github五年前有人也给QT团队提出过这个问题，但是没有得到回复
    QAudioDeviceInfo device = QAudioDeviceInfo::defaultOutputDevice();
    QFile inputFile;
    inputFile.setFileName("./audio.pcm");
    inputFile.open(QIODevice::ReadWrite);

    //设置采样格式
    QAudioFormat audioFormat;
    //设置采样率
    audioFormat.setSampleRate(16000);
    //设置通道数
    audioFormat.setChannelCount(1);
    //设置采样大小，一般为8位或16位
    audioFormat.setSampleSize(16);
    //设置编码方式
    audioFormat.setCodec("audio/pcm");
    //设置字节序
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    //设置样本数据类型
    qDebug()<<&inputFile;
    audioFormat.setSampleType(QAudioFormat::SignedInt);
    QAudioOutput *audio = new QAudioOutput(audioFormat, 0);
//    audio->start(&inputFile);
*/
    //换成音频流写入声卡解决了问题
    QAudioFormat fmt;
        fmt.setSampleRate(16000);
        fmt.setChannelCount(1);
        fmt.setSampleSize(16);
        fmt.setCodec("audio/pcm");
        fmt.setCodec("audio/pcm");
        fmt.setByteOrder(QAudioFormat::LittleEndian);
        fmt.setSampleType(QAudioFormat::UnSignedInt);

        QAudioOutput *out = new QAudioOutput(fmt, this);

        QByteArray ba;
        QFile f("./audio/"+filename+".pcm");
        if (!f.open(QIODevice::ReadOnly))
            exit(0);
        ba = f.readAll();
//        qDebug()<<ba.size()/16000/2.0;
        f.close();

        MyDevice *dev = new MyDevice(ba);
        out->start(dev);
        size = ba.size()/16000/2;
        startProgress();
}
void spe::startProgress(){
        progDlg = new QProgressDialog();
        progDlg->setWindowTitle("正在播放中");
        progDlg->setFixedWidth(300);
        progDlg->setRange(0, size);
        progDlg->show();
        timer = new QTimer();
        progDlg ->setCancelButtonText("取消播放");
        QString size1 = QString::number(size);
        progDlg ->setLabelText("播放总时长:"+size1+" S");
        currentValue = 0;
        progDlg->setValue(currentValue);
        connect(timer, SIGNAL(timeout()), this, SLOT(add()));
        timer->start(1000);//开启一个没有终点的定时器

}
void spe::add(){
    currentValue++;
    if(currentValue == size){
        //耗时操作完成后，关闭进度对话框
        timer->stop();//停止定时器
        progDlg -> setValue(size);
    }
    else {
        progDlg ->setValue(currentValue);
        QCoreApplication::processEvents();//避免界面冻结
        if(progDlg->wasCanceled()){
            progDlg->setHidden(true);//隐藏对话框
            timer->stop();//停止定时器
        }
    }
}

