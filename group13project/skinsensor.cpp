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
}

void SkinSensor::setSkinOff(){
    skinOn = false;
}
