#include "include/QualisysInterface.h"

QualisysInterface::QualisysInterface()
{

}

QualisysInterface::~QualisysInterface()
{

}

void QualisysInterface::connectQualisys()
{
    socket = new QTcpSocket;

    QString host("localhost");
    uint port(22222);
    
    connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(error(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
    socket->connectToHost(host, port);
}

void QualisysInterface::error(int mn)
{
	showWarning(this, "Network Error", QString("Error %1").arg(mn));
	disconnected();
}

void QualisysInterface::disconnected()
{
    socket->close();
}
void QualisysInterface::readyRead()
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
   QString qualisysData(data);
   qDebug("Incoming Data: %s", qualisysData);
   QDataStream ds(data);
/* quint8 format;
   qint16 speed[4];
   qint16 angle;
   ds >> format;
   if (format != 0) return;
   ds >> speed[0];
   ds >> speed[1];
   ds >> speed[2];
   ds >> speed[3];
   ds >> angle;
*/  
}

void QualisysInterface::error(QAbstractSocket::SocketError)
{

}

static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext)
{
	Q_ASSERT(mparent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, mtitle, mtext, QMessageBox::Ok, mparent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}



#include "../include/moc_QualisysInterface.cpp"
