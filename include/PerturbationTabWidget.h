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

#include "SendSetpoints.h"
#include "MccDaqConnectButtonWidget.h"
#include "MccDaqRecordButtonWidget.h"
#include "MccDaqInterface.h"
#include "RecordTreadmillStream.h"

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
        void addDaqDataGroupBox();
        void showDaqDataBox(bool checked);

    public slots:
        void showTimer(bool state);
        void updateDaqDataStreamTableWidget(double data);
        void updateCol(int mColNo);
        void getActiveState(int channel);
        void getChannelType(int channel);
        void getGainType(int channel);
        void setChannel(int mchannel);
        void randomDelay();

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
        void setDaqConnectColor();
        void setDaqRecordColor();
        void setDaqRecordBool();
        void addChannels();
        void scanForDaqDevice();
        void setDaqText(QString daqText);
        void setupDataCollection();
        void startDataCollectionThread();
        void setRowCount(int mRowCount);
        void setDaqLogFileName();
        void treadmillWait(double);

    private:

        SendSetpoints* sendSetpoints;
        MccDaqInterface* pmccDaqInterface;
        
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

        //addDaqControlGroupBox
        void addDaqControlGroupBox();
        QGroupBox* daqControlGroupBox;
        QVBoxLayout* daqControlGroupBoxLayout; 
        
        QScrollArea* daqControlGroupBoxScrollArea;
        QGroupBox* daqControlScrollGroupBox;
        QVBoxLayout* daqControlScrollGroupBoxVerticalLayout;
        QGroupBox* numberOfChannelsGroupBox;
        QFont numberOfChannelsGroupBoxFont;
        QHBoxLayout* numberOfChannelsGroupBoxLayout;
        QGroupBox* daqPushButtonBox;
        QHBoxLayout* daqPushButtonBoxLayout;
        QFont daqControlGroupBoxFont;

        QPushButton* scanForDaqDev;
        QMenu* daqDevMenu;
        
        MccDaqConnectButtonWidget* mccDaqConnectButtonWidget;
        MccDaqRecordButtonWidget* mccDaqRecordButtonWidget;
        QFont mccDaqConnectButtonFont;
        QFont mccDaqRecordButtonFont;
        QLabel* numberOfChannelsLabel;
        QSpinBox* numberOfChannelsSpinBox;
        QPushButton* setNumChannels;
        int numChannels;
        QTableWidget* channelTableWidget;
        QStringList channelHeaderStringList;

        
        void addChannelGrid();
        bool clicked;

        //addChannelGrid
        QGroupBox* channelGridGroupBox;
        QHBoxLayout* channelGridGroupBoxLayout;
        QGroupBox* channelsHeadingGroupBox;
        QFont channelsHeadingGroupBoxFont;
        QHBoxLayout* channelsHeadingGroupBoxLayout;
        QFont daqControlScrollGroupBoxFont;


        int rowCount;
        int colNo;

        int currentChannel;

        bool recordClicked;

        RecordTreadmillStream* recTreadmillStream;

        int currentRightSpeed;
        int currentLeftSpeed;

        
        
};
#endif
