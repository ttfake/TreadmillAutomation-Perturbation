#include "Datasource.h"
#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QDebug>
#include <QtCore/QRandomGenerator>
#include <QtCore/QtMath>

QT_CHARTS_USE_NAMESPACE

Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)

DataSource::DataSource(QQuickView *appViewer, QObject *parent) :
    QObject(parent),
    m_appViewer(appViewer),
    m_index(-1)
{
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();

//    generateData(0, 5, 1024);
}

void DataSource::update(QAbstractSeries *series)
{
    if (series) {
        QXYSeries *xySeries = static_cast<QXYSeries *>(series);
//        m_index++;
//        if (m_index > m_data.count() - 1)
//            m_index = 0;

//        QVector<QPointF> points = m_data.at(m_index);
        
        // Use replace instead of clear + append, it's optimized for performance
        //qDebug() << points[0];
        xySeries->replace(points);
    }
}

void DataSource::setDataPoints(QVector<double> dataPoints)
{
    int x = 0;
    points.clear();
    for(auto& dp : dataPoints)
    {
        //qDebug() << dp;
        QPointF dataPair(x,dp);
        points.append(dataPair);
        x++;
    }
}

#include "../include/moc_DataSource.cpp"
