#include "include/PerturbationTabWidget.h"

PerturbationTabWidget* PerturbationTabWidget::_perturbationTabWidget = 0;


PerturbationTabWidget::PerturbationTabWidget(QWidget* parent, Qt::WindowFlags flags)
{
    sendSetpoints = SendSetpoints::getInstance();
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
    addMaxSpeedGroupBox();
    addSpeedGroupBox();
    addAccelDecelGroupBox();
    addTimerGroupBox();
    addStartPertRunGroupBox();
    addStartMaxSpeedRunGroupBox();
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

void PerturbationTabWidget::addMaxSpeedGroupBox()
{
    maxSpeedGroupBox = new QGroupBox;
    maxSpeedGroupBoxLayout = new QHBoxLayout;
    maxSpeedGroupBox->setLayout(maxSpeedGroupBoxLayout);
    maxSpeedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    
    maxLeftSpeedLabel = new QLabel;
    maxLeftSpeedLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    maxLeftSpeedLabel->setText("Maximum Left Speed: ");
    maxLeftSpeedLabel->setFixedSize(180,180);
    maxLeftSpeedLabelFont.setFamily("Times");
    maxLeftSpeedLabelFont.setWeight(75);
    maxLeftSpeedLabelFont.setPointSize(12);
    maxLeftSpeedLabel->setFont(maxLeftSpeedLabelFont);
    maxSpeedGroupBoxLayout->addWidget(maxLeftSpeedLabel);
    maxLeftSpeedSpinBox = new QDoubleSpinBox;
    maxLeftSpeedSpinBox->setSuffix("  m/s");
    maxLeftSpeedSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    maxLeftSpeedSpinBox->setFixedSize(160,40);

    maxLeftSpeedSpinBoxFont.setFamily("Times");
    maxLeftSpeedSpinBoxFont.setWeight(75);
    maxLeftSpeedSpinBoxFont.setPointSize(12);
    maxLeftSpeedSpinBox->setFont(maxLeftSpeedSpinBoxFont);
    //connect(maxLeftSpeedSpinBox, SIGNAL(valueChanged(double)), SLOT(setMaxLeftSpeed(double)));
    maxSpeedGroupBoxLayout->addWidget(maxLeftSpeedSpinBox);
    maxRightSpeedLabel = new QLabel;
    maxRightSpeedLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    maxRightSpeedLabel->setFixedSize(180,180);
    maxRightSpeedLabel->setText("Maximum Right Speed: ");
    maxRightSpeedLabelFont.setFamily("Times");
    maxRightSpeedLabelFont.setWeight(75);
    maxRightSpeedLabelFont.setPointSize(12);
    maxRightSpeedLabel->setFont(maxRightSpeedLabelFont);
    maxSpeedGroupBoxLayout->addWidget(maxRightSpeedLabel);
    maxRightSpeedSpinBox = new QDoubleSpinBox;
    maxRightSpeedSpinBox->setSuffix("  m/s");
    maxRightSpeedSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    maxRightSpeedSpinBox->setFixedSize(160,40);
    maxRightSpeedSpinBoxFont.setFamily("Times");
    maxRightSpeedSpinBoxFont.setWeight(75);
    maxRightSpeedSpinBoxFont.setPointSize(12);
    maxRightSpeedSpinBox->setFont(maxRightSpeedSpinBoxFont);
    //connect(maxRightSpeedSpinBox, SIGNAL(valueChanged(double)), SLOT(setMaxRightSpeed(double)));
    maxSpeedGroupBoxLayout->addWidget(maxRightSpeedSpinBox);


    quadrantOnePerturbationLayout->addWidget(maxSpeedGroupBox);
    maxSpeedGroupBox->hide();

}

void PerturbationTabWidget::setMaxLeftSpeed(double mMaxLeftSpeed)
{
    maxLeftSpeed = mMaxLeftSpeed;
    sendSetpoints->setMaxLeftSpeed(maxLeftSpeed);
}

double PerturbationTabWidget::getMaxLeftSpeed()
{
   return maxLeftSpeed; 
}

void PerturbationTabWidget::setMaxRightSpeed(double mMaxRightSpeed)
{
    maxRightSpeed = mMaxRightSpeed;
    sendSetpoints->setMaxRightSpeed(maxRightSpeed);
}

double PerturbationTabWidget::getMaxRightSpeed()
{
    return maxRightSpeed;
}

void PerturbationTabWidget::showMaxSpeedBox(bool state)
{
    if(state)
    {
        maxSpeedGroupBox->show();
        startMaxSpeedRunGroupBox->show();
    }
    else
    {
        maxSpeedGroupBox->hide();
        startMaxSpeedRunGroupBox->hide();
    }

}


void PerturbationTabWidget::addSpeedGroupBox()
{
    speedGroupBox = new QGroupBox;
    speedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedGroupBoxHorizontalLayout = new QHBoxLayout;
    speedGroupBox->setLayout(speedGroupBoxHorizontalLayout);
    

    speedLeftFrontLabel = new QLabel;
    speedLeftFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedLeftFrontLabel->setText("Left Starting Speed: ");
    speedLeftFrontLabel->setFixedSize(180,180);
    speedLeftFrontLabelFont.setFamily("Times");
    speedLeftFrontLabelFont.setWeight(75);
    speedLeftFrontLabelFont.setPointSize(12);
    speedLeftFrontLabel->setFont(speedLeftFrontLabelFont);
    speedGroupBoxHorizontalLayout->addWidget(speedLeftFrontLabel);
    leftFrontSpeedSetpoint = new QDoubleSpinBox;
    leftFrontSpeedSetpointFont.setFamily("Times");
    leftFrontSpeedSetpointFont.setWeight(75);
    leftFrontSpeedSetpointFont.setPointSize(12);
    leftFrontSpeedSetpoint->setFont(leftFrontSpeedSetpointFont);
    leftFrontSpeedSetpoint->setSuffix("  m/s");
    leftFrontSpeedSetpoint->setFixedSize(160,40);
    speedGroupBoxHorizontalLayout->addWidget(leftFrontSpeedSetpoint);

    speedRightFrontLabel = new QLabel;
    speedRightFrontLabel->setText("Right Starting Speed: ");
    speedRightFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedRightFrontLabel->setFixedSize(180,180);
    speedRightFrontLabelFont.setFamily("Times");
    speedRightFrontLabelFont.setWeight(75);
    speedRightFrontLabelFont.setPointSize(12);
    speedRightFrontLabel->setFont(speedRightFrontLabelFont);
    speedGroupBoxHorizontalLayout->addWidget(speedRightFrontLabel);
    rightFrontSpeedSetpoint = new QDoubleSpinBox;
    rightFrontSpeedSetpointFont.setFamily("Times");
    rightFrontSpeedSetpointFont.setWeight(75);
    rightFrontSpeedSetpointFont.setPointSize(12);
    rightFrontSpeedSetpoint->setFont(rightFrontSpeedSetpointFont);
    rightFrontSpeedSetpoint->setSuffix("  m/s");
    rightFrontSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightFrontSpeedSetpoint->setFixedSize(160,40);
    speedGroupBoxHorizontalLayout->addWidget(rightFrontSpeedSetpoint);

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
    //connect(timeAccelSpinBox, SIGNAL(valueChanged(double)), SLOT(setAccelerationTimeValue(double)));
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
    //connect(timeDecelSpinBox, SIGNAL(valueChanged(double)), SLOT(setDecelerationTimeValue(double)));

    quadrantOnePerturbationLayout->addWidget(timeGroupBox);
    timeGroupBox->hide();

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
    
    accelerationDecelerationHorizontalLayout->addWidget(deceleration);

    quadrantOnePerturbationLayout->addWidget(accelDecelGroupBox);
}

void PerturbationTabWidget::addStartMaxSpeedRunGroupBox()
{
    startMaxSpeedRunGroupBox = new QGroupBox;
    startMaxSpeedRunGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startMaxSpeedRunGroupBoxLayout = new QHBoxLayout;
    startMaxSpeedRunGroupBox->setLayout(startMaxSpeedRunGroupBoxLayout);
    startMaxSpeedRunBtn = new QPushButton;
    startMaxSpeedRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startMaxSpeedRunBtn->setFixedSize(200,40);
    startMaxSpeedRunBtn->setText("Start Max Speed Run");
    startMaxSpeedRunBtnFont.setFamily("Times");
    startMaxSpeedRunBtnFont.setWeight(75);
    startMaxSpeedRunBtnFont.setPointSize(12);
    startMaxSpeedRunBtn->setFont(startMaxSpeedRunBtnFont);
    startMaxSpeedRunGroupBoxLayout->addWidget(startMaxSpeedRunBtn);
    quadrantOnePerturbationLayout->addWidget(startMaxSpeedRunGroupBox);
    startMaxSpeedRunGroupBox->hide();

    connect(startMaxSpeedRunBtn, SIGNAL(clicked()), SLOT(startMaxSpeedRun()));

}

void PerturbationTabWidget::startMaxSpeedRun()
{
    setMaxLeftSpeed(maxLeftSpeedSpinBox->value());
    setMaxRightSpeed(maxRightSpeedSpinBox->value());
    setAccelerationValue(acceleration->value());
    setDecelerationValue(deceleration->value());
    setLeftFrontSpeedValue(leftFrontSpeedSetpoint->value());
    setRightFrontSpeedValue(rightFrontSpeedSetpoint->value());
    maxRunTime = getMaxLeftSpeed() / getAccelerationValue();
    qDebug("Acceleration will commence for %f seconds", maxRunTime);
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::ACCEL, SendSetpoints::NormalSetpoint);
    QTimer::singleShot(maxRunTime * millisecondConversion, this, SLOT(startMaxSpeedDecel()));
}

