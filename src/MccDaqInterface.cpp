#include "MccDaqInterface.h"


MccDaqInterface::MccDaqInterface()
{
    mccDaqDisc = new MccDaqDiscovery;
    qRegisterMetaType<uint16_t>("uint16_t");
    connect(mccDaqDisc, SIGNAL(setText(QString)), this, SLOT(setDaqButtonText(QString)));

}

MccDaqInterface::~MccDaqInterface()
{

}

void MccDaqInterface::beginDataCollection()
{

    std::vector<short> ChanVector;
    std::vector<short> ChanTypeVector;
    std::vector<short> GainVector;
    BoardNum = 0;
    ULStat = 0;
    rowCount = 0;
    
    qDebug("beginning data collection");

    forcePlateDataString = "forcePlateData.csv";

    forcePlateDataFile = new QFile(forcePlateDataString);
   
    ULStat = cbDeclareRevision(&RevLevel);

    qDebug("cbDeclareRevision ULStat: %d", ULStat);

    ADData = static_cast<WORD*>(cbWinBufAlloc(NUMPOINTS * NUMCHANS));
    if (!ADData)    /* Make sure it is a valid pointer */
    {
        std::cout << "\nout of memory\n" << std::endl;
    }
    
    
    /* Initiate error handling
       Parameters:
       PRINTALL :all warnings and errors encountered will be printed
       DONTSTOP :program will continue even if error occurs.
       Note that STOPALL and STOPFATAL are only effective in 
       Windows applications, not Console applications. 
    */
    cbErrHandling (PRINTALL, DONTSTOP);

    std::cout << "Continuous data collection has begun in the BACKGROUND.\n" << std::endl;

    /* load the arrays with values */
    
    for(channel = 0; channel < NUMCHANS; channel++)
    {
        emit getActiveState(channel);

        QThread::msleep(30);
        if (!forcePlateDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
            return;

        if(activeState)
        {
            qDebug("Channel %i is set to active", channel);
            ChanVector.push_back(channel);
            ChanTypeVector.push_back(ANALOG);
            GainVector.push_back(BIP10VOLTS);

            QTextStream forcePlateDataStream(forcePlateDataFile);

            QString channelHeaderString("Channel ");
            channelHeaderString += QString::number(channel);
            channelHeaderString += ",";

            forcePlateDataStream << channelHeaderString;

            activeState = false;
        }

/*        if (!forcePlateDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
            return;

        ChanVector.push_back(channel);
        ChanTypeVector.push_back(ANALOG);
        GainVector.push_back(BIP10VOLTS);

        QTextStream forcePlateDataStream(forcePlateDataFile);

        QString channelHeaderString("Channel ");
        channelHeaderString += QString::number(channel);
        channelHeaderString += ",";

        forcePlateDataStream << channelHeaderString;
*/
        forcePlateDataFile->close();

    }
    
    
    short ChanArray[ChanVector.size()];
    short ChanTypeArray[ChanTypeVector.size()];
    short GainArray[GainVector.size()];


    std::copy(ChanVector.begin(), ChanVector.end(), ChanArray);
    std::copy(ChanTypeVector.begin(), ChanTypeVector.end(), ChanTypeArray);
    std::copy(GainVector.begin(), GainVector.end(), GainArray);
    

	/* configure FIRSTPORTA and FIRSTPORTB for digital input */
	
	PortNum = FIRSTPORTA;
    Direction = DIGITALIN;
    qDebug("BoardNumber %d", BoardNum);
    ULStat = cbDConfigPort (BoardNum, PortNum, Direction);
    qDebug("cbDConfigPort UL Stat: %d", ULStat);

	PortNum = FIRSTPORTB;
	ULStat = cbDConfigPort (BoardNum, PortNum, Direction);

    qDebug("UL Status %i", ULStat);


    /* Collect the values with cbDaqInScan() in BACKGROUND mode, CONTINUOUSLY
        Parameters:
            BoardNum    :the number used by CB.CFG to describe this board
            ChanArray[] :array of channel values
			ChanTypeArray[] : array of channel types
            GainArray[] :array of gain values
            ChanCount    :the number of channels
            Rate        :sample rate in samples per second
			PretrigCount:number of pre-trigger A/D samples to collect
            TotalCount  :the total number of A/D samples to collect
            ADData[]    :the array for the collected data values
            Options     :data collection options  */

    ChanCount = NUMCHANS;
	PreTrigCount =0;
	TotalCount = NUMPOINTS * NUMCHANS;
	Rate = 1000;								             /* sampling rate (samples per second) */
	Options = CONVERTDATA + BACKGROUND + CONTINUOUS;         /* data collection options */

    channel = 0;
    qDebug("Starting scan");
	ULStat = cbDaqInScan(BoardNum, ChanArray, \
            ChanTypeArray, GainArray, \
            ChanCount, &Rate, &PreTrigCount, &TotalCount, ADData, Options);
    qDebug("Error code is %d", ULStat);

	if(ULStat == NOERRORS)
		Status = RUNNING;

    
    
    while (!_kbhit() && Status==RUNNING)
    {
        /* Check the status of the current background operation
           Parameters:
           BoardNum  :the number used by CB.CFG to describe this board
           Status    :current status of the operation (IDLE or RUNNING)
           CurCount  :current number of samples collected
           CurIndex  :index to the last data value transferred 
           FunctionType: A/D operation (DAQIFUNCTION)*/

        ULStat = cbGetStatus (BoardNum, &Status, &CurCount, &CurIndex, DAQIFUNCTION);

        /* check the current status of the background operation */
        if (Status == RUNNING)
        {
            DataIndex = CurIndex -  CurIndex % NUMCHANS - NUMCHANS;
            if(DataIndex>0)
            {
                emit updateRowCount(rowCount);
                if (!forcePlateDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
                    return;

                QTextStream forcePlateDataStream(forcePlateDataFile);

                for(channel = 0; channel < NUMCHANS; channel++)
                {
                    emit updateCol(channel);
                    emit updateDaqDataBoxSignal(static_cast<uint16_t>(ADData[DataIndex]));
                    QString channel0("Channel 0");
                    forcePlateDataStream << channel0 << ",";
                    QString dataPoint1String(QString::number(ADData[DataIndex],'e',12));
                    forcePlateDataStream << QTime::currentTime().toString() << ",";
                    forcePlateDataStream << dataPoint1String << "\n";
                    DataIndex++;
                }

                //channel = 1;
                //emit updateCol(channel);
                //emit updateDaqDataBoxSignal(static_cast<uint16_t>(ADData[DataIndex]));
                //QString channel1("Channel 1");
                //forcePlateDataStream << channel1 << ",";
                //QString dataPoint2String(QString::number(ADData[DataIndex],'e',12));
                //forcePlateDataStream << QTime::currentTime().toString() << ",";
                //forcePlateDataStream << dataPoint2String << "\n";
                forcePlateDataFile->close(); 
                rowCount++;

            }
        }
    }

    /* The BACKGROUND operation must be explicitly stopped
       Parameters:
       BoardNum    :the number used by CB.CFG to describe this board 
       FunctionType: A/D operation (DAQIFUNCTION)*/  
    qDebug("Exited");
    
    ULStat = cbStopBackground (BoardNum,DAQIFUNCTION);

    cbWinBufFree(ADData);
}

void MccDaqInterface::setDaqButtonText(QString daqTitleText)
{
    emit setDaqTitleText(daqTitleText);
}

void MccDaqInterface::setDaqDataBox(QPlainTextEdit* mdaqBox)
{
    daqBox = new QPlainTextEdit;
    daqBox = mdaqBox;
}

void MccDaqInterface::startChannelScan(QMenu* mmenu)
{
    mccDaqDisc->discoverDaqDevices(mmenu);
}

void MccDaqInterface::dataCollectionSetup()
{

}

void MccDaqInterface::setNumberOfChannels(long mchs)
{
    NUMCHANS = mchs;
    qDebug("Number of Channels: %d", NUMCHANS);
}

void MccDaqInterface::setCurrentChannelActiveState(bool mactiveState)
{
    activeState = mactiveState;
}

#include "../include/moc_MccDaqInterface.cpp"
