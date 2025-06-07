#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
class Link{
    public:
        Link();
        Link(float l , float h , float b , float r,float m);
        float get_length() const;
        float get_high() const;
        float get_width() const;
        float get_radius() const;
        float get_mass() const;
        float get_momentOfInertia() const;
        float get_max_angular_acc() const;
        float get_payload_m() const;
        float get_bendingMoment()const;
        float get_max_stress()const;
        float get_torque_req()const;
        float get_speed_req()const;
        bool check_Link() const;
        void set_length(float l);
        void set_high(float h);
        void set_width(float b) ;
        void set_radius(float r);
        void set_mass(float d);
        void reduce_dimensions();
        void increase_dimensions();
        void set_momentOfInertia();
        void set_max_angular_acc(float a);
        void set_payload_m(float m);
        void set_bendingMoment();
        void set_max_stress();
        void set_torque_req();
        void set_speed_req(float s);
    private:
        float length;
        float high;
        float width;
        float radius;
        float mass;
        float momentOfInertia;
        float max_angular_acc;
        float payload_m;
        float max_stress;
        float bendingMoment;
        float torque_req;
        float speed_req;
};

#endif // LINK_H_INCLUDED
