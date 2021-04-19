#ifndef SKINSENSOR_H
#define SKINSENSOR_H
#include <QObject>



class SkinSensor : public QObject{

    Q_OBJECT


public:
    SkinSensor();
    ~SkinSensor();



private:
    bool skinOn;




public slots:
    void setSkinOn();
    void setSkinOff();
    void checkSkin();
    void checkSkin2();
    bool loopCheck();





signals:

    void startTimer();
    void startTimer2();






};
#endif // SKINSENSOR_H
