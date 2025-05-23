#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Gears -1.h"
#include <stdio.h>
using namespace std;

    /*double Gearbox::calculateCost() const
    {
        cost = mass + (diameter / 100.0) + (width / 100.0);
    }

   /* vector<Gearbox> Gearbox::filterByEfficiency(const vector<Gearbox>& gearboxes, double minEfficiency) const
    {
        vector<Gearbox> filtered;
        for (const auto& g : gearboxes)
        {
            if (g.efficiency >= minEfficiency)
            {
                filtered.push_back(g);
            }
        }
        return filtered;
    }

    vector<Gearbox> Gearbox::filterByRatio(const vector<Gearbox>& gearboxes, double requiredRatio) const
    {
        vector<Gearbox> filtered;
        for (const auto& g : gearboxes)
        {
            if (g._ratio >= requiredRatio)
            {
                filtered.push_back(g);
            }
        }
        return filtered;
    }

    /* Gearbox::findBestGearbox(const vector<Gearbox>& gearboxes) const
    {
        if (gearboxes.empty()) return Gearbox();
        Gearbox best = gearboxes[0];
        double minCost = best.calculateCost();

        for (const auto& g : gearboxes)
        {
            double currentCost = g.calculateCost();
            if (currentCost < minCost)
            {
                minCost = currentCost;
                best = g;
            }
        }
        return best;
    }

    void Gearbox::display() const
    {
        if (name.empty())
        {
            cout << "No suitable gearbox found.\n";
            return;
        }

        cout << "Best Gearbox Selection:\n";
        cout << "Name: " << name << "\n";
        cout << " Ratio: " << _ratio << "\n";
        cout << " Efficiency: " << efficiency << "\n";
        cout << " Mass: " << mass << " kg\n";
        cout << " Diameter: " << diameter << " mm\n";
        cout << " Width: " << width << " mm\n";
        cout << " Cost: " << cost << "\n";
        //cout << " Cost Function Value: " << calculateCost() << "\n";
    }*/

    Gearbox::Gearbox(){};
    Gearbox::Gearbox(string n, double r, double e, double m, double d, double w, double c)
        : name(n), _ratio(r), efficiency(e), mass(m), diameter(d), width(w), cost(c) {}

    void Gearbox::selectAndDisplayGearbox(const vector<Gearbox>& allGearboxes, double reqRatio, double minEff)
    {
        vector<Gearbox> efficientGearboxes = filterByEfficiency(allGearboxes, minEff);
        vector<Gearbox> validGearboxes = filterByRatio(efficientGearboxes, reqRatio);
        Gearbox best = findBestGearbox(validGearboxes);
        best.display();
    }

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



