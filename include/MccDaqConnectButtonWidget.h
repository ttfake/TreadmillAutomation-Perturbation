#ifndef MCCDAQCONNECTBUTTONWIDGET_H
#define MCCDAQCONNECTBUTTONWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QPushButton>

class MccDaqConnectButtonWidget : public QPushButton
{
    Q_OBJECT
        
    public:
        MccDaqConnectButtonWidget();
        ~MccDaqConnectButtonWidget();
        void changeDaqConnectLight(QColor mcolor);
        QColor getDaqConnectLightColor();

    private:
        void paintEvent(QPaintEvent* paintEvent) override;
        QHBoxLayout* mccDaqConnectButtonWidgetLayout; 
        QColor color;



};
#endif
