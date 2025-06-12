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
using namespace std;
int main()
{
    Link link(0,0,0,0,0);
    Matrial Selected_material;
    //selecting crossSection
    int cross_section;
    cross_section = selection_Crossection();
    // presenting the materials
    presentingMaterials(materials);
    // selecting the material
    Selected_material = selectingMaterial(materials);
    //set link initial dimintions
    setInitialDimintions(link,cross_section);
    // Get  pay load math and maximum angular acceleration and requeird speed
    cout << "Please enter the pay load mass (in Kg) ...";
    link.set_payload_m(checkValidation(1,inf));
    cout << "\nPlease enter the maximum angular acceleration (in rad/s^2) ...";
    link.set_max_angular_acc(checkValidation(pow(10,-12),inf));
    cout <<"\nPlease enter the speed(rad/s) ...";
    link.set_speed_req(checkValidation(1,inf));
    // stress calculations
    checkStress(Selected_material,link);
    // -------------------- Part 2 ----------------------------
//Motors DataBase
    vector<Motor> motors;
    setMotorsDatabase(motors);
// GearBoxes Database
    vector<Gearbox> gearboxes;
    setGearboxDatabase(gearboxes);
    //searching algorthem
    vector<MotorGearboxCompination> Good_compinations;
    searching(Good_compinations,motors,gearboxes,link.get_torque_req(),link.get_speed_req());
    //sorting algorthem
    cout << "Please enter 1 to minimize cost or 2 to minimize weight " <<endl;
    int min_selector;
    min_selector = checkValidation(1,2);
    sorting(Good_compinations,min_selector);
    cout << "The Motor Gear" << Good_compinations[0].get_Name()<<endl;
    return 0;
}
