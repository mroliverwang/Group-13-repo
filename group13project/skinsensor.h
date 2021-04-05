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





signals:







};
#endif // SKINSENSOR_H
