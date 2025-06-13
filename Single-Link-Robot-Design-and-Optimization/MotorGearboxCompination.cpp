#include <iostream>
#include <string>
#include <vector>
#include "MotorGearboxCompination.h"
using namespace std;
MotorGearboxCompination::MotorGearboxCompination() {}
MotorGearboxCompination::MotorGearboxCompination(Motor m, Gearbox g)
{
    motor = m;
    gearbox = g;
}
float MotorGearboxCompination::get_outputTorque() const
{
    return motor.getTorque()*gearbox.get_ratio()*gearbox.get_efficiency();
}
float MotorGearboxCompination::get_TotalCost()
{
    return motor.getCost()+gearbox.get_cost();
}
float MotorGearboxCompination::get_outputSpeed() const
{
    return motor.getSpeed()/gearbox.get_ratio();
}

string MotorGearboxCompination::get_Name()
{
    name = "["+motor.getModelName()+"/"+gearbox.get_name()+"]";
    return name;
}
float MotorGearboxCompination::get_TotalWeight()
{
    return motor.getMass()+gearbox.get_mass();
}

void MotorGearboxCompination::get_Motor_data()
{
        cout <<  motor.getTorque()
     <<motor.getSpeed()
    <<motor.getMass()
    <<motor.getDiameter()
    <<motor.getWidth()
    <<motor.getCost()<<endl;
}
void MotorGearboxCompination::get_Gearbox_data()
{
    cout << gearbox.get_name()
    <<gearbox.get_ratio()
    <<gearbox.get_efficiency()
    <<gearbox.get_cost()
    <<gearbox.get_diameter()
    <<gearbox.get_mass()<<endl;
}
