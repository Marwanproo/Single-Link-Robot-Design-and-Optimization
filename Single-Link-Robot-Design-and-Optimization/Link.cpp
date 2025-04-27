#include <iostream>
#include <string>
#include <vector>
#include "Link.h"
#include <stdio.h>

        Link::Link(){};
        Link::Link(float l , float h , float b , float r){
            length = l;
            high=h;
            width=b;
            radius=r;
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
        void Link::set_length(float l){
            length = l;
        }
        void Link::set_high(float h){
            high =h;
        }
        void Link::set_width(float b){
            width = b;
        }
        void Link::set_radius(float r){
            radius=r;
        }
        void Link::set_mass(float m){
            mass = m;
        }
        bool Link::check_Link()const{
            bool valid;
            if((length <= 0 || width <= 0 || high <= 0  || high>=length || width>=length || width > high)&&radius ==0 ){
                valid = true;
                cout << "Invalid link dimensions make sure length > 0 & width > 0 & high > 0  & high<length & width<length & width<high"<<endl;
            }else if((length <= 0 || radius <=0)&&high==0){
                cout << "Invalid link dimensions make sure length >0 & length > radius & radius > 0 "<<endl;
                valid = true;
            }else {
                valid = false;
            }

            return valid;
        }


