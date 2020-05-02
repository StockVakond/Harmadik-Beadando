#ifndef ROLLER_H_INCLUDED
#define ROLLER_H_INCLUDED
#include "graphics.hpp"
#include "widget.h"

using namespace genv;
class Roller : public Widget{
protected:
    int rpos_y;
    bool grabbed;
    int dy;
public:

    Roller(Application * ca, int px, int py, int sx, int sy):
        Widget(ca, px, py, sx, sy)
        {
            rpos_y=0;
            grabbed = false;
            dy=0;
        }
    int gety(){return rpos_y;}
    virtual void handle(event ev);
    virtual void draw();
    virtual void roll(int a);
    virtual std::string getvalue(){return "";}
    virtual void button_release();
};


#endif // ROLLER_H_INCLUDED
