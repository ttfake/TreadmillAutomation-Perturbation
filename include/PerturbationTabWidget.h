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

class PerturbationTabWidget : public QWidget
{
    Q_OBJECT

        enum TreadmillProperty
        {
            DEFAULT,
            ACCEL,
            DECEL,
            SPEED,
            INCLIN

        };
    enum SetpointType { NormalSetpoint, FeedbackRegistrationSetpoint };


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

    private slots:
        void setLeftFrontSpeedValue(double mleftFrontSpeedValue);
        void setRightFrontSpeedValue(double mrightFrontSpeedValue);
        void setAccelerationValue(double maccelerationValue);
        void setAccelerationTimeValue(double maccelTimeValue);
        void setDecelerationValue(double mdecelValue);
        void setDecelerationTimeValue(double mdecelTimeValue);
        void startAccelTimer();
        void sendSetpoints(TreadmillProperty mproperty, SetpointType mt);
        void sendSetpointsDirectly(TreadmillProperty mproperty, SetpointType mt);
        void sendSetpointsLibrary(SetpointType mt);
        void startDecelTimer();
        void slotTimeout();
        void addTimer(int state);


    private:

        PerturbationTabWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~PerturbationTabWidget();
        static PerturbationTabWidget* _perturbationTabWidget;

        //createRemoteTab
        QWidget* perturbationTab;
        QGridLayout* perturbationTabLayout;
        void createTreadmillPerturbationTab();
        void populateTreadmillPerturbationTab();

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

        QCheckBox* timerCheckBox;
        QGroupBox* timerCheckBoxGroupBox;
        QHBoxLayout* timerCheckBoxGroupBoxLayout;
        QFont timerCheckBoxLabelFont;
        QLabel* timerCheckBoxLabel;
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

        QAbstractSocket* pertSocket;

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
