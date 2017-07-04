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
    addQuadrantOne();
    addQuadrantTwo();
    addQuadrantThree();
    addQuadrantFour();
}

void PerturbationTabWidget::addQuadrantOne()
{
    quadrantOneGroupBox = new QGroupBox;
    quadrantOnePerturbationLayout = new QVBoxLayout;
    quadrantOneGroupBox->setLayout(quadrantOnePerturbationLayout);
    perturbationTabLayout->addWidget(quadrantOneGroupBox, 0,0);
    addSpeedGroupBox();
    addAccelDecelGroupBox();
    addTimerGroupBox();
    addStartPertRunGroupBox();
}

void PerturbationTabWidget::addQuadrantTwo()
{
    quadrantTwoGroupBox = new QGroupBox;
    perturbationTabLayout->addWidget(quadrantTwoGroupBox, 0,1);
}

void PerturbationTabWidget::addQuadrantThree()
{
    quadrantThreeGroupBox = new QGroupBox;
    perturbationTabLayout->addWidget(quadrantThreeGroupBox, 1,0);

}

void PerturbationTabWidget::addQuadrantFour()
{
    quadrantFourGroupBox = new QGroupBox;
    perturbationTabLayout->addWidget(quadrantFourGroupBox, 1,1);

}


void PerturbationTabWidget::addSpeedGroupBox()
{
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
}

void PerturbationTabWidget::addTimerGroupBox()
{
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


}


void PerturbationTabWidget::addAccelDecelGroupBox()
{
    accelDecelGroupBox = new QGroupBox;
    accelDecelGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    accelerationDecelerationHorizontalLayout = new QHBoxLayout;
    accelDecelGroupBox->setLayout(accelerationDecelerationHorizontalLayout);
    
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

    quadrantOnePerturbationLayout->addWidget(accelDecelGroupBox);
}

void PerturbationTabWidget::addStartPertRunGroupBox()
{
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
    QByteArray accelData;
    QByteArray decelData;
    QDataStream accelDataStream(&accelData, QIODevice::WriteOnly);
    QDataStream decelDataStream(&decelData, QIODevice::WriteOnly);
    QByteArray accelFiller(27, 0);
    QByteArray decelFiller(27, 0);
    qint16 accelSpeed[4];
    qint16 decelSpeed[4];
    qint16 accelAngle;
    qint16 decelAngle;
    qint16 accelAccel;
    qint16 decelAccel;
    char accelLdata[64];
    char decelLdata[64];

        switch(mproperty){
        case TreadmillProperty::DEFAULT:
            std::cout << "DEFAULT selected" << std::endl;
            break;
        case TreadmillProperty::ACCEL:
                        
            std::cout << "ACCEL selected" << std::endl;

            accelSpeed[0] = getRightFrontSpeedValue();
            accelSpeed[1] = getLeftFrontSpeedValue();
            accelSpeed[2] = 0;
            accelSpeed[3] = 0;
            accelAccel = (mt == NormalSetpoint) ? getAccelerationValue() * 1000.0 : 0.0;
            accelAngle = 0;
            accelDataStream << (quint8)0; // format
					         // straight
            accelDataStream << accelSpeed[0];
            accelDataStream << accelSpeed[1];
            accelDataStream << accelSpeed[2];
            accelDataStream << accelSpeed[3];
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAngle;
            // 1s complement
            accelDataStream << (qint16)(accelSpeed[0] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[1] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[2] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[3] ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAngle ^ 0xFFFF);
            accelDataStream.writeRawData(accelFiller.data(), accelFiller.size());
            qDebug("Sending Acceleration: %s", qPrintable(accelData.toHex()));
            memcpy(accelLdata, accelData.data(), 64);
            Q_ASSERT(accelData.size() == 64);
            pertSocket->write(accelData);
            break;
        case TreadmillProperty::DECEL:
            std::cout << "DECEL selected" << std::endl;
            decelSpeed[0] = getRightFrontSpeedValue();
            decelSpeed[1] = getLeftFrontSpeedValue();
            decelSpeed[2] = 0;
            decelSpeed[3] = 0;
            decelAccel = (mt == NormalSetpoint) ? getDecelerationValue() * 1000.0 : 0.0;
            decelAngle = 0;
            decelDataStream << (quint8)0; // format
					         // straight
            decelDataStream << decelSpeed[0];
            decelDataStream << decelSpeed[1];
            decelDataStream << decelSpeed[2];
            decelDataStream << decelSpeed[3];
            decelDataStream << decelAccel;
            decelDataStream << decelAccel;
            decelDataStream << decelAccel;
            decelDataStream << decelAccel;
            decelDataStream << decelAngle;
            // 1s complement
            decelDataStream << (qint16)(decelSpeed[0] ^ 0xFFFF);
            decelDataStream << (qint16)(decelSpeed[1] ^ 0xFFFF);
            decelDataStream << (qint16)(decelSpeed[2] ^ 0xFFFF);
            decelDataStream << (qint16)(decelSpeed[3] ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAngle ^ 0xFFFF);
            decelDataStream.writeRawData(decelFiller.data(), decelFiller.size());
            qDebug("Sending Deceleration: %s", qPrintable(decelData.toHex()));
            memcpy(decelLdata, decelData.data(), 64);
            Q_ASSERT(decelData.size() == 64);
            pertSocket->write(decelData);
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
    qDebug("Incoming Right Speed: %i", speed[0]);
    qDebug("Incoming Left Speed: %i", speed[1]);
    setRightFrontSpeedValueFromIncoming(speed[0]);
    setLeftFrontSpeedValueFromIncoming(speed[1]);
    qDebug("Sending Setpoints...");
    sendSetpoints(TreadmillProperty::DECEL, NormalSetpoint);
    qDebug("Starting Timer...");
    qDebug("Deceleration will commence for %f seconds", retDecelValue/millisecondConversion);
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
