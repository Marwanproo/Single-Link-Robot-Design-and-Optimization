#include <iostream>
#include <string>
#include <vector>
#include "MotorGearboxCompination.h"
using namespace std;
MotorGearboxCompination::MotorGearboxCompination(){}
MotorGearboxCompination::MotorGearboxCompination(Motor m , Gearbox g){
    motor = m;
    gearbox = g;
}
float MotorGearboxCompination::get_outputTorque() const{
    return motor.getTorque()*gearbox.get_ratio()*gearbox.get_efficiency();
}
float MotorGearboxCompination::get_TotalCost(){
    return motor.getCost()+gearbox.get_cost();
}
float MotorGearboxCompination::get_outputSpeed() const{
    return motor.getSpeed()/gearbox.get_ratio();
}

string MotorGearboxCompination::get_Name()const{
    return ("["+motor.getModelName()+"/"+gearbox.get_name()+"]");
}
float MotorGearboxCompination::get_TotalWeight(){
    return motor.getMass()+gearbox.get_mass();
}

