#ifndef MCCDAQDISCOVERY_H
#define MCCDAQDISCOVERY_H

#include <QMenu>
#include <conio.h>
#include "cbw.h"

class MccDaqDiscovery : QObject
{
    Q_OBJECT

    public:
        MccDaqDiscovery();
        ~MccDaqDiscovery();
        void discoverDaqDevices(QMenu* deviceMenu);

    private:
        static const int MAXNUMDEVS = 100;
        static const int NUMCHANS = 4;
        static const int NUMPOINTS = 10000;

        int Row, Col;
        int  BoardNum = 0;
        int Options;
        long PreTrigCount, TotalCount, Rate, ChanCount;
        short ChanArray[NUMCHANS];
        short ChanTypeArray[NUMCHANS];
        short GainArray[NUMCHANS];
        int ULStat = 0;
        short Status = IDLE;
        long CurCount;
        long CurIndex, DataIndex;
        int PortNum, Direction, CounterNum;
        WORD *ADData;
        float RevLevel = (float)CURRENTREVNUM;

};
#endif
