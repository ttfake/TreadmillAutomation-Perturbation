#include "QmlInterface.h"

QmlInterface::QmlInterface()
{
}

QString QmlInterface::userName()
{
    return m_userName;
}

void QmlInterface::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}

#include "../include/moc_QmlInterface.cpp"
