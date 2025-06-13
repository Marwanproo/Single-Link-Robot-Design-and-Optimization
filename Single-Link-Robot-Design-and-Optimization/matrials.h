#include <iostream>
#include <string>
#include <vector>
#ifndef MATRIALS_H_INCLUDED
#define MATRIALS_H_INCLUDED

using namespace std;
class Matrial
{
public:
    Matrial();
    Matrial(string name,float yieldstrength, float density,int id);
    string get_Name() const;
    float get_Yieldstrength() const;
    float get_Density() const;
    int get_Id() const;
    void set_Name(string n);
    void set_Yieldstrength(float y);
    void set_Density(float d);
    void set_Id(int id);
private:
    string Name;
    float Yieldstrength;
    float Density;
    int Id;
};

#endif // MATRIALS_H_INCLUDED
