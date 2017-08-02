#include "MccDaqInterface.h"


MccDaqInterface::MccDaqInterface()
{
    mccDaqDisc = new MccDaqDiscovery;
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

    ULStat = cbIgnoreInstaCal();
    qDebug("UL Stat of Ignore InstaCal call: %d", ULStat);
    
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

    std::cout << "Data are being collected in the BACKGROUND, CONTINUOUSLY\n" << std::endl;


	/* load the arrays with values */
    ChanVector.push_back(0);
	ChanTypeVector.push_back(ANALOG);
    GainVector.push_back(BIP10VOLTS);

    ChanVector.push_back(FIRSTPORTA);
	ChanTypeVector.push_back(DIGITAL16);
    GainVector.push_back(NOTUSED);

	ChanVector.push_back(0);
	ChanTypeVector.push_back(CTR32LOW);
    GainVector.push_back(NOTUSED);

	ChanVector.push_back(0);
	ChanTypeVector.push_back(CTR32HIGH);
    GainVector.push_back(NOTUSED);

    short ChanArray[ChanVector.size()];
    short ChanTypeArray[ChanTypeVector.size()];
    short GainArray[GainVector.size()];


    std::copy(ChanVector.begin(), ChanVector.end(), ChanArray);
    std::copy(ChanTypeVector.begin(), ChanTypeVector.end(), ChanTypeArray);
    std::copy(GainVector.begin(), GainVector.end(), GainArray);
    
    for(const auto& item : ChanArray)
    {
        qDebug("Channel Element %d", item);
    }

    for(const auto& item : ChanTypeArray)
    {
        qDebug("Channel Type Element %d", item);
    }

    for(const auto& item : GainArray)
    {
        qDebug("Gain Element %d", item);
    }

	/* configure FIRSTPORTA and FIRSTPORTB for digital input */
	
	PortNum = FIRSTPORTA;
    Direction = DIGITALIN;
    qDebug("BoardNumber %d", BoardNum);
    ULStat = cbDConfigPort (BoardNum, PortNum, Direction);
    qDebug("cbDConfigPort UL Stat: %d", ULStat);

	PortNum = FIRSTPORTB;
	ULStat = cbDConfigPort (BoardNum, PortNum, Direction);

    qDebug("UL Status %i", ULStat);

    qDebug("Configuring Scan");
	// configure counter 0
	CounterNum = ChanArray[2];
    ULStat = cbCConfigScan(BoardNum, CounterNum, ROLLOVER, CTR_DEBOUNCE_NONE, 0, CTR_RISING_EDGE, \
            0, CounterNum);

    qDebug("Configuration finished");

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

        ULStat = cbGetStatus (BoardNum, &Status, &CurCount, &CurIndex,DAQIFUNCTION);

        /* check the current status of the background operation */
        if (Status == RUNNING)
        {
            DataIndex = CurIndex -  CurIndex % NUMCHANS - NUMCHANS;
            if(DataIndex>0)
            {
                if (!forcePlateDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
                    return;

                QTextStream forcePlateDataStream(forcePlateDataFile);


                printf ("Channel 0   Data point: %3ld   ", DataIndex);
                printf ("  Value: %d  \n",ADData[DataIndex]);
                updateDaqDataBox(ADData[DataIndex]);
                QString dataPoint1String(QString::number(ADData[DataIndex],'e',12));
                forcePlateDataStream << QTime::currentTime().toString() << ",";
                forcePlateDataStream << dataPoint1String << ",";
                DataIndex++;
                printf ("FIRSTPORTA  Data point: %3ld   ", DataIndex);
                printf ("  Value: %d  \n",ADData[DataIndex]);
                updateDaqDataBox(ADData[DataIndex]);
                QString dataPoint2String(QString::number(ADData[DataIndex],'e',12));
                forcePlateDataStream << dataPoint2String << ",";
                DataIndex++;
                printf ("Counter 0   Data point: %3ld   ", DataIndex);
                printf ("  Value: %u  ",ADData[DataIndex] + (ADData[DataIndex+1]<<16));   // 32-bit counter
                updateDaqDataBox(ADData[DataIndex] + (ADData[DataIndex+1]<<16));
                QString dataPoint3String(QString::number((ADData[DataIndex] + \
                                ADData[DataIndex+1]<<16),'e',12));
                forcePlateDataStream << dataPoint3String << '\n';
                forcePlateDataFile->close(); 
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

void MccDaqInterface::setNumberOfChannels(int mchs)
{
    NUMCHANS = mchs;
    qDebug("Number of Channels: %d", NUMCHANS);
}

#include "../include/moc_MccDaqInterface.cpp"
