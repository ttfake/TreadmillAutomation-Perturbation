#include "include/PerturbationTabWidget.h"


PerturbationTabWidget::PerturbationTabWidget(QWidget* parent, Qt::WindowFlags flags)
{
    sendSetpoints = SendSetpoints::getInstance();
    createTreadmillPerturbationTab();
    populateTreadmillPerturbationTab();
    recordClicked = true;
    trialRun = 1;
    prp = new ParseRunProfile;
}

PerturbationTabWidget::~PerturbationTabWidget()
{
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
    addFudgeFactorGroupBox();
    //addSpeedGroupBox();
    addAccelDecelGroupBox();
    addTimerGroupBox();
    addStartPertRunGroupBox();
}

void PerturbationTabWidget::addQuadrantTwo()
{
    quadrantTwoGroupBox = new QGroupBox;
    quadrantTwoPerturbationLayout = new QVBoxLayout;
    quadrantTwoGroupBox->setLayout(quadrantTwoPerturbationLayout);
    perturbationTabLayout->addWidget(quadrantTwoGroupBox, 0,1);
}

void PerturbationTabWidget::addQuadrantThree()
{
    quadrantThreeGroupBox = new QGroupBox;
    quadrantThreePerturbationLayout = new QVBoxLayout;
    quadrantThreeGroupBox->setLayout(quadrantThreePerturbationLayout);
    perturbationTabLayout->addWidget(quadrantThreeGroupBox, 1,0);
    addRecordDataStreamVelocityBox();
}

void PerturbationTabWidget::addQuadrantFour()
{
    quadrantFourGroupBox = new QGroupBox;
    quadrantFourPerturbationLayout = new QVBoxLayout;
    quadrantFourGroupBox->setLayout(quadrantFourPerturbationLayout);
    perturbationTabLayout->addWidget(quadrantFourGroupBox, 1,1);


}

void PerturbationTabWidget::addFudgeFactorGroupBox()
{
    fudgeFactorGroupBox = new QGroupBox;
    fudgeFactorGroupBoxHorizontalLayout = new QHBoxLayout;
    fudgeFactorGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    fudgeFactorGroupBox->setLayout(fudgeFactorGroupBoxHorizontalLayout);
    fudgeFactorLabel = new QLabel;
    fudgeFactorLabel->setFixedSize(180,180);
    fudgeFactorLabelFont.setFamily("Times");
    fudgeFactorLabelFont.setWeight(75);
    fudgeFactorLabelFont.setPointSize(12);
    fudgeFactorLabel->setFont(fudgeFactorLabelFont);
    fudgeFactorLabel->setText("Added Time: ");
    fudgeFactorGroupBoxHorizontalLayout->addWidget(fudgeFactorLabel);
    fudgeFactorDoubleSpinBox = new QDoubleSpinBox;
    fudgeFactorDoubleSpinBox->setRange(0.00, 100000000.00);
    fudgeFactorDoubleSpinBox->setFont(fudgeFactorLabelFont);
    fudgeFactorDoubleSpinBox->setSuffix(" ms");
    fudgeFactorDoubleSpinBox->setFixedSize(160, 40);
    fudgeFactorGroupBoxHorizontalLayout->addWidget(fudgeFactorDoubleSpinBox);

    quadrantOnePerturbationLayout->addWidget(fudgeFactorGroupBox);
    fudgeFactorGroupBox->hide();
}

void PerturbationTabWidget::addSpeedGroupBox()
{
    speedGroupBox = new QGroupBox;
    speedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedGroupBoxHorizontalLayout = new QHBoxLayout;
    speedGroupBox->setLayout(speedGroupBoxHorizontalLayout);
    

    speedLeftFrontLabel = new QLabel;
    speedLeftFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedLeftFrontLabel->setText("Left Acceleration Speed: ");
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
    speedRightFrontLabel->setText("Right Acceleration Speed: ");
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
    speedGroupBox->hide();

    quadrantOnePerturbationLayout->addWidget(speedGroupBox);
}

