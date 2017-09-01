
#include "../../include/RTClientSDK/Network.h"

#include <stdio.h>
#include <iphlpapi.h>
#include <Ws2tcpip.h>

CNetwork::CNetwork()
{
    mhSocket             = new QTcpSocket;
}


CNetwork::~CNetwork()
{
}

bool CNetwork::qualisysConnect(char* pServerAddr, unsigned short nPort)
{
    QString qualisysHost(pServerAddr);
    mhSocket->connectToHost(pServerAddr, nPort);
    connect(mhSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    return true;
} // Connect


void CNetwork::Disconnect()
{
    // Try to shutdown gracefully

    
} // Disconnect


bool CNetwork::Connected()
{
	return true;
}

// Receive a data packet. Data is stored in a local static buffer
// Returns number of bytes in received message, 0 on timeout or -1 if there is an error. 
int CNetwork::Receive(char* rtDataBuff, int nDataBufSize, bool bHeader, int nTimeout, unsigned int *ipAddr)
{
    int         nRecved = 0;
    QByteArray incomingData;
    
    nRecved = mhSocket->bytesAvailable();
    incomingData = mhSocket->readAll();
    rtDataBuff = incomingData.data();  

    return nRecved;
} // RecvMessage


bool CNetwork::Send(const char* pSendBuf, int nSize)
{
    int         nSent      = 0;
    int         nTotSent   = 0;

    while (nTotSent < nSize)
    {
       // nSent = send(mhSocket, pSendBuf + nTotSent, nSize - nTotSent, 0);
        if (nSent == SOCKET_ERROR)
        {
            SetErrorString();
            return false;
        }
        nTotSent += nSent;
    }

    return true;
} // Send



void CNetwork::SetErrorString()
{ 
    char *tError = NULL; 
    mnLastError  = GetLastError(); 
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
                  NULL, mnLastError, 0, reinterpret_cast<LPTSTR>(&tError), 0, NULL); 

    sprintf_s(maErrorStr, sizeof(maErrorStr), "%s", tError); 

    LocalFree(tError);
}


char* CNetwork::GetErrorString()
{
    return maErrorStr;
}


int CNetwork::GetError()
{
    return mnLastError;
}


bool CNetwork::IsLocalAddress(unsigned int nAddr)
{
    
    return false;
}

void CNetwork::readyRead()
{
    qDebug("Data Detected...");
    qDebug("Receiving...");
    Receive(maDataBuff, sizeof(maDataBuff), true);
    qDebug("Received: %s", maDataBuff);
}

#include "../../include/RTClientSDK/moc_Network.cpp"
