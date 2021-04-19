#include <iostream>
using namespace std;
#include <string>
#include "therapy.h"


Therapy::Therapy(){

    startTherapy = false;
    startFrequency = false;

}


Therapy::~Therapy(){

}


void Therapy::allergy(){
    int t = 60;

    emit setTime(t);
    //emit displayTime(t);
    //emit setRate(r);
    emit checkSkin();
}


void Therapy::diarrhea(){
    int t = 120;

    emit setTime(t);


    emit checkSkin();
}


void Therapy::kidneys(){
    int t = 150;

    emit setTime(t);


    emit checkSkin();
}


void Therapy::muscles(){
    int t = 30;

    emit setTime(t);


    emit checkSkin();
}



void Therapy::therapyStart(int index){
    startTherapy = true;

    if(index == 0){
        allergy();
    }
    else if(index == 1){
        diarrhea();
    }
    else if(index == 2){
        kidneys();
    }
    else if(index == 3){
        muscles();
    }

}




void Therapy::frequencyStart(int index){
    startFrequency = true;

    if(index == 0){
        emit checkSkin2();
    }
    else if(index == 1){
        emit checkSkin2();
    }
    else if(index == 2){
        emit checkSkin2();
    }
    else if(index == 3){
        emit checkSkin2();
    }

}









void Therapy::stopTherapy(){
    startTherapy = false;
}


void Therapy::stopFrequency(){
    startFrequency = false;
}



bool Therapy::getFrequencyStatus(){
    return startFrequency;
}

bool Therapy::getTherapyStatus(){
    return startTherapy;
}
