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

        void showMaxSpeedBox();
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


        //populateTreadmillPerturbationTab
                
        QLabel* speedRightFrontLabel;
        QFont speedRightFrontLabelFont;
        QDoubleSpinBox* rightFrontSpeedSetpoint;
        QFont rightFrontSpeedSetpointFont;
        
        QGroupBox* rearSpeedGroupBox;
        QHBoxLayout* rearSpeedHorizontalLayout;
        
        QLabel* speedLeftRearLabel;
        QFont speedLeftRearLabelFont;
        QDoubleSpinBox* leftRearSpeedSetpoint;
        QFont leftRearSpeedSetpointFont;
        
        QDoubleSpinBox* rightRearSpeedSetpoint;
        QLabel* speedRightRearLabel;
        QFont speedRightRearLabelFont;
        QFont rightRearSpeedSetpointFont;

        
        QFont accelerationLabelFont;
        QLabel* accelerationLabel;
        QFont accelerationSpinBoxFont;
        QDoubleSpinBox* acceleration;
        QLabel* decelerationLabel;
        QFont decelerationLabelFont;
        QFont decelerationSpinBoxFont;
        QDoubleSpinBox* deceleration;
        QLabel* accelerationDurationLabel;
        QPlainTextEdit* accelerationDuration;
        QLabel* decelerationDurationLabel;
        QPlainTextEdit* decelerationDuration;

        QGroupBox* quadrantTwoGroupBox;
        QGroupBox* recordGroupBox;

        QGroupBox* timeGroupBox;
        QHBoxLayout* timeGroupBoxLayout;
        QLabel* timeAccelLabel;
        QFont timeAccelLabelFont;
        QTimer accelTimer;
        QDoubleSpinBox* timeAccelSpinBox;
        QLabel* accelTimeDurationLabel;
        QFont accelTimeDurationFont;
        QDoubleSpinBox* accelTimeDurationSpinBox;

        QFont timeAccelSpinBoxFont;
        QLabel* timeDecelLabel;
        QFont timeDecelLabelFont;
        QDoubleSpinBox* timeDecelSpinBox;
        QTimer decelTimer;
        QFont timeDecelSpinBoxFont;

        QGroupBox* startPertRunGroupBox;
        QHBoxLayout* startPertRunGroupBoxLayout;
        QPushButton* startPertRun;
        
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
