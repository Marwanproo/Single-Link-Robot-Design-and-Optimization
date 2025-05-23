
#ifndef GEARBOX_H_INCLUDED
#define GEARBOX_H_INCLUDED
#include <string>
#include <vector>


using namespace std;
class Gearbox {
public:
    Gearbox();
    Gearbox(string n, double r, double e, double m, double d, double w, double c);
    double calculateCost();
    string get_name();
    void set_name(string n);
    void set_ratio(double r);
    void set_efficiency(double e);
    void set_mass(double m);
    void set_diameter(double d);
    void set_width(double w);
    void set_cost(double c);
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

