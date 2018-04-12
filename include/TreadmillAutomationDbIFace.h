#ifndef TREADMILLAUTOMATIONDBIFACE_H
#define TREADMILLAUTOMATIONDBIFACE_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QMessageBox>

class TreadmillAutomationDbIFace : public QWidget
{
    Q_OBJECT

    public:

        enum Direction {
            AP,
            PA
        };

        TreadmillAutomationDbIFace();
        ~TreadmillAutomationDbIFace();
        void insertRunProfileRecord(QStringList recordList);
        void insertRecord(QString table, QString columns, QString values);
        void getParticipantId();
        void getSessionNo();
        void getRunNo();
        void getTypeNo();
        void getLevelNo();
        void getStimOrder();
        void getTrialNo();
        
        double getAccelLeft();
        double getAccelRight();
        double getAccelTime();
        double getDecelTime();
        double getDecelLeft();
        double getDecelRight();
        QVector<QString> getRunResults();

        int getDir();
        
        QSqlQuery selectQueryDb(QString columns, QString table, bool whereBool=false, QString where="empty");
        void truncateTable(QString table);
        void retrieveRuns();
        void retrieveRun(int runAddIndex);
        QSqlQuery runsQuery;
        QVector<QString> getRunProfileHead();
        void updateRunTable(QString tableName, QString setString, QString whereString);
                //QString type, QString level, 
                //QString stimOrder, QString participantId, QString sessionNo, QString runNo, 
                //QString trialNo);
        void clearRunResultsVector();
        double getAccelLeftFromDb(QString typeNum, QString levelNum);
        void setAccelLeft(double accel);
        void setAccelRight(double accel);
        double getAccelRightFromDb(QString typeNum, QString levelNum);

        void setAccelTime(double accelTime);
        void setDecelTime(double mdecelTime);
        double getAccelTimeFromDb(QString typeNum);
       
        void setDecelLeft(double decel);
        double getDecelLeftFromDb(QString typeNum, QString levelNum);

        void setDecelRight(double decel);
        double getDecelRightFromDb(QString typeNum, QString levelNum);

        double getDecelTimeFromDb(QString typeNum);

        int getParticipantMotionFromDb(QString typeNum, QString levelNum);
        int getDirectionFromDb(QString type, QString level);

        void setStimSeq(QString stim);
        QString getStimSeq();
        QString getStimSeqFromDb(int stimLvl);

        QString stimSeq;

        void clearRunProfileHeadVector();

        void resetRunsVectorIndex();
        void setAccelDecelFromDb();

    
    signals:
        startStimulation();
    
    private:
        QSqlDatabase db;
        QVector<QString> runResults;
        QVector<QString> runProfileHead;
        int runsVectorIndex_ = 0;
        double accelerationLeft;
        double accelerationRight;
        double decelerationLeft;
        double decelerationRight;
        double accelerationTime;
        double decelerationTime;
        int direction;
        
        void setDir(int dir);
        

        
        bool firstRun;





};
#endif

