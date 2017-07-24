#include "MccDaqConnectButtonWidget.h"

MccDaqConnectButtonWidget::MccDaqConnectButtonWidget()
{

    color = Qt::red;

}

MccDaqConnectButtonWidget::~MccDaqConnectButtonWidget()
{

}

void MccDaqConnectButtonWidget::paintEvent(QPaintEvent* paintEvent)
{

    QPushButton::paintEvent(paintEvent);

    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 15));
    painter.setPen(Qt::blue);
    static const QPointF trianglePoints[4] = {
        QPointF(155,13),
        QPointF(160,28),
        QPointF(160,28),
        QPointF(165,13)
               
    };
    
    painter.setPen(color);
    painter.setBrush(QBrush(color, Qt::SolidPattern));
    painter.drawPolygon(trianglePoints, 4);

}

void MccDaqConnectButtonWidget::changeDaqConnectLight(QColor mcolor)
{

    color = mcolor;
    repaint();

}

#include "../include/moc_MccDaqConnectButtonWidget.cpp"
