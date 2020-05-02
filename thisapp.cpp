#include "thisapp.h"
#include <vector>
using namespace std;
MyApp::MyApp()
{
    vector<vector<Tile *>> all_c;
    genv::gout.open(800,800);
    for(int i=0;i<8;i++){
        vector<Tile *> one_c;
        for(int j=0; j<8;j++){
            one_c.push_back(new Tile(this,200+i*50,200+j*50,50,50,{i,j},2));
        }
        all_c.push_back(one_c);
    }
    board=all_c;
}
