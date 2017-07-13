#ifndef TREADMILLAUTOMATION_H
#define TREADMILLAUTOMATION_H

#pragma once

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QLibrary>
#include <QAbstractSocket>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QMessageBox>
#include <iostream>
#include <QDoubleSpinBox>
#include <QPalette>
#include <QTimeEdit>
#include <QTimer>
#include <QMap>
#include <QSignalMapper>

#include "include/NetworkTabWidget.h"
#include "include/PerturbationTabWidget.h"
#include "include/SendSetpoints.h"

class TreadmillAutomation : public QMainWindow
{

    Q_OBJECT

    public:
        TreadmillAutomation(QWidget *parent=0, Qt::WindowFlags flags=0);
        ~TreadmillAutomation();
        void createFileMenu();
        void createTabWidget();
        void createNetworkTab();
        void populateNetworkTab();
        void createTreadmillPerturbationTab();
        void populateTreadmillPerturbationTab();
        void error(int);
        NetworkTabWidget* networkTabWidget;
        PerturbationTabWidget* perturbationTabWidget;
        SendSetpoints* sendSetpointObject;
        bool useLibraryCheckBox;

    public slots:

        void setUseLibraryStatus();
        void setSocket();

    private slots:

        void showTimer();

    private:
        QWidget* centralWidget;
        QVBoxLayout* centralWidgetLayout;
        t_TREADMILL_initialize TREADMILL_initialize;
        t_TREADMILL_initializeUDP TREADMILL_initializeUDP;
        t_TREADMILL_setSpeed TREADMILL_setSpeed;
        t_TREADMILL_setSpeed4 TREADMILL_setSpeed4;
        t_TREADMILL_close TREADMILL_close;

        //createFileMenu
        QMenuBar* menuBar;
        QMenu* menuFile;
        QMenu* menuView;
        QAction *exitAct;
        QAction* timerViewAct;
        QAction* maxSpeedViewAct;
        
        //createTabWidget
        QTabWidget* centralTabWidget;
        QGridLayout* centralGridLayout;


            
        double getAccelerationValue();
        double getAccelerationTimeValue();
        double getDecelerationValue();
        double getDecelerationTimeValue();
        double getLeftFrontSpeedValue();
        double getRightFrontSpeedValue();
        double getLeftRearSpeedValue();
        double getRightRearSpeedValue();

        void setLeftFrontSpeedValueFromIncoming(qint16 leftFrontSpeedValue);
        void setLeftRearSpeedValueFromIncoming(qint16 leftRearSpeedValue);
        void setRightFrontSpeedValueFromIncoming(qint16 rightFrontSpeedValue);
        void setRightRearSpeedValueFromIncoming(qint16 rightRearSpeedValue);
        void setAccelerationValueFromIncoming(qint16 accelerationValue);
        void setDecelerationValueFromIncoming(qint16 decelerationValue);
        template<typename T, typename U> void addWidgetToLayout(T* widget, U* layout);
                
        
        double accelerationTimeValue;
        double decelerationTimeValue;
        double accelerationValue;
        double decelerationValue;
        double leftSpeedFrontValue;
        double leftSpeedRearValue;
        double rightSpeedFrontValue;
        double rightSpeedRearValue;

};

#endif
