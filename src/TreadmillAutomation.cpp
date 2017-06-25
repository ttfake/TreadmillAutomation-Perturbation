#include "include/TreadmillAutomation.h"

TreadmillAutomation::TreadmillAutomation(QWidget *parent, Qt::WindowFlags flags):
    centralWidget(new QWidget)
{

#if defined(Q_OS_MAC)
	QString libFile = "libtreadmill-remote.dylib";
#elif defined(Q_OS_LINUX)
	QString libFile = "libtreadmill-remote.so";
#elif defined(Q_OS_WIN)
	QString libFile = "treadmill-remote.dll";
#endif

    QLibrary lib("./treadmill-remote");
    TREADMILL_initialize = (t_TREADMILL_initialize)(lib.resolve("TREADMILL_initialize"));
	TREADMILL_initializeUDP = (t_TREADMILL_initializeUDP)(lib.resolve("TREADMILL_initializeUDP"));
	TREADMILL_setSpeed = (t_TREADMILL_setSpeed)(lib.resolve("TREADMILL_setSpeed"));
	TREADMILL_setSpeed4 = (t_TREADMILL_setSpeed4)(lib.resolve("TREADMILL_setSpeed4"));
	TREADMILL_close = (t_TREADMILL_close)(lib.resolve("TREADMILL_close"));

    setCentralWidget(centralWidget);
    centralWidgetLayout = new QVBoxLayout;
    centralWidget->setLayout(centralWidgetLayout);
    createFileMenu();
    createTabWidget();
    createNetworkTab();
    populateNetworkTab();
    createTreadmillPerturbationTab();
    populateTreadmillPerturbationTab();
}

TreadmillAutomation::~TreadmillAutomation()
{

}

void TreadmillAutomation::createFileMenu()
{
    menuBar = new QMenuBar;
    menuFile = new QMenu(menuBar);
    menuFile->setObjectName(QStringLiteral("menuFile"));
    menuFile->setTitle(QApplication::translate("TreadmillAutomation", "File", Q_NULLPTR));
    exitAct = new QAction();
    menuFile->addAction(exitAct);
    exitAct->setText("Exit");
    menuBar->addMenu(menuFile);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    centralWidgetLayout->setMenuBar(menuBar);
}

void TreadmillAutomation::createTabWidget()
{
    centralTabWidget = new QTabWidget;
    centralWidgetLayout->addWidget(centralTabWidget);
    centralGridLayout = new QGridLayout;
    centralTabWidget->setLayout(centralGridLayout);
}


void TreadmillAutomation::createNetworkTab()
{
    networkTab = new QWidget;
    networkTab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    networkTabLayout = new QVBoxLayout;
    networkTab->setObjectName("NetworkTab");
    networkTab->setLayout(networkTabLayout);
    centralTabWidget->addTab(networkTab, QString());
    centralTabWidget->setTabText(centralTabWidget->indexOf(networkTab), \
            QApplication::translate("Treadmill Automation", "Network", Q_NULLPTR));
}

