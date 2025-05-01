#include <iostream>
#include <string>
#include <vector>
#include "Link.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
float bendingMoment(const float& ml,const float& mp , const float& l , const float& max_acc);
float maximumStress1(const float& M,const float& I, const float& h);
float maximumStress2(const float& M,const float& I, const float& r);
void checkStress(const float& s_y,Link& l,const float& d);
#endif // FUNCTIONS_H_INCLUDED
