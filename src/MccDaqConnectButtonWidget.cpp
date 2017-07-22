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
        QPointF(105,13),
        QPointF(110,28),
        QPointF(110,28),
        QPointF(115,13)
               
    };

    
    painter.setPen(color);
    painter.setBrush(QBrush(color, Qt::SolidPattern));
    painter.drawPolygon(trianglePoints, 4);

//    painter.drawLine(20,20,30,50);
//    painter.drawLine(30,50,40,20);
//    painter.drawLine(20,20,40,20);

}

void MccDaqConnectButtonWidget::changeDaqConnectLight(QColor mcolor)
{

    color = mcolor;
    repaint();

}

#include "../include/moc_MccDaqConnectButtonWidget.cpp"
