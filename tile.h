#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED
#include "widget.h"
#include "brain.h"
#include <vector>
using namespace std;

class Tile : public Widget{
protected:
    int state; ///0,1,-1; 1 for white -1 for black
    pair<int, int> rel_pos;
    Brain *pa_brain;

public:
    Tile(Application *ca,Brain *rev,int px,int py,int sx,int sy, std::pair<int,int>rp,int _state);
     void change_state(int target_state);
     void draw();
     void handle(genv::event ev);
     void button_release();
     pair<int,int> get_rp(){return rel_pos;}
    //virtual string getvalue();

};



#endif // TILE_H_INCLUDED
