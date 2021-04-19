#ifndef BATTERY_H
#define BATTERY_H
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QString>
#include "ui_mainwindow.h"



class Battery : public QObject{

    Q_OBJECT


public:
    Battery();
    ~Battery();

    //void updateBattery();




private:

    int batteryAmount;
    float rate;
    float frequency;
    int powerlevel;
    QTimer *batTimer;









public slots:
    void setBattery(int amount);
    void setRate(float r);
    void setPowerLevel(int p);
    int getPowerLevel();
    float getBattery();


    void batOn();
    void batOff();
    void updateBattery();







signals:
    void displayBattery(float b);
    void turnOff();
    Ui::MainWindow *getUI();
    void display(int x);
    void on_pushButton_clicked();
    int getOnOff();




};
#endif // BATTERY_H
