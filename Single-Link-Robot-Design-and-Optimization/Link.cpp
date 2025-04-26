#include <iostream>
#include "matrials.h"
#include "matrials.cpp"
#include <string>
#include <vector>
#include "Functions.h"
#include "Functions.cpp"
#include "link.h"
class Link{
    public:
        Link();
        Link(float l , float h , float b);
        Link(float l,float r);
        float get_length();
        float get_high();
        float get_width();
        float get_radius();
        void set_length();
        void set_high();
        void set_width();
        void set_radius();
    private:
        float length;
        float high;
        float width;
        float radius;
};