void TreadmillAutomation::populateNetworkTab()
{
    hostLabelFont.setFamily("Times");
    hostLabelFont.setWeight(75);
    hostLabelFont.setPointSize(12);
    hostLabel = new QLabel;
    hostLabel->setText("Host: ");
    hostLabel->setFixedSize(50,40);
    hostLabel->setFont(hostLabelFont);
    hostLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    hostTextBox = new QPlainTextEdit;
    hostTextBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    hostTextBox->setFixedSize(200,30);
    
    portLabelFont.setFamily("Times");
    portLabelFont.setWeight(75);
    portLabelFont.setPointSize(12);
    portLabel = new QLabel;
    portLabel->setText("Port: ");
    portLabel->setFixedSize(50,40);
    portLabel->setFont(portLabelFont);
    portLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    portTextBox = new QPlainTextEdit;
    portTextBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    portTextBox->setFixedSize(200,30);


    networkGroupBox = new QGroupBox;
    networkGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalNetworkGroupBoxLayout = new QVBoxLayout;
    networkGroupBox->setLayout(verticalNetworkGroupBoxLayout);
    networkTabLayout->addWidget(networkGroupBox);
    
    useLibraryLabelFont.setFamily("Times");
    useLibraryLabelFont.setWeight(75);
    useLibraryLabelFont.setPointSize(12);
    useLibraryLabel = new QLabel;
    useLibraryLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    useLibraryLabel->setFixedSize(300,40);
    useLibraryLabel->setText("Use Treadmill Library");
    useLibraryLabel->setFont(useLibraryLabelFont);
    useLibraryGroupBox = new QGroupBox;
    useLibraryGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    useLibraryGroupBoxLayout = new QHBoxLayout;
    useLibraryGroupBox->setLayout(useLibraryGroupBoxLayout);
    useLibrary = new QCheckBox;
    useLibrary->setFixedSize(50,50);
    useLibraryGroupBoxLayout->addWidget(useLibraryLabel);
    useLibraryGroupBoxLayout->addWidget(useLibrary);

    networkLabelTextGroupBox = new QGroupBox;
    networkLabelTextGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    horizontalNetworkLabelTextGroupBoxLayout = new QHBoxLayout;
    networkLabelTextGroupBox->setLayout(horizontalNetworkLabelTextGroupBoxLayout);
    

    tcpLabelFont.setFamily("Times");
    tcpLabelFont.setWeight(75);
    tcpLabelFont.setPointSize(12);
    tcpLabel = new QLabel;
    tcpLabel->setFont(tcpLabelFont);
    tcpLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    tcpLabel->setFixedSize(50, 40);
    tcpLabel->setText("TCP: ");

    udpLabelFont.setFamily("Times");
    udpLabelFont.setWeight(75);
    udpLabelFont.setPointSize(12);
    udpLabel = new QLabel;
    udpLabel->setFont(udpLabelFont);
    udpLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    udpLabel->setFixedSize(50,40);
    udpLabel->setText("UDP: ");
    tcpRadioButton = new QRadioButton;
    udpRadioButton = new QRadioButton;
    networkTcpUdbGroupBox = new QGroupBox;
    networkTcpUdbGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    horizontalNetworkTcpUdbGroupBoxLayout = new QHBoxLayout;
    networkTcpUdbGroupBox->setLayout(horizontalNetworkTcpUdbGroupBoxLayout);
    horizontalNetworkTcpUdbGroupBoxLayout->addWidget(tcpLabel);
    horizontalNetworkTcpUdbGroupBoxLayout->addWidget(tcpRadioButton);
    horizontalNetworkTcpUdbGroupBoxLayout->addWidget(udpLabel);
    horizontalNetworkTcpUdbGroupBoxLayout->addWidget(udpRadioButton);
    
    networkButtonGroupBox = new QGroupBox;
    networkButtonGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    horizontalNetworkButtonGroupBoxLayout = new QHBoxLayout;
    networkButtonGroupBox->setLayout(horizontalNetworkButtonGroupBoxLayout);

    verticalNetworkGroupBoxLayout->addWidget(useLibraryGroupBox);
    verticalNetworkGroupBoxLayout->addWidget(networkLabelTextGroupBox);
    verticalNetworkGroupBoxLayout->addWidget(networkTcpUdbGroupBox);
    verticalNetworkGroupBoxLayout->addWidget(networkButtonGroupBox);

    horizontalNetworkLabelTextGroupBoxLayout->addWidget(hostLabel);
    horizontalNetworkLabelTextGroupBoxLayout->addWidget(hostTextBox);
    horizontalNetworkLabelTextGroupBoxLayout->addWidget(portLabel);
    horizontalNetworkLabelTextGroupBoxLayout->addWidget(portTextBox);

    connectBtn = new QPushButton;
    connectBtn->setText("Connect");
    connectBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    connectBtn->setFixedSize(200, 40);
    horizontalNetworkButtonGroupBoxLayout->addWidget(connectBtn);
    
    disconnectBtn = new QPushButton;
    disconnectBtn->setText("Disconnect");
    disconnectBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    disconnectBtn->setFixedSize(200, 40);
    horizontalNetworkButtonGroupBoxLayout->addWidget(disconnectBtn);

    connect(connectBtn, SIGNAL(clicked()), this, SLOT(onClickConnect()));



}

void TreadmillAutomation::createTreadmillPerturbationTab()
{
    perturbationTab = new QWidget;
    perturbationTab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    perturbationTabLayout = new QGridLayout;
    perturbationTab->setObjectName("PerturbationTab");
    perturbationTab->setLayout(perturbationTabLayout);
    centralTabWidget->addTab(perturbationTab, QString());
    centralTabWidget->setTabText(centralTabWidget->indexOf(perturbationTab), \
            QApplication::translate("Treadmill Automation", "Perturbation", Q_NULLPTR));
}

