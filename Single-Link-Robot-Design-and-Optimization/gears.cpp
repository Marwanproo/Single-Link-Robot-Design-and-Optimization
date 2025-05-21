#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Gearbox {
private:
    string name;
    double ratio;
    double efficiency;
    double mass;
    double diameter;
    double width;
    double cost;

    double calculateCost() const {
        return mass + (diameter / 100.0) + (width / 100.0);
    }

    vector<Gearbox> filterByEfficiency(const vector<Gearbox>& gearboxes, double minEfficiency) const {
        vector<Gearbox> filtered;
        for (const auto& g : gearboxes) {
            if (g.efficiency >= minEfficiency) {
                filtered.push_back(g);
            }
        }
        return filtered;
    }

    vector<Gearbox> filterByRatio(const vector<Gearbox>& gearboxes, double requiredRatio) const {
        vector<Gearbox> filtered;
        for (const auto& g : gearboxes) {
            if (g.ratio >= requiredRatio) {
                filtered.push_back(g);
            }
        }
        return filtered;
    }

    Gearbox findBestGearbox(const vector<Gearbox>& gearboxes) const {
        if (gearboxes.empty()) return Gearbox();
        Gearbox best = gearboxes[0];
        double minCost = best.calculateCost();

        for (const auto& g : gearboxes) {
            double currentCost = g.calculateCost();
            if (currentCost < minCost) {
                minCost = currentCost;
                best = g;
            }
        }
        return best;
    }

    void display() const {
        if (name.empty()) {
            cout << "No suitable gearbox found.\n";
            return;
        }

        cout << "Best Gearbox Selection:\n";
        cout << "Name: " << name << "\n";
        cout << " Ratio: " << ratio << "\n";
        cout << " Efficiency: " << efficiency << "\n";
        cout << " Mass: " << mass << " kg\n";
        cout << " Diameter: " << diameter << " mm\n";
        cout << " Width: " << width << " mm\n";
        cout << " Cost: " << cost << "\n";
        cout << " Cost Function Value: " << calculateCost() << "\n";
    }

public:
    Gearbox() = default;
    Gearbox(string n, double r, double e, double m, double d, double w, double c)
        : name(n), ratio(r), efficiency(e), mass(m), diameter(d), width(w), cost(c) {}

    void selectAndDisplayGearbox(const vector<Gearbox>& allGearboxes, double reqRatio, double minEff) {
        vector<Gearbox> efficientGearboxes = filterByEfficiency(allGearboxes, minEff);
        vector<Gearbox> validGearboxes = filterByRatio(efficientGearboxes, reqRatio);
        Gearbox best = findBestGearbox(validGearboxes);
        best.display();
    }

string set_name(string n)
    {
        name=n;
        return name;
    }
double set_ratio(double r)
    {
        ratio=r;
        return ratio;
    }
double set_eff(double e)
    {
        efficiency=e;
        return efficiency;
    }
double set_mass (double m)
    {
        mass=m;
        return mass;
    }
double set_diameter (double d)
    {
        diameter=d;
        return diameter;
    }
double set_width (double w)
    {
        width=w;
        return width;
    }
 double set_cost (double c)
    {
        cost=c;
        return cost;
    }


};


