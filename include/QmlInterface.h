#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QString>

class QmlInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit QmlInterface();

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // QMLINTERFACE_H
