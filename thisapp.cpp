#include "application.h"
#include "widget.h"
#include "counter.h"
#include "drop_list.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;

class MyApp: public Application{
private:
    Counter *c1;
    Counter *c2;
    Droplist *d1;
    Droplist *d2;
public:
    MyApp(){
    gout.open(500,500);
    d1= new Droplist(this,50,50,100,100,{"aaaa","aasdfasdf","fasd","asdf","sfdf","qwer","dsf"});
    }
    void action(string action_id){
        /*if(action_id=="enter"){
            }
        if(action_id=="right"){
            }
        }
        if(action_id=="left"){
        }*/
    }
};
