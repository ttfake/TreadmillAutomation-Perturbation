#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>

class QQuickView;

QT_CHARTS_USE_NAMESPACE

class DataSource : public QObject
{
    Q_OBJECT

    public:
        explicit DataSource(QQuickView *appViewer, QObject *parent = 0);
        void setDataPoints(QVector<double>);

    Q_SIGNALS:

    public slots:
        void update(QAbstractSeries *series);


    private:
        QQuickView *m_appViewer;
        QList<QVector<QPointF> > m_data;
        int m_index;
        QVector<QPointF> points; 
};

#endif // DATASOURCE_H
