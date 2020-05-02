#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED
#include "widget.h"
#include <vector>
using namespace std;
class Tile : public Widget{
protected:
    int state; ///0,1,-1; 1 for white -1 for black
    vector<int> rel_pos;
public:
    Tile(Application *ca,int px,int py,int sx,int sy, std::vector<int>rp,int _state);
    void change_state(int target_state);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void button_release();
    virtual string getvalue();

};



#endif // TILE_H_INCLUDED
