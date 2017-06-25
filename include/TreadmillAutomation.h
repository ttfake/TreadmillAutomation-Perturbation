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

#ifdef _WIN32

#include <windows.h>
#ifdef TREADMILLREMOTEDLL_EXPORTS
#define TREADMILLREMOTEDLL_API
#else
#define TREADMILLREMOTEDLL_API
#endif

#else

#define WINAPI
#define TREADMILLREMOTEDLL_API

#endif

enum {
	TREADMILL_OK = 0,
	// errors in TREADMILL_initialize
	TREADMILL_WSA_STARTUP = 10,
	TREADMILL_ADDRESS = 11,
	TREADMILL_SOCKET = 12,
	TREADMILL_CONNECT = 13,
	TREADMILL_SETSOCKOPT = 14,
	// errors in TREADMILL_setSpeed
	TREADMILL_NOT_CONNECTED = 20,
	TREADMILL_SEND = 21
};

enum SetpointType { NormalSetpoint, FeedbackRegistrationSetpoint };


	typedef int (WINAPI *t_TREADMILL_initialize)(char *, char *);
	typedef int (WINAPI *t_TREADMILL_setSpeed)(double, double, double);
	typedef int (WINAPI *t_TREADMILL_setSpeed4)(double, double, double, double, double);
	typedef int (WINAPI *t_TREADMILL_close)(void);
	typedef int (WINAPI *t_TREADMILL_initializeUDP)(char *, char *);


static void showWarning(QWidget * parent, const QString & title, const QString & text);

enum TreadmillProperty
{
    DEFAULT,
    ACCEL,
    DECEL,
    SPEED,
    INCLIN

};

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

    public slots:

        void onClickConnect(void);
        void onClickDisconnect(void);
        void connected();
        void disconnected();
        void readyRead();
        void error(QAbstractSocket::SocketError);
        void sendSetpoints(TreadmillProperty property = TreadmillProperty::DEFAULT, SetpointType t = NormalSetpoint);
        void sendSetpointsDirectly(TreadmillProperty property = TreadmillProperty::DEFAULT, SetpointType t = NormalSetpoint);
        void sendSetpointsLibrary(SetpointType t);
        void startAccelTimer();
        void startDecelTimer();
        void setAccelerationTimeValue(double accelValue);
        void setDecelerationTimeValue(double decelTimeValue);
        void setLeftFrontSpeedValue(double leftFrontSpeedValue);
        void setLeftRearSpeedValue(double leftRearSpeedValue);
        void setRightFrontSpeedValue(double rightFrontSpeedValue);
        void setRightRearSpeedValue(double rightRearSpeedValue);
        void setAccelerationValue(double accelerationValue);
        void setDecelerationValue(double decelerationValue);
        void slotTimeout();
    
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
        QAction *exitAct;
        
        //createTabWidget
        QTabWidget* centralTabWidget;
        QGridLayout* centralGridLayout;

        //createNetworkTab
        QWidget* networkTab;
        QVBoxLayout* networkTabLayout;

        //populateNetworkTab
        QGroupBox *networkGroupBox;
        QVBoxLayout* verticalNetworkGroupBoxLayout;
        QHBoxLayout* horizontalNetworkGroupBoxLayout; 
        QPushButton* connectBtn;
        QPushButton* disconnectBtn;
        QGroupBox* networkLabelTextGroupBox;
        QGroupBox* networkTcpUdbGroupBox;
        QGroupBox* networkButtonGroupBox;
        QHBoxLayout* horizontalNetworkLabelTextGroupBoxLayout;
        QHBoxLayout* horizontalNetworkTcpUdbGroupBoxLayout;
        QHBoxLayout* horizontalNetworkButtonGroupBoxLayout;
        QGroupBox* startServerGroup;
        QPlainTextEdit* hostTextBox;
        QPlainTextEdit* portTextBox;
        QLabel* hostLabel;
        QFont hostLabelFont;
        QLabel* portLabel;
        QFont portLabelFont;
        QLabel* tcpLabel;
        QFont tcpLabelFont;
        QLabel* udpLabel;
        QFont udpLabelFont;
        QRadioButton* tcpRadioButton;
        QRadioButton* udpRadioButton;
        QLabel* useLibraryLabel;
        QFont useLibraryLabelFont;
        QCheckBox* useLibrary;
        QAbstractSocket* socket;
        QMessageBox msgBox;
        QString port;
        QGroupBox* useLibraryGroupBox;
        QHBoxLayout* useLibraryGroupBoxLayout;
        bool* ok;
        int base;

        //createRemoteTab
        QWidget* perturbationTab;
        QGridLayout* perturbationTabLayout;
        

        //populateTreadmillPerturbationTab
        QCheckBox* lftRghtTie;
        QGroupBox* quadrantOneGroupBox;
        QVBoxLayout* quadrantOneGroupBoxLayout;
        QVBoxLayout* quadrantOnePerturbationLayout;
        QVBoxLayout* quadrantTwoPerturbationLayout;
        QGroupBox* accelDecelGroupBox;
        QHBoxLayout* accelerationDecelerationHorizontalLayout;
        QGroupBox* speedGroupBox;
        QGridLayout* speedGroupBoxGridLayout;
        QGroupBox* frontSpeedGroupBox;
        QHBoxLayout* frontSpeedHorizontalLayout;


        QLabel* speedLeftFrontLabel;
        QFont speedLeftFrontLabelFont;
        QDoubleSpinBox* leftFrontSpeedSetpoint;
        QFont leftFrontSpeedSetpointFont;
        
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
