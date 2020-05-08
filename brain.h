#ifndef BRAIN_H_INCLUDED
#define BRAIN_H_INCLUDED
#include <vector>
using namespace std;
class Tile;
class Brain{
private:
    vector<vector<int>> val_tiles;
    vector<vector<vector<pair<int,int>>>> dependencies; ///which tile would every tile change
    bool hints;
public:
    void look_for_moves();
    void tile_sync(vector<vector<Tile *>> board);
    void make_move(Tile *);

};


#endif // BRAIN_H_INCLUDED
