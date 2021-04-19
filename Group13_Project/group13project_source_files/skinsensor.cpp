#include <iostream>
using namespace std;
#include <string>
#include "skinsensor.h"


SkinSensor::SkinSensor(){

    skinOn = false;

}


SkinSensor::~SkinSensor(){
}


void SkinSensor::setSkinOn(){
    skinOn = true;
    cout<<"skin on"<<endl;
}

void SkinSensor::setSkinOff(){
    skinOn = false;
    cout<<"skin off"<<endl;

}

void SkinSensor::checkSkin(){
    cout<<"skin check"<<endl;
    //if(skinOn == true){
        emit startTimer();
    //}
}

void SkinSensor::checkSkin2(){
    cout<<"skin check2"<<endl;
    //if(skinOn == true){
        emit startTimer2();
    //}
}

bool SkinSensor::loopCheck(){
    cout<<"skin loop check"<<endl;
    return skinOn;
}