void TreadmillAutomation::populateTreadmillPerturbationTab()
{
    quadrantOneGroupBox = new QGroupBox;
    quadrantOnePerturbationLayout = new QVBoxLayout;
    quadrantOneGroupBox->setLayout(quadrantOnePerturbationLayout);
    accelDecelGroupBox = new QGroupBox;
    accelDecelGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    accelerationDecelerationHorizontalLayout = new QHBoxLayout;
    accelDecelGroupBox->setLayout(accelerationDecelerationHorizontalLayout);


    perturbationTabLayout->addWidget(quadrantOneGroupBox, 0,0);

    speedGroupBox = new QGroupBox;
    frontSpeedGroupBox = new QGroupBox;
    frontSpeedHorizontalLayout = new QHBoxLayout;
    frontSpeedGroupBox->setLayout(frontSpeedHorizontalLayout);
    speedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedGroupBoxGridLayout = new QGridLayout;
    speedGroupBox->setLayout(speedGroupBoxGridLayout);
    speedGroupBoxGridLayout->addWidget(frontSpeedGroupBox);
    
    speedLeftFrontLabel = new QLabel;
    speedLeftFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedLeftFrontLabel->setText("Left Front Speed: ");
    speedLeftFrontLabel->setFixedSize(150,180);
    speedLeftFrontLabelFont.setFamily("Times");
    speedLeftFrontLabelFont.setWeight(75);
    speedLeftFrontLabelFont.setPointSize(12);
    speedLeftFrontLabel->setFont(speedLeftFrontLabelFont);
    frontSpeedHorizontalLayout->addWidget(speedLeftFrontLabel);
    leftFrontSpeedSetpoint = new QDoubleSpinBox;
    leftFrontSpeedSetpointFont.setFamily("Times");
    leftFrontSpeedSetpointFont.setWeight(75);
    leftFrontSpeedSetpointFont.setPointSize(12);
    leftFrontSpeedSetpoint->setFont(leftFrontSpeedSetpointFont);
    leftFrontSpeedSetpoint->setSuffix("  m/s");
    leftFrontSpeedSetpoint->setFixedSize(160,40);
    connect(leftFrontSpeedSetpoint, SIGNAL(valueChanged(double)), SLOT(setLeftFrontSpeedValue(double)));
    frontSpeedHorizontalLayout->addWidget(leftFrontSpeedSetpoint);

    speedRightFrontLabel = new QLabel;
    speedRightFrontLabel->setText("Right Front Speed: ");
    speedRightFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedRightFrontLabel->setFixedSize(150,180);
    speedRightFrontLabelFont.setFamily("Times");
    speedRightFrontLabelFont.setWeight(75);
    speedRightFrontLabelFont.setPointSize(12);
    speedRightFrontLabel->setFont(speedRightFrontLabelFont);
    frontSpeedHorizontalLayout->addWidget(speedRightFrontLabel);
    rightFrontSpeedSetpoint = new QDoubleSpinBox;
    rightFrontSpeedSetpointFont.setFamily("Times");
    rightFrontSpeedSetpointFont.setWeight(75);
    rightFrontSpeedSetpointFont.setPointSize(12);
    rightFrontSpeedSetpoint->setFont(rightFrontSpeedSetpointFont);
    rightFrontSpeedSetpoint->setSuffix("  m/s");
    rightFrontSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightFrontSpeedSetpoint->setFixedSize(160,40);
    connect(rightFrontSpeedSetpoint, SIGNAL(valueChanged(double)), SLOT(setRightFrontSpeedValue(double)));
    frontSpeedHorizontalLayout->addWidget(rightFrontSpeedSetpoint);
    

    rearSpeedGroupBox = new QGroupBox;
    rearSpeedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rearSpeedHorizontalLayout = new QHBoxLayout;
    rearSpeedGroupBox->setLayout(rearSpeedHorizontalLayout);
    speedGroupBoxGridLayout->addWidget(rearSpeedGroupBox);
    speedLeftRearLabel = new QLabel;
    speedLeftRearLabel->setText("Left Rear Speed: ");
    speedLeftRearLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedLeftRearLabel->setFixedSize(150, 180);
    rearSpeedHorizontalLayout->addWidget(speedLeftRearLabel);
    speedLeftRearLabelFont.setFamily("Times");
    speedLeftRearLabelFont.setWeight(75);
    speedLeftRearLabelFont.setPointSize(12);
    speedLeftRearLabel->setFont(speedLeftRearLabelFont);
    leftRearSpeedSetpoint = new QDoubleSpinBox;
    leftRearSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    leftRearSpeedSetpointFont.setFamily("Times");
    leftRearSpeedSetpointFont.setWeight(75);
    leftRearSpeedSetpointFont.setPointSize(12);
    leftRearSpeedSetpoint->setFont(speedLeftRearLabelFont);
    leftRearSpeedSetpoint->setSuffix("  m/s");
    leftRearSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    leftRearSpeedSetpoint->setFixedSize(160,40);
    connect(leftRearSpeedSetpoint, SIGNAL(valueChanged(double)), SLOT(setLeftRearSpeedValue(double)));
    rearSpeedHorizontalLayout->addWidget(leftRearSpeedSetpoint);

    rightRearSpeedSetpoint = new QDoubleSpinBox;
    speedRightRearLabel = new QLabel;
    speedRightRearLabel->setText("Right Rear Speed: ");
    speedRightRearLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedRightRearLabel->setFixedSize(150,180);
    speedRightRearLabelFont.setFamily("Times");
    speedRightRearLabelFont.setWeight(75);
    speedRightRearLabelFont.setPointSize(12);
    speedRightRearLabel->setFont(speedRightRearLabelFont);
    rearSpeedHorizontalLayout->addWidget(speedRightRearLabel);
    rightRearSpeedSetpoint = new QDoubleSpinBox;
    rightRearSpeedSetpoint->setSuffix("  m/s");
    rightRearSpeedSetpointFont.setFamily("Times");
    rightRearSpeedSetpointFont.setWeight(75);
    rightRearSpeedSetpointFont.setPointSize(12);
    rightRearSpeedSetpoint->setFont(rightRearSpeedSetpointFont);
    rightRearSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightRearSpeedSetpoint->setFixedSize(160,40);
    connect(rightRearSpeedSetpoint, SIGNAL(valueChanged(double)), SLOT(setRightRearSpeedValue(double)));
    rearSpeedHorizontalLayout->addWidget(rightRearSpeedSetpoint);

    quadrantOnePerturbationLayout->addWidget(speedGroupBox);


    quadrantOnePerturbationLayout->addWidget(accelDecelGroupBox);
    
    accelerationLabel = new QLabel;
    accelerationLabelFont.setFamily("Times");
    accelerationLabelFont.setWeight(75);
    accelerationLabelFont.setPointSize(12);
    accelerationLabel->setFont(accelerationLabelFont);
    accelerationLabel->setText("Acceleration: ");
    accelerationLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    accelerationLabel->setFixedSize(150,180);
    accelerationDecelerationHorizontalLayout->addWidget(accelerationLabel);
    acceleration = new QDoubleSpinBox;
    accelerationSpinBoxFont.setFamily("Times");
    accelerationSpinBoxFont.setWeight(75);
    accelerationSpinBoxFont.setPointSize(12);
    acceleration->setSuffix("  m/s²");
    acceleration->setRange(0.00, 10.00);
    acceleration->setFont(accelerationSpinBoxFont);
    acceleration->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    acceleration->setFixedSize(160,40);
    connect(acceleration, SIGNAL(valueChanged(double)), SLOT(setAccelerationValue(double)));
    accelerationDecelerationHorizontalLayout->addWidget(acceleration);
    
    decelerationLabel = new QLabel;
    decelerationLabelFont.setFamily("Times");
    decelerationLabelFont.setWeight(75);
    decelerationLabelFont.setPointSize(12);
    decelerationLabel->setFont(decelerationLabelFont);
    decelerationLabel->setText("Deceleration: ");
    decelerationLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelerationLabel->setFixedSize(150,180);
    accelerationDecelerationHorizontalLayout->addWidget(decelerationLabel);
    deceleration = new QDoubleSpinBox;
    decelerationSpinBoxFont.setFamily("Times");
    decelerationSpinBoxFont.setWeight(75);
    decelerationSpinBoxFont.setPointSize(12);
    deceleration->setSuffix("  m/s²");
    deceleration->setRange(-10.00, 0.00);
    deceleration->setFont(decelerationLabelFont);
    deceleration->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    deceleration->setFixedSize(160,40);
    connect(deceleration, SIGNAL(valueChanged(double)), SLOT(setDecelerationValue(double)));
    accelerationDecelerationHorizontalLayout->addWidget(deceleration);
    
    timeGroupBox = new QGroupBox;
    timeGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    quadrantOnePerturbationLayout->addWidget(timeGroupBox);
    timeGroupBoxLayout = new QHBoxLayout;
    timeGroupBox->setLayout(timeGroupBoxLayout);
    timeAccelLabel = new QLabel;
    timeAccelLabelFont.setFamily("Times");
    timeAccelLabelFont.setWeight(75);
    timeAccelLabelFont.setPointSize(12);
    timeAccelLabel->setText("Acceleration Time: ");
    timeAccelLabel->setFont(timeAccelLabelFont);
    timeAccelLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeAccelLabel->setFixedSize(190,180);
    timeGroupBoxLayout->addWidget(timeAccelLabel);
    timeAccelSpinBox = new QDoubleSpinBox;
    timeAccelSpinBoxFont.setFamily("Times");
    timeAccelSpinBoxFont.setWeight(75);
    timeAccelSpinBoxFont.setPointSize(12);
    timeAccelSpinBox->setFont(timeAccelSpinBoxFont);
    timeAccelSpinBox->setFixedSize(160,40);
    timeAccelSpinBox->setSuffix("  ms");
    timeAccelSpinBox->setRange(0.00, 100000000.00);

    timeAccelSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed); 
    connect(timeAccelSpinBox, SIGNAL(valueChanged(double)), SLOT(setAccelerationTimeValue(double)));
    timeGroupBoxLayout->addWidget(timeAccelSpinBox);

    
    timeDecelLabel = new QLabel;
    timeDecelLabelFont.setFamily("Times");
    timeDecelLabelFont.setWeight(75);
    timeDecelLabelFont.setPointSize(12);
    timeDecelLabel->setFont(timeDecelLabelFont);
    timeDecelLabel->setText("Deceleration Time: ");
    timeDecelLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeDecelLabel->setFixedSize(190,180);
    timeGroupBoxLayout->addWidget(timeDecelLabel);
    timeDecelSpinBox = new QDoubleSpinBox;
    timeDecelSpinBoxFont.setFamily("Times");
    timeDecelSpinBoxFont.setWeight(75);
    timeDecelSpinBoxFont.setPointSize(12);
    timeDecelSpinBox->setFont(timeDecelSpinBoxFont);
    timeDecelSpinBox->setSuffix("  ms");
    timeDecelSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeDecelSpinBox->setFixedSize(160,40);
    timeDecelSpinBox->setRange(0.00, 100000000.00);
    timeGroupBoxLayout->addWidget(timeDecelSpinBox);
    connect(timeDecelSpinBox, SIGNAL(valueChanged(double)), SLOT(setDecelerationTimeValue(double)));


    startPertRunGroupBox = new QGroupBox;
    startPertRunGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunGroupBoxLayout = new QHBoxLayout;
    startPertRunGroupBox->setLayout(startPertRunGroupBoxLayout);
    startPertRun = new QPushButton;
    startPertRun->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRun->setFixedSize(200,40);
    startPertRun->setText("Start");    
    startPertRunGroupBoxLayout->addWidget(startPertRun);
    quadrantOnePerturbationLayout->addWidget(startPertRunGroupBox);

    connect(startPertRun, SIGNAL(clicked()), SLOT(startAccelTimer()));

    quadrantTwoGroupBox = new QGroupBox;
    perturbationTabLayout->addWidget(quadrantTwoGroupBox, 0,1);

}

