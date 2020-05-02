#include "tile.h"
#include <vector>
#include <cmath>
using namespace std;
using namespace genv;

Tile::Tile(Application *ca,int px,int py,int sx,int sy, std::vector<int>rp,int _state)
    :Widget(ca,px,py,sx,sy)
    {
        rel_pos=rp;
        state=_state;
    }
void Tile::change_state(int target_state){
    state=target_state;
}
void Tile::draw(){
    if(!state){}

    else if(state==1){
        gout.set_color(235,235,235);
    }
    else if(state==-1){
        gout.set_color(20,20,20);
    }
    else if(state==2){
        gout.set_color(160,160,160);
    }
    double c=size_x/2;
    for(int i=-c; i<c;i++){
        for(int j=-c;j<c;j++){
            if(sqrt(pow(j,2)+pow(i,2))<size_x-35)
                gout<<move_to(pos_x+c+i,pos_y+c+j)<<dot;
        }
    }
}
void Tile::button_release(){}
void Tile::handle(event ev){}
string Tile::getvalue(){}
