#ifndef NETWORKTABWIDGET_H
#define NETWORKTABWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPlainTextEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QAbstractSocket>
#include <QMessageBox>
#include <QPainter>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QLibrary>
#include <iostream>

#include "SendSetpoints.h"
#include "treadmill-remote.h"


enum TreadmillProperty
{
    DEFAULT,
    ACCELERATION,
    DECELERATION,
    SPEED,
    INCLINATION

};

enum SetpointType { NormalSetpoint, FeedbackRegistrationSetpoint };
static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext);



class NetworkTabWidget : public QWidget
{
    Q_OBJECT
    public:
        static NetworkTabWidget* getInstance();
        QAbstractSocket* getSocketInstance();
        bool getUseLibraryIsCheckedStatus();
        void populateNetworkTab();
        void createNetworkTabWidget();
        QPushButton* connectBtn;


    private:

        NetworkTabWidget(QWidget* parent=0, Qt::WindowFlags flags = 0);
        ~NetworkTabWidget();
        SendSetpoints* sendSetpoints;


        void paintEvent(QPaintEvent* paintEvent);

        void setAccelerationValue(double maccelerationValue);
        void setDecelerationValue(double mdecelerationValue);
        void setLeftFrontSpeedValue(double mleftSpeedFrontValue);
        void setRightFrontSpeedValue(double mrightSpeedFrontValue);
        double getAccelerationValue();
        double getDecelerationValue();
        double getLeftFrontSpeedValue();
        double getRightFrontSpeedValue();

        
        
        
        typedef int (WINAPI *t_TREADMILL_initialize)(char *, char *);
        t_TREADMILL_initialize TREADMILL_initialize;
        t_TREADMILL_initializeUDP TREADMILL_initializeUDP;
        t_TREADMILL_setSpeed TREADMILL_setSpeed;
        t_TREADMILL_setSpeed4 TREADMILL_setSpeed4;
        t_TREADMILL_close TREADMILL_close;
        void error(int mn);

        static NetworkTabWidget* _networkTabWidget;

        //createNetworkTab
        QWidget* networkTab;
        QVBoxLayout* networkTabLayout;


        
        //populateNetworkTab
        QGroupBox *networkGroupBox;
        QVBoxLayout* verticalNetworkGroupBoxLayout;
        QHBoxLayout* horizontalNetworkGroupBoxLayout; 
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

       

        double accelerationValue;
        double decelerationValue;
        double leftFrontSpeedValue;
        double rightFrontSpeedValue;

    
    public slots:
        void onClickConnect();
        void onClickDisconnect();
        void connected();
        void disconnected();
        void readyRead();
        void error(QAbstractSocket::SocketError);



        //paintEvent





};


#endif
