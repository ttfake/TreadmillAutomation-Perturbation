#ifndef MOUSEINTERFACE_H
#define MOUSEINTERFACE_H

#include <windows.h>
#include <QObject>
#include <QDebug>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <vector>
#include <QTextStream>
#include <QTimer>
#include <QPushButton>
#include <QFile>
#include <QtMath>
#include <QDate>
#include <QDateTime>

class MouseInterface : public QObject
{ 
    Q_OBJECT

    public:
        MouseInterface();
        ~MouseInterface();
        int openPort();
        void setMovementBool(bool);
        void setPerturbationActiveBoolFalse();
    public slots:
        void getRawInput();
        void setPerturbationActiveBoolTrue();
    signals:
        movement();
    private:
        QByteArray                        dataRead;
        QSerialPort*                      serial;
        QSerialPort*                      serialPort;
        QTimer                            m_timer;
        QString                           serialPortName;  
        int                               serialPortBaudRate;
        std::vector<QString>              availableComPorts;
        std::vector<QSerialPortInfo>      comPortInfo;
        bool                              movementBool;
        bool                              perturbationActiveBool;
};
#endif
