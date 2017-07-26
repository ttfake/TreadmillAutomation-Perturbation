#include "MccDaqDiscovery.h"

MccDaqDiscovery::MccDaqDiscovery()
{

}

MccDaqDiscovery::~MccDaqDiscovery()
{

}

void MccDaqDiscovery::discoverDaqDevices(QMenu* deviceMenu)
{
/* Variable Declarations */
    int BoardNum = 0;
    int UDStat = 0;
	float    RevLevel = (float)CURRENTREVNUM;

	int numberOfDevices = MAXNUMDEVS;
	DaqDeviceDescriptor inventory[MAXNUMDEVS];

	DaqDeviceDescriptor DeviceDescriptor;

	/* Declare UL Revision Level */
	UDStat = cbDeclareRevision(&RevLevel);

    /* Initiate error handling
       Parameters:
           PRINTALL :all warnings and errors encountered will be printed
           DONTSTOP :program will continue even if error occurs.
                     Note that STOPALL and STOPFATAL are only effective in 
                     Windows applications, not Console applications. 
   */
    cbErrHandling (PRINTALL, DONTSTOP);

	/* Ignore InstaCal device discovery */
	cbIgnoreInstaCal();

	/* Discover DAQ devices with cbGetDaqDeviceInventory()
	Parameters:
            InterfaceType   :interface type of DAQ devices to be discovered
            inventory[]		:array for the discovered DAQ devices
            numberOfDevices	:number of DAQ devices discovered */

	UDStat = cbGetDaqDeviceInventory(ANY_IFC, inventory, &numberOfDevices);

	if(numberOfDevices > 0)
	{

		for(BoardNum = 0; BoardNum < numberOfDevices; BoardNum++)
		{
			DeviceDescriptor = inventory[BoardNum];

            QAction* tempAction = new QAction;
            tempAction->setText(DeviceDescriptor.ProductName);
            deviceMenu->addAction(tempAction);
            QSignalMapper* tempSigMapper = new QSignalMapper;
            tempSigMapper->setMapping(tempAction, QString(DeviceDescriptor.ProductName));
            connect(tempAction, SIGNAL(triggered()), tempSigMapper, SLOT(map()));
            connect(tempSigMapper, SIGNAL(mapped(QString)), SLOT(selectDevice(QString)));

			/* Creates a device object within the Universal Library and 
			   assign a board number to the specified DAQ device with cbCreateDaqDevice()

			Parameters:
				BoardNum			: board number to be assigned to the specified DAQ device
				DeviceDescriptor	: device descriptor of the DAQ device */

			UDStat = cbCreateDaqDevice(BoardNum, DeviceDescriptor);
		}
    }
}

void MccDaqDiscovery::selectDevice(QString devName)
{
    emit setText(devName);
}


#include "../include/moc_MccDaqDiscovery.cpp"


