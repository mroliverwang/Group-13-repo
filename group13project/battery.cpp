#include <iostream>
using namespace std;
#include <string>
#include "battery.h"


Battery::Battery(){

    batteryAmount = 100.0;

}


Battery::~Battery(){

}


void Battery::setBattery(float amount){
    batteryAmount = amount;
}
