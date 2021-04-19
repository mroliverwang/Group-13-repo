#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QKeyEvent>
#include <iostream>
#include <vector>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(this,SIGNAL(display(int)),ui->lcdNumber,SLOT(display(int)));
    connect(battery,SIGNAL(display(int)),ui->lcdNumber_2,SLOT(display(int)));
    connect(timer,SIGNAL(getUI()),this,SLOT(getUI()));


    connect(this,SIGNAL(turnOn()),processor,SLOT(turnOn()));
    connect(this,SIGNAL(turnOff()),processor,SLOT(turnOff()));
    connect(this,SIGNAL(getOnOff()),processor,SLOT(getOnOff()));
    connect(this,SIGNAL(setSkinOn()),skinSensor,SLOT(setSkinOn()));
    connect(this,SIGNAL(setSkinOff()),skinSensor,SLOT(setSkinOff()));
    connect(this,SIGNAL(therapyStart(int)),therapy,SLOT(therapyStart(int)));
    connect(this,SIGNAL(frequencyStart(int)),therapy,SLOT(frequencyStart(int)));
    connect(therapy,SIGNAL(checkSkin()),skinSensor,SLOT(checkSkin()));
    connect(therapy,SIGNAL(checkSkin2()),skinSensor,SLOT(checkSkin2()));
    connect(skinSensor,SIGNAL(startTimer()),timer,SLOT(startTimer()));
    connect(skinSensor,SIGNAL(startTimer2()),timer,SLOT(startTimer2()));
    connect(timer,SIGNAL(stopTherapy()),therapy,SLOT(stopTherapy()));
    connect(timer,SIGNAL(stopFrequency()),therapy,SLOT(stopFrequency()));
    connect(timer,SIGNAL(loopCheck()),skinSensor,SLOT(loopCheck()));

    connect(battery,SIGNAL(on_pushButton_clicked()),this,SLOT(on_pushButton_clicked()));

    connect(this,SIGNAL(getPowerLevel()),battery,SLOT(getPowerLevel()));
    connect(this,SIGNAL(setPowerLevel(int)),battery,SLOT(setPowerLevel(int)));
    connect(therapy,SIGNAL(setTime(int)),timer,SLOT(setTime(int)));
    connect(timer,SIGNAL(on_returnButton_clicked()),this,SLOT(on_returnButton_clicked()));
    connect(this,SIGNAL(stopTherapy()),therapy,SLOT(stopTherapy()));
    connect(this,SIGNAL(stopFrequency()),therapy,SLOT(stopFrequency()));
    connect(this,SIGNAL(batOn()),battery,SLOT(batOn()));
    connect(this,SIGNAL(batOff()),battery,SLOT(batOff()));
    connect(this,SIGNAL(getBattery()),battery,SLOT(getBattery()));
    connect(timer,SIGNAL(getFrequencyStatus()),therapy,SLOT(getFrequencyStatus()));
    connect(timer,SIGNAL(getTherapyStatus()),therapy,SLOT(getTherapyStatus()));
    connect(this,SIGNAL(getTherapyStatus()),therapy,SLOT(getTherapyStatus()));
    connect(this,SIGNAL(getFrequencyStatus()),therapy,SLOT(getFrequencyStatus()));
    connect(this,SIGNAL(stopTimer()),timer,SLOT(stopTimer()));

    connect(this,SIGNAL(recordOn()),processor,SLOT(recordOn()));
    connect(this,SIGNAL(recordOff()),processor,SLOT(recordOff()));
    connect(this,SIGNAL(storeCurrentTreatment(QString)),processor,SLOT(storeCurrentTreatment(QString)));
    connect(this,SIGNAL(storeHighestLevel(int)),processor,SLOT(storeHighestLevel(int)));
    connect(this,SIGNAL(storeDateTime(QDateTime)),processor,SLOT(storeDateTime(QDateTime)));
    connect(this,SIGNAL(getHistory()),processor,SLOT(getHistory()));
    connect(this,SIGNAL(getHighestLevel()),processor,SLOT(getHighestLevel()));
    connect(this,SIGNAL(getDuration()),processor,SLOT(getDuration()));
    connect(this,SIGNAL(getDateTime()),processor,SLOT(getDateTime()));
    connect(this,SIGNAL(clearHistory()),processor,SLOT(clearHistory()));
    connect(this,SIGNAL(needDuration()),timer,SLOT(needDuration()));
    connect(timer,SIGNAL(storeDuration(int)),processor,SLOT(storeDuration(int)));
    connect(this,SIGNAL(setBattery(int)),battery,SLOT(setBattery(int)));
    connect(battery,SIGNAL(getOnOff()),processor,SLOT(getOnOff()));

    highestLevel = 1;
}


MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_upButton_clicked()
{
    int currentIndex = ui->listWidget->currentRow();
    if (currentIndex !=-1 and currentIndex>0){
        QListWidgetItem *currentItem = ui->listWidget->item(currentIndex);


        ui->listWidget->insertItem(currentIndex-1,currentItem);

        ui->listWidget->setCurrentRow(currentIndex-1);
    }

}

void MainWindow::on_downButton_clicked()
{
    int currentIndex = ui->listWidget->currentRow();
    if (currentIndex !=-1 and currentIndex+1< ui->listWidget->count()){
        QListWidgetItem *currentItem = ui->listWidget->item(currentIndex);


        ui->listWidget->insertItem(currentIndex+1,currentItem);

        ui->listWidget->setCurrentRow(currentIndex+1);
    }

}

void MainWindow::on_okButton_clicked(){
    int currentIndex = ui->listWidget->currentRow();
    if(menu == 1){
        if(currentIndex == 0){

            ui->listWidget->clear();
            ui->listWidget->addItem("Allergy");
            ui->listWidget->addItem("Diarrhea");
            ui->listWidget->addItem("Muscles");
            ui->listWidget->addItem("Kidneys");

            ui->listWidget->setCurrentRow(0);
            ui->listWidget->itemClicked(ui->listWidget->currentItem());

            menu =2;
        }
        if(currentIndex == 1){
            ui->listWidget->clear();
            ui->listWidget->addItem("10HZ");
            ui->listWidget->addItem("60HZ");
            ui->listWidget->addItem("77HZ");
            ui->listWidget->addItem("200HZ");

            ui->listWidget->setCurrentRow(0);
            ui->listWidget->itemClicked(ui->listWidget->currentItem());

            menu =3;
        }



        if(currentIndex == 2){
            ui->listWidget->clear();

            ui->listWidget->addItem("View");
            ui->listWidget->addItem("Clear");


            ui->listWidget->setCurrentRow(0);
            ui->listWidget->itemClicked(ui->listWidget->currentItem());
            menu = 4;
        }
    }





    //porgram
    else if(menu == 2){

        ui->listWidget->clear();
        emit therapyStart(currentIndex);
        if(currentIndex==0){
            //emit storeCurrentTreatment("Allergy");
            therapyName = "Allergy";
            dateTime = QDateTime::currentDateTime();
        }
        else if(currentIndex==1){
            //emit storeCurrentTreatment("Diarrhea");
            therapyName = "Diarrhea";
            dateTime = QDateTime::currentDateTime();
        }
        else if(currentIndex==2){
            //emit storeCurrentTreatment("Muscles");
            therapyName = "Muscles";
            dateTime = QDateTime::currentDateTime();
        }
        else if(currentIndex==3){
            //emit storeCurrentTreatment("Kidneys");
            therapyName = "Kidneys";
            dateTime = QDateTime::currentDateTime();
        }


    }



    //frequency
    else if(menu ==3){

        ui->listWidget->clear();
        emit frequencyStart(currentIndex);
        if(currentIndex==0){
            //emit storeCurrentTreatment("10Hz");
            therapyName = "10Hz";
            dateTime = QDateTime::currentDateTime();

        }
        else if(currentIndex==1){
            //emit storeCurrentTreatment("60Hz");
            therapyName = "60Hz";
            dateTime = QDateTime::currentDateTime();
        }
        else if(currentIndex==2){
            //emit storeCurrentTreatment("77Hz");
            therapyName = "77Hz";
            dateTime = QDateTime::currentDateTime();
        }
        else if(currentIndex==3){
            //emit storeCurrentTreatment("200Hz");
            therapyName = "200Hz";
            dateTime = QDateTime::currentDateTime();
        }

    }

    else if(menu ==4){

        ui->listWidget->clear();

        if(currentIndex==0){
            ui->listWidget->clear();

            //add items from the stored history
            vector<QString> history = emit getHistory();
            vector<int> highest = emit getHighestLevel();
            vector<int> duration = emit getDuration();
            vector<QDateTime> time = emit getDateTime();

            for(unsigned long i = 0; i<history.size();i++){
                QString h = QString::number(highest[i]);

                QString d = QString::number(duration[i]);
                QString temp = QString("       ")+QString("TREATMENT:         ")+QString(history[i]);
                QString temp2 = QString("       ")+QString("HIGHEST LEVEL:    ")+ h;
                QString temp3 = QString("       ")+QString("Duration:               ")+ d + QString("  seconds");

                ui->listWidget->addItem(time[i].toString());
                ui->listWidget->addItem(temp);
                ui->listWidget->addItem(temp2);
                ui->listWidget->addItem(temp3);
            }

            ui->listWidget->setCurrentRow(0);
            ui->listWidget->itemClicked(ui->listWidget->currentItem());
            menu=5;
        }


        else if(currentIndex==1){
            emit clearHistory();
            on_returnButton_clicked();
        }


    }
}





