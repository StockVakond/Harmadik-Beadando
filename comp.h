#ifndef COMP_H_INCLUDED
#define COMP_H_INCLUDED
#include <vector>
#include "tile.h"
#include "brain.h"
class Comp{
protected:
    vector<vector<int>> val_map;
    vector<vector<Tile *>> *cboard;
    Brain *cbrain;
public:
    Comp(vector<vector<int>> vmap,vector<vector<Tile *>> *_board, Brain* _cb);
    void c_move();
};


#endif // COMP_H_INCLUDED
