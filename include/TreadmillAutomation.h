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
        void sendSetpoints(SetpointType t = NormalSetpoint);
        void sendSetpointsDirectly(SetpointType t);
        void sendSetpointsLibrary(SetpointType t);

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
        QDoubleSpinBox* leftFrontSpeedSetpoint;
        QDoubleSpinBox* leftRearSpeedSetpoint;
        QDoubleSpinBox* rightFrontSpeedSetpoint;
        QDoubleSpinBox* rightRearSpeedSetpoint;
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
        QPushButton* startPertRun;
        QGroupBox* quadrantTwoGroupBox;
        QGroupBox* recordGroupBox;

};

#endif
