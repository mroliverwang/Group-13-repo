#include <iostream>
using namespace std;
#include <string>
#include "battery.h"


Battery::Battery(){

    batteryAmount = 100;
    powerlevel = 1;
    batTimer = new QTimer(this);
    connect(batTimer, SIGNAL(timeout()),this,SLOT(updateBattery()));
}


Battery::~Battery(){

}


void Battery::setBattery(int amount){
    batteryAmount = amount;

    int o = emit getOnOff();
    if(o==1){
        display(batteryAmount);
    }
}


void Battery::setRate(float r){
    rate= r;
}

void Battery::setPowerLevel(int p){
    powerlevel= p;
    batTimer->stop();
    batTimer->start(10000-powerlevel*85);
}


float Battery::getBattery(){
    return batteryAmount;
}


int Battery::getPowerLevel(){
    return powerlevel;
}




void Battery::batOn(){

    display(batteryAmount);
    batTimer->start(10000);

}

void Battery::batOff(){
    display(0);
    batTimer->stop();
}












void Battery::updateBattery(){
    int o = emit getOnOff();
    if(o==1){
        if(batteryAmount>0){
            batteryAmount--;
        }
        display(batteryAmount);
        if(batteryAmount <=0){
            batTimer->stop();
            emit on_pushButton_clicked();
        }

    }



}
