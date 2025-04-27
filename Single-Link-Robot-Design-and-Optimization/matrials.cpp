#include <iostream>
#include <string>
#include <vector>
#include "matrials.h"
#include <stdio.h>
using namespace std;

Matrial::Matrial(){
    Name=" ";
    Yieldstrength=0;
    Density=0;
    Id=0;
}
Matrial::Matrial(string name,float yieldstrength,float density,int id)
: Name(name), Yieldstrength(yieldstrength), Density(density) , Id(id){}
string Matrial::get_Name() const{
    return Name;
}
float Matrial::get_Yieldstrength() const{
    return Yieldstrength;
}
float Matrial::get_Density() const{
    return Density;
}
int Matrial::get_Id() const{
    return Id;
}
void Matrial::set_Name(string n){
    Name = n;
}
void Matrial::set_Yieldstrength(float y){
    Yieldstrength = y;
}
void Matrial::set_Density(float d){
    Density = d;
}
void Matrial::set_Id(int id){
    Id = id ;
}
bool Matrial::check_material() const{
    bool valid;
    if(Yieldstrength <= 0 || Density <= 0){
        cout << "Not valid parameter.." <<endl;
        valid = false;
    }
    if(Density > 22.5){

    }
}
// materials data base


Matrial materials[10]={
    Matrial("Cast iron",130,7.3,1),
    Matrial("copper nickel",130,8.94,2),
    Matrial("Brass",200,8.73,3),
    Matrial("Aluminum",241,2.7,4),
    Matrial("steel",247,7.58,5),
    Matrial("Acrylic",72,1.16,6),
    Matrial("Copper",70,8.92,7),
    Matrial("Stainless steel",275,7.86,8),
    Matrial("Tungsten",941,19.25,9),
    Matrial()
    };





