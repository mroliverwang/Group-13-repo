#ifndef MICROPROCESSOR_H
#define MICROPROCESSOR_H

#include <QObject>




class MicroProcessor : public QObject{

    Q_OBJECT


public:
    MicroProcessor();
    ~MicroProcessor();




private:

    bool powerOn;









public slots:
    void turnOn();
    void turnOff();





signals:






};













#endif // MICROPROCESSOR_H
