#ifndef QTCONTROLLER_H
#define QTCONTROLLER_H
#include <QString>
#include <QSerialPort>
#include <QDebug>
#include <QTextStream>
#include <QSerialPortInfo>
#include <QFile>

class Qtcontroller
{
private:
    char button[15];
public:

    Qtcontroller(): button{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    {

    }


    void apply(std::string str){
        for (int i = 0; i < 15; ++i) {
            button[i] = str[i];
        }
    }

    void send(){


        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
            QSerialPort serial;
            serial.setPort(info);

            if(serial.open(QIODevice::ReadWrite)){
                serial.write( button);
                serial.waitForBytesWritten(15);
            }
             }

    }

};
#endif // QTCONTROLLER_H
