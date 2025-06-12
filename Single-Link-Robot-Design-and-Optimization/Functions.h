#include <iostream>
#include <string>
#include <vector>
#include "Link.h"
#include "matrials.h"
#include "Motor.h"
#include "gear.h"
#include "MotorGearboxCompination.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
auto checkValidation(auto r1, auto r2 );
void checkStress(Matrial& m,Link& l);
void setInitialDimintions(Link& l,int& shape_selector);
void presentingMaterials(Matrial m[]);
Matrial selectingMaterial(Matrial m[]);
void setMotorsDatabase(vector<Motor>& m);
void setGearboxDatabase(vector<Gearbox>& g);
void searching(vector<MotorGearboxCompination>& mg,vector<Motor>& m,vector<Gearbox>& g,float req_torque,float req_speed);
void sorting(vector<MotorGearboxCompination>& mg, int i);
int selection_Crossection();
#endif // FUNCTIONS_H_INCLUDED
