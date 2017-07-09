#include "SendSetpoints.h"

SendSetpoints* SendSetpoints::_sendSetpoints = 0;

void SendSetpoints::setUseLibraryStatus(bool useLibCheckBox)
{
    useLibraryCheckBoxStatus = useLibCheckBox;
}

SendSetpoints* SendSetpoints::getInstance()
{
    if(_sendSetpoints == NULL)
    {
        _sendSetpoints = new SendSetpoints();
    }

    return _sendSetpoints;
}

void SendSetpoints::setSocket(QAbstractSocket* mSocket)
{
    pertSocket = mSocket;
}

double SendSetpoints::getAccelerationValue()
{

    return accelerationValue;

}

void SendSetpoints::setAccelerationValue(double maccelerationValue)
{
    accelerationValue = maccelerationValue;

}

double SendSetpoints::getDecelerationValue()
{

    return decelerationValue;
}

void SendSetpoints::setDecelerationValue(double mDecelValue)
{
    decelerationValue = mDecelValue;
}

void SendSetpoints::setRightFrontSpeedValue(double mrightFrontSpeedValue)
{

    rightSpeedFrontValue = mrightFrontSpeedValue;

}

double SendSetpoints::getRightFrontSpeedValue()
{

    return rightSpeedFrontValue;

}

void SendSetpoints::setLeftFrontSpeedValue(double mleftFrontSpeedValue)
{

    leftSpeedFrontValue = mleftFrontSpeedValue;

}

double SendSetpoints::getLeftFrontSpeedValue()
{

    return leftSpeedFrontValue;
}


void SendSetpoints::sendSetpoints(TreadmillProperty mproperty, SetpointType mt)
{

/*	if (lftRghtTie->isChecked())
	{
		rightFrontSpeedSetpoint->setValue(leftFrontSpeedSetpoint->value());
		rightRearSpeedSetpoint->setValue(leftRearSpeedSetpoint->value());
	}*/
	std::cout << "setSetpoints activated" << std::endl;
	if (useLibraryCheckBoxStatus) 
    {
		sendSetpointsLibrary(mt);
	}
	else {
		sendSetpointsDirectly(mproperty, mt);
	}
}

void SendSetpoints::sendSetpointsDirectly(TreadmillProperty mproperty, SetpointType mt)
{
    QByteArray accelData;
    QByteArray decelData;
    QDataStream accelDataStream(&accelData, QIODevice::WriteOnly);
    QDataStream decelDataStream(&decelData, QIODevice::WriteOnly);
    QByteArray accelFiller(27, 0);
    QByteArray decelFiller(27, 0);
    qint16 accelSpeed[4];
    qint16 decelSpeed[4];
    qint16 accelAngle;
    qint16 decelAngle;
    qint16 accelAccel;
    qint16 decelAccel;
    char accelLdata[64];
    char decelLdata[64];
    const qint16 scaleFactor = 1000;

        switch(mproperty){
        case TreadmillProperty::DEFAULT:
            std::cout << "DEFAULT selected" << std::endl;
            std::cout << "Stopping Treadmill" << std::endl;
            accelSpeed[0] = 0;
            accelSpeed[1] = 0;
            accelSpeed[2] = 0;
            accelSpeed[3] = 0;
            accelAccel = 0;
            accelAngle = 0;
            accelDataStream << (quint8)0; // format
					         // straight
            accelDataStream << accelSpeed[0];
            accelDataStream << accelSpeed[1];
            accelDataStream << accelSpeed[2];
            accelDataStream << accelSpeed[3];
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAngle;
            // 1s complement
            accelDataStream << (qint16)(accelSpeed[0] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[1] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[2] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[3] ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAngle ^ 0xFFFF);
            accelDataStream.writeRawData(accelFiller.data(), accelFiller.size());
            qDebug("Sending Acceleration: %s", qPrintable(accelData.toHex()));
            memcpy(accelLdata, accelData.data(), 64);
            Q_ASSERT(accelData.size() == 64);
            pertSocket->write(accelData);
            break;
        case TreadmillProperty::ACCEL:
                        
            std::cout << "ACCELERATION selected" << std::endl;

            accelSpeed[0] = getRightFrontSpeedValue() * scaleFactor;
            accelSpeed[1] = getLeftFrontSpeedValue() * scaleFactor;
            accelSpeed[2] = 0;
            accelSpeed[3] = 0;
            accelAccel = (mt == NormalSetpoint) ? getAccelerationValue() * 1000.0 : 0.0;
            accelAngle = 0;
            accelDataStream << (quint8)0; // format
					         // straight
            accelDataStream << accelSpeed[0];
            accelDataStream << accelSpeed[1];
            accelDataStream << accelSpeed[2];
            accelDataStream << accelSpeed[3];
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAccel;
            accelDataStream << accelAngle;
            // 1s complement
            accelDataStream << (qint16)(accelSpeed[0] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[1] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[2] ^ 0xFFFF);
            accelDataStream << (qint16)(accelSpeed[3] ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAccel ^ 0xFFFF);
            accelDataStream << (qint16)(accelAngle ^ 0xFFFF);
            accelDataStream.writeRawData(accelFiller.data(), accelFiller.size());
            qDebug("Sending Acceleration: %s", qPrintable(accelData.toHex()));
            memcpy(accelLdata, accelData.data(), 64);
            Q_ASSERT(accelData.size() == 64);
            pertSocket->write(accelData);
            break;
        case TreadmillProperty::DECEL:
            std::cout << "DECEL selected" << std::endl;
            decelSpeed[0] = getRightFrontSpeedValue() * scaleFactor;
            decelSpeed[1] = getLeftFrontSpeedValue() * scaleFactor;
            decelSpeed[2] = 0;
            decelSpeed[3] = 0;
            decelAccel = (mt == NormalSetpoint) ? getDecelerationValue() * 1000.0 : 0.0;
            decelAngle = 0;
            decelDataStream << (quint8)0; // format
					         // straight
            decelDataStream << decelSpeed[0];
            decelDataStream << decelSpeed[1];
            decelDataStream << decelSpeed[2];
            decelDataStream << decelSpeed[3];
            decelDataStream << decelAccel;
            decelDataStream << decelAccel;
            decelDataStream << decelAccel;
            decelDataStream << decelAccel;
            decelDataStream << decelAngle;
            // 1s complement
            decelDataStream << (qint16)(decelSpeed[0] ^ 0xFFFF);
            decelDataStream << (qint16)(decelSpeed[1] ^ 0xFFFF);
            decelDataStream << (qint16)(decelSpeed[2] ^ 0xFFFF);
            decelDataStream << (qint16)(decelSpeed[3] ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAccel ^ 0xFFFF);
            decelDataStream << (qint16)(decelAngle ^ 0xFFFF);
            decelDataStream.writeRawData(decelFiller.data(), decelFiller.size());
            qDebug("Sending Deceleration: %s", qPrintable(decelData.toHex()));
            memcpy(decelLdata, decelData.data(), 64);
            Q_ASSERT(decelData.size() == 64);
            pertSocket->write(decelData);
            break;
        case TreadmillProperty::SPEED:
            std::cout << "SPEED selected " << std::endl;
            break;
        case TreadmillProperty::INCLIN:
            std::cout << "INCLIN selected" << std::endl;
            break;
        default:
                std::cout << "None Selected" << std::endl;
                break;

    }

}

void SendSetpoints::sendSetpointsLibrary(bool useLibCheckBox)
{

}


