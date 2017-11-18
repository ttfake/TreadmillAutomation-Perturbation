#ifndef SUBJECTINTERFACEWIDGET_H
#define SUBJECTINTERFACEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

class SubjectInterfaceWidget : public QWidget
{
    Q_OBJECT
        
    public:
        SubjectInterfaceWidget();
        ~SubjectInterfaceWidget();
        void changeToCircle(bool circleBool);
        void changeCircleColor(QColor mcolor);
        void changePicture();
        QColor getCircleColor();
        void setTrialComplete(bool mTrialComplete);
        void setRunOver(bool mRunOver);
        void runStarted(bool mRunStartedBool);

    private:
        QPainter* globalPainter;
        QHBoxLayout* subjectInterfaceWidgetLayout; 
        QColor circleColor;
        QColor crossColor;
        bool runStartedBool;
        bool circleDrawnBool;
        bool trialComplete;
        bool runOver;
        void paintEvent(QPaintEvent* paintEvent) override;
        bool changeToCircleBool;
        void drawCircle();
        void drawCross();
        void writeText(QColor mColor, QPoint mTextLoc, QString text);
        void setPainter(QPainter* painter);
        QPainter* getPainter();


};
#endif
