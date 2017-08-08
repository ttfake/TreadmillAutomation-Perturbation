#include "include/PerturbationTabWidget.h"


PerturbationTabWidget::PerturbationTabWidget(QWidget* parent, Qt::WindowFlags flags)
{
    pmccDaqInterface = new MccDaqInterface;

    connect(pmccDaqInterface, SIGNAL(updateDaqDataBoxSignal(double)), \
                this, SLOT(updateDaqDataStreamTableWidget(double)));

    connect(pmccDaqInterface, SIGNAL(updateRowCount(int)), \
                this, SLOT(setRowCount(int)));

    connect(pmccDaqInterface, SIGNAL(updateCol(int)), \
                this, SLOT(updateCol(int)));

    connect(pmccDaqInterface, SIGNAL(getActiveState(int)), this, SLOT(getActiveState(int)));

    sendSetpoints = SendSetpoints::getInstance();
    createTreadmillPerturbationTab();
    populateTreadmillPerturbationTab();
    clicked = true;
    scanForDaqDevice();

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
    addDaqControlGroupBox();
}

void PerturbationTabWidget::addQuadrantThree()
{
    quadrantThreeGroupBox = new QGroupBox;
    quadrantThreePerturbationLayout = new QVBoxLayout;
    quadrantThreeGroupBox->setLayout(quadrantThreePerturbationLayout);
    perturbationTabLayout->addWidget(quadrantThreeGroupBox, 1,0);

}

