#include <iostream>
#include <vector>
#include <cmath>
#include "gear.h"
using namespace std;

    double Gearbox::calculateCost()
    {
        cost = mass + (diameter / 100.0) + (width / 100.0);
    }

    Gearbox::Gearbox(){};
    Gearbox::Gearbox(string n, double r, double e, double m, double d, double w, double c)
        : name(n), _ratio(r), efficiency(e), mass(m), diameter(d), width(w), cost(c) {}

    void Gearbox::set_name(string n)
    {
        name=n;
    }
    void Gearbox::set_ratio(double r)
    {
        _ratio=r;
    }
    void Gearbox::set_efficiency(double e)
    {
        efficiency=e;
    }
    void Gearbox::set_mass(double m)
    {
        mass=m;
    }
    void Gearbox::set_diameter (double d)
    {
        diameter=d;
    }
    void Gearbox::set_width (double w)
    {
        width=w;
    }
    void Gearbox::set_cost (double c)
    {
        cost=c;
    }

string Gearbox::get_name ()
    {
        return name;
    }

