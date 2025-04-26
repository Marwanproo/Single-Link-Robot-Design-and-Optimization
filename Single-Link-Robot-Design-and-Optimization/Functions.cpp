#include <iostream>
#include <string>
#include <vector>
#include <cmath>
const float PI = 22.0/7.0;
float linkMath1(const float& D,const float& l,const float& h,const float& b){
    float m = (D*l*h*b);
    return m;
};
float linkMath2(const float& D,const float& l,const float& r){
    float m = D*l*pow(r,2)*PI;
    return m;
};
