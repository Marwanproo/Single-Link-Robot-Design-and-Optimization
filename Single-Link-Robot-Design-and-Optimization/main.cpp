#include <iostream>
#include <string>
#include <vector>
#include "matrials.h"
#include "matrials.cpp"
#include "Functions.h"
#include "Functions.cpp"
#include "Link.h"
#include "Link.cpp"
#include "gears.cpp"
#include "motorss.cpp"
using namespace std;
int main()
{
    Link* link=new Link();
    Matrial Selected_material;
    int shape_selector;
    int material_Selector;
    float l,h,b,r,mp,max_acc,new_Yieldstrength,new_Density;
    string new_Name;
    // selecting the initial dimensions
        do
        {
            cout << "please select a cross-section shape \n" <<" (1) for rectangular \n (2) for circular" <<endl;
            cin >> shape_selector;
            if(cin.fail()){
            cin.clear();
            cin.ignore(1);
            cout<<"Invalid input"<<endl;
            }
        }while(shape_selector != 1 && shape_selector != 2);

         do
           {
            if (shape_selector == 1)
            {
                cout <<"please enter the initial dimensions (in millimeter)."<<endl;
                cout <<"the length:";
                cin >>l;
                link->set_length(l);
                cout <<"the height:";
                cin >>h;
                link->set_high(h);
                cout <<"the width:";
                cin >>b;
                link->set_width(b);
            }
            else if (shape_selector == 2 )
            {
                cout <<"please enter the initial dimensions (in millimeter)"<<endl;
                cout <<"the length:";
                cin >>l;
                link->set_length(l);
                cout <<"the radius:";
                cin>>r;
                link->set_radius(r);
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
    do
    {
        cin >> material_Selector;
        if(material_Selector > 10 || material_Selector < 1)
        {
            cout << "Invalid value ... try again\n";
        }
        else if(material_Selector == 10)
        {
            cout << "Enter the material's name ";
            cin >> new_Name;
            materials[9].set_Name(new_Name);
            do
            {
                cout << "\nEnter the material yield strength (in MPa) ";
                cin >> new_Yieldstrength;
                materials[9].set_Yieldstrength(new_Yieldstrength);
                cout <<"\nEnter the material Density (in g/cm^3) ";
                cin >> new_Density;
                materials[9].set_Density(new_Density);
                materials[9].set_Id(10);
            }
            while(materials[9].check_material());
        }
    }
    while(material_Selector > 10 || material_Selector < 1);
    Selected_material = materials[material_Selector-1];
    // Get  pay load math and maximum angular acceleration
    do
    {
        cout << "Please enter the pay load mass (in Kg) ...";
        cin >> mp;
        link->set_payload_m(mp);
        if(mp < 0)cout<<"Invalid input try again"<<endl;
    }
    while(mp <= 0 );
    cout << "\n Please enter the maximum angular acceleration (in mm/s^2) ...";
    cin >> max_acc;
    link->set_max_angular_acc(max_acc);
    // stress calculations
    checkStress(Selected_material,*link);
    cout << "the math"<<link->get_mass()<<" ";

    // -------------------- Part 2 ----------------------------

   string motor_name; double motor_torque; double motor_speed; double motor_mass; double motor_diameter; double motor_width; double motor_cost;
    Motor M1(motor_name,motor_torque,motor_speed,motor_mass,motor_diameter,motor_width,motor_cost);
    cout << "enter the motor name: " <<endl;
    cin>> motor_name;
     cout << "enter the motor torque: " <<endl;
    cin>> motor_torque;
     cout << "enter the motor speed " <<endl;
    cin>> motor_speed;
     cout << "enter the motor mass: " <<endl;
    cin>> motor_mass;
     cout << "enter the motor diameter: " <<endl;
    cin>> motor_diameter;
     cout << "enter the motor width: " <<endl;
    cin>> motor_width;
     cout << "enter the motor cost: " <<endl;
    cin>> motor_cost;

/////////////////////////////////////////////////////////////////////////////////////////

    string n; double rat; double e; double m; double d; double w; double c;
    cout << "enter the gearbox name: " <<endl;
    cin>> n;
     cout << "enter the gearbox ratio: " <<endl;
    cin>> rat;
     cout << "enter the gearbox effeciency " <<endl;
    cin>> e;
     cout << "enter the gearbox mass: " <<endl;
    cin>> m;
     cout << "enter the gearbox diameter: " <<endl;
    cin>> d;
     cout << "enter the gearbox width: " <<endl;
    cin>> w;
     cout << "enter the gearbox cost: " <<endl;
    cin>> c;
    Gearbox G1(n,rat,e,m,d,w,c);

    return 0;
}
