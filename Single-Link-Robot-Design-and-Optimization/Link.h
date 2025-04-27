#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
class Link{
    public:
        Link();
        Link(float l , float h , float b , float r);
        float get_length() const;
        float get_high() const;
        float get_width() const;
        float get_radius() const;
        float get_mass() const;
        void set_length(float l);
        void set_high(float h);
        void set_width(float b) ;
        void set_radius(float r);
        void set_mass(float m);
        bool check_Link() const;
    private:
        float length;
        float high;
        float width;
        float radius;
        float mass;
};


#endif // LINK_H_INCLUDED
