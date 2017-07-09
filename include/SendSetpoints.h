#ifndef SENDSETPOINTS_H
#define SENDSETPOINTS_H

#include <iostream>
#include <QByteArray>
#include <QDataStream>
#include <QAbstractSocket>


class SendSetpoints
{

    public:
        static SendSetpoints* getInstance();
        void setUseLibraryStatus(bool useLibCheckBox);

        enum TreadmillProperty
        {
            DEFAULT,
            ACCEL,
            DECEL,
            SPEED,
            INCLIN

        };
        enum SetpointType { NormalSetpoint, FeedbackRegistrationSetpoint };
        void sendSetpoints(TreadmillProperty mproperty, SetpointType mt);
        void sendSetpointsDirectly(TreadmillProperty mproperty, SetpointType mt);
        void sendSetpointsLibrary(bool useLibCheckBox);
        void setRightFrontSpeedValue(double mrightFrontSpeedValue);
        void setLeftFrontSpeedValue(double mleftFrontSpeedValue);
        void setAccelerationValue(double mAccelValue);
        void setDecelerationValue(double mdecelValue);
        void setSocket(QAbstractSocket* mSocket);

    
    private:
    
        static SendSetpoints* _sendSetpoints;
        bool useLibraryCheckBoxStatus;
        double getRightFrontSpeedValue();
        double getLeftFrontSpeedValue();
        double getAccelerationValue();
        double getDecelerationValue();

        double accelerationValue;
        double decelerationValue;
        double leftSpeedFrontValue;
        double rightSpeedFrontValue;


        QAbstractSocket* pertSocket;

};
#endif
