#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#pragma once

#include <QtWidgets/QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>
#include <QAbstractSocket>
#include <QObject>

static void showWarning(QWidget * parent, const QString & title, const QString & text);

class DataCollection : public QMainWindow
{
    Q_OBJECT
    public:
        DataCollection(QAbstractSocket* msocket);
        ~DataCollection();
    private slots:
        void readyRead();
    signals:
        void setRightSpeed(double);
        void setLeftSpeed(double);
    private:
        QAbstractSocket* socket;
        void startDataCollection();

};
#endif
