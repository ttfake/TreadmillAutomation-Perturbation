#include "ConfigTabWidget.h"

ConfigTabWidget::ConfigTabWidget(QWidget* parent, Qt::WindowFlags flags)
{
    clicked = true;
    pmccDaqInterface = new MccDaqInterface;
    configGridLayout = new QGridLayout;
    setLayout(configGridLayout);
    addDaqControlGroupBox();
    daqThread = new QThread;
    connect(daqThread, SIGNAL(started()), pmccDaqInterface, SLOT(beginDataCollection()));
    connect(pmccDaqInterface, SIGNAL(finished()), daqThread, SLOT(quit()));
}

ConfigTabWidget::~ConfigTabWidget()
{
}

void ConfigTabWidget::addDaqControlGroupBox()
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
    connect(mccDaqConnectButtonWidget, SIGNAL(clicked()), SLOT(setDaqLogFileName()));
    connect(mccDaqConnectButtonWidget, SIGNAL(clicked()), \
            SLOT(startDataCollectionThread()));
    connect(mccDaqConnectButtonWidget, SIGNAL(clicked()), SLOT(setDaqConnectColor()));
    daqControlGroupBoxLayout->addWidget(daqPushButtonBox);

    mccDaqRecordButtonWidget = new MccDaqRecordButtonWidget;
    mccDaqRecordButtonWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    mccDaqRecordButtonWidget->setFixedSize(180,40);
    mccDaqRecordButtonFont.setFamily("Times");
    mccDaqRecordButtonFont.setWeight(80);
    mccDaqRecordButtonFont.setPointSize(12);
    mccDaqRecordButtonFont.setBold(true);
    mccDaqRecordButtonWidget->setFont(mccDaqRecordButtonFont);
    mccDaqRecordButtonWidget->setText("DAQ Record");
    daqPushButtonBoxLayout->addWidget(mccDaqRecordButtonWidget);
    connect(mccDaqRecordButtonWidget, SIGNAL(clicked()), SLOT(setDaqRecordBool()));
    connect(mccDaqRecordButtonWidget, SIGNAL(clicked()), SLOT(setDaqRecordColor()));
    daqControlGroupBox->setLayout(daqControlGroupBoxLayout);

    
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
    configGridLayout->addWidget(daqControlGroupBox);
//    quadrantTwoPerturbationLayout->addWidget(daqControlGroupBox);
}

void ConfigTabWidget::setDaqConnectColor()
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

void ConfigTabWidget::scanForDaqDevice()
{
    pmccDaqInterface->startChannelScan(daqDevMenu);
}

void ConfigTabWidget::startDataCollectionThread()
{
    if(mccDaqConnectButtonWidget->getDaqConnectLightColor() == Qt::red)
    {
        pmccDaqInterface->moveToThread(daqThread);
        daqThread->start();
    }

    else if(mccDaqConnectButtonWidget->getDaqConnectLightColor() == Qt::green)
    {
        qDebug("Terminating Thread.");
        pmccDaqInterface->setRunningState(IDLE);
        emit pmccDaqInterface->finished();

    }

}

void ConfigTabWidget::setDaqText(QString title)
{
    scanForDaqDev->setText(title);
}

void ConfigTabWidget::setupDataCollection()
{
    pmccDaqInterface->dataCollectionSetup();
}

void ConfigTabWidget::setRowCount(int mRowCount)
{
    rowCount = mRowCount;
}

void ConfigTabWidget::updateCol(int mColNo)
{
    colNo = mColNo;
}

void ConfigTabWidget::updateDaqDataStreamTableWidget(double force)
{
    QString dataString = QString::number(force, 'f', 4);
    QTableWidgetItem* channel = new QTableWidgetItem(dataString);
    daqDataStreamTableWidget->setRowCount(rowCount);
    channel->setTextAlignment(Qt::AlignCenter);
    daqDataStreamTableWidget->setItem(rowCount-1, colNo, channel);
}

void ConfigTabWidget::getActiveState(int channel)
{
    QGroupBox* activeChannelGroupBox = static_cast<QGroupBox*>(channelTableWidget->cellWidget(channel, 2));
    QString activeCheckSearchString = QString("activeCheck%1").arg(channel);
    QCheckBox* activeCheckBoxFound = activeChannelGroupBox->findChild<QCheckBox*>(activeCheckSearchString);

    if(activeCheckBoxFound->isChecked())
    {
        pmccDaqInterface->setCurrentChannelActiveState(true);
    }
}

void ConfigTabWidget::getChannelType(int channel)
{

}

void ConfigTabWidget::getGainType(int channel)
{

}

void ConfigTabWidget::setChannel(int mchannel)
{
    currentChannel = mchannel;
}

void ConfigTabWidget::setDaqRecordBool()
{
    if(mccDaqRecordButtonWidget->getDaqRecordLightColor() == Qt::red)
    {
        pmccDaqInterface->setRecordBool(true);
    }

    else if(mccDaqRecordButtonWidget->getDaqRecordLightColor() == Qt::green)
    {
        pmccDaqInterface->setRecordBool(false);
    }

}

void ConfigTabWidget::setDaqLogFileName()
{
    if(mccDaqConnectButtonWidget->getDaqConnectLightColor() == Qt::red)
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), \
                "C:\\Users\\User\\Desktop\\HReflex_Binaries-master\\untitled.csv", \
                tr("CSV (*.csv)"));
        pmccDaqInterface->setDaqLogFileName(fileName);
    }
}

void ConfigTabWidget::setDaqRecordColor()
{
    if(recordClicked)
    {
        mccDaqRecordButtonWidget->changeDaqRecordLight(Qt::green);
        recordClicked = false;
    }
    else
    {
        mccDaqRecordButtonWidget->changeDaqRecordLight(Qt::red);
        recordClicked = true;
    }

}


void ConfigTabWidget::addChannels()
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

void ConfigTabWidget::addDaqDataGroupBox()
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
    //quadrantFourConfigLayout->addWidget(daqDataGroupBox);

    //daqDataGroupBox->hide();

}

void ConfigTabWidget::showDaqDataBox(bool checked)
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
                                    "\"Config\" tab before viewing the" \
                                    " Daq Streaming Box.");
        daqDataBoxAlert.exec();
    }
}
#include "../include/moc_ConfigTabWidget.cpp"
