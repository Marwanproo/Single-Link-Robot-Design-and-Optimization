#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Link.h"
#include "matrials.h"
const float g = 9.81*1000;
const float PI = 22.0/7.0;
const float D_Unit = pow(10,-6);
void checkStress(Matrial& m,Link& l){
    cout<< m.get_Id()<<endl;
    l.set_mass(m.get_Density());
    l.set_momentOfInertia();
    l.set_bendingMoment();
    l.set_max_stress();
    cout << "the ratio " << ceil(l.get_max_stress()/m.get_Yieldstrength()) <<endl;
    cout << " s_y " << m.get_Yieldstrength() <<endl;
    cout << "the math" << l.get_mass()<<endl;
    cout << "the bending moment " << l.get_bendingMoment()<<endl;
    cout << "the I " << l.get_momentOfInertia()<<endl;
    cout<< "the stress "<<l.get_max_stress()<<"    "<<endl;
    if(l.get_max_stress() > m.get_Yieldstrength()){
                while(l.get_max_stress() >= m.get_Yieldstrength()){
                    l.increase_dimensions();
                    l.set_mass(m.get_Density());
                    l.set_momentOfInertia();
                    l.set_bendingMoment();
                    l.set_max_stress();
    }
            }else{
                    while(l.get_max_stress() <= m.get_Yieldstrength()){
                        l.reduce_dimensions();
                        l.set_mass(m.get_Density());
                        l.set_momentOfInertia();
                        l.set_bendingMoment();
                        l.set_max_stress();}
            }
            cout << "the final length "<< l.get_length()<<endl;
            if(l.get_radius()==0.0){
                cout << "the final high "<< l.get_high()<<endl;
                cout << "the final width "<<l.get_width()<<endl;
            }else{
                cout << "the final radius "<<l.get_radius()<<endl;
            }
            cout << "the bending moment " << l.get_bendingMoment()<<endl;
            cout << "the I " << l.get_momentOfInertia()<<endl;
            cout <<"the max stress "<< l.get_max_stress()<<endl;
            }

