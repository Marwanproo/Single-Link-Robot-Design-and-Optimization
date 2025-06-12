
#ifndef GEARBOX_H_INCLUDED
#define GEARBOX_H_INCLUDED
#include <string>
#include <vector>


using namespace std;
class Gearbox {
public:
    Gearbox();
    Gearbox(string n, float r, float e, float m, float d, float w);
    float calculateCost();
    string get_name() const;
    float get_ratio() const;
    float get_efficiency() const;
    float get_cost() ;
    float get_diameter()const;
    float get_mass()const;
    void set_name(string n);
    void set_ratio(float r);
    void set_efficiency(float e);
    void set_mass(float m);
    void set_diameter(float d);
    void set_width(float w);
    void set_cost();
    vector<Gearbox> gearboxes;
private:
    string name;
    float _ratio;
    float efficiency;
    float mass;
    float diameter;
    float width;
    float cost;
};
#endif

