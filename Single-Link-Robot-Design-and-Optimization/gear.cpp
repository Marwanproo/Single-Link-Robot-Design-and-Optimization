#include <iostream>
#include <vector>
#include <cmath>
#include "gear.h"
using namespace std;
    Gearbox::Gearbox(){};
    Gearbox::Gearbox(string n, float r, float e, float m, float d, float w)
        : name(n), _ratio(r), efficiency(e), mass(m), diameter(d), width(w) {}
    float Gearbox::calculateCost()
    {
        cost = mass + (diameter / 100.0) + (width / 100.0);
    }

    void Gearbox::set_name(string n)
    {
        name=n;
    }
    void Gearbox::set_ratio(float r)
    {
        _ratio=r;
    }
    void Gearbox::set_efficiency(float e)
    {
        efficiency=e;
    }
    void Gearbox::set_mass(float m)
    {
        mass=m;
    }
    void Gearbox::set_diameter (float d)
    {
        diameter=d;
    }
    void Gearbox::set_width (float w)
    {
        width=w;
    }
    void Gearbox::set_cost ()
    {
        cost=mass + diameter/100 + width/100;
    }

string Gearbox::get_name() const
    {
        return name;
    }
float Gearbox::get_ratio() const{
    return _ratio;
}
float Gearbox::get_efficiency() const{
    return efficiency;
}
float Gearbox::get_cost(){
    cost = mass + diameter/100 + width/100;
    return cost;
}
float Gearbox::get_diameter()const{
    return diameter;
}
float Gearbox::get_mass()const{
    return mass;
}


