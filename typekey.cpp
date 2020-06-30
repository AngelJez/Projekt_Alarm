#include "typekey.h"
#include "ui_typekey.h"
#include <QDebug>
#include <wiringPi.h>

TypeKey::TypeKey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TypeKey)
{
    ui->setupUi(this);

    wiringPiSetup();
    pinMode(21, INPUT); // Sensor1
    pinMode(24, INPUT); // Sensor2
    pinMode(25, INPUT); // Sensor3
    pinMode(22, OUTPUT); //Brzeczek
    pinMode(23, OUTPUT); //LED

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(AlarmFunction()));
    timer->start();



}

void TypeKey::AlarmFunction()
{
    if(this->alarmState)
    {
        if(digitalRead(21) || digitalRead(24) || digitalRead(25))
        {
            this->movemenDetected = 1;
            if (this->timerTripDelayStarted==0)
            {
                this->timerTripDelay.start(timerDelayTime);
                this->timerTripDelay.setSingleShot(1);
                this->timerTripDelayStarted=1;
                digitalWrite(23,1);
                system("python3 /home/pi/PROG/Alarm_Display/hello.py");
            }
        }
        if(this->movemenDetected && this->timerTripDelayStarted && (timerTripDelay.remainingTime()==-1))
        {
            digitalWrite(22,1);
            if(this->emailSend==0)
            {
                system("python3 /home/pi/PROG/Alarm_Display/sendFirebase.py");
                system("python3 /home/pi/PROG/Alarm_Display/sendMail.py");
            }
            this->emailSend=1;
        }
    }
    else
    {
        this->movemenDetected = 0;
        this->timerTripDelayStarted = 0;
        digitalWrite(22,0);
        digitalWrite(23,0);
    }


}

TypeKey::~TypeKey()
{
    delete ui;
}

void TypeKey::on_toolButton_clicked()
{
    this->password = password + "1";
}

void TypeKey::on_toolButton_2_clicked()
{
    this->password = password + "2";
}

void TypeKey::on_toolButton_3_clicked()
{
    this->password = password + "3";
}

void TypeKey::on_toolButton_4_clicked()
{
    this->password = password + "4";
}

void TypeKey::on_toolButton_5_clicked()
{
    this->password = password + "5";
    cout<<password<<endl;
}

void TypeKey::on_toolButton_6_clicked()
{
    this->password = password + "6";
}

void TypeKey::on_toolButton_7_clicked()
{
    this->password = password + "7";
}

void TypeKey::on_toolButton_8_clicked()
{
    this->password = password + "8";
}

void TypeKey::on_toolButton_9_clicked()
{
    this->password = password + "9";
}

void TypeKey::on_pushButton_2_clicked()
{
    this->password = "";
    cout<<"Password reseted"<<endl;
}

void TypeKey::on_pushButton_clicked()
{
    if (this->password==this->correctPassword)
    {
        if (this->alarmState==0)
        {
            this->alarmState=1;
        }
        else
        {
            this->alarmState=0;
        }
        cout<<"Alarm State to: "<<this->alarmState<<endl;
        this->password = "";
    }
}
