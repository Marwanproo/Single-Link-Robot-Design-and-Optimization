#include <iostream>
#include <string>
#include <vector>
#include "motors.h"
#include <stdio.h>
using namespace std;

Motor::Motor(){}
Motor::Motor(const string& name, double t, double s, double m, double d, double w, double c)
    : modelName(name), torque(t), speed(s), mass(m), diameter(d), width(w), cost(c) {}
/*void Motor::printInfo() const
{
    cout << "Model: " << modelName << endl
         << "Torque: " << torque << " Nm" << endl
         << "Speed: " << speed << " RPM" << endl
         << "Mass: " << mass << " kg" << endl
         << "Diameter: " << diameter << " mm" << endl
         << "Width: " << width << " mm" << endl
         << "Cost: $" << cost << endl;
}*/
/*double Motor::calculatePerformance() const
{
    return torque * speed;
}*/



/*vector<Motor> Motor::filterMotors(const vector<Motor>& motors,
        double requiredTorque,
        double requiredSpeed) const
{
    vector<Motor> result;
    for (const Motor& m : motors)
    {
        if (m.meetsRequirements(requiredTorque, requiredSpeed))
        {
            result.push_back(m);
        }
    }
    return result;
}*/


/*bool Motor::isLightweight(double thresholdMass) const
{
    return mass <= thresholdMass;
}*/

/*void Motor::updateCost(double massCostFactor, double diameterCostFactor, double widthCostFactor)
{
    cost = (mass * massCostFactor)
           + (diameter * diameterCostFactor)
           + (width * widthCostFactor);
}*/


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

