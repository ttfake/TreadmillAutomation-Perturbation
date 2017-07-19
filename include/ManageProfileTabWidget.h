#ifndef MANAGEPROFILEWIDGET_H
#define MANAGEPROFILEWIDGET_H
#include <QGraphicsScene>

class ManageProfileTabWidget : public QObject
{
    Q_OBJECT

    public:
        ManageProfileTabWidget();
        ~ManageProfileTabWidget();

    private:
        QGraphicsScene* scene;


};
#endif
