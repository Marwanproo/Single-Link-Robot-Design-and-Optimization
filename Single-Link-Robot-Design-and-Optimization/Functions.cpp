#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Link.h"
#include "matrials.h"
#include <limits>
using namespace std;
// constant use for all project
const float g = 9.81*1000;
const float PI = 22.0/7.0;
const float D_Unit = pow(10,-6);
const double inf = 1.0 / 0.0;
auto checkValidation(auto r1, auto r2)
{
    double var;
    do
    {
        cin >> var;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        if(var  < r1 || var > r2){
            cout << "Invalid input please try again : " << "\a";
        }
    }
    while(var  < r1 || var > r2);
    return var;
}

void setInitialDimintions(Link& l){
    int shape_selector;
    cout << "please select a cross-section shape \n" <<" (1) for rectangular \n (2) for circular" <<endl;
        shape_selector = checkValidation(1,2);
         do{
            if (shape_selector == 1){
                cout <<"please enter the initial dimensions (in millimeter)."<<endl;
                cout <<"the length:";
                l.set_length(checkValidation(1,inf));
                cout <<"the height:";
                l.set_high(checkValidation(1,inf));
                cout <<"the width:";
                l.set_width(checkValidation(1,inf));
            }
            else if (shape_selector == 2 )
            {
                cout <<"please enter the initial dimensions (in millimeter)"<<endl;
                cout <<"the length:";
                l.set_length(checkValidation(1,inf));
                cout <<"the radius:";
                l.set_radius(checkValidation(1,inf));
            }

    }
    while(l.check_Link());
}
void checkStress(Matrial& m,Link& l)
{
    l.set_mass(m.get_Density());
    l.set_momentOfInertia();
    l.set_bendingMoment();
    l.set_max_stress();
    l.set_torque_req();
    if(l.get_max_stress() > m.get_Yieldstrength())
    {
        while(l.get_max_stress() >= m.get_Yieldstrength())
        {
            l.increase_dimensions();
            l.set_mass(m.get_Density());
            l.set_momentOfInertia();
            l.set_bendingMoment();
            l.set_max_stress();
            l.set_torque_req();
        }
    }
    else
    {
        while(l.get_max_stress() <= m.get_Yieldstrength())
        {
            l.reduce_dimensions();
            l.set_mass(m.get_Density());
            l.set_momentOfInertia();
            l.set_bendingMoment();
            l.set_max_stress();
            l.set_torque_req();
        }
    }
    cout << "The final length is: "<< l.get_length()<< " Millimeter"<<endl;
    if(l.get_radius()==0.0)
    {
        cout << "The final height is: "<< l.get_high()<< " Millimeter"<<endl;
        cout << "The final width is: "<<l.get_width()<< " Millimeter"<<endl;
    }
    else
    {
        cout << "The final radius is: "<<l.get_radius()<<  " Millimeter"<<endl;
    }
    cout << "The mass :" << l.get_mass()<<endl;
    cout <<"The max stress is: "<< l.get_max_stress()<<" MPa"<<endl;
    cout << "the requierd torque" << l.get_torque_req()<<endl;
}
void presentingMaterials(Matrial m[]){
    cout << "please select a material from the data shown enter (10) to add a new material\n";
    int length = (sizeof(m) / sizeof(m[0]));
    for(int i=0;  i < 9; i++)
    {
        cout <<"("<< m[i].get_Id()<<")"<< " --> "
             <<m[i].get_Name() << " Yield strength: "<< m[i].get_Yieldstrength()<< "(MPa)"
             << " , Density is: " <<  m[i].get_Density() << "(g/cm^3)"<<endl;
    }
}
Matrial selectingMaterial(Matrial m[]){
    int material_Selector;
    string new_Name;
    material_Selector = checkValidation(1,10);
        if(material_Selector == 10)
        {
            cout << "Enter the material's name ";
            cin >> new_Name;
            m[9].set_Name(new_Name);
                cout << "\n Enter the material yield strength (in MPa) ";
                m[9].set_Yieldstrength(checkValidation(1,inf));
                cout <<"\n Enter the material Density (in g/cm^3) ";
                m[9].set_Density(checkValidation(1,inf));
                m[9].set_Id(10);
            }
        return m[material_Selector-1];
}
void setMotorsDatabase(vector<Motor>& m){
    cout << "How many motors do you want to enter sir?"<<endl;
    int number_motors = checkValidation(0,inf);
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
        if(i != number_motors-1){
            cout << " ////////////////// The next Motor ////////////////// " <<endl;
        }
        Motor M1(motor_name,motor_torque,motor_speed,motor_mass,motor_diameter,motor_width);
        m.push_back(M1);
    }
}
void setGearboxDatabase(vector<Gearbox>& g){
    cout << "How many Gearboxes do you want to enter sir?"<<endl;
    int number_Gearbox = checkValidation(1,inf);
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
        g.push_back(G1);
    }
}
void searching(vector<MotorGearboxCompination>& mg,vector<Motor>& m,vector<Gearbox>& g,float req_torque , float req_speed){
    for(int i = 0;i<m.size();++i){
            for(int j = 0; j<g.size();++j){
                if(m[i].getTorque()*g[j].get_ratio()*g[j].get_efficiency() >= req_torque &&
                   m[i].getSpeed()/g[j].get_ratio() >= req_speed &&
                   m[i].getDiameter() == g[j].get_diameter()){
                    mg.push_back(MotorGearboxCompination(m[i],g[j]));
                }
            }
    }
}
void sorting(vector<MotorGearboxCompination>& mg){
    int min_selector;
    cout << "Please enter 1 to minimize cost or 2 to minimize weight " <<endl;
    min_selector = checkValidation(1,2);
    if (min_selector = 1){
        //cost
        for(int j = 0 ; j < mg.size();++j){
        for(int i = 1 ; i < mg.size();++i){
            MotorGearboxCompination storage;
            if(mg[i].get_TotalCost() < mg[i-1].get_TotalCost()){
                storage = mg[i-1];
                mg[i-1] = mg[i];
                mg[i] = storage;
            }}}
        cout <<"The best motor and gearbox combination is "<<mg[0].get_Name()<<endl;
    }else{
    // (weight)
    for(int j = 0 ; j < mg.size();++j){
        for(int i = 1 ; i < mg.size();++i){
            MotorGearboxCompination storage;
            if(mg[i].get_TotalWeight() < mg[i-1].get_TotalWeight()){
                storage = mg[i-1];
                mg[i-1] = mg[i];
                mg[i] = storage;
            }}}
        cout << "The best motor and gearbox combination is " <<mg[0].get_Name()<<endl;
    }
    for(int i = 1; i < mg.size();i++){
        cout << i <<"-"<<mg[i].get_Name()<<"//"<<mg[i].get_TotalCost()
        << "// " << mg[i].get_outputTorque()<<endl;
    }
}






