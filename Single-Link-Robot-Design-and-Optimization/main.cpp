#include <iostream>
#include <string>
#include <vector>
#include "matrials.h"
#include "matrials.cpp"
#include "Functions.h"
#include "Functions.cpp"
#include "Link.h"
#include "Link.cpp"
#include "Motor.h"
#include "gear.h"
#include "MotorGearboxCompination.h"
#include <algorithm>
using namespace std;
int main(){
    Link* link=new Link();
    Matrial Selected_material;
    //set link initial dimintions
    setInitialDimintions(*link);
    // presenting the materials
    presentingMaterials(materials);
    // selecting the material
    Selected_material = selectingMaterial(materials);
    // Get  pay load math and maximum angular acceleration and requeird speed
    cout << "Please enter the pay load mass (in Kg) ...";
    link->set_payload_m(checkValidation(1,inf));
    cout << "\nPlease enter the maximum angular acceleration (in rad/s^2) ...";
    link->set_max_angular_acc(checkValidation(1,inf));
    cout <<"\nPlease enter the speed(rad/s) ...";
    link->set_speed_req(checkValidation(1,inf));
    // stress calculations
    checkStress(Selected_material,*link);
    // -------------------- Part 2 ----------------------------
//Motors DataBase

    vector<Motor> motors;
    setMotorsDatabase(motors);
// GearBoxes Database
    vector<Gearbox> gearboxes;
    setGearboxDatabase(gearboxes);
    //searching algorthem
    vector<MotorGearboxCompination> Good_compinations;
    searching(Good_compinations,motors,gearboxes,link->get_torque_req(),link->get_speed_req());
    //sorting algorthem
    sorting(Good_compinations);
    return 0;
}
