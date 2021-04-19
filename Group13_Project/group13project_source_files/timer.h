#ifndef TIMER_H
#define TIMER_H
#include <QObject>

#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QString>


class Timer : public QObject{

    Q_OBJECT


public:
    Timer();
    ~Timer();





private:

    int time;
    QTimer *timer1;
    QTimer *timer2;
    int duration;










public slots:
    void setTime(int t);
    void startTimer();
    void startTimer2();
    void countTime();
    void countDown();
    void stopTimer();
    void needDuration();




signals:
    void stopTherapy();
    void stopFrequency();
    bool loopCheck();
    Ui::MainWindow *getUI();
    void on_returnButton_clicked();
    bool getFrequencyStatus();
    bool getTherapyStatus();
    void storeDuration(int d);



};
#endif // TIMER_H
