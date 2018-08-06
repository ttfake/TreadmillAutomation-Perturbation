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
#include <QString>
#include <chrono>
#include <sstream>
#include "NIDAQmx.h"

typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
#define _WIN32_WINNT_WIN7 0x0601

class MouseInterface : public QObject
{ 
    Q_OBJECT

    public:
        MouseInterface();
        ~MouseInterface();
        int                               openPort();
        void                              setMovementBool(bool);
        void                              setPerturbationActiveBoolFalse();
        void                              setLogPath(QString m_logPath);
        void                              setMovementDetectedBool(bool mMovementDetectedBool);
        void                              SetupDigitalOutput();
        int                               GetDevices();

        void                              SetupEventTrigger();
		void							  SetupChannelSelection();
		void                              SetupStimTrigger();
        void                              StopTask();
        bool                              movementDetectedBool;
    public slots:
        void                              getRawInput();
        void                              setPerturbationActiveBoolTrue();
        //void                              WriteLine();
		
        void                              WriteEvent();
		void                              WriteStim();
		void                              WriteChannel(int channel);
    signals:
        movement();
        movementStopped();
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
        QString                           logPath;


        TaskHandle                        EventHandle=0;
		TaskHandle                        StimTriggerHandle=1;
		TaskHandle                        ChannelSelectionHandle=2;

        QFile* pertTriggerLog;
        QString defaultPath;


};
#endif
