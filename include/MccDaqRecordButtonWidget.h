#ifndef MCCDAQRECORDBUTTONWIDGET_H
#define MCCDAQRECORDBUTTONWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QHBoxLayout>
#include <QPushButton>

class MccDaqRecordButtonWidget : public QPushButton
{
    Q_OBJECT
        
    public:
        MccDaqRecordButtonWidget();
        ~MccDaqRecordButtonWidget();
        void changeDaqRecordLight(QColor mcolor);
        QColor getDaqRecordLightColor();

    private:
        void paintEvent(QPaintEvent* paintEvent) override;
        QHBoxLayout* mccDaqRecordButtonWidgetLayout; 
        QColor color;
};
#endif
