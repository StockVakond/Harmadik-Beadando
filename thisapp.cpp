#include "thisapp.h"
#include <vector>

using namespace std;
using namespace genv;
MyApp::MyApp()
{
    vector<vector<Tile *>> all_c;
    genv::gout.open(800,800);
    for(int i=0;i<8;i++){
        vector<Tile *> one_c;
        for(int j=0; j<8;j++){
            one_c.push_back(new Tile(this,reversi,200+i*50,200+j*50,50,50,{i,j},2));
        }
        all_c.push_back(one_c);
    }
    board=all_c;
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
        if(ev.type==ev_key&&ev.keycode==key_enter)
            action("enter");
        if(ev.type==ev_key&&ev.keycode==key_right)
            action("right");
        if(ev.keycode==key_escape)
            focus=nullptr;

        if (focus) {
            focus->handle(ev);
        }
        if(ev.button==-1)
            for (itr=widgets.begin();itr<widgets.end();itr++){
                (*itr)->button_release();
        }


        gout << refresh;
    }
    for (Widget * wg : widgets) {
        wg->draw();
    }
    gout << refresh;

}