void PerturbationTabWidget::startMaxSpeedDecel()
{
    std::cout << "Acceleration Run has ended" << std::endl;
    maxDecelRunTime = getMaxLeftSpeed() / abs(getDecelerationValue());
    setRightFrontSpeedValue(abs(getDecelerationValue()) * (maxDecelRunTime) + \
            getRightFrontSpeedValue());
    setLeftFrontSpeedValue(abs(getDecelerationValue()) * (maxDecelRunTime) + \
            getLeftFrontSpeedValue());
    qDebug("Deceleration will commence for %f seconds", maxDecelRunTime);
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::DECEL, SendSetpoints::NormalSetpoint);
    QTimer::singleShot(maxDecelRunTime * millisecondConversion, this, SLOT(maxSpeedTimeout()));

}

void PerturbationTabWidget::maxSpeedTimeout()
{
    sendSetpoints->sendSetpoints(SendSetpoints::ZERO, SendSetpoints::NormalSetpoint);
    std::cout << "Deceleration Run has ended" << std::endl;
}




void PerturbationTabWidget::addStartPertRunGroupBox()
{
    startPertRunGroupBox = new QGroupBox;
    startPertRunGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunGroupBoxLayout = new QHBoxLayout;
    startPertRunGroupBox->setLayout(startPertRunGroupBoxLayout);
    startPertRunBtn = new QPushButton;
    startPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunBtn->setFixedSize(200,40);
    startPertRunBtn->setText("Start Timer");    
    startPertRunGroupBoxLayout->addWidget(startPertRunBtn);
    startPertRunBtnFont.setFamily("Times");
    startPertRunBtnFont.setWeight(75);
    startPertRunBtnFont.setPointSize(12);
    startPertRunBtn->setFont(startPertRunBtnFont);
    quadrantOnePerturbationLayout->addWidget(startPertRunGroupBox);
    startPertRunGroupBox->hide();

    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(startAccelTimer()));
}


