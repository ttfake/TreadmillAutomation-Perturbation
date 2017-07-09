#ifndef PERTURBATIONTABWIDGET_H
#define PERTURBATIONTABWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>
#include <QDoubleSpinBox>
#include <QPlainTextEdit>
#include <QTimer>
#include <QPushButton>
#include <iostream>
#include <QAbstractSocket>

#include "SendSetpoints.h"

class PerturbationTabWidget : public QWidget
{
    Q_OBJECT
 
    public:
        static PerturbationTabWidget* getInstance();
        double getLeftFrontSpeedValue();
        double getRightFrontSpeedValue();
        double getAccelerationValue();
        double getAccelerationTimeValue();
        double getDecelerationValue();
        double getDecelerationTimeValue();
        void setLeftFrontSpeedValueFromIncoming(qint16 mleftFrontSpeedValue);
        void setRightFrontSpeedValueFromIncoming(qint16 mrightFrontSpeedValue);
        void setUseLibraryStatus(bool useLibCheckBox);
        bool useLibraryCheckBoxStatus;
        void setSocket(QAbstractSocket* socket);

    
        
    public slots:
        void showTimer(bool state);
        void showMaxSpeedBox(bool state);

    private slots:
        void setLeftFrontSpeedValue(double mleftFrontSpeedValue);
        void setRightFrontSpeedValue(double mrightFrontSpeedValue);
        void setAccelerationValue(double maccelerationValue);
        void setAccelerationTimeValue(double maccelTimeValue);
        void setDecelerationValue(double mdecelValue);
        void setDecelerationTimeValue(double mdecelTimeValue);
        void startAccelTimer();
        void startDecelTimer();
        void slotTimeout();
        void startMaxSpeedRun();
        void startMaxSpeedDecel();
        void setMaxLeftSpeed(double mMaxLeftSpeed);
        void setMaxRightSpeed(double mMaxRightSpeed);
        void maxSpeedTimeout();


    private:

        PerturbationTabWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~PerturbationTabWidget();
        static PerturbationTabWidget* _perturbationTabWidget;

        SendSetpoints* sendSetpoints;

        //createRemoteTab
        QWidget* perturbationTab;
        QGridLayout* perturbationTabLayout;
        void createTreadmillPerturbationTab();
        void populateTreadmillPerturbationTab();
        void addQuadrantOne();
        void addSpeedGroupBox();
        void addAccelDecelGroupBox();
        void addTimerGroupBox();
        void addStartPertRunGroupBox();
        void addStartEndSpeedGroupBox();
        void addQuadrantTwo();
        void addQuadrantThree();
        void addQuadrantFour();
        void addMaxSpeedGroupBox();
        void addStartMaxSpeedRunGroupBox();
        double getMaxLeftSpeed();
        double getMaxRightSpeed();


        
        //populateTreadmillPerturbationTab
        QCheckBox* lftRghtTie;
        QGroupBox* quadrantOneGroupBox;
        QGroupBox* quadrantThreeGroupBox;
        QGroupBox* quadrantFourGroupBox;
        QVBoxLayout* quadrantOneGroupBoxLayout;
        QVBoxLayout* quadrantOnePerturbationLayout;
        QVBoxLayout* quadrantTwoPerturbationLayout;
        QGroupBox* accelDecelGroupBox;
        QHBoxLayout* accelerationDecelerationHorizontalLayout;
        
        QGroupBox* speedGroupBox;
        QHBoxLayout* speedGroupBoxHorizontalLayout;
        QLabel* speedLeftFrontLabel;
        QFont speedLeftFrontLabelFont;
        QDoubleSpinBox* leftFrontSpeedSetpoint;
        QFont leftFrontSpeedSetpointFont;
 

        QGroupBox* maxSpeedGroupBox;
        QHBoxLayout* maxSpeedGroupBoxLayout;
        QLabel* maxLeftSpeedLabel;
        QFont maxLeftSpeedLabelFont;
        QDoubleSpinBox* maxLeftSpeedSpinBox;
        QFont maxLeftSpeedSpinBoxFont;
        QLabel* maxRightSpeedLabel;
        QFont maxRightSpeedLabelFont;
        QDoubleSpinBox* maxRightSpeedSpinBox;
        QFont maxRightSpeedSpinBoxFont;

        QGroupBox* startMaxSpeedRunGroupBox;
        QHBoxLayout* startMaxSpeedRunGroupBoxLayout;
        QPushButton* startMaxSpeedRunBtn;
        QFont startMaxSpeedRunBtnFont;

        double maxLeftSpeed;
        double maxRightSpeed;
        double maxRunTime;
        double maxDecelRunTime;
        
        QLabel* speedRightFrontLabel;
        QFont speedRightFrontLabelFont;
        QDoubleSpinBox* rightFrontSpeedSetpoint;
        QFont rightFrontSpeedSetpointFont;


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
        QDoubleSpinBox* timeAccelSpinBox;
        QLabel* accelTimeDurationLabel;
        QFont accelTimeDurationFont;
        QDoubleSpinBox* accelTimeDurationSpinBox;

        QFont timeAccelSpinBoxFont;
        QLabel* timeDecelLabel;
        QFont timeDecelLabelFont;
        QDoubleSpinBox* timeDecelSpinBox;
        QFont timeDecelSpinBoxFont;

        QGroupBox* startPertRunGroupBox;
        QHBoxLayout* startPertRunGroupBoxLayout;
        QPushButton* startPertRunBtn;
        QFont startPertRunBtnFont;

        QAbstractSocket* pertSocket;

        QGroupBox* startEndSpeedGroupBox;
        QGridLayout* startEndSpeedGroupBoxGridLayout;


        const int millisecondConversion = 1000;

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
