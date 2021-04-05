#include <iostream>
using namespace std;
#include <string>
#include "microprocessor.h"


MicroProcessor::MicroProcessor(){
    powerOn = false;

}


MicroProcessor::~MicroProcessor(){

}



void MicroProcessor::turnOn(){
    powerOn = true;
}

void MicroProcessor::turnOff(){
    powerOn = false;
}