void TreadmillAutomation::setAccelerationTimeValue(double maccelTimeValue)
{

    accelerationTimeValue = maccelTimeValue;

    std::cout << "Acceleration Time Set to: " << accelerationTimeValue << std::endl;
}

void TreadmillAutomation::setDecelerationTimeValue(double mdecelTimeValue)
{
    decelerationTimeValue = mdecelTimeValue;

    std::cout << "Deceleration Time Set to: " << decelerationTimeValue << std::endl;
}

void TreadmillAutomation::setAccelerationValue(double maccelValue)
{
    accelerationValue = maccelValue;
    std::cout << "Acceleration Value Set to: " << accelerationValue << std::endl;
}

void TreadmillAutomation::setDecelerationValue(double mdecelValue)
{
    decelerationValue = mdecelValue;
    std::cout << "Deceleration Set to: " << decelerationValue << std::endl;
}

void TreadmillAutomation::setLeftFrontSpeedValue(double mleftFrontSpeedValue)
{

    leftSpeedFrontValue = mleftFrontSpeedValue;
    std::cout << "Left Front Speed Set to: " << leftSpeedFrontValue << std::endl;
}

void TreadmillAutomation::setLeftFrontSpeedValueFromIncoming(qint16 mleftFrontSpeedValue)
{
    leftSpeedFrontValue = static_cast<double>(mleftFrontSpeedValue);
}

