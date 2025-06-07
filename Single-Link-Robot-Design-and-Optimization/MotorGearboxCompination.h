#ifndef MOTORGEARBOXCOMPINATION_H_INCLUDED
#define MOTORGEARBOXCOMPINATION_H_INCLUDED
#include <string>
#include <vector>
#include "Motor.h"
#include "gear.h"
using namespace std;
class MotorGearboxCompination{
    public:
        MotorGearboxCompination();
        MotorGearboxCompination(Motor m,Gearbox g);
        float get_outputTorque() const;
        float get_TotalCost() ;
        float get_outputSpeed() const;
        float get_TotalWeight() ;
        string get_Name();
    private:
        string name;
        Motor motor;
        Gearbox gearbox;
};


#endif // MOTORGEARBOXCOMPINATION_H_INCLUDED
