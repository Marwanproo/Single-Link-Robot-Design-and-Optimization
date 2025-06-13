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
// this function responsible for checking every input in the project.
// the function take two parameters that represent the range of the input.
auto checkValidation(auto r1, auto r2 );
// responsible for taking the cross section for the link.
int selection_Crossection();
//responsible for set initial Dimintions for the link.
void setInitialDimintions(Link& l,int& shape_selector);
//this function edit the dimintions until the stress on the link be smaller than the yield strength of the matrial.
//if the stress on the matrial is much smaller the link dimintions also will be edited.
//it also edit the other link members that depend on the dimintions.
void checkStress(Matrial& m,Link& l);
//this function present the matrial data base.
//parameters: array of matials.
void presentingMaterials(Matrial m[]);
//this function select the matrial the user want.
//also adding new matrial if needs.
Matrial selectingMaterial(Matrial m[]);
//adding motors to the motor data base.
//parameters: vector of motors.
void setMotorsDatabase(vector<Motor>& m);
//adding gearboxes to the gear box data base.
//parameters:vector of gearboxes.
void setGearboxDatabase(vector<Gearbox>& g);
//search for combinations between motors and gearboxes that gave the needed torque.
//parameters: vector of (motors & gearboxes & MotorGearboxCompination) & reqiuierd torque and reuierd speed.
void searching(vector<MotorGearboxCompination>& mg,vector<Motor>& m,vector<Gearbox>& g,float& req_torque,float& req_speed);
//sort the combination between motors and gearboxes by cost or weight.
//parameters: vector of MotorGearboxCompination & integer responsible of the sorting type.
void sorting(vector<MotorGearboxCompination>& mg, int i);
//print the link safe dimensions.
void s_dim(Link& l);
#endif // FUNCTIONS_H_INCLUDED
