#include <iostream>
using namespace std;
#include <string>
#include "timer.h"


Timer::Timer(){

    duration =0;

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this,SLOT(countDown()));
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),this,SLOT(countTime()));
}


Timer::~Timer(){

}


void Timer::setTime(int t){
    time = t;
    cout<<time<<endl;
}



//Ui::MainWindow *ui = emit getUI();



//program
void Timer::startTimer(){
    Ui::MainWindow *ui = emit getUI();
    int minute = time / 60;
    int second = time % 60;
    ui->label->setText(QString::number(minute / 10));
    ui->label_2->setText(QString::number(minute % 10));
    ui->label_3->setText(":");
    ui->label_4->setText(QString::number(second / 10));
    ui->label_5->setText(QString::number(second % 10));

    timer2->start(1000);



}



//frequency
void Timer::startTimer2(){

    Ui::MainWindow *ui = emit getUI();
    ui->label->setText("0");
    ui->label_2->setText("0");
    ui->label_3->setText(":");
    ui->label_4->setText("0");
    ui->label_5->setText("0");

    timer1->start(1000);


}







void Timer::countTime(){
    bool status = emit getFrequencyStatus();
    bool skin = emit loopCheck();

    if(status&&skin){
        duration++;
        Ui::MainWindow *ui = emit getUI();
        int a = ui->label_5->text().toInt();
        int b = ui->label_4->text().toInt();
        int c = ui->label_2->text().toInt();
        int d = ui->label->text().toInt();
        if(d == 6){
            ui->label->setText("");
            ui->label_2->setText("");
            ui->label_3->setText("");
            ui->label_4->setText("");
            ui->label_5->setText("");
            emit stopFrequency();
            timer1->stop();
        }
        else{
            if(a < 9){
                a++;
                ui->label_5->setText(QString::number(a));
            }
            else {
                ui->label_5->setText("0");
                b++;
                if(b < 6){
                    ui->label_4->setText(QString::number(b));
                }
                else {
                    ui->label_4->setText("0");
                    if(c < 9){
                        c++;
                        ui->label_2->setText(QString::number(c));
                    }
                    else {
                        ui->label_2->setText("0");
                        d++;
                        ui->label->setText(QString::number(d));
                    }
                }

            }
        }
    }
}


void Timer::countDown(){
    bool status = emit getTherapyStatus();
    bool skin = emit loopCheck();

    if(status&&skin){
        duration++;
        Ui::MainWindow *ui = emit getUI();
        //qDebug()<<"1";
        int a = ui->label_5->text().toInt();
        int b = ui->label_4->text().toInt();
        int c = ui->label_2->text().toInt();
        int d = ui->label->text().toInt();
        if(a==0&&b==0&&c==0&&d==0){
            emit on_returnButton_clicked();
            emit stopTherapy();
            timer2->stop();
            //return to main pg
        }
        else{
            if(a>0){
                a--;
                ui->label_5->setText(QString::number(a));
            }
            else{
                if(b>0){
                b--;
                a=9;
                ui->label_4->setText(QString::number(b));
                ui->label_5->setText(QString::number(a));
                }
                else {
                    if(c>0){
                        c--;
                        b=5;
                        a=9;
                        ui->label_4->setText(QString::number(b));
                        ui->label_2->setText(QString::number(c));
                        ui->label_5->setText(QString::number(a));
                    }
                    else {
                        d--;
                        c=9;
                        b=5;
                        a=9;
                        ui->label->setText(QString::number(d));
                        ui->label_2->setText(QString::number(c));
                        ui->label_4->setText(QString::number(b));
                        ui->label_5->setText(QString::number(a));
                    }
                }
            }
        }
    }
}



void Timer::stopTimer(){
    timer1->stop();
    timer2->stop();
}


void Timer::needDuration(){
    emit storeDuration(duration);
    duration=0;
}















