#include <iostream>
#include <string>
#include <vector>
#include <cmath>
const float PI = 22.0/7.0;
const float g = 9.81;
float linkMass1(const float& D,const float& l,const float& h,const float& b){
    float m = (D*l*h*b);
    return m;
}
float linkMass2(const float& D,const float& l,const float& r){
    float m = D*l*pow(r,2)*PI;
    return m;
}
float bendingMoment(const float& ml,const float& mp , const float& l , const float& max_acc){
    float M = (ml*g*l/2)+(mp*g*l)+(ml*pow((l/2),2)*max_acc)+(mp*pow(l,2)*max_acc);
    return M;
}
float momentOfInertia1(const float& h,const float& b){
    float I = (b*pow(h,3))/12;
    return I;
}
float momentOfInertia2(const float& r){
    float I = (PI*pow(r,4))/4;
    return I;
}
float maximumStress1(const float& M,const float& I, const float& h){
    float max_stress = (M*h)/(2*I);
    return max_stress;
}
float maximumStress2(const float& M,const float& I, const float& r){
    float max_stress = (M*r)/I;
    return max_stress;
}
