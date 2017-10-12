#include "DataCollection.h"


static void showWarning( const QString & title, const QString & text)
{
   QMessageBox * box = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::Ok);
   box->setWindowModality(Qt::WindowModal);
   box->setAttribute(Qt::WA_DeleteOnClose);
   box->show();
}

DataCollection::DataCollection ()
{
    record = false;
    emitComplete = false;
}

DataCollection::~DataCollection()
{

}

void DataCollection::setSocket(QAbstractSocket* msharedSocket)
{
    sharedSocket = msharedSocket;
    if(!record)
    {
        connect(sharedSocket, SIGNAL(readyRead()), SLOT(readyRead()));
    }

    else if(record)
    {
        connect(sharedSocket, SIGNAL(readyRead()), SLOT(startRecording()));
    }
}

void DataCollection::createSocket()
{
    dataCollectionSocket = new QTcpSocket;
    qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError");
    connect(dataCollectionSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    dataCollectionSocket->connectToHost(host, 4000 /*static_cast<quint16>(port.toUShort())*/);
    connect(dataCollectionSocket, SIGNAL(QAbstractSocket::SocketError), SLOT(error()));
}

void DataCollection::error(QAbstractSocket::SocketError)
{
   showWarning("Network Error", dataCollectionSocket->errorString());
}

void DataCollection::error()
{
//    qDebug("Network Error. %s", QString("Error %1").arg(mn));

//    qDebug("Error: %s", qPrintable(dataCollectionSocket->errorString()));
}


void DataCollection::setHost(QString mhost)
{
    host = mhost;
//    qDebug("From DataCollection: The Host is: %s", qPrintable(host));
}

void DataCollection::setPort(QString mport)
{
    port = mport;
//    qDebug("From DataCollection: The Port is: %s", qPrintable(port));
}

void DataCollection::startDataCollection()
{
//    qDebug("Data Collection Started");
//    while(dataCollectionSocket->canReadLine());
    while(sharedSocket->canReadLine());
//    qDebug("No Data to read");
}

void DataCollection::readyRead()
{
   // ** Incoming Packet format 0 **
   // [u8] format specifier (0)
   // [4 x s16] belt 0..3 speed in mm/s
   // [s16] incline angle in 0.01 deg
   // [21 x u8] padding
   // Size: 1 + (8+2) + 21 = 22 + 10 = 32 bytes
   const int packetSize = 32;
   int fullPackets = sharedSocket->bytesAvailable() / packetSize;
   if (! fullPackets) return;
   if (fullPackets > 1) sharedSocket->read((fullPackets-1) * packetSize);
   const QByteArray data = sharedSocket->read(packetSize);
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
  
   double velocity = static_cast<double>(speed[0]) / 1000;
   velocity = fabs(velocity);
//   qDebug("Velocity: %f", velocity);
   if((velocity > 0.00) && !emitComplete)
   {
       emit treadmillStarted(velocity);
       emit stopThread();
       emitComplete = true;
   }

}

void DataCollection::startRecording()
{
   // ** Incoming Packet format 0 **
   // [u8] format specifier (0)
   // [4 x s16] belt 0..3 speed in mm/s
   // [s16] incline angle in 0.01 deg
   // [21 x u8] padding
   // Size: 1 + (8+2) + 21 = 22 + 10 = 32 bytes
   
//    qDebug("Starting Data Recording");
    const int packetSize = 32;
    int fullPackets = sharedSocket->bytesAvailable() / packetSize;
    if (! fullPackets) return;
    if (fullPackets > 1) sharedSocket->read((fullPackets-1) * packetSize);
    const QByteArray data = sharedSocket->read(packetSize);
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

    double velocity = static_cast<double>(speed[0]) / 1000;
    velocity = fabs(velocity);
//    qDebug("Velocity: %f", velocity);

    if (!velocityDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
        return;
    QTextStream velocityTextStream(velocityDataFile);
    velocityTextStream << QString::number(QDateTime::currentMSecsSinceEpoch()) << ",";
    velocityTextStream << velocity << "\n";
    velocityDataFile->close();
}

void DataCollection::setRecord(bool mrecord)
{
    record = mrecord;
}

void DataCollection::setDataFile(QFile* mfile)
{
    velocityDataFile = mfile;
}

void DataCollection::setEmitComplete()
{
    emitComplete = false;
}


#include "../include/moc_DataCollection.cpp"
