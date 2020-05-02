#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include <string>
#include "graphics.hpp"
#include "application.h"
class Widget {
protected:
    int pos_x, pos_y;
    size_t size_x, size_y;
    Application* current_app;
public:
    virtual ~Widget(){};
    Widget(Application *,int px, int py, size_t sx, size_t sy);
    virtual bool active(int, int);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual std::string getvalue()=0;
    virtual void button_release() =0;
};
#endif // WIDGET_H_INCLUDED
