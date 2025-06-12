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
vector<Gearbox> gearboxes= {
Gearbox ("g1",19,81,23/1000,16,19.1),
Gearbox ("g2",84,73,27/1000,16,22.7),
Gearbox ("g3",24,81,31/1000,19,19.5),
Gearbox ("g4",84,73,36/1000,19,23.1),
Gearbox ("g5",27,80,77/1000,26,32.9),
Gearbox ("g6",71,70,93/1000,26,39.5),
Gearbox ("g7",103,75,21/1000,14,25.5),
Gearbox ("g8",243,65,23/1000,14,30.3),
Gearbox ("g9",84,59,68/1000,22,36.2),
Gearbox ("g10",370,49,81/1000,22,43),
};
