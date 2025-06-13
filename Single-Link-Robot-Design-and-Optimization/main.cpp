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
#include "Database.cpp"
using namespace std;
int main()
{
    cout << "\t\t\t Welcome to the single-link robot design and optimization program!" << endl;
    cout << "\t\t\t--------------------------------------------------------------------" << endl;
    Link link(0,0,0,0,0);
    Matrial Selected_material;
    int cross_section;
    cross_section = selection_Crossection();
    presentingMaterials(materials);
    Selected_material = selectingMaterial(materials);
    setInitialDimintions(link,cross_section);
    cout <<endl<< "Please enter the pay load mass (in Kg) ...";
    link.set_payload_m(checkValidation(1,inf));
    cout << "\nPlease enter the maximum angular acceleration (in rad/s^2) ...";
    link.set_max_angular_acc(checkValidation(pow(10,-12),inf));
    cout <<"\nPlease enter the speed (in rpm) ...";
    link.set_speed_req(checkValidation(1,inf));
    cout << "--------------------------------------------------------------------" << endl;
    checkStress(Selected_material,link);
    // -------------------- Part 2 ----------------------------
    vector<Motor> motors =
    {
        Motor ("m1",6.24,7770.0,54.0/1000,22,31.9), Motor ("m2",2.17,6660.0,21.0/1000,16,25.4),
        Motor ("m3",3.59,4000.0,33.0/1000,19,28.9), Motor ("m4",3.49,6510.0,33.0/1000,19,28.9),
        Motor ("m5",5.03,8070.0,117.0/1000,26,44.7), Motor ("m6",13.7,5310.0,117.0/1000,26,44.7),
        Motor ("m7",6.19,5150.0,26.0/1000,14,35.6), Motor ("m8",6.34,5220.0,26.0/1000,14,35.6),
        Motor ("m9",4.81,7440.0,54.0/1000,22,31.9), Motor ("m10",2.22,4530.0,21.0/1000,16,25.4),
    };
    vector<Gearbox> gearboxes=
    {
        Gearbox ("g1",84,73,27/1000,16,22.7), Gearbox ("g2",24,81,31/1000,19,19.5),
        Gearbox ("g3",19,81,23/1000,16,19.1), Gearbox ("g4",84,73,36/1000,19,23.1),
        Gearbox ("g5",27,80,77/1000,26,32.9), Gearbox ("g6",71,70,93/1000,26,39.5),
        Gearbox ("g7",103,75,21/1000,14,25.5), Gearbox ("g8",243,65,23/1000,14,30.3),
        Gearbox ("g9",84,59,68/1000,22,36.2), Gearbox ("g10",370,49,81/1000,22,43),
    };
    cout << "Do you want to enter a new motor database (Enter 1) or just use the current database (Enter 2) ... ";
    int in_motors = checkValidation(1,2);
    if(in_motors == 1)setMotorsDatabase(motors);
    cout << "Do you want to enter a new gearbox database (Enter 1) or just use the current database (Enter 2) ... ";
    int in_gear = checkValidation(1,2);
    if(in_gear == 1)setGearboxDatabase(gearboxes);
    vector<MotorGearboxCompination> Good_compinations(0);
    searching(Good_compinations,motors,gearboxes,link.get_torque_req()*Nmm_NM,link.get_speed_req());
    if(Good_compinations.size() > 0)
    {
       cout << "Please enter 1 to minimize cost or 2 to minimize weight ... ";
        int min_selector;
        min_selector = checkValidation(1,2);
         cout << "--------------------------------------------------------------------" << endl;
        sorting(Good_compinations,min_selector);
        cout << "--------------------------------------------------------------------" << endl;
          s_dim(link);
    }
    return 0;
    }
