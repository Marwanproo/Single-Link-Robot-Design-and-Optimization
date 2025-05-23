#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Link.h"
#include "matrials.h"
#include <limits>
using namespace std;
const float g = 9.81*1000;
const float PI = 22.0/7.0;
const float D_Unit = pow(10,-6);
void checkStress(Matrial& m,Link& l)
{
    cout<< m.get_Id()<<endl;
    l.set_mass(m.get_Density());
    l.set_momentOfInertia();
    l.set_bendingMoment();
    l.set_max_stress();
    cout << "The math" << l.get_mass()<<endl;
    cout<< "The stress is: "<<l.get_max_stress()<<"    "<<endl;
    if(l.get_max_stress() > m.get_Yieldstrength())
    {
        while(l.get_max_stress() >= m.get_Yieldstrength())
        {
            l.increase_dimensions();
            l.set_mass(m.get_Density());
            l.set_momentOfInertia();
            l.set_bendingMoment();
            l.set_max_stress();
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
    cout << "The math:" << l.get_mass()<<endl;
    cout <<"The max stress is: "<< l.get_max_stress()<<" MPa"<<endl;
}
auto checkValidation(auto r1, auto r2)
{
    double var;
    do
    {
        cin >> var;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(var  < r1 || var > r2){
            cout << "Invalid input please try again : " << "\a";
        }
    }
    while(var  < r1 || var > r2);
    return var;
}

