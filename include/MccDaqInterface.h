#ifndef MCCDAQINTERFACE_H
#define MCCDAQINTERFACE_H

#include <iostream>
#include <conio.h>
#include <QObject>
#include <QThread>
#include <QTime>
#include <vector>
#include <QMenu>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include "MccDaqDiscovery.h"

class MccDaqInterface : public QObject
{
    Q_OBJECT
    
    public:
        static MccDaqInterface* getInstance();


    public slots:
        void beginDataCollection();
    signals:
        void finished();

    private:

        template<typename T> void updateDaqDataBox(T data)
        {
            QString dataString = QString::number(data, 'e', 12);
            daqBox->appendPlainText(dataString);
        }

        MccDaqInterface();
        ~MccDaqInterface();

        static MccDaqInterface* _mccDaqInterfaceInstance;

        static const int numChans = 4;
        static const int numPoints = 10000;
        static const int MAXNUMDEVS = 100;

        int Row, Col;
        int  BoardNum = 0;
        int Options;
        long PreTrigCount, TotalCount, Rate, ChanCount;
        short ChanArray[numChans];
        short ChanTypeArray[numChans];
        short GainArray[numChans];
        int ULStat = 0;
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
        void startChannelScan(QMenu* mmenu);
};
#endif
