#ifndef THISAPP_H_INCLUDED
#define THISAPP_H_INCLUDED
#include "application.h"
#include "brain.h"
#include "widget.h"
#include "tile.h"
#include <vector>
using namespace std;

class MyApp: public Application{
private:
    vector<vector<Tile *>> board;///vector of columns
    Brain *reversi;
public:
    MyApp();
    void events();
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



#endif // THISAPP_H_INCLUDED
