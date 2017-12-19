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
#include <QThread>
#include <QSignalMapper>

#include "include/NetworkTabWidget.h"
#include "include/PerturbationTabWidget.h"
#include "include/SendSetpoints.h"
#include "include/MouseInterface.h"
#include "include/SubjectInterface.h"

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
//        MccDaqInterface* mccDaqInterface;
        PerturbationTabWidget* perturbationTabWidget;
        SendSetpoints* sendSetpointObject;
        bool useLibraryCheckBox;

    public slots:

        void setUseLibraryStatus();
        void setSocket();
        void showDaqDataBox();

    private slots:
        void showTimer();
        void errorString(QString s);
        void showSubjectView();

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
        QMenu* menuQualisys;
        QAction* saveVelocityDataAct;
        QAction *exitAct;
        QAction* timerViewAct;
        QAction* daqViewAct;
        QAction* viewSubjectInterfaceAct;
        QAction* loadRunProfileAction;
        
        //createTabWidget
        QTabWidget* centralTabWidget;
        QGridLayout* centralGridLayout;

        QSignalMapper* daqSignalMapper;
            
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
        template<typename T, typename U> void addWidgetToLayout(T* widget, U* layout)
        {
            layout->addWidget(widget);

        };
        
        double accelerationTimeValue;
        double decelerationTimeValue;
        double accelerationValue;
        double decelerationValue;
        double leftSpeedFrontValue;
        double leftSpeedRearValue;
        double rightSpeedFrontValue;
        double rightSpeedRearValue;
        SubjectInterface* sInterface;
        
        void uncheckDaqDataView();
};

#endif
