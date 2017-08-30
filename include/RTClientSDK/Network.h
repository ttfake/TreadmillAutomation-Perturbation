#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>
#include <windows.h>
#include <QTcpSocket>
#include <QString>
#include <QAbstractSocket>
#include <QByteArray>
#define  WIN32_LEAN_AND_MEAN


class COutput;

class CNetwork
{
public:
    CNetwork();
    ~CNetwork();
    bool  Connect(char* pServerAddr, unsigned short nPort);
    void  Disconnect();
    bool  Connected();
    int   Receive(char* rtDataBuff, int nDataBufSize, bool bHeader, int nTimeout, unsigned int *ipAddr = NULL);
    bool  Send(const char* pSendBuf, int nSize);
    char* GetErrorString();
    int   GetError();
    bool  IsLocalAddress(unsigned int nAddr);

private:
    
    void SetErrorString();
    

private:
    COutput*   mpoOutput;
    QTcpSocket*     mhSocket;
    char       maErrorStr[256];
    unsigned long      mnLastError;
};


#endif
