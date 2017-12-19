#ifndef PARSERUNPROFILE_H
#define PARSERUNPROFILE_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

#include "TreadmillAutomationDbIFace.h"

class ParseRunProfile : public QWidget
{
    Q_OBJECT

    public:
        ParseRunProfile();
        ~ParseRunProfile();
        void parseRunFile();
        double getAccelLeft();
        double getAccelRight();
        double getAccelTime();
        double getDecelLeft();
        double getDecelRight();
        double getDecelTime();
        void getRuns();
        void getRun(int runIndex);
        void truncateTable(QString table);
        void setRunFile(QString mRunFile);

    signals:
        startStimulation();

    public slots:
        void startStim();
    
    private:
        QFile* runFile;
        TreadmillAutomationDbIFace* treadmillDb;
};
#endif
