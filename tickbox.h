#ifndef TICKBOX_H_INCLUDED
#define TICKBOX_H_INCLUDED

#include "widget.h"

using namespace std;

class Tickbox : public Widget {
protected:
    bool ticked;
public:
    Tickbox(Application *ca,int px, int py,int s,bool in_tick);
    void draw();
    void handle(genv::event ev);
    //void button_release();
    bool get_ticked(){return ticked;}
    void switch_tick(){if(ticked){ticked=false;}else{ticked=true;};}

};


#endif // TICKBOX_H_INCLUDED