void TreadmillAutomation::setRightFrontSpeedValue(double mrightFrontSpeedValue)
{
    rightSpeedFrontValue = mrightFrontSpeedValue;  
    std::cout << "Right Front Speed Set to: " << rightSpeedFrontValue << std::endl;

}

void TreadmillAutomation::setRightFrontSpeedValueFromIncoming(qint16 mrightFrontSpeedValue)
{
  rightSpeedFrontValue = static_cast<double>(mrightFrontSpeedValue); 
}

void TreadmillAutomation::setLeftRearSpeedValue(double mleftRearSpeedValue)
{
    leftSpeedRearValue = mleftRearSpeedValue;
    std::cout << "Left Rear Speed Set to: " << leftSpeedRearValue << std::endl;

}

void TreadmillAutomation::setLeftRearSpeedValueFromIncoming(qint16 mleftRearSpeedValue)
{
    leftSpeedRearValue = static_cast<double>(mleftRearSpeedValue);
}

void TreadmillAutomation::setRightRearSpeedValue(double mrightRearSpeedValue)
{
    rightSpeedRearValue = mrightRearSpeedValue;
    std::cout << "Right Rear Speed Set to: " << rightSpeedRearValue << std::endl;

}

void TreadmillAutomation::setRightRearSpeedValueFromIncoming(qint16 mrightRearSpeedValue)
{
    rightSpeedRearValue = static_cast<double>(mrightRearSpeedValue);
}

