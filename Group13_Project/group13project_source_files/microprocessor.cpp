#include <iostream>
using namespace std;
#include <string>
#include "microprocessor.h"
#include <QDateTime>


MicroProcessor::MicroProcessor(){
    powerOn = 0;
    recorded = false;

}


MicroProcessor::~MicroProcessor(){

}



void MicroProcessor::turnOn(){
    powerOn = true;

}

void MicroProcessor::turnOff(){
    powerOn = false;
}


int MicroProcessor::getOnOff(){
    return powerOn;
}


void MicroProcessor::recordOn(){
    recorded = true;
    cout<<"record on"<<endl;
}


void MicroProcessor::recordOff(){
    recorded = false;
    cout<<"record off"<<endl;
}



void MicroProcessor::storeCurrentTreatment(QString name){
    if(recorded){
        history.push_back(name);
        cout<<"treatment stored"<<endl;
    }
}


vector<QString> MicroProcessor::getHistory(){
    return history;
}


vector<int> MicroProcessor::getHighestLevel(){
    return highestPowerLevel;
}

vector<int> MicroProcessor::getDuration(){
    return duration;
}

vector<QDateTime> MicroProcessor::getDateTime(){
    return dateTime;
}



void MicroProcessor::storeHighestLevel(int l){
    if(recorded){
        highestPowerLevel.push_back(l);
        cout<<"Level stored"<<endl;
    }
}

void MicroProcessor::storeDateTime(QDateTime t){
    if(recorded){
        dateTime.push_back(t);
        cout<<"date stored"<<endl;
    }
}


void MicroProcessor::storeDuration(int d){
    if(recorded){
        duration.push_back(d);
        cout<<"duration stored"<<endl;
    }
}



void MicroProcessor::clearHistory(){

    for(int i = history.size()-1; i>-1 ;i--){
        history.erase(history.begin()+i);

    }
    for(int i = highestPowerLevel.size()-1; i>-1 ;i--){
        highestPowerLevel.erase(highestPowerLevel.begin()+i);

    }
    for(int i = duration.size()-1; i>-1 ;i--){
        duration.erase(duration.begin()+i);

    }
    for(int i = dateTime.size()-1; i>-1 ;i--){
        dateTime.erase(dateTime.begin()+i);

    }
}
