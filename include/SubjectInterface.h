#ifndef SUBJECTINTERFACE_H
#define SUBJECTINTERFACE_H

#pragma once

#include <QDialog>

#include "../include/SubjectInterfaceWidget.h"


class SubjectInterface : public QDialog
{
    Q_OBJECT

    public:
        SubjectInterface();
        ~SubjectInterface();

        SubjectInterfaceWidget* sIFaceWidget;
        void changeToCircle(bool circleBool);
        void changeCircleColor(QColor circleColor);
        void setTrialComplete(bool mTrialComplete);
        void startTrialRun(bool runStartedBool);
        void setRunOver(bool mRunOver);


    private:
        QVBoxLayout* SubjectInterfaceLayout;

};
#endif



