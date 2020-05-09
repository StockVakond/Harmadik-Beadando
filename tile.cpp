#include "tile.h"
#include "brain.h"
#include <vector>
#include <cmath>
using namespace std;
using namespace genv;

Tile::Tile(Application *ca,Brain *rev,Tickbox* _ticker,int px,int py,int sx,int sy, std::pair<int,int>rp,int _state)
    :Widget(ca,px,py,sx,sy)
    {
        pa_brain=rev;
        rel_pos=rp;
        state=_state;
        ticker=_ticker;
    }
void Tile::change_state(int target_state){
    state=target_state;
}
void Tile::draw(){

    gout<<move_to(pos_x,pos_y)<<color(190,190,130)<<box(size_x,size_y);
    gout<<move_to(pos_x+1,pos_y+1)<<color(210,210,130)<<box(size_x-2,size_y-2);
    if(!state){}

    else if(state==1){
        gout.set_color(235,235,235);
    }
    else if(state==-1){
        gout.set_color(20,20,20);
    }

    else if(state==2&&ticker->get_ticked()){
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

void Tile::handle(event ev){
    if(ev.type=ev_mouse&&ev.button==btn_left){
        pa_brain->make_move(this);
    }
    else if(ev.type ==ev_mouse&&ev.button==btn_right)
        pa_brain->show_move(this);
}
//string Tile::getvalue(){}
