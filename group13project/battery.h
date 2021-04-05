#ifndef BATTERY_H
#define BATTERY_H
#include <QObject>




class Battery : public QObject{

    Q_OBJECT


public:
    Battery();
    ~Battery();




private:

    float batteryAmount;









public slots:
    void setBattery(float amount);







signals:






};
#endif // BATTERY_H
