#include "DataCollection.h"


static void showWarning(QWidget * parent, const QString & title, const QString & text)
{
   Q_ASSERT(parent);
   QMessageBox * box = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::Ok, parent);
   box->setWindowModality(Qt::WindowModal);
   box->setAttribute(Qt::WA_DeleteOnClose);
   box->show();
}

DataCollection::DataCollection ()
{
    record = false;
}

DataCollection::~DataCollection()
{

}

void DataCollection::setSocket(QAbstractSocket* msocket)
{
    socket = msocket;
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
}

void DataCollection::startDataCollection()
{
    qDebug("Data Collection Started");
    while(socket->canReadLine());
    qDebug("No Data to read");
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
  
   double velocity = static_cast<double>(speed[0]) / 1000;
   qDebug("Velocity: %f", velocity);
   if((velocity > 0.00) && !record)
   {
       emit treadmillStarted(velocity);
       emit stopThread();
   }

   if(record)
   {
       if (!velocityDataFile->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
           return;
       QTextStream velocityTextStream(velocityDataFile);
       velocityTextStream << QString::number(QDateTime::currentMSecsSinceEpoch()) << ",";
       velocityTextStream << velocity << "\n";
       velocityDataFile->close();
   }
}

void DataCollection::setRecord(bool mrecord)
{
    record = mrecord;
}

void DataCollection::setDataFile(QFile* mfile)
{
    velocityDataFile = mfile;
}
#include "../include/moc_DataCollection.cpp"
