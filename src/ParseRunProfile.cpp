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

void ParseRunProfile::resetRunsVectorIndex()
{
    treadmillDb->resetRunsVectorIndex();
}

void ParseRunProfile::setAccelDecelFromDb()
{
    treadmillDb->setAccelDecelFromDb();
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

double ParseRunProfile::getDecelTime()
{
    double decelTime(treadmillDb->getDecelTime());
    return decelTime;
}

double ParseRunProfile::getDecelTimeDb(QString typeNo)
{
    return treadmillDb->getDecelTimeFromDb(typeNo);
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

bool ParseRunProfile::compareDbWithRunTable(QString typeNo, QString levelNo)
{
    bool checkPassed;

    double leftAccel = getAccelLeftDb(typeNo, levelNo);
    double rightAccel = getAccelRightDb(typeNo, levelNo);
    double leftDecel = getDecelLeftDb(typeNo, levelNo);
    double rightDecel = getDecelRightDb(typeNo, levelNo);
    
    if(treadmillDb->getDirectionFromDb(typeNo, levelNo) == 0)
    {
        leftAccel = -leftAccel;
        rightAccel = -rightAccel;
        leftDecel = -leftDecel;
        rightDecel = -rightDecel;
    }

    qDebug() << "leftAccel: " << leftAccel;
    qDebug() << "getAccelLeft: " << getAccelLeft();
    qDebug() << "rightAccel: " << rightAccel;  

    checkPassed = leftAccel == getAccelLeft() &&
        accelValue == getAccelLeft() &&
        rightAccel == getAccelRight() && 
        accelValue == getAccelRight() &&
        leftDecel == getDecelLeft() &&
        decelValue == getDecelLeft() &&
        rightDecel == getDecelRight() && 
        decelValue == getDecelRight();

    return checkPassed;
}

void ParseRunProfile::setAccelDecelFromAccelDecelSpinBox(double maccelValue, double mdecelValue)
{
    accelValue = maccelValue;
    decelValue = mdecelValue;
}

void ParseRunProfile::updateRunTable(QString tableName, QString setString, QString whereString)
    //QString type, QString level, 
    //QString stimOrder, QString participantId, QString sessionNo, QString runNo, 
    //QString trialNo)
{
    treadmillDb->updateRunTable(tableName, setString, whereString); 
            //type, level, 
         //stimOrder, participantId, sessionNo, runNo, 
         //trialNo);
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
