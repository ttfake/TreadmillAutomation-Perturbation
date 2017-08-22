#ifndef QUALISYSINTERFACE_H
#define QUALISYSINTERFACE_H

#pragma once

#include <QAbstractSocket>
#include <QTcpSocket>
#include <QWidget>

class QualisysInterface : public QWidget
{
    public:
        QualisysInterface();
        ~QualisysInterface();
    private slots:
        void readyRead();

};
#endif
