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
    socket = msocket;
    dataCollect = new DataCollection(socket);
    dataCollectThread = new QThread;
    dataCollect->moveToThread(dataCollectThread);
    connect(dataCollectThread, SIGNAL(started()), dataCollect, SLOT(startDataCollection()));
    connect(dataCollect, SIGNAL(setRightSpeed(double)), this, SLOT(setCurrentRightBeltSpeed(double)));
    connect(dataCollect, SIGNAL(setLeftSpeed(double)), this, SLOT(setCurrentLeftBeltSpeed(double)));
    dataCollectThread->start();
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

void RecordTreadmillStream::setCurrentRightBeltSpeed(double mcurrentRightSpeed)
{
    currentRightBeltVelocity = mcurrentRightSpeed;
}

void RecordTreadmillStream::setCurrentLeftBeltSpeed(double mcurrentLeftSpeed)
{
    currentLeftBeltVelocity = mcurrentLeftSpeed;
}

/*void RecordTreadmillStream::readyRead()
{
   // ** Incoming Packet format 0 **
   // [u8] format specifier (0)
   // [4 x s16] belt 0..3 speed in mm/s
   // [s16] incline angle in 0.01 deg
   // [21 x u8] padding
   // Size: 1 + (8+2) + 21 = 22 + 10 = 32 bytes
   const int packetSize = 32;
   int fullPackets = socket->bytesAvailable() / packetSize;
   if (! fullPackets) return;
   if (fullPackets > 1) socket->read((fullPackets-1) * packetSize);
   const QByteArray data = socket->read(packetSize);
   QDataStream ds(data);
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

   rightSpeedFeedback->setText(QString("%1 m/s").arg(speed[0]/1000.0, 0, 'f', 3));
   QString rightVelocity(QString("%1 m/s").arg(speed[0]/1000.0, 0, 'f', 3));
   QString leftVelocity(QString("%1 m/s").arg(speed[1]/1000.0, 0, 'f', 3));

   if(recordBool)
   {
       if (!velocityDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
            return;
       QTextStream velocityTextStream(velocityDataFile);
       velocityTextStream << QString::number(QDateTime::currentMSecsSinceEpoch()) << ",";
       velocityTextStream << rightVelocity << ",";
       velocityTextStream << leftVelocity  << "\n";
       velocityDataFile->close();
   }
   leftSpeedFeedback->setText(QString("%1 m/s").arg(speed[1]/1000.0, 0, 'f', 3));
}
*/

void RecordTreadmillStream::setRecord()
{
    if(recordButton->getDaqRecordLightColor() == Qt::red)
    {

        setVelocityFileName();
        
        recordButton->changeDaqRecordLight(Qt::green);
        connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
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

    velocityTextStream << "Right" << "," << "Left" << "\n";
    velocityDataFile->close();
}

#include "../include/moc_RecordTreadmillStream.cpp"
