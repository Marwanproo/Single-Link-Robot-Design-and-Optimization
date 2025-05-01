#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Link.h"
#include "matrials.h"
const float g = 9.81;
const float PI = 22.0/7.0;
void checkStress(const float& s_y,Link& l,const float& d){
l.set_mass(d);
    l.set_momentOfInertia();
    l.set_bendingMoment();
    l.set_max_stress();
    cout<< "    "<<l.get_max_stress()<<"    "<<endl;
    if(l.get_max_stress() > s_y){
            do{
            l.increase_dimensions();
            l.set_mass(d);
            l.set_momentOfInertia();
            l.set_bendingMoment();
            l.set_max_stress();
            }while(l.get_max_stress() >= s_y);
            cout << "the final length "<< l.get_length()<<endl;
            if(l.get_radius()==0.0){
                cout << "the final high "<< l.get_high()<<endl;
                cout << "the final width "<<l.get_width()<<endl;
            }else{
                cout << "the final radius "<<l.get_radius()<<endl;
            }
            cout << l.get_max_stress();
    }else{
            do{
            l.increase_dimensions();
            l.set_mass(d);
            l.set_momentOfInertia();
            l.set_bendingMoment();
            l.set_max_stress();
            }while(l.get_max_stress() < s_y);
            cout << "the final length "<< l.get_length()<<endl;
            if(l.get_radius()==0.0){
                cout << "the final high "<< l.get_high()<<endl;
                cout << "the final width "<<l.get_width()<<endl;
            }else{
                cout << "the final radius "<<l.get_radius()<<endl;
            }
            cout << l.get_max_stress();
    }
}

