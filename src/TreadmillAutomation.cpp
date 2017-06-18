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

    quadrantOnePerturbationLayout->addWidget(accelDecelGroupBox);
    perturbationTabLayout->addWidget(quadrantOneGroupBox);

    accelerationLabel = new QLabel;
    accelerationLabelFont.setFamily("Times");
    accelerationLabelFont.setWeight(75);
    accelerationLabelFont.setPointSize(12);
    accelerationLabel->setFont(accelerationLabelFont);
    accelerationLabel->setText("Acceleration: ");
    accelerationLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    accelerationLabel->setFixedSize(90,180);
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
    accelerationDecelerationHorizontalLayout->addWidget(acceleration);

    quadrantTwoGroupBox = new QGroupBox;
    perturbationTabLayout->addWidget(quadrantTwoGroupBox);






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



void TreadmillAutomation::onClickDisconnect()
{

}

void TreadmillAutomation::connected()
{
    if (udpRadioButton->isChecked()) 
    {
		// Register ourselves for feedback by sending a zero-acceleration setpoint to the
		// treadmill control panel. Such setpoint is otherwise ignored.
		sendSetpoints(FeedbackRegistrationSetpoint);
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

void TreadmillAutomation::sendSetpoints(SetpointType t)
{
	if (lftRghtTie->isChecked())
	{
		rightFrontSpeedSetpoint->setValue(leftFrontSpeedSetpoint->value());
		rightRearSpeedSetpoint->setValue(leftRearSpeedSetpoint->value());
	}
	std::cout << "setSetpoints activated" << std::endl;
	if (useLibrary->isChecked()) {
		sendSetpointsLibrary(t);
	}
	else {
		sendSetpointsDirectly(t);
	}

}

void TreadmillAutomation::sendSetpointsDirectly(SetpointType)
{

}

void TreadmillAutomation::sendSetpointsLibrary(SetpointType)
{

}

void TreadmillAutomation::error(int n)
{
	showWarning(this, "Network Error", QString("Error %1").arg(n));
	disconnected();
}

static void showWarning(QWidget * parent, const QString & title, const QString & text)
{
	Q_ASSERT(parent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::Ok, parent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}



#include "../include/moc_TreadmillAutomation.cpp"
