#pragma once
#include <QWidget>
#include <QProgressDialog>
#include "audio.h"
#include "speech.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }

class spe : public QWidget
{
    Q_OBJECT

public:
    spe(QWidget *parent = nullptr);
    ~spe();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_clearButton_clicked();

    void on_sendButton_clicked();

    void on_PlayButton_clicked();

    void startProgress();

    void add();

private:
    Ui::Widget *ui;
    Audio *audio;
    QProgressDialog *progDlg;
    QTimer *timer;
    int currentValue;
    int size;
    QString filename;


signals:
    void getStr(QString &str);
};
