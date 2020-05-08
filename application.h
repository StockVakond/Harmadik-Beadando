#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <string>
#include <vector>
class Widget;

class Application{
protected:
    std::vector<Widget*> widgets;
public:
    virtual ~Application(){};
    virtual void events()=0;
    virtual void action(std::string)=0;
    void load_widget(Widget * current_widget);
};


#endif // APPLICATION_H_INCLUDED
