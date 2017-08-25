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
    uint port(22224);
    
    connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(error(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
    socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    socket->connectToHost(host, port);
    socket->write("StreamFrames Frequency:30 3D Analog\r\n");
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
   char* data;
   qDebug("Data Received");
   qDebug() << socket->bytesAvailable() << "\r\n";
   qDebug() <<  socket->readAll() << "\r\n";
}

void QualisysInterface::error(QAbstractSocket::SocketError)
{
    qDebug("There was a socket error.");
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
