#ifndef ROLLER_H_INCLUDED
#define ROLLER_H_INCLUDED
#include "graphics.hpp"

#include <iostream>

using namespace genv;
class Roller{
protected:
    int pos_x;
    int pos_y;
    int size_x;
    int size_y;
    int rpos_y;
    bool grabbed;
    int dy;
    int r_y;
public:

    Roller(int px, int py, int sx, int sy,int s_elements);
    int gety(){return rpos_y;}
    virtual void handle(event ev);
    virtual void draw();
    virtual void roll(int a);
    virtual void button_release();
};


#endif // ROLLER_H_INCLUDED
