#include "MccDaqRecordButtonWidget.h"

MccDaqRecordButtonWidget::MccDaqRecordButtonWidget()
{

    color = Qt::red;

}

MccDaqRecordButtonWidget::~MccDaqRecordButtonWidget()
{

}

void MccDaqRecordButtonWidget::paintEvent(QPaintEvent* paintEvent)
{

    QPushButton::paintEvent(paintEvent);

    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 15));
    painter.setPen(Qt::blue);
    QPoint circleCenter(155,13);
               
    painter.setPen(color);
    painter.setBrush(QBrush(color, Qt::SolidPattern));
    painter.drawEllipse(circleCenter, 5, 5);

}

void MccDaqRecordButtonWidget::changeDaqRecordLight(QColor mcolor)
{

    color = mcolor;
    repaint();

}

QColor MccDaqRecordButtonWidget::getDaqRecordLightColor()
{
    return color;
}

#include "../include/moc_MccDaqRecordButtonWidget.cpp"
