#ifndef TEXTVIEW_H_INCLUDED
#define TEXTVIEW_H_INCLUDED

#include "widget.h"

using namespace std;

class Textview : public Widget{
protected:
    string dtext;
public:
    Textview(Application *ca,int px, int py,int sx,int sy,string _text);
    void draw();
    void handle(genv::event ev);
    //void button_release();
};


#endif // TEXTVIEW_H_INCLUDED