void PerturbationTabWidget::addDecelerationSpeedGroupBox()
{
    decelSpeedGroupBox = new QGroupBox;
    decelSpeedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelSpeedGroupBoxHorizontalLayout = new QHBoxLayout;
    decelSpeedGroupBox->setLayout(decelSpeedGroupBoxHorizontalLayout);
    

    decelSpeedLeftLabel = new QLabel;
    decelSpeedLeftLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelSpeedLeftLabel->setText("Left Deceleration Speed: ");
    decelSpeedLeftLabel->setFixedSize(180,180);
    decelSpeedLeftLabelFont.setFamily("Times");
    decelSpeedLeftLabelFont.setWeight(75);
    decelSpeedLeftLabelFont.setPointSize(12);
    decelSpeedLeftLabel->setFont(decelSpeedLeftLabelFont);
    decelSpeedGroupBoxHorizontalLayout->addWidget(decelSpeedLeftLabel);
    leftDecelSpeedSetpoint = new QDoubleSpinBox;
    leftDecelSpeedSetpointFont.setFamily("Times");
    leftDecelSpeedSetpointFont.setWeight(75);
    leftDecelSpeedSetpointFont.setPointSize(12);
    leftDecelSpeedSetpoint->setFont(leftDecelSpeedSetpointFont);
    leftDecelSpeedSetpoint->setSuffix("  m/s");
    leftDecelSpeedSetpoint->setFixedSize(160,40);
    decelSpeedGroupBoxHorizontalLayout->addWidget(leftDecelSpeedSetpoint);

    decelSpeedRightLabel = new QLabel;
    decelSpeedRightLabel->setText("Right Deceleration Speed: ");
    decelSpeedRightLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelSpeedRightLabel->setFixedSize(180,180);
    decelSpeedRightLabelFont.setFamily("Times");
    decelSpeedRightLabelFont.setWeight(75);
    decelSpeedRightLabelFont.setPointSize(12);
    decelSpeedRightLabel->setFont(decelSpeedRightLabelFont);
    decelSpeedGroupBoxHorizontalLayout->addWidget(decelSpeedRightLabel);
    rightDecelSpeedSetpoint = new QDoubleSpinBox;
    rightDecelSpeedSetpointFont.setFamily("Times");
    rightDecelSpeedSetpointFont.setWeight(75);
    rightDecelSpeedSetpointFont.setPointSize(12);
    rightDecelSpeedSetpoint->setFont(rightDecelSpeedSetpointFont);
    rightDecelSpeedSetpoint->setSuffix("  m/s");
    rightDecelSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightDecelSpeedSetpoint->setFixedSize(160,40);
    decelSpeedGroupBoxHorizontalLayout->addWidget(rightDecelSpeedSetpoint);

    quadrantOnePerturbationLayout->addWidget(decelSpeedGroupBox);

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
    timeDecelSpinBox->setValue(600.00);
    timeDecelSpinBox->setEnabled(false);
    timeGroupBoxLayout->addWidget(timeDecelSpinBox);
    
    quadrantOnePerturbationLayout->addWidget(timeGroupBox);
    timeGroupBox->hide();

}

void PerturbationTabWidget::addTrialRunName()
{

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
    acceleration->setRange(-15.00, 15.00);
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
    deceleration->setRange(-15.00, 15.00);
    deceleration->setFont(decelerationLabelFont);
    deceleration->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    deceleration->setFixedSize(160,40);
    
    accelerationDecelerationHorizontalLayout->addWidget(deceleration);

//    accelDecelGroupBox->hide();

    quadrantOnePerturbationLayout->addWidget(accelDecelGroupBox);
}


void PerturbationTabWidget::addStartPertRunGroupBox()
{
//    prp = new ParseRunProfile();
    startPertRunGroupBox = new QGroupBox;
    startPertRunGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunGroupBoxLayout = new QHBoxLayout;
    startPertRunGroupBox->setLayout(startPertRunGroupBoxLayout);
    startPertRunBtn = new QPushButton;
    nextPertRunBtn = new QPushButton;
    nextPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    nextPertRunBtn->setFixedSize(200,40);
    nextPertRunBtn->setText("Next Trial");
    prevPertRunBtn = new QPushButton;
    prevPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    prevPertRunBtn->setFixedSize(200,40);
    prevPertRunBtn->setText("Previous Trial");
    startPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunBtn->setFixedSize(200,40);
    startPertRunBtn->setText("Start Timer");    
    startPertRunGroupBoxLayout->addWidget(startPertRunBtn);
    startPertRunGroupBoxLayout->addWidget(prevPertRunBtn);
    startPertRunGroupBoxLayout->addWidget(nextPertRunBtn);
    startPertRunBtnFont.setFamily("Times");
    startPertRunBtnFont.setWeight(75);
    startPertRunBtnFont.setPointSize(12);
    startPertRunBtn->setFont(startPertRunBtnFont);
    prevPertRunBtn->setFont(startPertRunBtnFont);
    nextPertRunBtn->setFont(startPertRunBtnFont);
    quadrantOnePerturbationLayout->addWidget(startPertRunGroupBox);
    startPertRunGroupBox->hide();
    recTreadmillStream = new RecordTreadmillStream;
    readTrialNameFile = new ReadTrialNameFile("config/TrialNames.txt");
    mouseInterface = new MouseInterface;
    mouseInterface->openPort();
    mouseInterface->SetupDigitalOutput();
    // The following connect waits for a change in speed data from the treadmill 
    // and when the treadmillStarted signal is received (a change in the treadmill 
    // speed is detected), treadmillWait is activated. This connect will be changed
    // to reflect the new mouse sensor system.
//    connect(recTreadmillStream, SIGNAL(treadmillStarted(double)), 
//            this, SLOT(treadmillWait(double)));
    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(getTrialName()));
    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(disableButton()));
