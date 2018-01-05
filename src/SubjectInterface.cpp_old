#include "../include/SubjectInterface.h"

SubjectInterface::SubjectInterface()
{
    resize(1580, 1100);
    SubjectInterfaceLayout = new QVBoxLayout;
    setLayout(SubjectInterfaceLayout);
    setAutoFillBackground(true);
    QPalette* pal = new QPalette;
    pal->setColor(QPalette::Background, Qt::black);
    setPalette(*pal);
    sIFaceWidget = new SubjectInterfaceWidget;
    SubjectInterfaceLayout->addWidget(sIFaceWidget);

    show();
}

SubjectInterface::~SubjectInterface()
{
}

void SubjectInterface::startTrialRun(bool runStartedBool)
{
    sIFaceWidget->runStarted(runStartedBool);
}

void SubjectInterface::changeToCircle(bool circleBool)
{
    sIFaceWidget->changeToCircle(circleBool);
}

void SubjectInterface::changeCircleColor(QColor circleColor)
{
    sIFaceWidget->changeCircleColor(circleColor);
}

void SubjectInterface::setTrialComplete(bool mTrialComplete)
{
    sIFaceWidget->setTrialComplete(mTrialComplete);
}

void SubjectInterface::setRunOver(bool mRunOver)
{
    sIFaceWidget->setRunOver(mRunOver);
}

#include "../include/moc_SubjectInterface.cpp"

