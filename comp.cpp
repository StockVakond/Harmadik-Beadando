#include "comp.h"
#include <cmath>
using namespace std;

Comp::Comp(vector<vector<double>> vmap, vector<vector<Tile*>> *_cboard, Brain* _cb):
    val_map(vmap),cboard(_cboard),cbrain(_cb){
    vector<vector<int>> whole;
    for(int i=0;i<8;i++){
        vector<int> oner;
        for(int j=0;j<8;j++){
            oner.push_back(0);
        }
        whole.push_back(oner);
    }
    move_count=whole;
    }


void Comp::c_think(){
    move_ct=0;
    for(int i=0;i<(*cboard).size();i++){
        for(int j=0;j<(*cboard)[i].size();j++){
            int q=(*cboard)[i][j]->get_val();
            if(q==1 or q==-1){
                move_ct++;
            }
        }
    }
    double modifier=3-(move_ct/64.0)*3;
    cbrain->sync_comp(move_count);

    vector<pair<pair<int,int>,int>> av_values;

    for(int i=0;i<(*cboard).size();i++){
        for(int j=0;j<(*cboard)[i].size();j++){
            int q=(*cboard)[i][j]->get_val();
            if(q==2){
                av_values.push_back({{i,j},val_map[i][j]*modifier+move_count[i][j]*(1/modifier)});
            }
        }

    }
    double temp_max=-99;
    temp_tile=nullptr;
    for(int i=0;i<av_values.size();i++){
        if(av_values[i].second>temp_max){

            temp_max=av_values[i].second;
            temp_tile=(*cboard)[(av_values[i].first).first][(av_values[i].first).second];
        }
    }
}
void Comp::c_move(){
    if(temp_tile){
        cbrain->make_move(temp_tile);
    }
    else
        cbrain->switch_player();

}

