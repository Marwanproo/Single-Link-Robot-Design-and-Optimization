#include <iostream>
#include <string>
#include <vector>
#include "matrials.h"
#include "matrials.cpp"
#include "Functions.h"
#include "Functions.cpp"
#include "Link.h"
#include "Link.cpp"
using namespace std;
int main()
{
    Link* link=new Link();
    int shape_selector;
    int material_Selector;
    float l,h,b,r,mp,max_acc;
    // selecting the initial dimintions
    do{
        do{
            cout << "please select a cross-section shape \n" <<" (1) for rectangular \n (2) for circular" <<endl;
            cin >> shape_selector ;
            if (shape_selector == 1){
                cout <<"please enter the initial dimensions (in Millimeter)."<<endl;
                cout <<"the length ..."; cin >>l;link->set_length(l);
                cout <<"the hight ...";cin >>h;link->set_high(h);
                cout <<"the width ...";cin >>b;link->set_width(b);
            }else if (shape_selector == 2){
                cout <<"please enter the initial dimensions (in Millimeter)"<<endl;
                cout <<"the length ..."; cin >>l;link->set_length(l);
                cout <<"the radius ...";cin>>r;link->set_radius(r);
            }else{
                cout << "not valid input try again\n";
            }
        }while(shape_selector !=1 && shape_selector !=2);
    }while(link->check_Link());
    // presenting the materials
    cout << "please select material from the data show (0) to add new material\n";
    for(int i=0;i<9;i++){cout << materials[i].get_Id()<< " --> "
        <<materials[i].get_Name() << " Yield strength: (MPa)"<< materials[i].get_Yieldstrength()
        << " Density: (g/cm^3)"<< materials[i].get_Density() <<endl;}
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
            cout << "Enter the material name "; cin >> new_Name;
                do{
                    cout << "\nEnter the material yield strength (in MPa) "; cin >> new_Yieldstrength;
                    cout <<"\nEnter the material Density (in g/cm^3) "; cin >> new_Density;
                    materials[9].set_Name(new_Name);
                    materials[9].set_Density(new_Density);
                    materials[9].set_Yieldstrength(new_Yieldstrength);
                }while(materials[9].check_material());
                cout << materials[9].get_Name()<<" "<<materials[9].get_Yieldstrength()<<" "
                << materials[9].get_Density() <<endl;
            }
    }while(material_Selector > 9 || material_Selector < 0);
    // Get  pay load math and maximum angular acceleration
    // hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    cout << "Please enter the pay load mass (in Kg) ..."; cin >> mp; link->set_payload_m(mp);
    cout << "\n Please enter the maximum angular acceleration (in mm/s^2) ..."; cin >> max_acc;link->set_max_angular_acc(max_acc);
    // stress calculations
    Matrial Selected_material = materials[material_Selector-1];
    checkStress(Selected_material.get_Yieldstrength(),*link,Selected_material.get_Density());


    return 0;
}
