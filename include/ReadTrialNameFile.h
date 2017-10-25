#include <QString>
#include <QFile>

class ReadTrialNameFile
{
    public: 
        ReadTrialNameFile(QString);
        ~ReadTrialNameFile();
        QFile* trialNamesConf;
    public slots:
        QString getTrialName();
};

