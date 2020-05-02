#include "drop_list.h"
#include "roller.h"

using namespace std;
using namespace genv;

Droplist::Droplist(Application *ca, int px, int py, int sx, int _no_displayed, vector<string>_elements)
    :Widget(ca,px,py,sx,(_no_displayed*(gout.cascent()+gout.cdescent()+4)))
    {
        rlr=new Roller(ca, px+sx-14, py, 14,(_no_displayed*(gout.cascent()+gout.cdescent()+4)));
        elements=_elements;
        int q=elements.size();
        no_displayed=min(_no_displayed, q);
        drpos=rlr->gety();
        double w=size_y/(elements.size()-no_displayed+2);
        top_order=drpos/w;
    }
void Droplist::draw(){

    gout<<color(150,150,150)<<move_to(pos_x-1, pos_y-1)<<box_to(pos_x+size_x+1, pos_y+size_y+1);

    drpos=rlr->gety();
    w=(size_y-14)/(elements.size()-no_displayed);
    top_order=drpos/w;
    string disptext;
    if(top_order>elements.size()-no_displayed)
        top_order=elements.size()-no_displayed;
    for(size_t i=0; i<no_displayed;i++){
        bool longer=false;
        gout<<color(130,130,130)<<move_to(pos_x, pos_y+i*element_size)<<box_to(pos_x+size_x,pos_y+(i+1)*element_size);
        disptext=elements[i+top_order];
        while(gout.twidth(disptext)>size_x-14-gout.twidth("...")){
                disptext=disptext.substr(0, disptext.size()-1);
                longer=true;
        }
        if(longer)
            disptext+="...";
        if(i+top_order!=order_of_active){
            gout<<color(220,220,220)<<move_to(pos_x+1, pos_y+1+i*element_size)<<box_to(pos_x-1+size_x,pos_y+(i+1)*element_size-1);
            gout<<move_to(pos_x+2, pos_y+i*element_size+2+gout.cascent())<<color(0,0,0)<<text(disptext);
        }
        else{gout<<color(160,160,160)<<move_to(pos_x, pos_y+i*element_size)<<box_to(pos_x+size_x,pos_y+(i+1)*element_size);
            gout<<move_to(pos_x+2, pos_y+i*element_size+2+gout.cascent())<<color(0,0,0)<<text(disptext);
        }
    }


}
void Droplist::handle(event ev){
    if(ev.type==ev_mouse){
        if(ev.button==btn_left){
            if(ev.pos_x<pos_x+size_x-14){
                for(size_t i=0; i<no_displayed; i++){
                    if(ev.pos_y>=pos_y+i*element_size&&ev.pos_y<pos_y+(i+1)*element_size){
                        order_of_active=i+top_order;
                    }
                }
            }
        }
        else if(ev.button==btn_wheelup){
            rlr->roll(-w);
        }
        else if(ev.button==btn_wheeldown){
            rlr->roll(w);
        }
    }
}
void Droplist::button_release(){
}
string Droplist::getvalue(){
    if(order_of_active!=-1)
        return elements[order_of_active]+"\n";
    else
        return "N/A";
}
void Droplist::addelement(string a){
    elements.push_back(a);
}
void Droplist::remelement(int id){
   /* vector<string> el;
    for(size_t i=0; i<elements.size();i++){
        if(i!=id){
            el.push_back(elements[i]);
        }
    }
    elements=el;*/
    elements.erase(elements.begin()+id);
}