//    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(startTreadmill()));
    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(randomDelay()));
    connect(startPertRunBtn, SIGNAL(clicked()), mouseInterface, SLOT(WriteLine()));  // Trigger 1
    connect(mouseInterface, SIGNAL(movement()), SLOT(treadmillWait()));
    connect(mouseInterface, SIGNAL(movementStopped()), SLOT(slotTimeout()));
    connect(startPertRunBtn, SIGNAL(clicked()), mouseInterface, SLOT(setPerturbationActiveBoolTrue()));
    connect(nextPertRunBtn, SIGNAL(clicked()), SLOT(nextRun()));
    connect(prevPertRunBtn, SIGNAL(clicked()), SLOT(prevRun()));

}


void PerturbationTabWidget::addRecordDataStreamVelocityBox()
{
    recTreadmillStream->hide();

    quadrantThreePerturbationLayout->addWidget(recTreadmillStream);

}

void PerturbationTabWidget::setAddToSpeed(double mAddToSpeed)
{
    addToSpeed = mAddToSpeed;
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

void PerturbationTabWidget::showFudgeFactorGroupBox(bool state)
{
    if(state)
    {
        fudgeFactorGroupBox->show();
    }
    else
    {
       fudgeFactorGroupBox->hide();
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
    accelerationValue = fabs(maccelValue);
    sendSetpoints->setAccelerationValue(accelerationValue);
    std::cout << "Acceleration Value Set to: " << accelerationValue << std::endl;
}

void PerturbationTabWidget::setDecelerationValue(double mdecelValue)
{
    decelerationValue = fabs(mdecelValue);
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

void PerturbationTabWidget::randomDelay()
{
    int randomTime = rand() % 2000 + 2000;
    qDebug("Random Time: %i", randomTime);
    QFile randomDelayLog(logPath + "/" + "randomDelayLog.log");
    randomDelayLog.open(QIODevice::Append);
    randomDelayLog.write(QString::number(randomTime).toUtf8() + "\n");
    randomDelayLog.close();
//    mouseInterface->WriteLine();
    QTimer::singleShot(randomTime, this, SLOT(startTreadmill()));
}

void PerturbationTabWidget::startTreadmill()
{
    QFile accelerationSignalSentLog(logPath + "/" + "accelerationSignalSentLog.log");
    accelerationSignalSentLog.open(QIODevice::Append);
/*    int low = 0;
    int hi  = 6;
    int millisecondsConversionFactor = 1000;
    int randomMilliseconds = qrand() % ((hi + 1) - low) + low;
    int millisecondsToSeconds = randomMilliseconds * millisecondsConversionFactor;
    QTimer timer;
    timer.setSingleShot(true);*/
//    recTreadmillStream->setRecord();
    setAccelerationValue(acceleration->value());
    setDecelerationValue(deceleration->value());
    setAccelerationTimeValue(timeAccelSpinBox->value());
    setDecelerationTimeValue(timeDecelSpinBox->value());
    setAddToSpeed(fudgeFactorDoubleSpinBox->value());
    qDebug() << addToSpeed;
    setLeftFrontSpeedValue(calculateSpeed());
    setRightFrontSpeedValue(calculateSpeed());
    //timer.start(millisecondsToSeconds);

    //-----------------------------------------------------------------------
    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::setprecision(5);
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    accelerationSignalSentLog.write(uptimeString.toUtf8() + "\n");
    //-----------------------------------------------------------------------

    //-----------------Current Unix Timestamp--------------------------------
    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationSignalSentLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------
    
    accelerationSignalSentLog.close();
    mouseInterface->WriteLine(); // Trigger 2
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::ACCEL, SendSetpoints::NormalSetpoint);
    //    recTreadmillStream->setSharedSocket(pertSocket);
//    recTreadmillStream->startDataCollection();
}

void PerturbationTabWidget::treadmillWait()
{
    QFile accelerationTimerStartedLog(logPath + "/" + "accelerationTimerStartedLog.log");
    accelerationTimerStartedLog.open(QIODevice::Append);
    double retAccelValue;
    //double timeSinceStart = fabs((mvelocity / fabs(getAccelerationValue())) * 1000.00);
//    retAccelValue = fabs(( getAccelerationTimeValue() * fabs(getAccelerationValue())) / 1000);

    retAccelValue = getAccelerationTimeValue();
    qDebug("Deceleration Time Set To: %f", retAccelValue);

   //-----------------------------------------------------------------------
    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    //-----------------------------------------------------------------------

 
    mouseInterface->setMovementBool(true);
//    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
//    accelerationTimerStartedLog.write(QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    accelerationTimerStartedLog.write(uptimeString.toUtf8() + "\n");

    //-----------------Current Unix Timestamp--------------------------------
    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationTimerStartedLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------
    
    accelerationTimerStartedLog.close();
    mouseInterface->WriteLine(); // Trigger 4
 
    QTimer::singleShot(retAccelValue, this, SLOT(startDecelTimer()));
}

void PerturbationTabWidget::startDecelTimer()
{

    //-----------------------------------------------------------------------
    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    //-----------------------------------------------------------------------

    QFile accelerationTimerEndedLog(logPath + "/" + "accelerationTimerEndedLog.log");
    QFile decelerationSignalSentLog(logPath + "/" + "decelerationSignalSentLog.log");
    QFile decelerationTimerStartedLog(logPath + "/" + "decelerationTimerStartedLog.log");
    accelerationTimerEndedLog.open(QIODevice::Append);
//    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationTimerEndedLog.write(uptimeString.toUtf8() + "\n");

    //-----------------Current Unix Timestamp--------------------------------
    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationTimerEndedLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------

    accelerationTimerEndedLog.close();
    decelerationSignalSentLog.open(QIODevice::Append);
    decelerationTimerStartedLog.open(QIODevice::Append);
    mouseInterface->setMovementBool(false);
    double retDecelTimeValue = getDecelerationTimeValue();
    setRightFrontSpeedValue(0);
    setLeftFrontSpeedValue(0);
//    qDebug("Sending Setpoints...");
 
    //-----------------------------------------------------------------------
    uptime = std::chrono::milliseconds(GetTickCount());
    out << std::chrono::milliseconds(uptime).count() << "ms";
    uptimeStdString = out.str();
    uptimeString = QString::fromStdString(uptimeStdString);
    decelerationSignalSentLog.write(uptimeString.toUtf8() + "\n");
    //-----------------------------------------------------------------------

    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::DECEL, SendSetpoints::NormalSetpoint);
//    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
//    decelerationSignalSentLog.write(QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    decelerationSignalSentLog.close();
//    qDebug("Starting Timer...");
//    qDebug("Deceleration will commence for %f seconds", retDecelTimeValue/millisecondConversion);
//    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    uptime = std::chrono::milliseconds(GetTickCount());
    
    out << std::chrono::milliseconds(uptime).count() << "ms";
    uptimeStdString = out.str();
    uptimeString = QString::fromStdString(uptimeStdString);
    decelerationTimerStartedLog.write(uptimeString.toUtf8() + "\n");

    //-----------------Current Unix Timestamp--------------------------------
    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    decelerationTimerStartedLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------
    
    decelerationTimerStartedLog.close();
    mouseInterface->WriteLine(); // Trigger 5
//    mouseInterface->setPerturbationActiveBoolFalse();
//    mouseInterface->setMovementDetectedBool(false);

    QTimer::singleShot(retDecelTimeValue, this, SLOT(slotTimeout()));
//    recTreadmillStream->setRecord();
//    emit recTreadmillStream->setEmitComplete();
}

void PerturbationTabWidget::slotTimeout()
{
    mouseInterface->setMovementDetectedBool(false);

    //-----------------------------------------------------------------------
/*    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    //-----------------------------------------------------------------------

    QFile decelerationTimerEndedLog(logPath + "/" + "decelerationTimerEndedLog.log");
    QFile zeroSignalSentLog(logPath + "/" + "zeroSignalSentLog.log");
    decelerationTimerEndedLog.open(QIODevice::Append);
    zeroSignalSentLog.open(QIODevice::Append);
//    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    decelerationTimerEndedLog.write(uptimeString.toUtf8() + "\n");

    mouseInterface->WriteLine();
    decelerationTimerEndedLog.close();
    sendSetpoints->sendSetpoints(SendSetpoints::ZERO, SendSetpoints::NormalSetpoint);
//    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
//    zeroSignalSentLog.write(QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    zeroSignalSentLog.write(uptimeString.toUtf8() + "\n");
    zeroSignalSentLog.close();
    std::cout << "Trial Ended" << std::endl;
    mouseInterface->setPerturbationActiveBoolFalse();
//    mouseInterface->StopTask();
    //recTreadmillStream->stopRecord();
*/
}



void PerturbationTabWidget::setSocket(QAbstractSocket* socket)
{
    pertSocket = socket;
    sendSetpoints->setSocket(socket);
}

double PerturbationTabWidget::calculateSpeed()
{
    //double addToSpeed = 100;    //Added to compensate for flat top
    return ((acceleration->value() * ((getAccelerationTimeValue()/millisecondConversion) + 
                    (addToSpeed / 1000)))); 
}



void PerturbationTabWidget::loadRunProfile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), \
            "C:\\Users\\User\\Desktop\\HReflex_Binaries-master\\untitled.csv", \
            tr("CSV (*.csv)"));
    prp->setRunFile(fileName);
    prp->getRuns();
    prp->getRun(1);
    setAccelerationValue(prp->getAccelLeft());
    acceleration->setValue(prp->getAccelLeft());
    setDecelerationValue(prp->getDecelLeft());
    deceleration->setValue(prp->getDecelLeft());
    timeAccelSpinBox->setValue(prp->getAccelTime());
    setAccelerationTimeValue(prp->getAccelTime());

}

