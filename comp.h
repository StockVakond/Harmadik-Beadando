#ifndef COMP_H_INCLUDED
#define COMP_H_INCLUDED
#include <vector>
#include "tile.h"
#include "brain.h"
class Comp{
protected:
    vector<vector<double>> val_map;
    vector<vector<Tile *>> *cboard;
    vector<vector<int>> move_count;
    Brain *cbrain;
    Tile * temp_tile=nullptr;
    int move_ct=0;
public:
    Comp(vector<vector<double>> vmap,vector<vector<Tile *>> *_board, Brain* _cb);
    void c_move();
    void c_think();
};


#endif // COMP_H_INCLUDED
