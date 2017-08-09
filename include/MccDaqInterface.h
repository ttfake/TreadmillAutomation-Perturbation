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
    
    public slots:
        void beginDataCollection();
        void setDaqButtonText(QString daqTitleText);

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
        void setDaqDataBox(QPlainTextEdit* mdaqBox);
        QPlainTextEdit* daqBox;
        std::tuple<short*,short*,short*> channelConfig;
        int rowCount;
        int channel;
        bool activeState;
        long chs;
        std::vector<int> channelVector;
        std::map<int,double> channelCoefficientMap;
        int forceCoefficientXKey;
        double forceCoefficientX;
        int forceCoefficientYKey;
        double forceCoefficientY;
        int forceCoefficientZKey;
        double forceCoefficientZ;
        int momentCoefficientXKey;
        double momentCoefficientX;
        int momentCoefficientYKey;
        double momentCoefficientY;
        int momentCoefficientZKey;
        double momentCoefficientZ;
        double scale;
        bool pertTrigger;
        bool recordBool;


};
#endif
