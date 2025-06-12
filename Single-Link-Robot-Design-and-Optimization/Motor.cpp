#include <iostream>
#include <string>
#include <vector>
#include "Motor.h"
using namespace std;

Motor::Motor(){}
Motor::Motor(const string& name, float t, float s, float m, float d, float w)
    : modelName(name), torque(t), speed(s), mass(m), diameter(d), width(w){}
string Motor::getModelName() const
{
    return modelName;
}
float Motor::getTorque() const
{
    return torque;
}
float Motor::getSpeed() const
{
    return speed;
}
float Motor::getMass() const
{
    return mass;
}
float Motor::getDiameter() const
{
    return diameter;
}
float Motor::getWidth() const
{
    return width;
}
float Motor::getCost()
{
    cost = mass + diameter/100 + width/100;
    return cost;
}

vector<Motor> motors = {
Motor ("m1",2.22/1000,4530,21/1000,16,25.4),
Motor ("m2",2.17/1000,6660,21/1000,16,25.4),
Motor ("m3",3.59/1000,4000,33/1000,19,28.9),
Motor ("m4",3.49/1000,6510,33/1000,19,28.9),
Motor ("m5",5.03/1000,8070,117/1000,26,44.7),
Motor ("m6",13.7/1000,5310,117/1000,26,44.7),
Motor ("m7",6.19/1000,5150,26/1000,14,35.6),
Motor ("m8",6.34/1000,5220,26/1000,14,35.6),
Motor ("m9",4.81/1000,7440,54/1000,22,31.9),
Motor ("m10",6.24/1000,7770,54/1000,22,31.9),
};
