#ifndef NETWORK_H
#define NETWORK_H

#include <windows.h>
#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QAbstractSocket>
#include <QByteArray>
#define  WIN32_LEAN_AND_MEAN
#define WAIT_FOR_DATA_TIMEOUT      5000000 // 5 s

class COutput;

class CNetwork : public QWidget
{
    Q_OBJECT
public:
    CNetwork();
    ~CNetwork();

    bool  qualisysConnect(char* pServerAddr, unsigned short nPort);
    void  Disconnect();
    bool  Connected();
    int   Receive(char* rtDataBuff, int nDataBufSize, bool bHeader, int nTimeout = WAIT_FOR_DATA_TIMEOUT, unsigned int *ipAddr = NULL);
    bool  Send(const char* pSendBuf, int nSize);
    char* GetErrorString();
    int   GetError();
    bool  IsLocalAddress(unsigned int nAddr);
    
public slots:
    void readyRead();

    

private:
    COutput*        mpoOutput;
    QTcpSocket*     mhSocket;
    char            maErrorStr[256];
    unsigned long   mnLastError;
    char            maDataBuff[65536];
    void            SetErrorString();
};


#endif
