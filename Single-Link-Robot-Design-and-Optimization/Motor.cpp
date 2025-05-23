#include <iostream>
#include <string>
#include <vector>
#include "Motor.h"
using namespace std;

Motor::Motor(){}
Motor::Motor(const string& name, double t, double s, double m, double d, double w, double c)
    : modelName(name), torque(t), speed(s), mass(m), diameter(d), width(w), cost(c) {}
string Motor::getModelName() const
{
    return modelName;
}
double Motor::getTorque() const
{
    return torque;
}
double Motor::getSpeed() const
{
    return speed;
}
double Motor::getMass() const
{
    return mass;
}
double Motor::getDiameter() const
{
    return diameter;
}
double Motor::getWidth() const
{
    return width;
}
double Motor::getCost() const
{
    return cost;
}

