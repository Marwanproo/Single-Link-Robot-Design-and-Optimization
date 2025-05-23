#ifndef GEARBOX_H_INCLUDED
#define GEARBOX_H_INCLUDED
#include <string>
#include <vector>
using namespace std;
class Gearbox {
public:
    Gearbox();
    Gearbox(string n, double r, double e, double m, double d, double w, double c);
    string get_name() const;
    double get_ratio() const;
    double get_efficiency() const;
    double get_mass() const;
    double get_diameter() const;
    double get_width() const;
    double get_cost() const;
    double get_cost_function() const;
    double calculateCost() const;
    void set_name(string n);
    void set_ratio(double r);
    void set_efficiency(double e);
    void set_mass(double m);
    void set_diameter(double d);
    void set_width(double w);
    void set_cost(double c);
    vector<Gearbox> filterByEfficiency(const vector<Gearbox>& gearboxes, double minEfficiency) const;
    vector<Gearbox> filterByRatio(const vector<Gearbox>& gearboxes, double required_ratio) const;
    Gearbox findBestGearbox(const vector<Gearbox>& gearboxes) const;
    void display() const;
    void selectAndDisplayGearbox(const vector<Gearbox>& all_gearboxes,
    double req_ratio,
    double min_efficiency);
private:
    string name;
    double _ratio;
    double efficiency;
    double mass;
    double diameter;
    double width;
    double cost;
};
#endif

