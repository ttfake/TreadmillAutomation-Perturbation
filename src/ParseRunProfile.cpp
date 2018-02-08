#include "ParseRunProfile.h"

ParseRunProfile::ParseRunProfile()
{
    treadmillDb = new TreadmillAutomationDbIFace;
    truncateTable("currentRunProfile");
    connect(treadmillDb, SIGNAL(startStimulation()), SLOT(startStim()));
}

ParseRunProfile::~ParseRunProfile()
{
}

void ParseRunProfile::setRunFile(QString mFileName)
{
    runFile = new QFile(mFileName);
    parseRunFile();
}

void ParseRunProfile::parseRunFile()
{
    treadmillDb->clearRunProfileHeadVector();
    treadmillDb->resetRunsVectorIndex();
    treadmillDb->clearRunResultsVector();
    truncateTable("currentRunProfile");
    QString table("runProfile");
    if(runFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream currentRun(runFile);
        while (!currentRun.atEnd())
        {
            QString line = currentRun.readLine();
            treadmillDb->insertRunProfileRecord(line.split('_'));
        }
        runFile->close();
    }
    else
    {
        qDebug() << "Error opening file";
    }
}

double ParseRunProfile::getAccelLeft()
{
    double accelerationLeft(treadmillDb->getAccelLeft());

    return accelerationLeft;
}

double ParseRunProfile::getAccelLeftDb(QString typeNo, QString levelNo)
{
    return treadmillDb->getAccelLeftFromDb(typeNo, levelNo);
}

double ParseRunProfile::getAccelRight()
{
    double accelerationRight(treadmillDb->getAccelRight());

    return accelerationRight;
}

double ParseRunProfile::getAccelRightDb(QString typeNo, QString levelNo)
{
    return treadmillDb->getAccelRightFromDb(typeNo, levelNo);
}

double ParseRunProfile::getDecelRight()
{
    double decelerationRight(treadmillDb->getDecelRight());

    return decelerationRight;
}

double ParseRunProfile::getDecelRightDb(QString typeNo, QString levelNo)
{
    return treadmillDb->getDecelRightFromDb(typeNo, levelNo);
}

double ParseRunProfile::getDecelLeft()
{
    double decelerationLeft(treadmillDb->getDecelLeft());

    return decelerationLeft;
}

double ParseRunProfile::getDecelLeftDb(QString typeNo, QString levelNo)
{
    return treadmillDb->getDecelLeftFromDb(typeNo, levelNo);
}

double ParseRunProfile::getAccelTime()
{
    double accelTime(treadmillDb->getAccelTime());

    return accelTime;
}

double ParseRunProfile::getAccelTimeDb(QString typeNo)
{
    return treadmillDb->getAccelTimeFromDb(typeNo);
}


void ParseRunProfile::getRuns()
{
    treadmillDb->retrieveRuns();
}

void ParseRunProfile::getRun(int runIndex)
{
    treadmillDb->retrieveRun(runIndex);
}

void ParseRunProfile::startStim()
{
    emit startStimulation();
}

void ParseRunProfile::truncateTable(QString table)
{
    treadmillDb->truncateTable(table);
}

QVector<QString> ParseRunProfile::getRunsVector()
{
    return treadmillDb->getRunResults();
}

QVector<QString> ParseRunProfile::getRunProfileHead()
{
    return treadmillDb->getRunProfileHead();
}

void ParseRunProfile::updateRunTable(QString tableName, QString type, QString level, 
        QString stimOrder, QString participantId, QString sessionNo, QString runNo, 
        QString trialNo)
{
    treadmillDb->updateRunTable(tableName, type, level, 
         stimOrder, participantId, sessionNo, runNo, 
         trialNo);
}

void ParseRunProfile::clearRunResultsVector()
{
    treadmillDb->clearRunResultsVector();
}

int ParseRunProfile::getDirectionFromDb(QString type, QString level)
{
    return treadmillDb->getDirectionFromDb(type, level);
}

QString ParseRunProfile::getStimSeq()
{
    return treadmillDb->getStimSeq();
}

#include "../include/moc_ParseRunProfile.cpp"
