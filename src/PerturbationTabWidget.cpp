#include "PerturbationTabWidget.h"

PerturbationTabWidget* PerturbationTabWidget::_perturbationTabWidget = 0;


PerturbationTabWidget::PerturbationTabWidget(QWidget* parent, Qt::WindowFlags flags)
{
    createTreadmillPerturbationTab();
    populateTreadmillPerturbationTab();
}

PerturbationTabWidget::~PerturbationTabWidget()
{

}

PerturbationTabWidget* PerturbationTabWidget::getInstance()
{
    if(_perturbationTabWidget == NULL)
    {
        _perturbationTabWidget = new PerturbationTabWidget();
    }

    return _perturbationTabWidget;
}


void PerturbationTabWidget::createTreadmillPerturbationTab()
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    perturbationTabLayout = new QGridLayout;
    setObjectName("PerturbationTab");
    setLayout(perturbationTabLayout);
}

void PerturbationTabWidget::populateTreadmillPerturbationTab()
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

    timerCheckBoxGroupBox = new QGroupBox;
    timerCheckBoxGroupBoxLayout = new QHBoxLayout;
    timerCheckBoxGroupBox->setLayout(timerCheckBoxGroupBoxLayout);
    timerCheckBox = new QCheckBox;
    timerCheckBoxGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timerCheckBoxGroupBox->setFixedSize(160,90);
    timerCheckBoxLabel = new QLabel;
    timerCheckBoxLabelFont.setFamily("Times");
    timerCheckBoxLabelFont.setWeight(75);
    timerCheckBoxLabelFont.setPointSize(12);
    timerCheckBoxLabel->setFont(timerCheckBoxLabelFont);
    timerCheckBoxLabel->setText("Use Timer:");
    timerCheckBoxGroupBoxLayout->addWidget(timerCheckBoxLabel);
    timerCheckBoxGroupBoxLayout->addWidget(timerCheckBox);

    quadrantOnePerturbationLayout->addWidget(timerCheckBoxGroupBox);
    quadrantOnePerturbationLayout->addWidget(timeGroupBox);
    timeGroupBox->hide();

    connect(timerCheckBox, SIGNAL(stateChanged(int)), SLOT(addTimer(int)));

    startPertRunGroupBox = new QGroupBox;
    startPertRunGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunGroupBoxLayout = new QHBoxLayout;
    startPertRunGroupBox->setLayout(startPertRunGroupBoxLayout);
    startPertRun = new QPushButton;
    startPertRun->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRun->setFixedSize(200,40);
    startPertRun->setText("Start Timer");    
    startPertRunGroupBoxLayout->addWidget(startPertRun);
    quadrantOnePerturbationLayout->addWidget(startPertRunGroupBox);
    startPertRun->hide();

    connect(startPertRun, SIGNAL(clicked()), SLOT(startAccelTimer()));

    quadrantTwoGroupBox = new QGroupBox;
    perturbationTabLayout->addWidget(quadrantTwoGroupBox, 0,1);

}

void PerturbationTabWidget::addTimer(int state)
{
    if(state)
    {
        timeGroupBox->show();
        startPertRun->show();
    }
    else
    {
        timeGroupBox->hide();
        startPertRun->hide();
    }
    
        

}

void PerturbationTabWidget::setAccelerationTimeValue(double maccelTimeValue)
{

    accelerationTimeValue = maccelTimeValue;

    std::cout << "Acceleration Time Set to: " << accelerationTimeValue << std::endl;
}

void PerturbationTabWidget::setDecelerationTimeValue(double mdecelTimeValue)
{
    decelerationTimeValue = mdecelTimeValue;

    std::cout << "Deceleration Time Set to: " << decelerationTimeValue << std::endl;
}

void PerturbationTabWidget::setAccelerationValue(double maccelValue)
{
    accelerationValue = maccelValue;
    std::cout << "Acceleration Value Set to: " << accelerationValue << std::endl;
}

void PerturbationTabWidget::setDecelerationValue(double mdecelValue)
{
    decelerationValue = mdecelValue;
    std::cout << "Deceleration Set to: " << decelerationValue << std::endl;
}

void PerturbationTabWidget::setLeftFrontSpeedValue(double mleftFrontSpeedValue)
{

    leftSpeedFrontValue = mleftFrontSpeedValue;
    std::cout << "Left Front Speed Set to: " << leftSpeedFrontValue << std::endl;
}

