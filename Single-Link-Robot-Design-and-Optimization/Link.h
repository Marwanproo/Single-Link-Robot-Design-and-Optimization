#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED
class Link{
    public:
        Link();
        Link(float l , float h , float b);
        Link(float l,float r);
        float get_length();
        float get_high();
        float get_width();
        float get_radius();
        void set_length();
        void set_high();
        void set_width();
        void set_radius();
    private:
        float length;
        float high;
        float width;
        float radius;
};


#endif // LINK_H_INCLUDED
