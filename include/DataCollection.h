#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#pragma once

#include <QTcpSocket>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QObject>
#include <QThread>
#include <QFile>
#include <QTime>
#include <cmath>

static void showWarning(const QString & title, const QString & text);

class DataCollection : public QObject
{
    Q_OBJECT
    public:
        DataCollection();
        ~DataCollection();
        void createSocket();
        void setHost(QString);
        void setPort(QString);
        void setDataFile(QFile*);
        void setRecord(bool);
        void setSocket(QAbstractSocket*);

    public slots:

        void startRecording();

    private slots:
        void readyRead();
        void startDataCollection();
        void setEmitComplete();
        void error(QAbstractSocket::SocketError);
        void error();
    signals:
        void treadmillStarted(double);
        void stopThread();
        void finished();
    private:
        QTcpSocket* dataCollectionSocket;
        QAbstractSocket* sharedSocket;
        bool record;
        QFile* velocityDataFile;
        QString host;
        QString port;
        bool emitComplete;
};
#endif
