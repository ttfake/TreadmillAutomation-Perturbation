#include "ReadTrialNameFile.h"

ReadTrialNameFile::ReadTrialNameFile(QString trialNamesFile)
{
    trialNamesConf = new QFile(trialNamesFile);
    trialNamesConf->open(QIODevice::ReadOnly);
}

ReadTrialNameFile::~ReadTrialNameFile()
{
}

QString ReadTrialNameFile::getTrialName()
{
    QString testString(trialNamesConf->readLine());

    return testString;
}
