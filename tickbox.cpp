#include "tickbox.h"
using namespace std;
using namespace genv;
Tickbox::Tickbox(Application *ca,int px, int py, int s,bool in_tick)
    :Widget(ca,px,py,s,s)
{
    ticked=in_tick;
}
void Tickbox::draw(){
    int temp_q=genv::gout.cascent()+genv::gout.cdescent()+9;
    gout<<move_to(pos_x,pos_y)<<color(210,210,210)<<box(size_x, size_y);
    gout << move_to(pos_x+1, pos_y+1) << color(230,230,230) << box(size_x-2, size_y-2);
    if(ticked){
        gout<<color(30,230,30)<<move_to(pos_x+3, pos_y+3)<<line(size_x-6, size_y-6);
        gout<<move_to(pos_x+size_x-3, pos_y+3) << line(6-size_x, size_y-6);
        }

}
void Tickbox::handle(genv::event ev){
    if(ev.type==ev_mouse&&ev.button==btn_left)
        switch_tick();
    else if(ev.type==ev_key&&ev.keycode==key_enter)
        switch_tick();
}
//void Tickbox::button_release(){}