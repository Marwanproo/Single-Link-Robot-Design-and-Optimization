#include <iostream>
#include "matrials.h"
#include "matrials.cpp"
#include <string>
#include <vector>
#include "Functions.h"
#include "Functions.cpp"
#include "link.h"

using namespace std;
int main()
{
    int shape_selector;
    int material_Selector;
    float l,h,b,r; // The initial dimensions of the link
    float payload_m = 0.0;
    float link_math = 0.0;
    float max_angular_acc = 0.0;
    Matrial Selected;
    // selecting the initial dimintions
    do{
        cout << "please select a cross-section shape \n" <<" (1) for rectangular \n (2) for circular" <<endl;
        cin >> shape_selector ;
        if (shape_selector == 1){
            cout <<"please enter the initial dimensions (in meter)."<<endl;
            cout <<"the length ..."; cin >>l;
            cout <<"the hight ...";cin >>h;
            cout <<"the width ...";cin >>b;
            //link_math = linkMath1(,l,h,b);
        }else if (shape_selector == 2){
            cout <<"please enter the initial dimensions"<<endl;
            cout <<"the length ..."; cin >>l;
            cout <<"the radius ...";cin>>r;
            //link_math = linkMath2(,l,r);
        }else{
            cout << "not valid input try again\n";
        }
    }while(shape_selector !=1 && shape_selector !=2);
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
                cout<<materials[i].get_Id() << " --> " << materials[i].get_Name()<<endl;
            }
        }
        if(material_Selector > 9 || material_Selector < 0){
            cout << "not valid value ... try again\n";
        }else if(material_Selector == 0){
            string new_Name;
            float new_Yieldstrength , new_Density;
            cout << "Enter the material name "; cin >> new_Name;
            cout << "\nEnter the material yield strength (in MPa) "; cin >> new_Yieldstrength;
            cout <<"\nEnter the material Density (in meter) "; cin >> new_Density;
            materials[9].set_Name(new_Name);
            materials[9].set_Density(new_Density);
            materials[9].set_Yieldstrength(new_Yieldstrength);
            cout << materials[9].get_Name()<<" "<<materials[9].get_Yieldstrength()<<" "<< materials[9].get_Density() <<endl;
        }
    }while(material_Selector > 9 || material_Selector < 0);
    // Get  pay load math and maximum angular acceleration
    cout << "Please enter the pay load math (in Kg) ..."; cin >> payload_m;
    cout << "\n Please enter the maximum angular acceleration (in m/s^2) ..."; cin >> max_angular_acc;
    return 0;
}