void PerturbationTabWidget::addQuadrantFour()
{
    quadrantFourGroupBox = new QGroupBox;
    quadrantFourPerturbationLayout = new QVBoxLayout;
    quadrantFourGroupBox->setLayout(quadrantFourPerturbationLayout);
    perturbationTabLayout->addWidget(quadrantFourGroupBox, 1,1);


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
    timeGroupBoxLayout->addWidget(timeDecelSpinBox);

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

    quadrantOnePerturbationLayout->addWidget(accelDecelGroupBox);
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

void PerturbationTabWidget::addDaqControlGroupBox()
{

    daqControlGroupBox = new QGroupBox;
    daqControlGroupBoxFont.setFamily("Times");
    daqControlGroupBoxFont.setWeight(80);
    daqControlGroupBoxFont.setPointSize(12);
    daqControlGroupBoxFont.setBold(true);
    daqControlGroupBox->adjustSize();
    daqControlGroupBox->setFont(daqControlGroupBoxFont);
    daqControlGroupBoxLayout = new QVBoxLayout;
    daqPushButtonBox = new QGroupBox;
    daqControlGroupBoxLayout->addWidget(daqPushButtonBox);
    daqPushButtonBoxLayout = new QHBoxLayout;
    daqPushButtonBox->setLayout(daqPushButtonBoxLayout);
    
    scanForDaqDev = new QPushButton;
    scanForDaqDev->setFixedSize(200,40);
    scanForDaqDev->setText("Discover DAQ Devices");
    daqDevMenu = new QMenu;
    scanForDaqDev->setMenu(daqDevMenu);
    daqPushButtonBoxLayout->addWidget(scanForDaqDev);
    connect(pmccDaqInterface, SIGNAL(setDaqTitleText(QString)), this, SLOT(setDaqText(QString)));
    
    mccDaqConnectButtonWidget = new MccDaqConnectButtonWidget();
    mccDaqConnectButtonWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    mccDaqConnectButtonWidget->setFixedSize(180,40);
    mccDaqConnectButtonFont.setFamily("Times");
    mccDaqConnectButtonFont.setWeight(80);
    mccDaqConnectButtonFont.setPointSize(12);
    mccDaqConnectButtonFont.setBold(true);
    mccDaqConnectButtonWidget->setFont(mccDaqConnectButtonFont);
    mccDaqConnectButtonWidget->setText("DAQ Connect");
    daqPushButtonBoxLayout->addWidget(mccDaqConnectButtonWidget);
    daqControlGroupBox->setLayout(daqControlGroupBoxLayout);
    connect(mccDaqConnectButtonWidget, SIGNAL(clicked()), \
            SLOT(startDataCollectionThread()));
    connect(mccDaqConnectButtonWidget, SIGNAL(clicked()), SLOT(setColor()));
    daqControlGroupBoxLayout->addWidget(daqPushButtonBox);
    
    numberOfChannelsGroupBox = new QGroupBox;
    numberOfChannelsGroupBoxFont.setFamily("Times");
    numberOfChannelsGroupBoxFont.setWeight(80);
    numberOfChannelsGroupBoxFont.setPointSize(12);
    numberOfChannelsGroupBoxFont.setBold(true);
    numberOfChannelsGroupBox->setFont(numberOfChannelsGroupBoxFont);
    numberOfChannelsGroupBoxLayout = new QHBoxLayout;
    daqControlGroupBoxLayout->addWidget(numberOfChannelsGroupBox);
    numberOfChannelsGroupBox->setLayout(numberOfChannelsGroupBoxLayout);
    numberOfChannelsLabel = new QLabel;
    numberOfChannelsLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    numberOfChannelsLabel->setFixedSize(150,40);
    numberOfChannelsLabel->setText("No. of Channels: ");
    numberOfChannelsGroupBoxLayout->addWidget(numberOfChannelsLabel);
    numberOfChannelsSpinBox = new QSpinBox;
    numberOfChannelsSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    numberOfChannelsSpinBox->setFixedSize(150,40);
    numberOfChannelsSpinBox->setAlignment(Qt::AlignCenter);
    numberOfChannelsSpinBox->setRange(0,64);
    numberOfChannelsGroupBoxLayout->addWidget(numberOfChannelsSpinBox);
    setNumChannels = new QPushButton;
    setNumChannels->setText("Set No. of Channels");
    setNumChannels->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    setNumChannels->setFixedSize(180,40);
    numberOfChannelsGroupBoxLayout->addWidget(setNumChannels);

    connect(setNumChannels, SIGNAL(clicked()), SLOT(addChannels()));
    
    channelTableWidget = new QTableWidget;
    channelTableWidget->setColumnCount(5);
    daqControlGroupBoxLayout->addWidget(channelTableWidget);
    channelHeaderStringList << "Channel" << "Label" << "Active" << "Type" << "Gain";
    channelTableWidget->setHorizontalHeaderLabels(channelHeaderStringList);

    quadrantTwoPerturbationLayout->addWidget(daqControlGroupBox);
}


void PerturbationTabWidget::setColor()
{
    if(clicked)
    {
        mccDaqConnectButtonWidget->changeDaqConnectLight(Qt::green);
        clicked = false;
    }
    else
    {
        mccDaqConnectButtonWidget->changeDaqConnectLight(Qt::red);
        clicked = true;
    }

}

void PerturbationTabWidget::addChannels()
{
    channelTableWidget->setRowCount(numberOfChannelsSpinBox->value());
    pmccDaqInterface->setNumberOfChannels(numberOfChannelsSpinBox->value());
    numChannels = numberOfChannelsSpinBox->value();
    for(int i = 0; i < numChannels; i++)
    {
        QTableWidgetItem* channel = new QTableWidgetItem(tr("%1").arg(i));
        channel->setTextAlignment(Qt::AlignCenter);
        channelTableWidget->setItem(i, 0, channel);
        QComboBox* gainCombo = new QComboBox;
        QStringList gainList;
        gainList << "BIP10VOLTS" << "BIP5VOLTS" << "BIP2PT5VOLTS" << "BIP1PT25VOLTS" << "UNI10VOLTS" \
                    << "UNI5VOLTS" << "UNI2PT5VOLTS" << "UNI1PT25VOLTS";
        gainCombo->addItems(gainList);
        channelTableWidget->setCellWidget(i, 4, static_cast<QWidget*>(gainCombo));
        QGroupBox* checkBoxGroupBox = new QGroupBox;
        checkBoxGroupBox->isCheckable();
        QHBoxLayout* checkBoxGroupBoxLayout = new QHBoxLayout;
        checkBoxGroupBox->setLayout(checkBoxGroupBoxLayout);
        checkBoxGroupBoxLayout->setAlignment(Qt::AlignCenter);
        QCheckBox* activeCheck = new QCheckBox;
        QString activeCheckBoxName = QString("activeCheck%1").arg(i);
        activeCheck->setObjectName(activeCheckBoxName);
        activeCheck->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        activeCheck->setFixedSize(20,20);
        checkBoxGroupBoxLayout->addWidget(activeCheck);
        channelTableWidget->setCellWidget(i, 2, static_cast<QWidget*>(checkBoxGroupBox));
        QComboBox* typeCombo = new QComboBox;
        QStringList typeComboList;
        typeComboList << "ANALOG" << "DIGITAL8" << "DIGITAL16";
        typeCombo->addItems(typeComboList);
        channelTableWidget->setCellWidget(i, 3, static_cast<QWidget*>(typeCombo));

    }
     addDaqDataGroupBox();
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
    setAccelerationTimeValue(timeAccelSpinBox->value());
    setDecelerationTimeValue(timeDecelSpinBox->value());
    setLeftFrontSpeedValue(calculateSpeed());
    setRightFrontSpeedValue(calculateSpeed());
    double retAccelValue = getAccelerationTimeValue();
    qDebug("Acceleration will commence for %f seconds", retAccelValue/millisecondConversion);
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::ACCEL, SendSetpoints::NormalSetpoint);
    QTimer::singleShot(retAccelValue, this, SLOT(startDecelTimer()));
}

