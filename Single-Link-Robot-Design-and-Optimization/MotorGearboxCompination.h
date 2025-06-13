#ifndef MOTORGEARBOXCOMPINATION_H_INCLUDED
#define MOTORGEARBOXCOMPINATION_H_INCLUDED
#include <string>
#include <vector>
#include "Motor.h"
#include "gear.h"
using namespace std;
class MotorGearboxCompination
{
public:
    MotorGearboxCompination();
    MotorGearboxCompination(Motor m,Gearbox g);
    float get_outputTorque() const;
    //compute(motor cost + gearbox cost) and return the total cost.
    float get_TotalCost() ;
    float get_outputSpeed() const;
    //compute(motor mass + gearbox mass) and return the total mass.
    float get_TotalWeight() ;
    string get_Name();
    void get_Motor_data();
    void get_Gearbox_data();
private:
    string name;
    Motor motor;
    Gearbox gearbox;
};


#endif // MOTORGEARBOXCOMPINATION_H_INCLUDED
