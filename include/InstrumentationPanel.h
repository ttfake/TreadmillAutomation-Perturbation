#ifndef INSTRUMENTATIONPANEL_H
#define INSTRUMENTATIONPANEL_H

#pragma once

#include <QDialog>
#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QQuickItem>
#include <QVBoxLayout>
#include <QtDataVisualization>
#include <QtDataVisualization/qutils.h>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QQmlApplicationEngine>
#include <QTabWidget>
#include <QGroupBox>

#include "DataSource.h"
#include "EmgChannel.h"

class InstrumentationPanel : public QDialog
{
    Q_OBJECT


    public:
        InstrumentationPanel(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        ~InstrumentationPanel();
        void                                      closeWindow();
        QObject*                                  instrumentationPanelItem;
        void                                      setChannelDataPoints(QMap<int,QVector<double>> dataPoints);

    public slots:
        void                                      showInstPanel();

    private:


        
        QVBoxLayout*                              instrumentationPanelLayout;
        QTabWidget*                               instTabWidget;
        QQuickView*                               instrumentationPanelQuickView;
        QWidget*                                  instrumentationPanelQuickViewContainer;
        QGridLayout*                              emgTabGridLayout;
        QWidget*                                  emgTab;
        QGroupBox*                                emgGroupBox;
        QHBoxLayout*                              emgGroupBoxHLayout;
        QObject*                                  emgQuickViewItem;
        
        QGroupBox*                                emgGroupBoxCh1To3;
        QVBoxLayout*                              emgGroupBoxCh1To3VLayout;
        
        QGroupBox*                                emgGroupBoxCh4To6;
        QVBoxLayout*                              emgGroupBoxCh4To6VLayout;
        
        QGroupBox*                                emgGroupBoxCh7To8;
        QVBoxLayout*                              emgGroupBoxCh7To8VLayout;

        enum                                      Channels { Ch1, Ch2, Ch3, Ch4, Ch5, Ch6, Ch7, Ch8 };

        QVector<DataSource*>                      chDataSourceVector;
        
        EmgChannel*                               channel1;
        DataSource*                               ch1DataSource;
        EmgChannel*                               channel2;
        DataSource*                               ch2DataSource;
        EmgChannel*                               channel3;
        DataSource*                               ch3DataSource;
        EmgChannel*                               channel4;
        DataSource*                               ch4DataSource;
        EmgChannel*                               channel5;
        DataSource*                               ch5DataSource;
        EmgChannel*                               channel6;
        DataSource*                               ch6DataSource;
        EmgChannel*                               channel7;
        DataSource*                               ch7DataSource;
        EmgChannel*                               channel8;
        DataSource*                               ch8DataSource;

        void                                      createInstrumentationEmgTab();
        void                                      addEMGQuadrant();
        void                                      addEmgDataVisualization();

        int                                       channel;

};
#endif



