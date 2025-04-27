#include <iostream>
#include <string>
#include <vector>
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
float linkMass1(const float& D,const float& l,const float& h,const float& b);
float linkMass2(const float& D,const float& l,const double& r);
float bendingMoment(const float& ml,const float& mp , const float& l , const float& max_acc);
float momentOfInertia1(const float& h,const float& b);
float momentOfInertia2(const float& r);
float maximumStress1(const float& M,const float& I, const float& h);
float maximumStress2(const float& M,const float& I, const float& r);

#endif // FUNCTIONS_H_INCLUDED
