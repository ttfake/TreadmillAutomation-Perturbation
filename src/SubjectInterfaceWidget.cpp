#include "SubjectInterfaceWidget.h"

SubjectInterfaceWidget::SubjectInterfaceWidget()
{

    circleColor                 = Qt::red;
    crossColor                  = Qt::blue;
    trialComplete               = false;
    circleDrawnBool             = false;
    runStartedBool              = false;
    changeToCircleBool          = false;
    runOver                     = false;
}

SubjectInterfaceWidget::~SubjectInterfaceWidget()
{

}

void SubjectInterfaceWidget::paintEvent(QPaintEvent* paintEvent)
{
    QPainter painter(this);
    setPainter(&painter);

    if(runStartedBool == true)
    {
        QPoint textLoc(455, 393);
        writeText(Qt::yellow, textLoc, "Please Stand Quietly");
        runStartedBool = false;
    }
    else if (changeToCircleBool == true)
    {
        if(getCircleColor() == Qt::green && trialComplete != true)
        {   drawCircle();
            drawCross();
        }
        if(trialComplete == true)
        {
            QPoint trialCpltTxtLoc(550, 463);
            circleColor = Qt::red;
            drawCircle();
            writeText(Qt::black, trialCpltTxtLoc, "Trial Complete");
        }
        if(runOver == true)
        {
            QPoint trialCpltTxtLoc(620, 463);
            circleColor = Qt::yellow;
            drawCircle();
            writeText(Qt::black, trialCpltTxtLoc, "Run Over");
            trialComplete = false;
            circleDrawnBool = false;
            runStartedBool = false;
            runOver = false;
        }
    }
}

void SubjectInterfaceWidget::runStarted(bool mRunStartedBool)
{
    runStartedBool = mRunStartedBool;
    repaint();
}

void SubjectInterfaceWidget::setPainter(QPainter* painter)
{
    globalPainter = painter;
}

QPainter* SubjectInterfaceWidget::getPainter()
{
    return globalPainter;
}

void SubjectInterfaceWidget::changeToCircle(bool circleBool)
{
    changeToCircleBool = circleBool;
    repaint();
}

void SubjectInterfaceWidget::changeCircleColor(QColor mcolor)
{
    circleColor = mcolor;
    repaint();
}

QColor SubjectInterfaceWidget::getCircleColor()
{
    return circleColor;
}

void SubjectInterfaceWidget::drawCircle()
{
    QPoint circleCenter(770,463);

    globalPainter->setPen(circleColor);
    globalPainter->setBrush(QBrush(circleColor, Qt::SolidPattern));
    globalPainter->drawEllipse(circleCenter, 455, 455);

}

void SubjectInterfaceWidget::drawCross()
{
    static const QPointF horizontalLine[4] = {
        QPointF(720.0, 443),
        QPointF(820.0, 443),
        QPointF(820.0, 453),
        QPointF(720.0, 453)
    };

    static const QPointF verticalLine[4] = {
        QPointF(765.0, 398),
        QPointF(765.0, 498),
        QPointF(775.0, 498),
        QPointF(775.0, 398)
    };

    globalPainter->setPen(Qt::blue);
    globalPainter->setBrush(QBrush(crossColor, Qt::SolidPattern));
    globalPainter->drawPolygon(horizontalLine, 4);
    globalPainter->drawPolygon(verticalLine, 4);
}

void SubjectInterfaceWidget::writeText(QColor mColor, QPoint mTextLoc, QString text)
{
    globalPainter->setPen(mColor);
    globalPainter->setFont(QFont("Arial", 135));
    globalPainter->drawText(mTextLoc, text);
}

void SubjectInterfaceWidget::setTrialComplete(bool mTrialComplete)
{
    trialComplete = mTrialComplete;
    repaint();
}

void SubjectInterfaceWidget::setRunOver(bool mRunOver)
{
    runOver = mRunOver;
    circleDrawnBool = false;
    repaint();
}

#include "../include/moc_SubjectInterfaceWidget.cpp"
