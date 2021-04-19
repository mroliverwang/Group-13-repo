#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <microprocessor.h>
#include <battery.h>
#include <skinsensor.h>
#include <therapy.h>
#include <timer.h>
#include <QLCDNumber>
#include<QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int menu = 1;





signals:
    void turnOn();
    void turnOff();
    int getOnOff();
    void setSkinOn();
    void setSkinOff();
    void therapyStart(int index);
    void frequencyStart(int index);
    void display(int x);
    int getPowerLevel();
    void setPowerLevel(int p);
    void stopTherapy();
    void stopFrequency();
    float getBattery();
    void stopTimer();
    void recordOn();
    void recordOff();
    bool getTherapyStatus();
    bool getFrequencyStatus();
    void storeCurrentTreatment(QString name);
    void storeHighestLevel(int l);
    vector<QString> getHistory();
    vector<int> getHighestLevel();
    vector<int> getDuration();
    vector<QDateTime> getDateTime();
    void clearHistory();
    void storeDateTime(QDateTime T);
    void needDuration();

    void batOn();
    void batOff();
    void setBattery(int v);




private slots:
    Ui::MainWindow *getUI();

    void on_downButton_clicked();

    void on_okButton_clicked();


    void on_upButton_clicked();

    void on_returnButton_clicked();


    void on_pushButton_clicked();

    void on_skinOnOff_stateChanged(int arg1);

    void on_Recorded_stateChanged(int arg1);

    void on_leftButon_clicked();

    void on_rightButton_clicked();



    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    MicroProcessor* processor = new MicroProcessor();
    Timer* timer = new Timer();
    SkinSensor* skinSensor = new SkinSensor();
    Therapy* therapy = new Therapy();
    Battery* battery = new Battery();

    int highestLevel;
    QString therapyName;
    QDateTime dateTime;



};

#endif // MAINWINDOW_H
