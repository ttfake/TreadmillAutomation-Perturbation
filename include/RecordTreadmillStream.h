#ifndef RECORDTREADMILLSTREAM_H
#define RECORDTREADMILLSTREAM_H

#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QTcpSocket>
#include <QPlainTextEdit>
#include <QMessageBox>
#include <QPainter>
#include <QFileDialog>
#include <QTextStream>
#include <QTime>
#include <QAbstractSocket>
#include "include/MccDaqRecordButtonWidget.h"

static void showWarning(QWidget * parent, const QString & title, const QString & text);

class RecordTreadmillStream : public QMainWindow
{ 
    Q_OBJECT
    public:
        RecordTreadmillStream(QWidget *parent = 0, Qt::WindowFlags flags = 0);
        ~RecordTreadmillStream();
        void setSocket(QAbstractSocket* msocket);
        void stopRecord();
    public slots:
        void readyRead();
        void setRecord();

    private:
        void populateRecordStreamGroupBox();
        QWidget* centralWidget;
        QVBoxLayout* centralWidgetLayout;
        QAbstractSocket* socket;
        QGroupBox* recordGroupBox;
        QVBoxLayout* recordGroupBoxVerticalLayout;
        QFont recordGroupBoxFont;
        QGroupBox* networkGroupBox;
        QHBoxLayout* networkGroupBoxLayout;
        QLabel* hostLabel;
        QPlainTextEdit* hostPlainTextEdit;
        QLabel* portLabel;
        QPlainTextEdit* portPlainTextEdit;
        MccDaqRecordButtonWidget* networkConnectButton;
        QGroupBox* speedGroupBox;
        QHBoxLayout* speedGroupBoxLayout;
        QLabel* leftSpeedLabel;
        QLabel* rightSpeedLabel;
        QLabel* leftSpeedFeedback;
        QLabel* rightSpeedFeedback;
        QGroupBox* recordButtonGroupBox;
        QHBoxLayout* recordButtonGroupBoxLayout;
        MccDaqRecordButtonWidget* recordButton;
        bool recordBool;
        QFile* velocityDataFile;
        void setVelocityFileName();


};
#endif
