#include "TreadmillAutomationDbIFace.h"

TreadmillAutomationDbIFace::TreadmillAutomationDbIFace()
{
    runsVectorIndex_ = 0;
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        qDebug() << "Driver Available";
        db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("TreadmillAutomation.db");
        qDebug() << "Opening Database";
        if(!db.open())
        {
            qWarning() << "ERROR: " << db.lastError();
        }
        qDebug() << "Database open";
    }
    else
    {
        qDebug() << "Driver Not Available";
    }
}

TreadmillAutomationDbIFace::~TreadmillAutomationDbIFace()
{
}

void TreadmillAutomationDbIFace::insertRunProfileRecord(QStringList recordList)
{
    QRegularExpression numbers("^(.)([0-9]+)$|^(.)([A-Z])([0-9]+$)");//(".(\\d+)+");
    QString table("runProfile");
    QString currentRunProfileTable("currentRunProfile");
    QString columns("dateTime, participantId, session, runNo, type, level, stimOrder, trial");
    QDateTime dateTime = QDateTime::currentDateTime();
    QString values;
    values += "\"" + dateTime.toString() + "\"" + ",";
    for(const auto& item : recordList)
    {
    //    qDebug() << item;
        QRegularExpressionMatchIterator numIter = numbers.globalMatch(item);
        while (numIter.hasNext()) 
        {
            QRegularExpressionMatch match = numIter.next();
            QString word = match.captured(0);
            values += "\"" + word + "\"" + ",";
        }
    }
    values.chop(1);
    //qDebug() << values;
    insertRecord(table, columns, values);
    insertRecord(currentRunProfileTable, columns, values);
}

void TreadmillAutomationDbIFace::truncateTable(QString table)
{
    QSqlQuery query;
    QString queryString("DELETE FROM " + table);
    query.prepare(queryString);
    if(!query.exec(queryString))
    {
        qWarning() << "ERROR: " << query.lastError().text();
    }
}

void TreadmillAutomationDbIFace::insertRecord(QString table, QString columns, QString values)
{
    QSqlQuery query;
    QString queryString("INSERT INTO " + table + "(" + columns + ")" + " VALUES(" + values +  ")");
    //qDebug() << queryString;
    query.prepare(queryString);

    if(!query.exec(queryString))
    {
        qWarning() << "ERROR: " << query.lastError().text();
    }

}

double TreadmillAutomationDbIFace::getAccelLeftFromDb(QString typeNum, QString levelNum)
{
    QString columns("accelerationLeft");
    QString table("runLevel");
    QString where(" WHERE typeNo=" + typeNum + " AND levelNo=" + levelNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);
    QString accel;

    if(query.first())
    {
        accel = query.value(0).toString();
    }
    else
    {
        accel = "Acceleration Not Found";
    }

    return accel.toDouble();
}

double TreadmillAutomationDbIFace::getAccelRightFromDb(QString typeNum, QString levelNum)
{
    QString columns("accelerationRight");
    QString table("runLevel");
    QString where(" WHERE typeNo=" + typeNum + " AND levelNo=" + levelNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);
    QString accel;

    if(query.first())
    {
        accel = query.value(0).toString();
    }
    else
    {
        accel = "Acceleration Not Found";
    }

    return accel.toDouble();
}


void TreadmillAutomationDbIFace::setAccelLeft(double accel)
{
    accelerationLeft = accel;
}

double TreadmillAutomationDbIFace::getAccelLeft()
{
    return accelerationLeft;
}

void TreadmillAutomationDbIFace::setAccelRight(double accel)
{
    accelerationRight = accel;
}

double TreadmillAutomationDbIFace::getAccelRight()
{
    return accelerationRight;
}

double TreadmillAutomationDbIFace::getAccelTimeFromDb(QString typeNum)
{
    QString columns("accelerationTime");
    QString table("runType");
    QString where(" WHERE typeNo=" + typeNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);
    QString accelerationTime;

    if(query.first())
    {
        accelerationTime = query.value(0).toString();
    }
    else
    {
        accelerationTime = "Acceleration Time Not Found";
    }

    return accelerationTime.toDouble();
}

void TreadmillAutomationDbIFace::setAccelTime(double accelTime)
{
    accelerationTime = accelTime;
}

double TreadmillAutomationDbIFace::getAccelTime()
{
    return accelerationTime;
}

double TreadmillAutomationDbIFace::getDecelLeftFromDb(QString typeNum, QString levelNum)
{
    QString columns("decelerationLeft");
    QString table("runLevel");
    QString where(" WHERE typeNo=" + typeNum + " AND levelNo=" + levelNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);
    QString decel;

    if(query.first())
    {
        decel = query.value(0).toString();
    }
    else
    {
        decel = "Deceleration Not Found";
    }

    return decel.toDouble();
}

double TreadmillAutomationDbIFace::getDecelRightFromDb(QString typeNum, QString levelNum)
{
    QString columns("decelerationLeft");
    QString table("runLevel");
    QString where(" WHERE typeNo=" + typeNum + " AND levelNo=" + levelNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);
    QString decel;

    if(query.first())
    {
        decel = query.value(0).toString();
    }
    else
    {
        decel = "Deceleration Not Found";
    }

    return decel.toDouble();
}


