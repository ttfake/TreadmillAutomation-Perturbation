#include "MccDaqInterface.h"

MccDaqInterface* MccDaqInterface::_mccDaqInterfaceInstance = 0;

MccDaqInterface::MccDaqInterface()
{
    pertTabWidget = PerturbationTabWidget::getInstance();
    connect(this, SIGNAL(updatePertPlainTextBox()), SLOT(updateDaqDataBox()));
}

MccDaqInterface::~MccDaqInterface()
{

}

MccDaqInterface* MccDaqInterface::getInstance()
{
    if(_mccDaqInterfaceInstance == NULL)
    {
        _mccDaqInterfaceInstance = new MccDaqInterface();
    }

    return _mccDaqInterfaceInstance;
}

void MccDaqInterface::beginDataCollection()
{
    qDebug("beginning data collection");

    forcePlateDataString = "forcePlateData.csv";

    forcePlateDataFile = new QFile(forcePlateDataString);
    
    if ( forcePlateDataFile->open(QIODevice::ReadWrite) )
    {
        stream = new QTextStream(forcePlateDataFile);
    }

    ULStat = cbDeclareRevision(&RevLevel);

    qDebug("%d", ULStat);

    ADData = static_cast<WORD*>(cbWinBufAlloc(numPoints * numChans));
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
    ChanArray[0] = 0;
	ChanTypeArray[0] = ANALOG;
    GainArray[0] = BIP10VOLTS;

    ChanArray[1] = FIRSTPORTA;
	ChanTypeArray[1] = DIGITAL16;
    GainArray[1] = NOTUSED;

	ChanArray[2] = 0;
	ChanTypeArray[2] = CTR32LOW;
    GainArray[2] = NOTUSED;

	ChanArray[3] = 0;
	ChanTypeArray[3] = CTR32HIGH;
    GainArray[3] = NOTUSED;

	/* configure FIRSTPORTA and FIRSTPORTB for digital input */
	
	PortNum = FIRSTPORTA;
    Direction = DIGITALIN;
    ULStat = cbDConfigPort (BoardNum, PortNum, Direction);

	PortNum = FIRSTPORTB;
	ULStat = cbDConfigPort (BoardNum, PortNum, Direction);

	// configure counter 0
	CounterNum = ChanArray[2];
    ULStat = cbCConfigScan(BoardNum, CounterNum, ROLLOVER, CTR_DEBOUNCE_NONE, 0, CTR_RISING_EDGE, \
            0, CounterNum);

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

    ChanCount = numChans;
	PreTrigCount =0;
	TotalCount = numPoints * numChans;
	Rate = 1000;								             /* sampling rate (samples per second) */
	Options = CONVERTDATA + BACKGROUND + CONTINUOUS;         /* data collection options */

	ULStat = cbDaqInScan(BoardNum, ChanArray, ChanTypeArray, GainArray, ChanCount, &Rate, &PreTrigCount, &TotalCount, ADData, Options);

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
            DataIndex = CurIndex -  CurIndex % numChans - numChans;
            if(DataIndex>0)
            {
                printf ("Channel 0   Data point: %3ld   ", DataIndex);
                printf ("  Value: %d  \n",ADData[DataIndex]);
                dataVector.push_back(ADData[DataIndex]);
                QString dataPoint1String(QString::number(ADData[DataIndex],'e',12));
                stream->setString(&dataPoint1String,QIODevice::ReadWrite);
                DataIndex++;
                printf ("FIRSTPORTA  Data point: %3ld   ", DataIndex);
                printf ("  Value: %d  \n",ADData[DataIndex]);
                dataVector.push_back(ADData[DataIndex]);
                QString dataPoint2String(QString::number(ADData[DataIndex],'e',12));
                stream->setString(&dataPoint2String,QIODevice::ReadWrite);
                DataIndex++;
                printf ("Counter 0   Data point: %3ld   ", DataIndex);
                printf ("  Value: %u  ",ADData[DataIndex] + (ADData[DataIndex+1]<<16));   // 32-bit counter
                dataVector.push_back(ADData[DataIndex] + (ADData[DataIndex+1]<<16));
                QString dataPoint3String(QString::number((ADData[DataIndex] + \
                                ADData[DataIndex+1]<<16),'e',12));
                stream->setString(&dataPoint3String,QIODevice::ReadWrite);

                emit(updatePertPlainTextBox());


            }
        }
    }

    /* The BACKGROUND operation must be explicitly stopped
       Parameters:
       BoardNum    :the number used by CB.CFG to describe this board 
       FunctionType: A/D operation (DAQIFUNCTION)*/  
    ULStat = cbStopBackground (BoardNum,DAQIFUNCTION);

    cbWinBufFree(ADData);

}

void MccDaqInterface::updateDaqDataBox()
{
    for(const auto& dataElement : dataVector)
    {
        pertTabWidget->updateDaqDataBox(dataElement);
    }
}
#include "../include/moc_MccDaqInterface.cpp"
