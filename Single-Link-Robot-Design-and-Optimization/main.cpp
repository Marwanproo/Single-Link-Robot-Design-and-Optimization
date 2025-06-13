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
   /* int cross_section;
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
    checkStress(Selected_material,link);*/
    // -------------------- Part 2 ----------------------------
   vector<Motor> motors = {
Motor ("m1",2.22/1000,4530.0,21.0/1000,16.0,25.4),
Motor ("m2",2.17/1000,6660.0,21.0/1000,16.0,25.4),
Motor ("m3",3.59/1000,4000.0,33.0/1000,19.0,28.9),
Motor ("m4",3.49/1000,6510.0,33.0/1000,19.0,28.9),
Motor ("m5",5.03/1000,8070.0,117.0/1000,26.0,44.7),
Motor ("m6",13.7/1000,5310.0,117.0/1000,26.0,44.7),
Motor ("m7",6.19/1000,5150.0,26.0/1000,14.0,35.6),
Motor ("m8",6.34/1000,5220.0,26.0/1000,14.0,35.6),
Motor ("m9",4.81/1000,7440.0,54.0/1000,22.0,31.9),
Motor ("m10",6.24/1000,7770.0,54.0/1000,22.0,31.9),
};
vector<Gearbox> gearboxes= {
Gearbox ("g1",19.0,81.0,23.0/1000,16.0,19.1),
Gearbox ("g2",84.0,73.0,27.0/1000,16.0,22.7),
Gearbox ("g3",24.0,81.0,31.0/1000,19.0,19.5),
Gearbox ("g4",84.0,73.0,36.0/1000,19.0,23.1),
Gearbox ("g5",27.0,80.0,77.0/1000,26.0,32.9),
Gearbox ("g6",71.0,70.0,93.0/1000,26.0,39.5),
Gearbox ("g7",103.0,75.0,21.0/1000,14.0,25.5),
Gearbox ("g8",243.0,65.0,23.0/1000,14.0,30.3),
Gearbox ("g9",84.0,59.0,68.0/1000,22.0,36.2),
Gearbox ("g10",370.0,49.0,81.0/1000,22.0,43.0),
};
//Motors DataBase

//    vector<Motor> motors;
  //  setMotorsDatabase(motors);
    //vector<Motor> motors;
    //setMotorsDatabase(motors);

// GearBoxes Database
    //vector<Gearbox> gearboxes;
    //setGearboxDatabase(gearboxes);
    //searching algorthem
    vector<MotorGearboxCompination> Good_compinations;
    searching(Good_compinations,motors,gearboxes,100.01,200.02);
    //sorting algorthem
    cout << "Please enter 1 to minimize cost or 2 to minimize weight " <<endl;
    int min_selector;
    min_selector = checkValidation(1,2);
    sorting(Good_compinations,min_selector);
    cout << "The Motor Gear" << Good_compinations[0].get_Name()<<endl;
    return 0;
}
