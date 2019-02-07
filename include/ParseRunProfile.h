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
        void getRun(int currentRunRowIndex, int runIndex);
        void truncateTable(QString table);
        void setRunFile(QString mRunFile);
        QVector<QString> getRunsVector();
        QVector<QString> getRunProfileHead();
        void updateRunTable(QString tableName, QString setString, QString whereString);//QString type, QString level, 
//        QString stimOrder, QString participantId, QString sessionNo, QString runNo, 
//        QString trialNo);
        void clearRunResultsVector();
        double getAccelLeftDb(QString typeNo, QString levelNo);
        double getAccelRightDb(QString typeNo, QString levelNo);
        double getDecelLeftDb(QString typeNo, QString levelNo);
        double getDecelRightDb(QString typeNo, QString levelNo);
        double getAccelTimeDb(QString typeNo);
        double getDecelTimeDb(QString typeNo);
        int getDirectionFromDb(QString type, QString level);
        QString getStimSeq();
        bool compareDbWithRunTable(QString typeNo, QString levelNo);
        void setAccelDecelFromAccelDecelSpinBox(double maccelValue, double mdecelValue);
        void resetRunsVectorIndex();
        void setAccelDecelFromDb();

    signals:
        startStimulation();

    public slots:
        void startStim();
    
    private:
        QFile* runFile;
        TreadmillAutomationDbIFace* treadmillDb;
        double accelValue;
        double decelValue;
};
#endif