double TreadmillAutomation::getAccelerationTimeValue()
{
    return accelerationTimeValue;
}

double TreadmillAutomation::getDecelerationTimeValue()
{
    return decelerationTimeValue;
}

double TreadmillAutomation::getAccelerationValue()
{
    return accelerationValue;
}
double TreadmillAutomation::getDecelerationValue()
{
    return decelerationValue;
}
double TreadmillAutomation::getLeftFrontSpeedValue()
{
    return leftSpeedFrontValue;
}
double TreadmillAutomation::getRightFrontSpeedValue()
{
    return rightSpeedFrontValue;
}
double TreadmillAutomation::getLeftRearSpeedValue()
{
    return leftSpeedRearValue;
}
double TreadmillAutomation::getRightRearSpeedValue()
{
    return rightSpeedRearValue;
}

void TreadmillAutomation::onClickConnect()
{
    ok = 0;
    base = 10;

    if (!useLibrary->isChecked()) 
    {
		delete socket;
		if (tcpRadioButton->isChecked())
		{
			socket = new QTcpSocket;
		}
		else
		{
			socket = new QUdpSocket;
		}

		connect(socket, SIGNAL(connected()), SLOT(connected()));
		connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
		connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(error(QAbstractSocket::SocketError)));
		connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
        port = portTextBox->toPlainText();
		qDebug("New connection made on port %d.", port.toUInt(ok, base));;
		socket->connectToHost(hostTextBox->toPlainText(), port.toUInt(ok, base));

	}
	else
	{
		int rc;
		if (tcpRadioButton->isChecked())
		{
			rc = TREADMILL_initialize((hostTextBox->toPlainText()).toLatin1().data(), \
                    (portTextBox->toPlainText()).toLatin1().data());
		}
		else
		{
			rc = TREADMILL_initializeUDP((hostTextBox->toPlainText()).toLatin1().data(), 
                    (portTextBox->toPlainText()).toLatin1().data());
		}

		if (rc != TREADMILL_OK)
		{
			error(rc);
			return;
		}
		connected();
	}

}

void TreadmillAutomation::startAccelTimer()
{
    double retAccelValue = getAccelerationTimeValue();
    const int millisecondConversion = 1000;
    qDebug("Acceleration will commence for %f seconds", retAccelValue/millisecondConversion);
    sendSetpoints(TreadmillProperty::ACCELERATION, NormalSetpoint);
    accelTimer.start(retAccelValue);
    connect(&accelTimer, SIGNAL(timeout()), SLOT(startDecelTimer()));
}

