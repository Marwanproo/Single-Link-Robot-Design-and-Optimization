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
    double calculate_cost() const;
    void set_name(string n);
    void set_ratio(double r);
    void set_efficiency(double e);
    void set_mass(double m);
    void set_diameter(double d);
    void set_width(double w);
    void set_cost(double c);
    vector<Gearbox> filter_by_efficiency(const vector<Gearbox>& gearboxes, double min_efficiency);
    vector<Gearbox> filter_by_ratio(const vector<Gearbox>& gearboxes, double required_ratio);
    Gearbox find_best_gearbox(const vector<Gearbox>& gearboxes);
    void display() const;
    void select_and_display_gearbox(const vector<Gearbox>& all_gearboxes,
    double req_ratio,
    double min_efficiency);
private:
    string name;
    double ratio;
    double efficiency;
    double mass;
    double diameter;
    double width;
    double cost;
};
#endif

