#ifndef MCCDAQINTERFACE_H
#define MCCDAQINTERFACE_H

#include <iostream>
#include <conio.h>
#include <QObject>
#include <QThread>
#include <QTime>
#include <vector>
#include <tuple>
#include <QMenu>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QThread>
#include <cmath>
#include <map>
#include <QDebug>
#include <QDateTime>
#include <QDate>
#include <QtMath>

#include "MccDaqDiscovery.h"



class MccDaqInterface : public QObject
{
    Q_OBJECT
    
    public:
        MccDaqInterface();
        ~MccDaqInterface();

        void startChannelScan(QMenu* mmenu);
        void setDaqButton(QPushButton* mdaqButton);
        void dataCollectionSetup();
        void setNumberOfChannels(long chs);
        void setCurrentChannelActiveState(bool mactiveState);
        void setRunningState(int runningState);
        void setPerturbationTrigger(bool mpertTrigger);
        void setRecordBool(bool mrecordBool);
        void setDaqLogFileName(QString mfileName);
        QMap<int,QVector<double>> getVoltageMap();
        QMap<int,QVector<double>> tmpVoltageMap;
        //int getVoltageMap();
        QMap<int,QVector<double>> getForceMap();
        void clearTmpVoltageMap();
    
    public slots:
        void beginDataCollection();
        void testDataCollection();
        void setDaqButtonText(QString daqTitleText);
        void beginDataCollectionOnChannel(int ch);

    signals:
        void finished();
        void setDaqTitleText(QString title);
        void updateDaqDataBoxSignal(double data);
        void updateRowCount(int mRowCount);
        void updateCol(int mColCount);
        void getActiveState(int mchannel);
        void getChannelType(int mchannel);
        void getGainType(int mchannel);
        void setCurrentChannel(int mchannel);
        void updateEmg();
        void updateForce(int channel);

    private:

        long NUMCHANS;
        static const int NUMPOINTS = 10000;
        static const int MAXNUMDEVS = 100;

        int Row, Col;
        int  BoardNum;
        int Options;
        long PreTrigCount, TotalCount, Rate, ChanCount;
        int ULStat;
        short Status = IDLE;
        long CurCount;
        long CurIndex, DataIndex;
        int PortNum, Direction, CounterNum;
        WORD *ADData;
        float RevLevel = (float)CURRENTREVNUM;
        std::vector<double> dataVector;
        QString forcePlateDataString;
        QFile* forcePlateDataFile;
        QTextStream* stream;
        MccDaqDiscovery* mccDaqDisc;
        void                                                         setDaqDataBox(QPlainTextEdit* mdaqBox);
        QPlainTextEdit*                                              daqBox;
        std::tuple<short*,short*,short*>                             channelConfig;
        int                                                          rowCount;
        int                                                          channel;
        bool                                                         activeState;
        long                                                         chs;
        std::vector<int>                                             channelVector;
        std::map<int,double>                                         channelCoefficientMap;
        
        int                                                          leftForceCoefficientXKey;
        double                                                       leftForceCoefficientX;
        int                                                          leftForceCoefficientYKey;
        double                                                       leftForceCoefficientY;
        int                                                          leftForceCoefficientZKey;
        double                                                       leftForceCoefficientZ;
        int                                                          leftMomentCoefficientXKey;
        double                                                       leftMomentCoefficientX;
        int                                                          leftMomentCoefficientYKey;
        double                                                       leftMomentCoefficientY;
        int                                                          leftMomentCoefficientZKey;
        double                                                       leftMomentCoefficientZ;

        int                                                          rightForceCoefficientXKey;
        double                                                       rightForceCoefficientX;
        int                                                          rightForceCoefficientYKey;
        double                                                       rightForceCoefficientY;
        int                                                          rightForceCoefficientZKey;
        double                                                       rightForceCoefficientZ;
        int                                                          rightMomentCoefficientXKey;
        double                                                       rightMomentCoefficientX;
        int                                                          rightMomentCoefficientYKey;
        double                                                       rightMomentCoefficientY;
        int                                                          rightMomentCoefficientZKey;
        double                                                       rightMomentCoefficientZ;
        int                                                          sampleRate;
        int                                                          sampleWindow;

        
        
        double                                                       scale;
        bool                                                         pertTrigger;
        bool                                                         recordBool;
        QString                                                      daqLogFileName;

        QMap<int,QVector<double>>                                    daqVoltageMap;
        QMap<int,QVector<double>>                                    tmpDaqVoltageMap;
        QMap<int,QVector<double>>                                    daqForceMap;

        quint64                                                      unixTime;
        quint64                                                      prevUnixTime;
        int                                                          captureTime;
        int                                                          dateIndex;
        QString                                                      dataPoint1String;
        int                                                          dataPoints;
        long                                                         globalDaqDataIndex;

};
#endif
