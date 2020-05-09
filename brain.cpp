#include "brain.h"
#include "tile.h"
#include <typeinfo>
#include <iostream>
using namespace std;
Brain::Brain(int v){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            val_tiles[i][j]=v;
        }
    }
    pair<int,int> q={-1,-1};
    vector<pair<int,int>> temp_1;
    temp_1.push_back(q);
    vector<vector<pair<int,int>>> temp_2;
    for(int i=0;i<8;i++)
        temp_2.push_back(temp_1);
    vector<vector<vector<pair<int,int>>>> temp_3;
    for(int i=0;i<8;i++)
        temp_3.push_back(temp_2);
    dependencies=temp_3;
}
void Brain::initiate(vector<vector<Tile *>> &board, Application *ca){
    genv::gout.open(800,800);
    for(int i=0;i<8;i++){
        vector<Tile *> one_c;
        for(int j=0; j<8;j++){
            one_c.push_back(new Tile(ca,this,200+i*50,200+j*50,50,50,{i,j},0));
            Brain::val_tiles[i][j]=0;
        }
        board.push_back(one_c);
    }
    val_tiles[3][3]=-1;
    val_tiles[4][4]=-1;
    val_tiles[3][4]=1;
    val_tiles[4][3]=1;
    tile_sync(board);
    look_for_moves();
    tile_sync(board);
}
void Brain::tile_sync(vector<vector<Tile *>> &board){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            (board[i][j])->change_state(val_tiles[i][j]);
        }
    }
}
void Brain::look_for_moves(){
    vector<pair<int,int>> inner_depend[8][8];
    int current_value=player;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(val_tiles[i][j]==2)
                val_tiles[i][j]=0;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ///going through all tiles
            if(val_tiles[i][j]==0){
                vector<pair<int,int>> to_right;
                int x,y;
                bool found=false;
                x=i;
                y=j;
                while(x<7&&y==j&&!found){
                    x++;
                    if(val_tiles[x][y]==0){
                        found=true;
                    }
                    if(val_tiles[x][y]==(-1)*current_value){
                        to_right.push_back({x,y});
                    }
                    if(val_tiles[x][y]==current_value){
                        for(pair<int,int>copypair :to_right){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
                vector<pair<int,int>> to_left;
                found=false;
                x=i;
                y=j;
                while(x>0&&y==j&&!found){
                    x--;
                    if(val_tiles[x][y]==0)
                        found=true;
                    if(val_tiles[x][j]==(-1)*current_value){
                        to_left.push_back({x,y});
                    }
                    if(val_tiles[x][j]==current_value){
                        for(pair<int,int>copypair :to_left){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
                vector<pair<int,int>> to_down;
                found=false;
                x=i;
                y=j;
                while(y<7&&x==i&&!found){
                        y++;
                    if(val_tiles[x][y]==0)
                        found=true;///actually just a break...not really found
                    if(val_tiles[i][y]==(-1)*current_value){
                        to_down.push_back({x,y});
                    }
                    if(val_tiles[i][y]==current_value){
                        for(pair<int,int>copypair :to_down){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
                vector<pair<int,int>> to_up;
                found=false;
                x=i;
                y=j;
                while(y>0&&x==i&&!found){
                    y--;
                    if(val_tiles[x][y]==0)
                        found=true;
                    if(val_tiles[i][y]==(-1)*current_value){
                        to_down.push_back({x,y});
                    }
                    if(val_tiles[i][y]==current_value){
                        for(pair<int,int>copypair :to_down){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }

                vector<pair<int,int>> down_right;
                found=false;
                x=i;
                y=j;
                while(x<7 && y<7&&!found){
                    x++;
                    y++;
                    if(val_tiles[x][y]==0)
                        found=true;
                    if(val_tiles[x][y]==(-1)*current_value){
                        down_right.push_back({x,y});
                    }
                    if(val_tiles[x][y]==current_value){
                        for(pair<int,int>copypair :down_right){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
                vector<pair<int,int>> up_right;
                found=false;
                x=i;
                y=j;
                while(x<7 && y>0&&!found){
                    x++;
                    y--;
                    if(val_tiles[x][y]==0)
                        found=true;
                    if(val_tiles[x][y]==(-1)*current_value){
                        up_right.push_back({x,y});
                    }
                    if(val_tiles[x][y]==current_value){
                        for(pair<int,int>copypair :up_right){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
                vector<pair<int,int>> up_left;
                found=false;
                x=i;
                y=j;
                while(x>0 && y>0&&!found){
                    x--;
                    y--;
                    if(val_tiles[x][y]==0)
                        found=true;

                    if(val_tiles[x][y]==(-1)*current_value){
                        up_left.push_back({x,y});
                    }
                    if(val_tiles[x][y]==current_value){
                        for(pair<int,int>copypair :up_left){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
                vector<pair<int,int>> down_left;
                found=false;
                x=i;
                y=j;
                while(x>0 && y<7&&!found){
                    x--;
                    y++;
                    if(val_tiles[x][y]==0){
                        found=true;
                    }
                    if(val_tiles[x][y]==(-1)*current_value){
                        down_left.push_back({x,y});
                    }
                    if(val_tiles[x][y]==current_value){
                        for(pair<int,int>copypair :down_left){
                            inner_depend[i][j].push_back(copypair);
                        }
                        found=true;
                    }

                }
            }
        }
    }
    pair<int,int> q={-1,-1};
    vector<pair<int,int>>e;
    e.push_back(q);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            dependencies[i][j]=e;
            for(pair<int,int> p:inner_depend[i][j]){
                dependencies[i][j].push_back(p);
            }
            if(dependencies[i][j].size()>1){
                val_tiles[i][j]=2;
            }
        }
    }


}
void Brain::make_move(Tile * chosen_tile){
    pair<int,int> relpos=chosen_tile->get_rp();
    if(dependencies[relpos.first][relpos.second].size()>1){
            ///vector<vector<vector<pair<int,int>>>> dependencies;
        for(pair<int,int> lpair:dependencies[relpos.first][relpos.second]){
            val_tiles[lpair.first][lpair.second]=player;
        }
        val_tiles[relpos.first][relpos.second]=player;
        switch_player();
    }
}
void Brain::switch_player(){
    player=player*(-1);
}
void Brain::show_move(Tile * chosen_tile){

}