void TreadmillAutomationDbIFace::setDecelLeft(double decel)
{
    decelerationLeft = decel;
}

double TreadmillAutomationDbIFace::getDecelLeft()
{
    return decelerationLeft;
}

void TreadmillAutomationDbIFace::setDecelRight(double decel)
{
    decelerationRight = decel;
}

double TreadmillAutomationDbIFace::getDecelRight()
{
    return decelerationRight;
}

double TreadmillAutomationDbIFace::getDecelTimeFromDb(QString typeNum)
{
    QString columns("decelerationTime");
    QString table("runType");
    QString where(" WHERE typeNo=" + typeNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);
    QString decelerationTime;

    if(query.first())
    {
        decelerationTime = query.value(0).toString();
    }
    else
    {
        decelerationTime = "Deceleration Time Not Found";
    }

    return decelerationTime.toDouble();
}

void TreadmillAutomationDbIFace::retrieveRuns()
{
    runsQuery = selectQueryDb("type,level,stimOrder", "currentRunProfile", false);

    while(runsQuery.next())
    {
        qDebug() << "Query Found";
        runResults.append(QString(runsQuery.value(0).toString() + "," + runsQuery.value(1).toString()));
    }
    
}

void TreadmillAutomationDbIFace::retrieveRun(int runAddIndex)
{
    if(runAddIndex < 0)
    {
        runsVectorIndex_ += runAddIndex;
    }
    
    if(runsVectorIndex_ < runResults.size() and runsVectorIndex_ >= 0)
    {
        qDebug() << runsVectorIndex_;
        QString type;
        QString level;
        QRegularExpression numbers("^.*([0-9]$)");
        QString run = runResults[runsVectorIndex_];
        QRegularExpressionMatchIterator typeNumIter = numbers.globalMatch(run.split(',')[0]);
        QRegularExpressionMatchIterator levelNumIter = numbers.globalMatch(run.split(',')[1]);

        while (typeNumIter.hasNext()) 
        {
            QRegularExpressionMatch match = typeNumIter.next();
            type = match.captured(1);
        }

        while (levelNumIter.hasNext()) 
        {
            QRegularExpressionMatch match = levelNumIter.next();
            level = match.captured(1);
        }

        if(getDirectionFromDb(type,level) == 0)
        {
            setAccelLeft(-(getAccelLeftFromDb(type,level)));
            qDebug() << "Accel Left: " << getAccelLeft();
            setAccelRight(-(getAccelRightFromDb(type,level)));
            setDecelLeft(-(getDecelLeftFromDb(type,level)));
            setDecelRight(-(getDecelRightFromDb(type,level)));
        }
        else
        {
            setAccelLeft(getAccelLeftFromDb(type,level));
            setAccelRight(getAccelRightFromDb(type,level));
            setDecelLeft(getDecelLeftFromDb(type,level));
            setDecelRight(getDecelRightFromDb(type,level));
        }

        setAccelTime(getAccelTimeFromDb(type));
        emit startStimulation();
        runsVectorIndex_ += 1;
    }

    else if (runsVectorIndex_ > runResults.size())
    {
        QMessageBox endRun;
        endRun.setText("The Run is Complete.");
        endRun.exec();

    }
    else if (runsVectorIndex_ < 0)
    {
        QMessageBox startRun;
        startRun.setText("This is the first Trial.");
        startRun.exec();
    }
}

QSqlQuery TreadmillAutomationDbIFace::selectQueryDb(QString columns, QString table, bool whereBool, QString where)
{
    QSqlQuery query;
    QString queryString;

    if(whereBool)
    {
        queryString = "SELECT " + columns + " FROM " + table + where;
    }
    else
    {
        queryString = "SELECT " + columns + " FROM " + table;
    }

    qDebug() << queryString;
    query.prepare(queryString);

    if(!query.exec(queryString))
    {
        qWarning() << "ERROR: " << query.lastError().text();
    }

    return query;
}

int TreadmillAutomationDbIFace::getDirectionFromDb(QString typeNum, QString levelNum)
{
    QString dirNum;
    QString columns = "typeNo,direction";
    QString table = "runType";
    QString where(" WHERE typeNo=" + typeNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);

    if(query.first())
    {
        dirNum = query.value(1).toString();
    }
    else
    {
        qDebug() << "Direction Not Found";
    }

   // qDebug() << direction.keyToValue("PA");

    return dirNum.toInt();
}

int TreadmillAutomationDbIFace::getDir()
{
    return direction;
}

void TreadmillAutomationDbIFace::setDir(int dir)
{
    direction = dir;
}

int TreadmillAutomationDbIFace::getParticipantMotionFromDb(QString typeNum, QString levelNum)
{
    QString parNum;
    QString columns = "typeNo,participantMotion";
    QString table = "runType";
    QString where(" WHERE typeNo=" + typeNum + " AND levelNo=" + levelNum);
    QSqlQuery query = selectQueryDb(columns, table, true, where);

    if(query.first())
    {
        parNum = query.value(1).toString();
    }
    else
    {
        qDebug() << "Participan Motion Not Found";
    }

   // qDebug() << direction.keyToValue("PA");

    return parNum.toInt();
}

#include "../include/moc_TreadmillAutomationDbIFace.cpp"