void PerturbationTabWidget::showTimer(bool state)
{
    if(state)
    {
        timeGroupBox->show();
        startPertRunGroupBox->show();
    }
    else
    {
        timeGroupBox->hide();
        startPertRunGroupBox->hide();
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
    sendSetpoints->setAccelerationValue(accelerationValue);
    std::cout << "Acceleration Value Set to: " << accelerationValue << std::endl;
}

void PerturbationTabWidget::setDecelerationValue(double mdecelValue)
{
    decelerationValue = mdecelValue;
    sendSetpoints->setDecelerationValue(decelerationValue);
    std::cout << "Deceleration Set to: " << decelerationValue << std::endl;
}

void PerturbationTabWidget::setLeftFrontSpeedValue(double mleftFrontSpeedValue)
{

    leftSpeedFrontValue = mleftFrontSpeedValue;
    sendSetpoints->setLeftFrontSpeedValue(leftSpeedFrontValue);
    std::cout << "Left Front Speed Set to: " << leftSpeedFrontValue << std::endl;
}

void PerturbationTabWidget::setLeftFrontSpeedValueFromIncoming(qint16 mleftFrontSpeedValue)
{
    leftSpeedFrontValue = static_cast<double>(mleftFrontSpeedValue);
}

void PerturbationTabWidget::setRightFrontSpeedValue(double mrightFrontSpeedValue)
{
    rightSpeedFrontValue = mrightFrontSpeedValue;  
    sendSetpoints->setRightFrontSpeedValue(rightSpeedFrontValue);
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

void PerturbationTabWidget::startAccelTimer()
{

    setAccelerationValue(acceleration->value());
    setDecelerationValue(deceleration->value());
    setLeftFrontSpeedValue(leftFrontSpeedSetpoint->value());
    setRightFrontSpeedValue(rightFrontSpeedSetpoint->value());
    setAccelerationTimeValue(timeAccelSpinBox->value());
    setDecelerationTimeValue(timeDecelSpinBox->value());
    double retAccelValue = getAccelerationTimeValue();
    qDebug("Acceleration will commence for %f seconds", retAccelValue/millisecondConversion);
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::ACCEL, SendSetpoints::NormalSetpoint);
    QTimer::singleShot(retAccelValue, this, SLOT(startDecelTimer()));
}

void PerturbationTabWidget::startDecelTimer()
{

    double retDecelTimeValue = getDecelerationTimeValue();
    setRightFrontSpeedValue(abs(getDecelerationValue()) * (retDecelTimeValue / millisecondConversion) + \
            getRightFrontSpeedValue());
    setLeftFrontSpeedValue(abs(getDecelerationValue()) * (retDecelTimeValue / millisecondConversion) + \
            getLeftFrontSpeedValue());
    qDebug("Sending Setpoints...");
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::DECEL, SendSetpoints::NormalSetpoint);
    qDebug("Starting Timer...");
    qDebug("Deceleration will commence for %f seconds", retDecelTimeValue/millisecondConversion);
    QTimer::singleShot(retDecelTimeValue, this, SLOT(slotTimeout()));

}

void PerturbationTabWidget::slotTimeout()
{
    sendSetpoints->sendSetpoints(SendSetpoints::ZERO, SendSetpoints::NormalSetpoint);
    std::cout << "Trial Ended" << std::endl;
}



void PerturbationTabWidget::setSocket(QAbstractSocket* socket)
{
    pertSocket = socket;
    sendSetpoints->setSocket(socket);
}

#include "../include/moc_PerturbationTabWidget.cpp"
