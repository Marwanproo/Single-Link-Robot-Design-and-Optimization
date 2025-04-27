#include <iostream>
#include "matrials.h"
#include "matrials.cpp"
#include <string>
#include <vector>
#include "Functions.h"
#include "Functions.cpp"
#include "Link.h"
#include "Link.cpp"
using namespace std;
int main()
{
    int shape_selector;
    int material_Selector;
    Link link(0,0,0,0);
    float l,h,b,r;
    float payload_m = 0.0;
    float max_angular_acc = 0.0;
    float max_stress = 0.0 ;
    float M = 0.0;
    float I = 0.0;
    // selecting the initial dimintions
    do{
        do{
            cout << "please select a cross-section shape \n" <<" (1) for rectangular \n (2) for circular" <<endl;
            cin >> shape_selector ;
            if (shape_selector == 1){
                cout <<"please enter the initial dimensions (in meter)."<<endl;
                cout <<"the length ..."; cin >>l;link.set_length(l);
                cout <<"the hight ...";cin >>h;link.set_high(h);
                cout <<"the width ...";cin >>b;link.set_width(b);
            }else if (shape_selector == 2){
                cout <<"please enter the initial dimensions"<<endl;
                cout <<"the length ..."; cin >>l;link.set_length(l);
                cout <<"the radius ...";cin>>r;link.set_radius(r);
            }else{
                cout << "not valid input try again\n";
            }
        }while(shape_selector !=1 && shape_selector !=2);
    }while(link.check_Link());
    // presenting the materials
    cout << "please select material from the data show (0) to add new material\n";
    for(int i=0;i<9;i++){cout << materials[i].get_Id()<< " --> "
        <<materials[i].get_Name() << " Yield strength: "<< materials[i].get_Yieldstrength()
        << " Density: "<< materials[i].get_Density() <<endl;}
    // selecting the material
    do{
        cin >> material_Selector;
        for(int i=0;i<9;i++){
            if(material_Selector == materials[i].get_Id()){
                }}
        if(material_Selector > 9 || material_Selector < 0){
            cout << "not valid value ... try again\n";
        }else if(material_Selector == 0){
            string new_Name;
            float new_Yieldstrength , new_Density;
            // hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
            cout << "Enter the material name "; cin >> new_Name;
            cout << "\nEnter the material yield strength (in MPa) "; cin >> new_Yieldstrength;
            cout <<"\nEnter the material Density (in g/cm^3) "; cin >> new_Density;
            materials[9].set_Name(new_Name);
            materials[9].set_Density(new_Density);
            materials[9].set_Yieldstrength(new_Yieldstrength);
            cout << materials[9].get_Name()<<" "<<materials[9].get_Yieldstrength()<<" "<< materials[9].get_Density() <<endl;
        }
    }while(material_Selector > 9 || material_Selector < 0);
    // Get  pay load math and maximum angular acceleration
    // hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    cout << "Please enter the pay load mass (in Kg) ..."; cin >> payload_m;
    cout << "\n Please enter the maximum angular acceleration (in m/s^2) ..."; cin >> max_angular_acc;
    // stress calculations
    Matrial Selected = materials[material_Selector];
    M = bendingMoment(link.get_mass(),payload_m,link.get_length(),max_angular_acc);
    if(shape_selector == 1){
        link.set_mass(linkMass1(3,link.get_length(),link.get_high(),link.get_width()));
        I = momentOfInertia1(link.get_high(),link.get_width());
        max_stress = maximumStress1(M,I,link.get_high());
    }else{
        link.set_mass(linkMass2(3,link.get_length(),link.get_radius()));
        I = momentOfInertia2(link.get_radius());
        max_stress = maximumStress2(M,I,link.get_radius());
    }
    cout << " the max stress === "<< max_stress ;
    return 0;
}
