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


