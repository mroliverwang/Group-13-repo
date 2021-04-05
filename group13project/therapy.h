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
    bool start;




public slots:
    void therapyStart();





signals:
    void startTimer();






};









#endif // THERAPY_H
