#ifndef CONFIGTABWIDGET_H
#define CONFIGTABWIDGET_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QFont>
#include <QPushButton>
#include <QMenu>
#include <QLabel>
#include <QSpinBox>
#include <QTableWidget>
#include <QStringList>
#include <QComboBox>
#include <QCheckBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QQuickView>
#include <QQuickItem>
#include <QGuiApplication>
#include <QQmlEngine>

#include "MccDaqConnectButtonWidget.h"
#include "MccDaqRecordButtonWidget.h"
#include "MccDaqInterface.h"
#include "QScrollArea.h"

class ConfigTabWidget : public QWidget
{
    Q_OBJECT

    private slots:
        void setDaqText(QString title);
        void setDaqLogFileName();
        void startDataCollectionThread();
        void setDaqConnectColor();
        void setDaqRecordBool();
        void setDaqRecordColor();
        void addChannels();
        void timerUpdatedSlot();
        void setEmgData();
        void getActiveState(int channel);
        void getChannelType(int channel);
        void getGainType(int channel);
    
    signals:
        void timerUpdatedSignal();
        void emgUpdated();
    public:
        ConfigTabWidget(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~ConfigTabWidget();

        double getStimTimerValue();
        QMap<int,QVector<double>> getEmgData();
        
    private:
        QGridLayout* configGridLayout;
        MccDaqInterface* pmccDaqInterface;
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

        bool recordClicked;
        QGroupBox* daqDataGroupBox;
        QVBoxLayout* daqDataGroupBoxVerticalLayout;
        QLabel* daqDataLabel;
        QStringList daqDataStreamHeaderStringList;
        
        void addChannelGrid();
        bool clicked;

        //addChannelGrid
        QGroupBox* channelGridGroupBox;
        QHBoxLayout* channelGridGroupBoxLayout;
        QGroupBox* channelsHeadingGroupBox;
        QFont channelsHeadingGroupBoxFont;
        QHBoxLayout* channelsHeadingGroupBoxLayout;
        QFont daqControlScrollGroupBoxFont;
        void setRowCount(int mRowCount);

        void scanForDaqDevice();


        void setupDataCollection();
        void updateCol(int mColNo);
        void updateDaqDataStreamTableWidget(double force);
        void setChannel(int mchannel);

        void addDaqDataGroupBox();
        void showDaqDataBox(bool checked);
        QTableWidget* daqDataStreamTableWidget;
        QThread* daqThread;
        QFont daqDataGroupBoxFont;

        int rowCount;
        int colNo;

        int currentChannel;

        void addStimTimerQmlBox();
        QQuickView* timerQuickView;
        QWidget* timerQuickViewContainer;
        QObject* timerQuickViewRootObject;
        QObject* timerQuickViewItem;


        double stimTimer;
        QVariant timerValue;

        void addDaqSampleConfig();
        QGroupBox* daqSampleConfigGroupBox;
        QVBoxLayout* daqSampleConfigGroupBoxLayout;
        QLabel* sampleRateLabel;
        QSpinBox* sampleRateSpinBox;
        QLabel* windowLabel;
        QSpinBox* windowSpinBox;

        
        QMap<int,QVector<double>> voltageMap;

       

};
#endif
