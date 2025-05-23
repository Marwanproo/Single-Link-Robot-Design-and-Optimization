#include <iostream>
#include <string>
#include <vector>
#include "Link.h"
using namespace std;
Link::Link(){};
Link::Link(float l , float h , float b , float r,float m){
    length = l;
    high=h;
    width=b;
    radius=r;
    mass = m;
}
float Link::get_length() const{
    return length;
}
float Link::get_high() const{
    return high;
}
float Link::get_width() const{
    return width;
}
float Link::get_radius() const{
    return radius;
}
float Link::get_mass()const{
    return mass;
}
float Link::get_max_angular_acc() const{
    return max_angular_acc;
}
float Link::get_payload_m() const{
    return payload_m;
}
float Link::get_bendingMoment()const{
    return bendingMoment;
}
float Link::get_max_stress() const{
    return max_stress;
}
void Link::set_length(float l){
    length = l;
}
void Link::set_high(float h){
    high =h;
    radius=0.0;
}
void Link::set_width(float b){
    width = b;
}
void Link::set_radius(float r){
    radius=r;
    high=0.0;
    width=0.0;
}
void Link::set_mass(float d){
    if(radius == 0 ){
        mass = (d*D_Unit*length*high*width);
    }
    if(high == 0 && width == 0){
        mass = d*D_Unit*length*pow(radius,2)*PI;
    }
}
bool Link::check_Link()const{
    bool valid = false;
    if(length <= high||length <= width || length <= radius || length <= 0 || high < 0|| width < 0 || radius <0){
        valid = true;
        cout << "Invalid inputs"<<endl;
    }
    return valid;
}
float Link::get_momentOfInertia() const{
    return momentOfInertia;
}
void Link::set_momentOfInertia(){
    if(radius == 0 ){
        if(high > width){
            momentOfInertia = (width*pow(high,3))/12;
        }else if (width > high){
            momentOfInertia = (high*pow(width,3))/12;
        }
    }
    if(high == 0 && width == 0){
        momentOfInertia = (PI*pow(radius,4))/4;
    }
}
void Link::reduce_dimensions(){
    high =- (0.01 * high) ;
    width =- (0.01 * width);
    radius =- (0.01 * radius);
}
void Link::increase_dimensions(){
    if (radius == 0 ){
    high += (0.01 * high) ;
    width += (0.01 * width);
    }
    if(high == 0){
        radius += (0.01 * radius);
    }
}
void Link::set_max_angular_acc(float a){
    max_angular_acc=a;
}
void Link::set_payload_m(float m){
    payload_m=m;
}
void Link::set_bendingMoment(){
    bendingMoment = (mass*g*length*0.5)+(payload_m*g*length)
    + (mass*pow((length*0.5),2)*max_angular_acc+payload_m*pow(length,2)*max_angular_acc);
    }
void Link::set_max_stress(){
    if (radius==0.0){
            max_stress = (bendingMoment*high)/(2.0*momentOfInertia);
    }else{
            max_stress = (bendingMoment*radius)/momentOfInertia;
    }
}




