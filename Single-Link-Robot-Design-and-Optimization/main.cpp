#include <iostream>
#include "matrials.h"
#include "matrials.c"
#include <string>
using namespace std;
int main()
{

    int shape_selector;
    int material_Selector;
    cout << "please select a cross-section shape \n" <<
     " (1) for rectangular \n (2) for circular" <<endl;
    cin >> shape_selector ;
    cout << "please select material from the data show (0) to add new material\n";
    cout << "1 ->"<<CastIron.get_Name() <<endl;
    cout << "2 ->"<<CopperNickel.get_Name() <<endl;
    cout << "3 ->"<<Brass.get_Name() <<endl;
    cout << "4 ->"<<Aluminum.get_Name() <<endl;
    cout << "5 ->"<<Steel.get_Name() <<endl;
    cout << "6 ->"<<Acrylic.get_Name() <<endl;
    cout << "7 ->"<<Copper.get_Name() <<endl;
    cout << "8 ->"<<StainlessSteel.get_Name() <<endl;
    cout << "9 ->"<<Tungsten.get_Name() <<endl;
    cin >> material_Selector;
    if (shape_selector == 1){
    }else if (shape_selector == 2){
    }else{
    }
    return 0;
}
