#ifndef THERAPY_H
#define THERAPY_H


#include <QObject>



class Therapy : public QObject{

    Q_OBJECT


public:
    Therapy();
    ~Therapy();


    void allergy();
    void diarrhea();
    void kidneys();
    void muscles();




private:
    bool startTherapy;
    bool startFrequency;




public slots:
    void therapyStart(int index);
    void frequencyStart(int index);
    void stopTherapy();
    void stopFrequency();
    bool getFrequencyStatus();
    bool getTherapyStatus();




signals:

    void setTime(int t);
    void displayTime(float t);
    void setRate(float r);
    void checkSkin();
    void checkSkin2();





};









#endif // THERAPY_H
