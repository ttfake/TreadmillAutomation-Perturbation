#ifndef EMGCHANNEL_H
#define EMGCHANNEL_H 

/*

#include <QtDataVisualization/qutils.h>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
*/

#include <QWidget>
#include <QGuiApplication>
#include <QtWidgets/QApplication>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtCore/QDir>
#include <QQuickItem>
#include <QtDataVisualization>

#include "include/DataSource.h"



class EmgChannel : public QWidget
{
    Q_OBJECT

    public:
        EmgChannel(QWidget* parent = 0, Qt::WindowFlags flags = 0, QString qmlFile = "Empty QML", 
                QString channelNo = "Empty Channel", DataSource* dsource = 0, 
                QQuickView* channelQuickView = 0);
        ~EmgChannel();

    private:
        QString                                   mChannelNo;
        QWidget*                                  channelQuickViewContainer;
        QQuickItem*                               channelQuickViewItem;
};
#endif
