#ifndef MICROPROCESSOR_H
#define MICROPROCESSOR_H

#include <QObject>
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <QDateTime>



class MicroProcessor : public QObject{

    Q_OBJECT


public:
    MicroProcessor();
    ~MicroProcessor();




private:

    int powerOn;
    bool recorded;
    vector<QString> history;
    vector<int> highestPowerLevel;
    vector<int> duration;
    vector<QDateTime> dateTime;









public slots:

    void turnOn();
    void turnOff();
    int getOnOff();
    void recordOn();
    void recordOff();
    void storeCurrentTreatment(QString name);
    void storeDateTime(QDateTime t);
    vector<QString> getHistory();
    vector<int> getHighestLevel();
    vector<int> getDuration();
    vector<QDateTime> getDateTime();
    void storeHighestLevel(int l);
    void clearHistory();
    void storeDuration(int d);






signals:
    bool getRecordedStatus();






};













#endif // MICROPROCESSOR_H