void MainWindow::on_returnButton_clicked()
{
    int p = emit getOnOff();
    if(p==1){

        bool f =emit getFrequencyStatus();
        bool t = emit getTherapyStatus();
        if(f||t){
            emit storeCurrentTreatment(therapyName);
            emit storeHighestLevel(highestLevel);
            emit storeDateTime(dateTime);
            emit needDuration();
        }



        ui->listWidget->clear();
        ui->listWidget->addItem("Programs");
        ui->listWidget->addItem("Frequency");
        ui->listWidget->addItem("Treatment Record");

        menu = 1;
        ui->listWidget->setCurrentRow(0);
        ui->listWidget->itemClicked(ui->listWidget->currentItem());

        ui->label->setText("");
        ui->label_2->setText("");
        ui->label_3->setText("");
        ui->label_4->setText("");
        ui->label_5->setText("");
        emit stopTimer();
        emit display(1);
        emit setPowerLevel(1);
        emit stopTherapy();
        emit stopFrequency();
        highestLevel = 1;


    }
}





void MainWindow::on_pushButton_clicked()
{


    int p = emit getOnOff();
    float battery = emit getBattery();
    if(p == 0){
        if(battery>0){
        emit turnOn();
            ui->listWidget->clear();
            ui->listWidget->addItem("Programs");
            ui->listWidget->addItem("Frequency");
            ui->listWidget->addItem("Treatment Record");

            menu = 1;
            ui->listWidget->setCurrentRow(0);
            ui->listWidget->itemClicked(ui->listWidget->currentItem());
            emit clearHistory();
            int value = emit getPowerLevel();
            emit display(value);
            emit batOn();
        }
    }
    else if (p == 1){
        ui->label->setText("");
        ui->label_2->setText("");
        ui->label_3->setText("");
        ui->label_4->setText("");
        ui->label_5->setText("");
        emit clearHistory();
        emit stopTimer();
        emit turnOff();
        ui->listWidget->clear();
        emit display(0);
        emit setPowerLevel(1);
        emit batOff();
    }
}



void MainWindow::on_skinOnOff_stateChanged(int arg1)
{
    //arg1 is 2 when skinOn, 0 when skin Off
    if(arg1==2){
        emit setSkinOn();
    }
    else if(arg1 == 0){
        emit setSkinOff();
    }
}


void MainWindow::on_Recorded_stateChanged(int arg1)
{
    //arg1 is 2 when recorded, 0 when not recorded
    if(arg1==2){
        emit recordOn();
    }
    else if(arg1 == 0){
        emit recordOff();
    }
}


void MainWindow::on_leftButon_clicked()
{
    int p = emit getOnOff();    
    bool f =emit getFrequencyStatus();
    bool t = emit getTherapyStatus();
    if(p==1){
        if(f||t){
            int value = emit getPowerLevel();
            if(value>1){
                value-=1;
            }
            emit display(value);
            emit setPowerLevel(value);
        }
    }
}

void MainWindow::on_rightButton_clicked()
{
    int p = emit getOnOff();
    bool f =emit getFrequencyStatus();
    bool t = emit getTherapyStatus();
    if(p==1){
        if(f||t){
            int value = emit getPowerLevel();
            if(value<100){
                value+=1;
                if(value>highestLevel){
                    highestLevel = value;
                }
            }
            emit display(value);
            emit setPowerLevel(value);
        }
    }
}



Ui::MainWindow *MainWindow::getUI(){
    return ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    emit setBattery(value+1);
}
