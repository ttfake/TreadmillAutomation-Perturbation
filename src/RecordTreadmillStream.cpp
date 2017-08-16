#include "RecordTreadmillStream.h"


RecordTreadmillStream::RecordTreadmillStream (QWidget *parent, Qt::WindowFlags flags):
    centralWidget(new QWidget)
{
    recordBool = false;

    setCentralWidget(centralWidget);
    centralWidgetLayout = new QVBoxLayout;
    centralWidget->setLayout(centralWidgetLayout);
    populateRecordStreamGroupBox();
}

RecordTreadmillStream::~RecordTreadmillStream()
{

}

void RecordTreadmillStream::setSocket(QAbstractSocket* msocket)
{
    if(socket == NULL)
    {
        socket = msocket;
        dataCollect = new DataCollection();
        dataCollect->setSocket(socket);
        connect(dataCollect, SIGNAL(stopThread()), this, SLOT(stopThread()));
        dataCollectThread = new QThread;
        dataCollect->moveToThread(dataCollectThread);
        connect(dataCollectThread, SIGNAL(started()), dataCollect, SLOT(startDataCollection()));
        connect(dataCollect, SIGNAL(finished()), dataCollectThread, SLOT(quit()));
        connect(dataCollect, SIGNAL(treadmillStarted(double)), this, SLOT(treadmillStartedSlot(double)));
        dataCollectThread->start();

        dataRecord = new DataCollection();
        dataRecord->setSocket(socket);
        dataRecord->setRecord(true);
        dataRecord->setDataFile(velocityDataFile);
        connect(dataRecord, SIGNAL(stopThread()), this, SLOT(stopThread()));
        dataRecordThread = new QThread;
        dataRecord->moveToThread(dataRecordThread);
        connect(dataRecordThread, SIGNAL(started()), dataRecord, SLOT(startDataCollection()));
        connect(dataRecord, SIGNAL(finished()), dataRecordThread, SLOT(quit()));
        connect(dataRecord, SIGNAL(treadmillStarted(double)), this, SLOT(treadmillStartedSlot(double)));
        dataRecordThread->start();
    }
}

void RecordTreadmillStream::populateRecordStreamGroupBox()
{
    recordGroupBox = new QGroupBox;
    recordGroupBoxVerticalLayout = new QVBoxLayout;
    recordGroupBoxFont.setWeight(95);
    recordGroupBoxFont.setFamily("Times");
    recordGroupBoxFont.setPointSize(12);
    recordGroupBoxFont.setBold(true);
    recordGroupBox->setFont(recordGroupBoxFont);
    centralWidgetLayout->addWidget(recordGroupBox);
    recordGroupBox->setLayout(recordGroupBoxVerticalLayout);

    speedGroupBox = new QGroupBox;
    speedGroupBoxLayout = new QHBoxLayout;
    speedGroupBox->setLayout(speedGroupBoxLayout);
    recordGroupBoxVerticalLayout->addWidget(speedGroupBox);
    recordGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    leftSpeedLabel = new QLabel;
    leftSpeedLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    leftSpeedLabel->setFixedSize(50,50);
    leftSpeedLabel->setText("Left: ");
    speedGroupBoxLayout->addWidget(leftSpeedLabel);
    leftSpeedFeedback = new QLabel;
    leftSpeedFeedback->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    leftSpeedFeedback->setFixedSize(50,50);
    speedGroupBoxLayout->addWidget(leftSpeedFeedback);
    rightSpeedLabel = new QLabel;
    rightSpeedLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightSpeedLabel->setFixedSize(50,50);
    rightSpeedLabel->setText("Right: ");
    speedGroupBoxLayout->addWidget(rightSpeedLabel);
    rightSpeedFeedback = new QLabel;
    rightSpeedFeedback->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightSpeedFeedback->setFixedSize(50,50);
    speedGroupBoxLayout->addWidget(rightSpeedFeedback);

    recordButtonGroupBox = new QGroupBox;
    recordButtonGroupBoxLayout = new QHBoxLayout;
    recordButtonGroupBox->setLayout(recordButtonGroupBoxLayout);
    recordButton = new MccDaqRecordButtonWidget;
    recordButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    recordButton->setFixedSize(180,40);
    recordButton->setText("Record");
    recordButtonGroupBoxLayout->addWidget(recordButton);
    recordGroupBoxVerticalLayout->addWidget(recordButtonGroupBox);
    connect(recordButton, SIGNAL(clicked()), this, SLOT(setRecord()));

}


void RecordTreadmillStream::setRecord()
{
    if(recordButton->getDaqRecordLightColor() == Qt::red)
    {

        setVelocityFileName();
        
        recordButton->changeDaqRecordLight(Qt::green);
//        connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
        recordBool = true;
    }
    else
    {
        recordButton->changeDaqRecordLight(Qt::red);
        recordBool = false;
    }
}

void RecordTreadmillStream::stopRecord()
{
    recordBool = false;
    recordButton->changeDaqRecordLight(Qt::red);
}

void RecordTreadmillStream::setVelocityFileName()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), \
            "C:\\Users\\User\\Desktop\\HReflex_Binaries-master\\untitled.csv", \
            tr("CSV (*.csv)"));
    velocityDataFile = new QFile(fileName);
    if (!velocityDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
            return;
    QTextStream velocityTextStream(velocityDataFile);

    velocityTextStream << "Time" << "," << "Right" << "," << "Left" << "\n";
    velocityDataFile->close();
}

void RecordTreadmillStream::treadmillStartedSlot(double mvelocity)
{
    emit treadmillStarted(mvelocity);
}

void RecordTreadmillStream::stopThread()
{
    emit dataCollect->finished();

}

#include "../include/moc_RecordTreadmillStream.cpp"
