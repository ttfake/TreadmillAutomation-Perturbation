#ifndef QUALISYSINTERFACE_H
#define QUALISYSINTERFACE_H

#pragma once

#include <QAbstractSocket>
#include <QTcpSocket>
#include <QWidget>
#include <QMessageBox>
#include <iostream>

static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext);

class QualisysInterface : public QWidget
{
    Q_OBJECT

    public:
        QualisysInterface();
        ~QualisysInterface();
        QTcpSocket* socket;
    public slots:
        void connectQualisys();
    private slots:
        void readyRead();
        void disconnected();
        void error(int mn);
        void error(QAbstractSocket::SocketError);

        

};
#endif
