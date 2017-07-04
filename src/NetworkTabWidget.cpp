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

void NetworkTabWidget::connected()
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

bool NetworkTabWidget::getUseLibraryIsCheckedStatus()
{
    return useLibrary->isChecked();
}

void NetworkTabWidget::sendSetpoints(TreadmillProperty mproperty, SetpointType mt)
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

void NetworkTabWidget::sendSetpointsDirectly(TreadmillProperty mproperty, SetpointType mt)
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
            speed[2] = 0;
            speed[3] = 0;
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
            speed[2] = 0; 
            speed[3] = 0;
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
            speed[2] = 0; 
            speed[3] = 0;
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



void NetworkTabWidget::sendSetpointsLibrary(SetpointType mt)
{

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



static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext)
{
	Q_ASSERT(mparent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, mtitle, mtext, QMessageBox::Ok, mparent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}





#include "../include/moc_NetworkTabWidget.cpp"
