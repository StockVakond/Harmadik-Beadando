#include "thisapp.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;
MyApp::MyApp()
{
    reversi=new Brain(0);
    reversi->initiate(board,this);
    hint=new Tickbox(this,50,350,20, true);
}
void MyApp::events(){
    event ev;
    vector<Widget*>::iterator itr;
    Widget* focus=nullptr;
    while(gin >> ev &&(char)(ev.keycode)!=('q')) {
        gout<<color(240,240,240)<<move_to(0,0)<<box_to(800-1,800-1);
        bool first=true;
        if(first){
            for (Widget * wg : widgets)
                wg->draw();
            first=false;
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (itr=widgets.begin();itr<widgets.end();itr++) {
                if ((*itr)->active(ev.pos_x, ev.pos_y)) {
                        focus = *itr;
                }
            }
        }
        if(ev.keycode==key_escape)
            focus=nullptr;
        if (focus) {
            focus->handle(ev);
            reversi->tile_sync(board);
            reversi->look_for_moves();
            for (Widget * wg : widgets)
                wg->draw();
            gout<<refresh;
        }
        /*if(ev.button==-1)
            for (itr=widgets.begin();itr<widgets.end();itr++){
                (*itr)->button_release();
        }*/


        gout << refresh;
    }
    for (Widget * wg : widgets) {
        wg->draw();
    }
    gout << refresh;

}
