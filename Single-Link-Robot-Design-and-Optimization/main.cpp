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
    const double inf = 1.0 / 0.0;
    Link* link=new Link();
    Matrial Selected_material;
    int shape_selector;
    int material_Selector;
    string new_Name;
        cout << "please select a cross-section shape \n" <<" (1) for rectangular \n (2) for circular" <<endl;
        shape_selector = checkValidation(1,2);
         do{
            if (shape_selector == 1){
                cout <<"please enter the initial dimensions (in millimeter)."<<endl;
                cout <<"the length:";
                link->set_length(checkValidation(1,inf));
                cout <<"the height:";
                link->set_high(checkValidation(1,inf));
                cout <<"the width:";
                link->set_width(checkValidation(1,inf));
            }
            else if (shape_selector == 2 )
            {
                cout <<"please enter the initial dimensions (in millimeter)"<<endl;
                cout <<"the length:";
                link->set_length(checkValidation(1,inf));
                cout <<"the radius:";
                link->set_radius(checkValidation(1,inf));
            }
            else
            {
                cout << "Invalid input try again\n";
            }

    }
    while(link->check_Link());
    // presenting the materials
    cout << "please select a material from the data shown enter (10) to add a new material\n";
    for(int i=0; i<9; i++)
    {
        cout <<"("<< materials[i].get_Id()<<")"<< " --> "
             <<materials[i].get_Name() << " Yield strength: "<< materials[i].get_Yieldstrength()<< "(MPa)"
             << " , Density is: " <<  materials[i].get_Density() << "(g/cm^3)"<<endl;
    }
    // selecting the material
        material_Selector = checkValidation(1,10);
        if(material_Selector == 10)
        {
            cout << "Enter the material's name ";
            cin >> new_Name;
            materials[9].set_Name(new_Name);
            do
            {
                cout << "\nEnter the material yield strength (in MPa) ";
                materials[9].set_Yieldstrength(checkValidation(1,inf));
                cout <<"\nEnter the material Density (in g/cm^3) ";
                materials[9].set_Density(checkValidation(1,inf));
                materials[9].set_Id(10);
            }
            while(materials[9].check_material());
        }

    Selected_material = materials[material_Selector-1];
    // Get  pay load math and maximum angular acceleration
    cout << "Please enter the pay load mass (in Kg) ...";
    link->set_payload_m(checkValidation(1,inf));
    cout << "\n Please enter the maximum angular acceleration (in mm/s^2) ...";
    link->set_max_angular_acc(checkValidation(1,inf));
    // stress calculations
    checkStress(Selected_material,*link);
    cout << "the mass"<<link->get_mass()<<" "<<endl;
    cout << "the requierd torque" << link->get_torque_req()<<endl;

    // -------------------- Part 2 ----------------------------
    vector<Motor> motors;
    vector<Motor> motors_bycost;
    cout << "How many motors do you want to enter sir?"<<endl;
    int number_motors;
    cin >> number_motors;
    string motor_name; double motor_torque; double motor_speed; double motor_mass; double motor_diameter; double motor_width; double motor_cost;
    for (int i =0 ; i < number_motors ; i++) {
        cout << "Enter the motor name: " <<endl;
        cin >> motor_name;
         cout << "Enter the motor torque: " <<endl;
        motor_torque = checkValidation(0,inf);
         cout << "Enter the motor speed:" <<endl;
        motor_speed = checkValidation(1,inf);
         cout << "Enter the motor mass (in Kg): " <<endl;
        motor_mass = checkValidation(1,inf);
         cout << "Enter the motor diameter(in millimeter): " <<endl;
        motor_diameter = checkValidation(1,inf);
         cout << "Enter the motor width( in millimeter): " <<endl;
        motor_width = checkValidation(1,inf);
         cout << "Enter the motor cost (in millimeter): " <<endl;
        if(i != number_motors-1){
            cout << " ////////////////// The next Motor ////////////////// " <<endl;
        }
        Motor M1(motor_name,motor_torque,motor_speed,motor_mass,motor_diameter,motor_width);
        motors.push_back(M1);
    }
/////////////////////////////////////////////////////////////////////////////////////////
    vector<Gearbox> gearboxes;
    cout << "How many Gearboxes do you want to enter sir?"<<endl;
    int number_Gearbox;
    cin >> number_Gearbox;
    string n; double rat; double e; double m; double d; double w; double c;
    for(int i =1 ; i <= number_Gearbox ; i++){
        cout << "Enter the gearbox name: " <<endl;
        cin >> n;
        cout << "Enter the gearbox ratio: " <<endl;
        rat = checkValidation(0,inf);
        cout << "Enter the gearbox effeciency:" <<endl;
        e = checkValidation(0,100);
        if(e > 1){
            e/=100;
            cout << e<<endl;
        }
        cout << "Enter the gearbox mass (in Kg): " <<endl;
        m = checkValidation(1,inf);
        cout << "Enter the gearbox diameter (in millimeter): " <<endl;
        d = checkValidation(1,inf);
        cout << "Enter the gearbox width  (in millimeter): " <<endl;
        w = checkValidation(1,inf);
        if(i != number_Gearbox){
            cout << " ////////////////// The next Gearbox ////////////////// " <<endl;
        }
        Gearbox G1(n,rat,e,m,d,w);
        gearboxes.push_back(G1);
    }
    //searching algorthem
    vector<MotorGearboxCompination> Good_compinations;
    for(int i = 0;i<motors.size();++i){
            for(int j = 0; j<gearboxes.size();++j){
                if(motors[i].getTorque()*gearboxes[j].get_ratio()*gearboxes[j].get_efficiency() >=link->get_torque_req() &&
                   //motors[i].getSpeed()/gearboxes[j].get_ratio() >= link->get_speed_req() &&
                   motors[i].getDiameter() == gearboxes[j].get_diameter()){
                    Good_compinations.push_back(MotorGearboxCompination(motors[i],gearboxes[j]));
                }
            }
    }
    //sorting algorthem
    //(cost)

    for(int j = 0 ; j < Good_compinations.size();++j){
        for(int i = 1 ; i < Good_compinations.size();++i){
            MotorGearboxCompination storage;
            if(Good_compinations[i].get_TotalCost() < Good_compinations[i-1].get_TotalCost()){
                storage = Good_compinations[i-1];
                Good_compinations[i-1] = Good_compinations[i];
                Good_compinations[i] = storage;
            }}}

    // (weight)
    for(int j = 0 ; j < Good_compinations.size();++j){
        for(int i = 1 ; i < Good_compinations.size();++i){
            MotorGearboxCompination storage;
            if(Good_compinations[i].get_TotalWeight() < Good_compinations[i-1].get_TotalWeight()){
                storage = Good_compinations[i-1];
                Good_compinations[i-1] = Good_compinations[i];
                Good_compinations[i] = storage;
            }}}
        for(int i = 1; i < Good_compinations.size();i++){
        cout << i <<"-"<<Good_compinations[i].get_Name()<<"//"<<Good_compinations[i].get_TotalCost() << "// " << Good_compinations[i].get_outputTorque()<<endl;
    }
    return 0;
}