void TreadmillAutomation::startDecelTimer()
{

    accelTimer.stop();
    double retDecelValue = getDecelerationTimeValue();
    const int millisecondConversion = 1000;

    const int packetSize = 32;
	int fullPackets = socket->bytesAvailable() / packetSize;
	if (!fullPackets) return;
	if (fullPackets > 1) socket->read((fullPackets - 1) * packetSize);
	const QByteArray data = socket->read(packetSize);
	qDebug("Deceleration Started...");
    qDebug("Data Received: %s.", qPrintable(data.toHex()));
	QDataStream ds(data);
    qDebug("Loading Datastream");
	quint8 format;
	qint16 speed[4];
	qint16 angle;
	ds >> format;
	if (format != 0) return;
	ds >> speed[0];
	ds >> speed[1];
	ds >> speed[2];
	ds >> speed[3];
	ds >> angle;

    qDebug("Datastream loaded");

    setRightFrontSpeedValueFromIncoming(speed[0]);
    setLeftFrontSpeedValueFromIncoming(speed[1]);
    setRightRearSpeedValueFromIncoming(speed[2]);
    setLeftRearSpeedValueFromIncoming(speed[3]);
    qDebug("Sending Setpoints...");
    sendSetpoints(TreadmillProperty::DECELERATION, NormalSetpoint);
    qDebug("Starting Timer...");
    qDebug("Deceleration will commence for %f seconds", retDecelValue/millisecondConversion);
    decelTimer.start(retDecelValue);
    connect(&decelTimer, SIGNAL(timeout()), SLOT(slotTimeout()));

}

void TreadmillAutomation::slotTimeout()
{
    std::cout << "Trial Ended" << std::endl;
    decelTimer.stop();
    const int packetSize = 32;

    int fullPackets = socket->bytesAvailable() / packetSize;
	if (!fullPackets) return;
	if (fullPackets > 1) socket->read((fullPackets - 1) * packetSize);
	const QByteArray data = socket->read(packetSize);
    QDataStream ds(data);
	quint8 format;
	qint16 speed[4];
	qint16 angle;
	ds >> format;
	if (format != 0) return;
	ds >> speed[0];
	ds >> speed[1];
	ds >> speed[2];
	ds >> speed[3];
    setRightFrontSpeedValueFromIncoming(speed[0]);
    setLeftFrontSpeedValueFromIncoming(speed[1]);
    setRightRearSpeedValueFromIncoming(speed[2]);
    setLeftRearSpeedValueFromIncoming(speed[3]);
    sendSetpoints(TreadmillProperty::DEFAULT, NormalSetpoint);


}


void TreadmillAutomation::onClickDisconnect()
{
    socket->close();
    connectBtn->setDisabled(false);
	disconnectBtn->setEnabled(false);
	useLibrary->setDisabled(false);
	tcpRadioButton->setDisabled(false);
	udpRadioButton->setDisabled(false);

    std::cout << "Client Disconnected" << std::endl;
}

void TreadmillAutomation::connected()
{
    if (udpRadioButton->isChecked()) 
    {
		// Register ourselves for feedback by sending a zero-acceleration setpoint to the
		// treadmill control panel. Such setpoint is otherwise ignored.
		sendSetpoints(TreadmillProperty::DEFAULT, FeedbackRegistrationSetpoint);
	}
	else if (useLibrary->isChecked()) 
    {
		socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
	}
	connectBtn->setDisabled(true);
	disconnectBtn->setEnabled(true);
	//ui.remoteControls->setEnabled(true);
	useLibrary->setDisabled(true);
	tcpRadioButton->setDisabled(true);
	udpRadioButton->setDisabled(true);
}

void TreadmillAutomation::disconnected()
{

}

void TreadmillAutomation::readyRead()
{

}

void TreadmillAutomation::error(QAbstractSocket::SocketError)
{

}

void TreadmillAutomation::sendSetpoints(TreadmillProperty mproperty, SetpointType mt)
{

/*	if (lftRghtTie->isChecked())
	{
		rightFrontSpeedSetpoint->setValue(leftFrontSpeedSetpoint->value());
		rightRearSpeedSetpoint->setValue(leftRearSpeedSetpoint->value());
	}*/
	std::cout << "setSetpoints activated" << std::endl;
	if (useLibrary->isChecked()) {
		sendSetpointsLibrary(mt);
	}
	else {
		sendSetpointsDirectly(mproperty, mt);
	}

}

