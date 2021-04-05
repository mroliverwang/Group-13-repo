#ifndef TIMER_H
#define TIMER_H
#include <QObject>




class Timer : public QObject{

    Q_OBJECT


public:
    Timer();
    ~Timer();




private:

    float time;









public slots:
    void setTime(float t);
    void startTimer();





signals:






};
#endif // TIMER_H
