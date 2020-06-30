#ifndef TYPEKEY_H
#define TYPEKEY_H

#include <cstdlib>
#include <iostream>
#include <QMainWindow>
#include <QTimer>

using namespace std;

namespace Ui {
class TypeKey;
}

class TypeKey : public QMainWindow
{
    Q_OBJECT

public:
    explicit TypeKey(QWidget *parent = nullptr);
    ~TypeKey();
    QTimer timerTripDelay;
    const string correctPassword ="12345";
    string password="";
    bool alarmState = 0;
    bool movemenDetected = 0;
    const int timerDelayTime = 10000;
    bool timerTripDelayStarted = 0;
    bool emailSend = 0;

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void AlarmFunction();

private:
    Ui::TypeKey *ui;
};

#endif // TYPEKEY_H