void TreadmillAutomation::sendSetpointsDirectly(TreadmillProperty mproperty, SetpointType mt)
{
    QByteArray data;
	QDataStream ds(&data, QIODevice::WriteOnly);
	QByteArray filler(27, 0);
    qint16 speed[4];
    qint16 angle;
    qint16 accel;
    char ldata[64];
    switch(mproperty){
        case TreadmillProperty::DEFAULT:
            std::cout << "DEFAULT selected" << std::endl;
            std::cout << "Setting Treadmill Acceleration to 0" << std::endl;
            speed[0] = getRightFrontSpeedValue();
            speed[1] = getLeftFrontSpeedValue();
            speed[2] = getRightRearSpeedValue();
            speed[3] = getLeftRearSpeedValue();
            accel = 0;
            angle = 0;
            ds << (quint8)0; // format
					         // straight
            ds << speed[0];
            ds << speed[1];
            ds << speed[2];
            ds << speed[3];
            ds << accel;
            ds << accel;
            ds << accel;
            ds << accel;
            ds << angle;
            // 1s complement
            ds << (qint16)(speed[0] ^ 0xFFFF);
            ds << (qint16)(speed[1] ^ 0xFFFF);
            ds << (qint16)(speed[2] ^ 0xFFFF);
            ds << (qint16)(speed[3] ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(angle ^ 0xFFFF);
            ds.writeRawData(filler.data(), filler.size());
            memcpy(ldata, data.data(), 64);
            Q_ASSERT(data.size() == 64);
            socket->write(data);
            break;
        case TreadmillProperty::ACCELERATION:
            std::cout << "ACCELERATION selected" << std::endl;

            speed[0] = getRightFrontSpeedValue();
            speed[1] = getLeftFrontSpeedValue();
            speed[2] = getRightRearSpeedValue();
            speed[3] = getLeftRearSpeedValue();
            accel = (mt == NormalSetpoint) ? getAccelerationValue() * 1000.0 : 0.0;
            angle = 0;
            ds << (quint8)0; // format
					         // straight
            ds << speed[0];
            ds << speed[1];
            ds << speed[2];
            ds << speed[3];
            ds << accel;
            ds << accel;
            ds << accel;
            ds << accel;
            ds << angle;
            // 1s complement
            ds << (qint16)(speed[0] ^ 0xFFFF);
            ds << (qint16)(speed[1] ^ 0xFFFF);
            ds << (qint16)(speed[2] ^ 0xFFFF);
            ds << (qint16)(speed[3] ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(angle ^ 0xFFFF);
            ds.writeRawData(filler.data(), filler.size());

            memcpy(ldata, data.data(), 64);
            Q_ASSERT(data.size() == 64);
            socket->write(data);
            break;
        case TreadmillProperty::DECELERATION:
            std::cout << "DECEL selected" << std::endl;
            speed[0] = getRightFrontSpeedValue();
            speed[1] = getLeftFrontSpeedValue();
            speed[2] = getRightRearSpeedValue();
            speed[3] = getLeftRearSpeedValue();
            accel = (mt == NormalSetpoint) ? getDecelerationValue() * 1000.0 : 0.0;
            angle = 0;
            ds << (quint8)0; // format
					         // straight
            ds << speed[0];
            ds << speed[1];
            ds << speed[2];
            ds << speed[3];
            ds << accel;
            ds << accel;
            ds << accel;
            ds << accel;
            ds << angle;
            // 1s complement
            ds << (qint16)(speed[0] ^ 0xFFFF);
            ds << (qint16)(speed[1] ^ 0xFFFF);
            ds << (qint16)(speed[2] ^ 0xFFFF);
            ds << (qint16)(speed[3] ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(accel ^ 0xFFFF);
            ds << (qint16)(angle ^ 0xFFFF);
            ds.writeRawData(filler.data(), filler.size());
            memcpy(ldata, data.data(), 64);
            Q_ASSERT(data.size() == 64);
            socket->write(data);
            break;

            break;
        case TreadmillProperty::SPEED:
            std::cout << "SPEED selected " << std::endl;
            break;
        case TreadmillProperty::INCLINATION:
            std::cout << "INCLIN selected" << std::endl;
            break;
        default:
                std::cout << "None Selected" << std::endl;
                break;

    }


}

void TreadmillAutomation::sendSetpointsLibrary(SetpointType mt)
{

}

void TreadmillAutomation::error(int mn)
{
	showWarning(this, "Network Error", QString("Error %1").arg(mn));
	disconnected();
}

static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext)
{
	Q_ASSERT(mparent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, mtitle, mtext, QMessageBox::Ok, mparent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}



#include "../include/moc_TreadmillAutomation.cpp"
