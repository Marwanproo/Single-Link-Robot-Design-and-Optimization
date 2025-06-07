#ifndef MOTORS_H_INCLUDED
#define MOTORS_H_INCLUDED
#include <string>
#include <vector>
using namespace std;
class Motor
{
public:
    Motor();
    Motor(const string& name, float t, float s, float m, float d, float w);
    string getModelName() const;
    float getTorque() const;
    float getSpeed() const;
    float getMass() const;
    float getDiameter() const;
    float getWidth() const;
    float getCost() ;
    void setModelName(const string& name);
    void setTorque(float t);
    void setSpeed(float s);
    void setMass(float m);
    void setDiameter(float d);
    void setWidth(float w);
    void setCost();
    private:
    string modelName;
    float torque;
    float speed;
    float mass;
    float diameter;
    float width;
    float cost;
};



#endif // MOTORS_H_INCLUDED
