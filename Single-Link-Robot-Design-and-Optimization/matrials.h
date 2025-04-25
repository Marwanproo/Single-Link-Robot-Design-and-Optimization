#include <iostream>
#include <string>
#ifndef MATRIALS_H_INCLUDED
#define MATRIALS_H_INCLUDED

using namespace std;

class Matrial {
    public:
        Matrial();
        Matrial(string name,float yieldstrength, float density);
        string get_Name();
        float get_Yieldstrength();
        float get_Density();
    private:
        string Name;
        float Yieldstrength;
        float Density;
};
#endif // MATRIALS_H_INCLUDED
