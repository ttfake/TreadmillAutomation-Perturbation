#ifndef MCCDAQINTERFACE_H
#define MCCDAQINTERFACE_H

#include <iostream>
#include <conio.h>
#include <QObject>
#include <QThread>
#include <vector>
#include "cbw.h"
#include "PerturbationTabWidget.h"

class MccDaqInterface : public QObject
{
    Q_OBJECT
    
    public:
        static MccDaqInterface* getInstance();


    public slots:
        void beginDataCollection();
        void updateDaqDataBox();
    signals:
        void updatePertPlainTextBox();
        void finished();

    private:

        MccDaqInterface();
        ~MccDaqInterface();

        static MccDaqInterface* _mccDaqInterfaceInstance;

        static const int numChans = 4;
        static const int numPoints = 10000;

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
        PerturbationTabWidget* pertTabWidget;
};
#endif
