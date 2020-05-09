#ifndef BRAIN_H_INCLUDED
#define BRAIN_H_INCLUDED
#include <vector>
#include<iostream>
using namespace std;
class Tile;
class Application;

class Brain{
private:
    int val_tiles[8][8];
    vector<vector<vector<pair<int,int>>>> dependencies; ///which tile would every tile change
    bool hints;
    int player=1;
public:
    Brain(int v);
    void initiate(vector<vector<Tile *>> &board, Application* ca);
    void look_for_moves();
    void switch_player();
    void tile_sync(vector<vector<Tile *>> &board);
    void make_move(Tile *);
    void show_move(Tile *);
};


#endif // BRAIN_H_INCLUDED