void PerturbationTabWidget::setLeftFrontSpeedValueFromIncoming(qint16 mleftFrontSpeedValue)
{
    leftSpeedFrontValue = static_cast<double>(mleftFrontSpeedValue);
}

void PerturbationTabWidget::setRightFrontSpeedValue(double mrightFrontSpeedValue)
{
    rightSpeedFrontValue = mrightFrontSpeedValue;  
    std::cout << "Right Front Speed Set to: " << rightSpeedFrontValue << std::endl;

}

void PerturbationTabWidget::setRightFrontSpeedValueFromIncoming(qint16 mrightFrontSpeedValue)
{
  rightSpeedFrontValue = static_cast<double>(mrightFrontSpeedValue); 
}

double PerturbationTabWidget::getAccelerationTimeValue()
{
    return accelerationTimeValue;
}

double PerturbationTabWidget::getDecelerationTimeValue()
{
    return decelerationTimeValue;
}

double PerturbationTabWidget::getAccelerationValue()
{
    return accelerationValue;
}
double PerturbationTabWidget::getDecelerationValue()
{
    return decelerationValue;
}
double PerturbationTabWidget::getLeftFrontSpeedValue()
{
    return leftSpeedFrontValue;
}
double PerturbationTabWidget::getRightFrontSpeedValue()
{
    return rightSpeedFrontValue;
}

void PerturbationTabWidget::setUseLibraryStatus(bool useLibCheckBox)
{
    useLibraryCheckBoxStatus = useLibCheckBox;
}

void PerturbationTabWidget::sendSetpoints(TreadmillProperty mproperty, SetpointType mt)
{

/*	if (lftRghtTie->isChecked())
	{
		rightFrontSpeedSetpoint->setValue(leftFrontSpeedSetpoint->value());
		rightRearSpeedSetpoint->setValue(leftRearSpeedSetpoint->value());
	}*/
	std::cout << "setSetpoints activated" << std::endl;
	if (useLibraryCheckBoxStatus) 
    {
		sendSetpointsLibrary(mt);
	}
	else {
		sendSetpointsDirectly(mproperty, mt);
	}

}

void PerturbationTabWidget::sendSetpointsDirectly(TreadmillProperty mproperty, SetpointType mt)
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
            break;
        case TreadmillProperty::ACCEL:
            std::cout << "ACCEL selected" << std::endl;

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
            pertSocket->write(data);
            break;
        case TreadmillProperty::DECEL:
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
            pertSocket->write(data);
            break;

            break;
        case TreadmillProperty::SPEED:
            std::cout << "SPEED selected " << std::endl;
            break;
        case TreadmillProperty::INCLIN:
            std::cout << "INCLIN selected" << std::endl;
            break;
        default:
                std::cout << "None Selected" << std::endl;
                break;

    }


}

void PerturbationTabWidget::sendSetpointsLibrary(SetpointType mt)
{

}


void PerturbationTabWidget::startAccelTimer()
{
    double retAccelValue = getAccelerationTimeValue();
    const int millisecondConversion = 1000;
    qDebug("Acceleration will commence for %f seconds", retAccelValue/millisecondConversion);
    sendSetpoints(TreadmillProperty::ACCEL, NormalSetpoint);
    accelTimer.start(retAccelValue);
    connect(&accelTimer, SIGNAL(timeout()), SLOT(startDecelTimer()));
}

void PerturbationTabWidget::startDecelTimer()
{

    accelTimer.stop();
    double retDecelValue = getDecelerationTimeValue();
    const int packetSize = 32;
	int fullPackets = pertSocket->bytesAvailable() / packetSize;
	if (!fullPackets) return;
	if (fullPackets > 1) pertSocket->read((fullPackets - 1) * packetSize);
	const QByteArray data = pertSocket->read(packetSize);
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
    qDebug("Sending Setpoints...");
    sendSetpoints(TreadmillProperty::DECEL, NormalSetpoint);
    qDebug("Starting Timer...");
    qDebug("Deceleration will commence for %f", retDecelValue);
    decelTimer.start(retDecelValue);
    connect(&decelTimer, SIGNAL(timeout()), SLOT(slotTimeout()));

}

void PerturbationTabWidget::slotTimeout()
{
    std::cout << "Trial Ended" << std::endl;
    decelTimer.stop();
}



void PerturbationTabWidget::setSocket(QAbstractSocket* socket)
{
    pertSocket = socket;
}

#include "../include/moc_PerturbationTabWidget.cpp"
