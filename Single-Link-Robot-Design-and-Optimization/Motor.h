#ifndef MOTORS_H_INCLUDED
#define MOTORS_H_INCLUDED
#include <string>
#include <vector>
using namespace std;
class Motor
{
public:

    Motor();
    Motor(const string& name, double t, double s, double m, double d, double w, double c);
    string getModelName() const;
    double getTorque() const;
    double getSpeed() const;
    double getMass() const;
    double getDiameter() const;
    double getWidth() const;
    double getCost() const;
    void setModelName(const string& name);
    void setTorque(double t);
    void setSpeed(double s);
    void setMass(double m);
    void setDiameter(double d);
    void setWidth(double w);
    void setCost(double c);
    string modelName;
    double torque;
    double speed;
    double mass;
    double diameter;
    double width;
    double cost;
};



#endif // MOTORS_H_INCLUDED
