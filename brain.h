#ifndef BRAIN_H_INCLUDED
#define BRAIN_H_INCLUDED
#include <vector>

using namespace std;
class Tile;
class Application;
class Tickbox;

class Brain{
private:
    int val_tiles[8][8];
    vector<vector<vector<pair<int,int>>>> dependencies; ///which tile would every tile change
    bool hints;
    int no_moves;
    int player=1;
public:
    Brain(int v);
    void initiate(vector<vector<Tile *>> &board, Application* ca, Tickbox* _ticker);
    void look_for_moves();
    void switch_player();
    void reset();
    void tile_sync(vector<vector<Tile *>> &board);
    void make_move(Tile *);
    void show_move(Tile *,vector<vector<Tile *>> &board);
    void dont_show(vector<vector<Tile *>> &board);
    int get_player(){return player;}
    int get_score(int plyr);
    int get_no_moves(){return no_moves;}
    void sync_comp(vector<vector<int>> &_move_count);
};


#endif // BRAIN_H_INCLUDED