void PerturbationTabWidget::saveVelocityData()
{
    recTreadmillStream->setVelocityFileName();
}

void PerturbationTabWidget::setHost(QString mhost)
{
    host = mhost;
    recTreadmillStream->setHost(host);
    qDebug("From PerturbationTabWidget: The host is %s ", qPrintable(host));
    
}

void PerturbationTabWidget::setPort(QString mport)
{
    port = mport;
    recTreadmillStream->setPort(port);
    qDebug("From PerturbationTabWidget: The port is %s ", qPrintable(port));
}

void PerturbationTabWidget::getTrialName()
{
    QString trialName(readTrialNameFile->getTrialName());
    setLoggingDirectory(trialName);
}

void PerturbationTabWidget::setLoggingDirectory(QString dirName)
{
    QString dataDir("data");
    if(!QDir(dataDir).exists())
    {
        QDir().mkdir(dataDir);
    }
    dirName = dirName.remove(QRegExp("[\\n\\t\\r]"));   
    dirName = dataDir + "/" + dirName;// + "_" + trialRun;
    qDebug() << dirName;

    if(!QDir(dirName).exists())
    {
        QDir().mkdir(dirName);
    }

    trialRun++;
    if(trialRun > 2)
    {
        trialRun = 1;
    }

    logPath = dirName;
    mouseInterface->setLogPath(logPath);
}

