#ifndef INSTRUMENTATIONPANEL_H
#define INSTRUMENTATIONPANEL_H

#pragma once

#include <QDialog>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQuickItem>
#include <QVBoxLayout>


class InstrumentationPanel : public QDialog
{
    Q_OBJECT

    public:
        InstrumentationPanel(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~InstrumentationPanel();

        QObject* instrumentationPanelItem;

    private:
        QVBoxLayout* instrumentationPanelLayout;
        QQuickView* instrumentationPanelQuickView;
        QWidget* instrumentationPanelQuickViewContainer;

};
#endif



