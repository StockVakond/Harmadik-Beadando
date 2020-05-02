#include "application.h"
#include "widget.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
using namespace genv;
void Application::load_widget(Widget * current_widget){
    widgets.push_back(current_widget);
    }
void Application::events(){
    event ev;
    vector<Widget*>::iterator itr;
    Widget* focus=nullptr;
    while(gin >> ev &&(char)(ev.keycode)!=('q')) {
        gout<<color(240,240,240)<<move_to(0,0)<<box_to(499,499);
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