void PerturbationTabWidget::disableButton()
{
    startPertRunBtn->setEnabled(false);
}

void PerturbationTabWidget::enableButton()
{
    startPertRunBtn->setEnabled(true);
}

void PerturbationTabWidget::nextRun()
{
    prp->getRun(1);
    setAccelerationValue(prp->getAccelLeft());
    acceleration->setValue(prp->getAccelLeft());
    setDecelerationValue(prp->getDecelLeft());
    deceleration->setValue(prp->getDecelLeft());
    timeAccelSpinBox->setValue(prp->getAccelTime());
    setAccelerationTimeValue(prp->getAccelTime());
    startStim();

}

void PerturbationTabWidget::prevRun()
{
    prp->getRun(-2);
    setAccelerationValue(prp->getAccelLeft());
    acceleration->setValue(prp->getAccelLeft());
    setDecelerationValue(prp->getDecelLeft());
    deceleration->setValue(prp->getDecelLeft());
    timeAccelSpinBox->setValue(prp->getAccelTime());
    setAccelerationTimeValue(prp->getAccelTime());
    connect(prp, SIGNAL(startStimulation()), SLOT(startStim()));
}

void PerturbationTabWidget::startStim()
{
    qDebug() << "Starting Stimulation...";
    randomDelay();
}

#include "../include/moc_PerturbationTabWidget.cpp"
