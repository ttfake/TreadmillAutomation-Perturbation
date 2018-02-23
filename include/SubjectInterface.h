#ifndef SUBJECTINTERFACE_H
#define SUBJECTINTERFACE_H

#pragma once

#include <QDialog>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQuickItem>

#include "../include/SubjectInterfaceWidget.h"


class SubjectInterface : public QDialog
{
    Q_OBJECT

    public:
        SubjectInterface(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~SubjectInterface();

        void changeCircleColor(QColor circleColor);
        void setTrialComplete(bool mTrialComplete);
        void startTrialRun(bool runStartedBool);
        void setRunOver(bool mRunOver);
        QObject *subjectIfaceItem;
        void updateTextField(QString newText);
        void updateTextColor(QString color);

        public slots:
            void changeToCircle();
            void hideRedCircle();

    private:
        QVBoxLayout* SubjectInterfaceLayout;
        QQuickView* subjectQuickView;
        QWidget* subjectQuickViewContainer;

};
#endif



