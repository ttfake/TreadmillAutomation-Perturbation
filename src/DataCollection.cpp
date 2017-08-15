#include "DataCollection.h"


static void showWarning(QWidget * parent, const QString & title, const QString & text)
{
   Q_ASSERT(parent);
   QMessageBox * box = new QMessageBox(QMessageBox::Warning, title, text, QMessageBox::Ok, parent);
   box->setWindowModality(Qt::WindowModal);
   box->setAttribute(Qt::WA_DeleteOnClose);
   box->show();
}

DataCollection::DataCollection (QAbstractSocket* msocket)
{
    socket = msocket;
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
}

DataCollection::~DataCollection()
{

}

void DataCollection::startDataCollection()
{
    while(socket->canReadLine());
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
   
   emit setRightSpeed(static_cast<double>(speed[0]/1000));
   emit setLeftSpeed(static_cast<double>(speed[1]/1000));

}

#include "../include/moc_DataCollection.cpp"
