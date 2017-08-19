#include "include/NetworkTabWidget.h"


NetworkTabWidget* NetworkTabWidget::_networkTabWidget = 0;


NetworkTabWidget::NetworkTabWidget(QWidget* parent, Qt::WindowFlags flags) 
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
  
    sendSetpoints = SendSetpoints::getInstance();

    
    createNetworkTabWidget();
    populateNetworkTab();
        
}

NetworkTabWidget::~NetworkTabWidget()
{

}

NetworkTabWidget* NetworkTabWidget::getInstance()
{
    if(_networkTabWidget == NULL)
    {
        _networkTabWidget = new NetworkTabWidget();
    }

    return _networkTabWidget;
}

void NetworkTabWidget::createNetworkTabWidget()
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    networkTabLayout = new QVBoxLayout;
    setObjectName("NetworkTab");
    setLayout(networkTabLayout);
}

void NetworkTabWidget::populateNetworkTab()
{
    const QString hostIpAddress = "127.0.0.1";
    const QString portNumber = "4000";
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
    hostTextBox->appendPlainText(hostIpAddress);
    
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
    portTextBox->appendPlainText(portNumber);


    networkGroupBox = new QGroupBox;
    networkGroupBoxFont.setFamily("Times");
    networkGroupBoxFont.setWeight(80);
    networkGroupBoxFont.setPointSize(12);
    networkGroupBoxFont.setBold(true);
    networkGroupBox->setFont(networkGroupBoxFont);
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
    tcpRadioButton->setChecked(true);
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
    connect(disconnectBtn, SIGNAL(clicked()), this, SLOT(onClickDisconnect()));
}

void NetworkTabWidget::setAccelerationValue(double maccelerationValue)
{
    accelerationValue = maccelerationValue;
}

double NetworkTabWidget::getAccelerationValue()
{
    return accelerationValue;
}

void NetworkTabWidget::setDecelerationValue(double mdecelerationValue)
{
    decelerationValue = mdecelerationValue;
}

double NetworkTabWidget::getDecelerationValue()
{
    return decelerationValue;
}

void NetworkTabWidget::setLeftFrontSpeedValue(double mleftFrontSpeedValue)
{
    leftFrontSpeedValue = mleftFrontSpeedValue;
}

double NetworkTabWidget::getLeftFrontSpeedValue()
{
    return leftFrontSpeedValue;
}

void NetworkTabWidget::setRightFrontSpeedValue(double mrightFrontSpeedValue)
{
    rightFrontSpeedValue = mrightFrontSpeedValue;
}

double NetworkTabWidget::getRightFrontSpeedValue()
{
    return rightFrontSpeedValue;
}

void NetworkTabWidget::paintEvent(QPaintEvent* paintEvent)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
}

QAbstractSocket* NetworkTabWidget::getSocketInstance()
{
    return socket;

}

void NetworkTabWidget::onClickConnect()
{
    ok = 0;
    base = 10;
    
    sendSetpoints->setUseLibraryStatus(useLibrary->isChecked());

    if (!useLibrary->isChecked()) 
    {
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
		qDebug("New connection made on port %d.", port.toUInt(ok, base));
        setHost(hostTextBox->toPlainText());
        setPort(port);
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

void NetworkTabWidget::connected()
{
    if (udpRadioButton->isChecked()) 
    {
        // Register ourselves for feedback by sending a zero-acceleration setpoint to the
        // treadmill control panel. Such setpoint is otherwise ignored.
        //sendSetpoints->sendSetpoints(sendSetpoints->TreadmillProperty::DEFAULT, \
                sendSetpoints->FeedbackRegistrationSetpoint);
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

bool NetworkTabWidget::getUseLibraryIsCheckedStatus()
{
    return useLibrary->isChecked();
}



void NetworkTabWidget::onClickDisconnect()
{
    socket->close();
    connectBtn->setDisabled(false);
	disconnectBtn->setEnabled(false);
	useLibrary->setDisabled(false);
	tcpRadioButton->setDisabled(false);
	udpRadioButton->setDisabled(false);

    std::cout << "Client Disconnected" << std::endl;
}

void NetworkTabWidget::disconnected()
{

}


void NetworkTabWidget::error(int mn)
{
	showWarning(this, "Network Error", QString("Error %1").arg(mn));
	disconnected();
}

void NetworkTabWidget::readyRead()
{

}

void NetworkTabWidget::error(QAbstractSocket::SocketError)
{

}

void NetworkTabWidget::setHost(QString mhost)
{
    hostText = mhost;
}

void NetworkTabWidget::setPort(QString mport)
{
    portText = mport;
}

QString NetworkTabWidget::getHost()
{
    return hostText;
}

QString NetworkTabWidget::getPort()
{
    return portText;
}

static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext)
{
	Q_ASSERT(mparent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, mtitle, mtext, QMessageBox::Ok, mparent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}



#include "../include/moc_NetworkTabWidget.cpp"
