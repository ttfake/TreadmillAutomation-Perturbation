#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#pragma once

#include <QTcpSocket>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>
#include <QAbstractSocket>
#include <QObject>
#include <QThread>
#include <QFile>
#include <QTime>
#include <cmath>

static void showWarning(QWidget * parent, const QString & title, const QString & text);

class DataCollection : public QObject
{
    Q_OBJECT
    public:
        DataCollection();
        ~DataCollection();
        void setSocket(QAbstractSocket* msocket);
        void setDataFile(QFile*);
        void setRecord(bool);
    private slots:
        void readyRead();
        void startDataCollection();
    signals:
        void treadmillStarted(double);
        void stopThread();
        void finished();
    private:
        QAbstractSocket* socket;
        bool record;
        QFile* velocityDataFile;

};
#endif
