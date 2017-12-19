#ifndef PERTURBATIONTABWIDGET_H
#define PERTURBATIONTABWIDGET_H

#include <windows.h>
#include <iostream>
#include <iomanip>
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
#include <QAbstractSocket>
#include <QComboBox>
#include <QVector>
#include <QScrollArea>
#include <QStringList>
#include <QMenu>
#include <QThread>
#include <QTableWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <QDateTime>
#include <QRegExp>
#include <chrono>

#include "SendSetpoints.h"
#include "RecordTreadmillStream.h"
#include "MouseInterface.h"
#include "ReadTrialNameFile.h"
#include "ParseRunProfile.h"

class PerturbationTabWidget : public QWidget
{
    Q_OBJECT

    public:
        PerturbationTabWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~PerturbationTabWidget();

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
        void addDecelerationSpeedGroupBox();
        double calculateSpeed();
        void setHost(QString mhost);
        void setPort(QString mport);
        void addTrialRunName();

    public slots:
        void showTimer(bool state);
        void randomDelay();
        void saveVelocityData();
        void loadRunProfile();

    private slots:
        void setLeftFrontSpeedValue(double mleftFrontSpeedValue);
        void setRightFrontSpeedValue(double mrightFrontSpeedValue);
        void setAccelerationValue(double maccelerationValue);
        void setAccelerationTimeValue(double maccelTimeValue);
        void setDecelerationValue(double mdecelValue);
        void setDecelerationTimeValue(double mdecelTimeValue);
        void startTreadmill();
        void startDecelTimer();
        void slotTimeout();
        void treadmillWait();
        void getTrialName();
        void enableButton();
        void disableButton();
        void nextRun();
        void prevRun();
        void startStim();
        

    private:

        SendSetpoints* sendSetpoints;
        ReadTrialNameFile* readTrialNameFile; 
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
        void addRecordDataStreamVelocityBox(); 
        
        //populateTreadmillPerturbationTab
        QCheckBox* lftRghtTie;
        QGroupBox* quadrantOneGroupBox;
        QGroupBox* quadrantThreeGroupBox;
        QGroupBox* quadrantFourGroupBox;

        QVBoxLayout* quadrantOneGroupBoxLayout;
        QVBoxLayout* quadrantOnePerturbationLayout;
        QVBoxLayout* quadrantTwoPerturbationLayout;
        QVBoxLayout* quadrantThreePerturbationLayout;
        QVBoxLayout* quadrantFourPerturbationLayout;
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

        QGroupBox* decelSpeedGroupBox;
        QHBoxLayout* decelSpeedGroupBoxHorizontalLayout;
        QLabel* decelSpeedLeftLabel;
        QLabel* decelSpeedRightLabel;
        QFont decelSpeedLeftLabelFont;
        QFont decelSpeedRightLabelFont;
        QFont leftDecelSpeedSetpointFont;
        QFont rightDecelSpeedSetpointFont;
        QDoubleSpinBox* leftDecelSpeedSetpoint;
        QDoubleSpinBox* rightDecelSpeedSetpoint;


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

        QThread* daqThread;
        QGroupBox* daqDataGroupBox;
        QVBoxLayout* daqDataGroupBoxVerticalLayout;

        QLabel* daqDataLabel;
        QFont daqDataGroupBoxFont;
        QTableWidget* daqDataStreamTableWidget;
        QPlainTextEdit* daqDataPlainTextEditBox;
        QTableWidget* daqStreamingDataTableWidget;
        QFont daqDataPlainTextEditBoxFont;
        QStringList daqDataStreamHeaderStringList;

        
        bool recordClicked;

        RecordTreadmillStream* recTreadmillStream;

        int currentRightSpeed;
        int currentLeftSpeed;

        QString host;
        QString port;

        MouseInterface* mouseInterface;
        
        void setLoggingDirectory(QString dirName);
        qint16 trialRun;
        QString logPath;

        //createFudgeFactorGroupBox
        QGroupBox* fudgeFactorGroupBox;
        QHBoxLayout* fudgeFactorGroupBoxHorizontalLayout; 
        QLabel* fudgeFactorLabel;
        QFont fudgeFactorLabelFont;
        QDoubleSpinBox* fudgeFactorDoubleSpinBox;
        void addFudgeFactorGroupBox();
        double addToSpeed;
        void setAddToSpeed(double mAddToSpeed);
        QPushButton* prevPertRunBtn;
        QPushButton* nextPertRunBtn;
        ParseRunProfile* prp;
        void showFudgeFactorGroupBox(bool state);
       
};
#endif
