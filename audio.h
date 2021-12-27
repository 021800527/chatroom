#pragma once
#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QMessageBox>
#include <QAudioInput>
#include <QFile>
#include <QAudioOutput>
class Audio : public QObject
{
    Q_OBJECT
public:
    explicit Audio(QObject *parent = nullptr);
    void startAudio(QString fileName);
    void stopAudio();
private:
    QAudioInput *m_audio;
    QFile *m_file;
};