void PerturbationTabWidget::startDecelTimer()
{

    double retDecelTimeValue = getDecelerationTimeValue();
    setRightFrontSpeedValue(0);
    setLeftFrontSpeedValue(0);
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

double PerturbationTabWidget::calculateSpeed()
{
    return (getAccelerationValue() * getAccelerationTimeValue()/millisecondConversion); 
}

void PerturbationTabWidget::addDaqDataGroupBox()
{
    daqDataGroupBox = new QGroupBox;
    daqDataGroupBoxFont.setFamily("Times");
    daqDataGroupBoxFont.setWeight(75);
    daqDataGroupBoxFont.setPointSize(12);
    daqDataGroupBoxFont.setBold(true);
    daqDataGroupBox->setFont(daqDataGroupBoxFont);

    daqDataGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    daqDataGroupBoxVerticalLayout = new QVBoxLayout;
    daqDataGroupBox->setLayout(daqDataGroupBoxVerticalLayout);
    daqDataLabel = new QLabel;
    daqDataLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    daqDataLabel->setFixedSize(220,100);
    daqDataLabel->setText("Forceplate Data: ");
    daqDataGroupBoxVerticalLayout->addWidget(daqDataLabel);
    
    daqDataStreamTableWidget = new QTableWidget;
    daqDataStreamTableWidget->setColumnCount(numChannels);

    for(int i = 0; i <= numChannels; i++)
    {
        QString channel = QString("Channel %1").arg(i);
        daqDataStreamHeaderStringList << channel;
    }

    daqDataStreamTableWidget->setHorizontalHeaderLabels(daqDataStreamHeaderStringList);
    daqDataGroupBoxVerticalLayout->addWidget(daqDataStreamTableWidget);
    quadrantFourPerturbationLayout->addWidget(daqDataGroupBox);

    daqDataGroupBox->hide();

}

void PerturbationTabWidget::showDaqDataBox(bool checked)
{
    if(checked && daqDataGroupBox != NULL)
    {
        daqDataGroupBox->show();
    }
    else if(daqDataGroupBox != NULL)
    {
        daqDataGroupBox->hide();
    }
    else
    {
        QMessageBox daqDataBoxAlert;
        daqDataBoxAlert.setText("You must enter the number of Channels in the \n " \
                                    "\"No. of Channels Box\" and click the \n" \
                                    "\"Set No. of Channels\" button in the\n" \
                                    "\"Perturbation\" tab before viewing the" \
                                    " Daq Streaming Box.");
        daqDataBoxAlert.exec();
    }
}

void PerturbationTabWidget::scanForDaqDevice()
{
    pmccDaqInterface->startChannelScan(daqDevMenu);
}

void PerturbationTabWidget::startDataCollectionThread()
{
    if(mccDaqConnectButtonWidget->getDaqConnectLightColor() == Qt::red)
    {
        if(daqThread == NULL)
        {
            daqThread = new QThread;

            pmccDaqInterface->moveToThread(daqThread);
        }


        connect(daqThread, SIGNAL(started()), pmccDaqInterface, SLOT(beginDataCollection()));
        connect(pmccDaqInterface, SIGNAL(finished()), daqThread, SLOT(quit()));
        daqThread->start();
    }

    else if(mccDaqConnectButtonWidget->getDaqConnectLightColor() == Qt::green)
    {
        qDebug("Terminating Thread.");
        pmccDaqInterface->setRunningState(IDLE);
        emit pmccDaqInterface->finished();
    }
}

void PerturbationTabWidget::setDaqText(QString title)
{
    scanForDaqDev->setText(title);
}

void PerturbationTabWidget::setupDataCollection()
{
    pmccDaqInterface->dataCollectionSetup();
}

void PerturbationTabWidget::setRowCount(int mRowCount)
{
    rowCount = mRowCount;
}

void PerturbationTabWidget::updateCol(int mColNo)
{
    colNo = mColNo;
}

void PerturbationTabWidget::updateDaqDataStreamTableWidget(double data)
{
    QString dataString = QString::number(data, 'g', 12);
    daqDataStreamTableWidget->setRowCount(rowCount);
    QTableWidgetItem* channel = new QTableWidgetItem(dataString);
    channel->setTextAlignment(Qt::AlignCenter);
    daqDataStreamTableWidget->setItem(rowCount-1, colNo, channel);
}

void PerturbationTabWidget::getActiveState(int channel)
{
    QGroupBox* activeChannelGroupBox = static_cast<QGroupBox*>(channelTableWidget->cellWidget(channel, 2));
    QString activeCheckSearchString = QString("activeCheck%1").arg(channel);
    QCheckBox* activeCheckBoxFound = activeChannelGroupBox->findChild<QCheckBox*>(activeCheckSearchString);

    if(activeCheckBoxFound->isChecked())
    {
        pmccDaqInterface->setCurrentChannelActiveState(true);
    }
}

void PerturbationTabWidget::getChannelType(int channel)
{

}

void PerturbationTabWidget::getGainType(int channel)
{

}

#include "../include/moc_PerturbationTabWidget.cpp"
