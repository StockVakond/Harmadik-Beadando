#include "textview.h"
using namespace std;
using namespace genv;
Textview::Textview(Application *ca,int px, int py,int sx,int sy,string _text):Widget(ca,px,py,sx,sy)
    {
        dtext=_text;
    }
void Textview::draw(){
    gout<<move_to(pos_x,pos_y)<<color(210,210,210)<<box(size_x, size_y);
    gout << move_to(pos_x+1, pos_y+1) << color(230,230,230) << box(size_x-2, size_y-2);
    gout<<move_to(pos_x+3, pos_y+3+gout.cascent())<<color(0,0,0)<<text(dtext);

}
void Textview::handle(genv::event ev){
}
