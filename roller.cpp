#include "roller.h"
#include <iostream>
using namespace std;
using namespace genv;
void Roller::roll(int a){
if(rpos_y+a>0){
    if(rpos_y+a<size_y-size_x)
        rpos_y+=a;
    else rpos_y=size_y-size_x;
}
else rpos_y=0;
}
void Roller::handle(event ev){
    if(ev.type==ev_mouse){
        if(ev.button==btn_left){
            if(ev.pos_y>=rpos_y+pos_y&&ev.pos_y<=rpos_y+pos_y+size_x){
                grabbed=true;
                dy=ev.pos_y-(pos_y+rpos_y);
                this->draw();
            }
        }

        else if(ev.button==0&&grabbed){
            if(ev.pos_x>pos_x-50&&ev.pos_x<pos_x+size_x+50){
                if(ev.pos_y>=pos_y+dy){
                    if(ev.pos_y<=pos_y+size_y-size_x+dy)
                        rpos_y=ev.pos_y-pos_y-dy;
                    else rpos_y=size_y-size_x;
                }
                else
                rpos_y=0;
            }
                else
                rpos_y=0;

        }
    }
}
void Roller::draw(){
    ///line
    gout<<color(180,180,180)<<move_to(pos_x,pos_y)<<box_to(pos_x+size_x, pos_y+size_y);
    gout<<color(170,170,170)<<move_to(pos_x+2,pos_y+2)<<box_to(pos_x+size_x-2, pos_y+size_y-2);
    ///slider
    gout<<color(195,195,195)<<move_to(pos_x+1, pos_y+rpos_y+1)<<box_to(pos_x+size_x-1, pos_y+rpos_y+size_x-1);
    if(!grabbed){
    gout<<color(210,210,210)<<move_to(pos_x+2, pos_y+rpos_y+2)<<box_to(pos_x+size_x-2, pos_y+rpos_y+size_x-2);
    }
    else{
    gout<<color(190,190,190)<<move_to(pos_x+2, pos_y+rpos_y+2)<<box_to(pos_x+size_x-2, pos_y+rpos_y+size_x-2);
    }
    }
void Roller::button_release(){
grabbed=false;
dy=0;
draw();
}
