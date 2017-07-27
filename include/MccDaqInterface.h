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
#include "MccDaqDiscovery.h"

class MccDaqInterface : public QObject
{
    Q_OBJECT
    
    public:
        static MccDaqInterface* getInstance();
        void startChannelScan(QMenu* mmenu);
        void setDaqButton(QPushButton* mdaqButton);
        void dataCollectionSetup();
        void setNumberOfChannels(int chs);
    
    public slots:
        void beginDataCollection();
        void setDaqButtonText(QString daqTitleText);

    signals:
        void finished();
        void setDaqTitleText(QString title);

    private:

        template<typename T> void updateDaqDataBox(T data)
        {
            QString dataString = QString::number(data, 'e', 12);
            daqBox->appendPlainText(dataString);
        }

        MccDaqInterface();
        ~MccDaqInterface();

        static MccDaqInterface* _mccDaqInterfaceInstance;

        int NUMCHANS;
        static const int NUMPOINTS = 10000;
        static const int MAXNUMDEVS = 100;

        int Row, Col;
        int  BoardNum = 0;
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
        
};
#endif
