#include <iostream>
#include <string>
#include "matrials.h"
#include <stdio.h>

using namespace std;

Matrial::Matrial(){
    Yieldstrength = 0;
    Density = 0;
}
Matrial::Matrial(string name,float yieldstrength,float density){
    Name=name;
    Yieldstrength=yieldstrength;
    Density=density;
}
string Matrial::get_Name(){
    return Name;
}
float Matrial::get_Yieldstrength(){
    return Yieldstrength;
}
float Matrial::get_Density(){
    return Density;
}
// material data base
Matrial CastIron("Cast iron",130,7.3);
Matrial CopperNickel ("copper nickel",130,8.94);
Matrial Brass("Brass",200,8.73);
Matrial Aluminum("Aluminum",241,2.7);
Matrial Steel ("steel",247,7.58);
Matrial Acrylic("Acrylic",72,1.16);
Matrial Copper ("Copper",70,8.92);
Matrial StainlessSteel ("Stainless steel",275,7.86);
Matrial Tungsten ("Tungsten",941,19.25);




