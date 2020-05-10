#include "comp.h"
using namespace std;

Comp::Comp(vector<vector<int>> vmap, vector<vector<Tile*>> *_cboard, Brain* _cb):val_map(vmap),cboard(_cboard),cbrain(_cb){}

void Comp::c_move(){
    vector<pair<pair<int,int>,int>> av_values;
    for(int i=0;i<(*cboard).size();i++){
        for(int j=0;j<(*cboard)[i].size();j++){
            int q=(*cboard)[i][j]->get_val();
            if(q==2)
                av_values.push_back({{i,j},val_map[i][j]});
        }
    }
    int temp_max=-99;
    Tile * temp_tile=nullptr;
    for(int i=0;i<av_values.size();i++){
        if(av_values[i].second>temp_max){

            temp_max=av_values[i].second;
            temp_tile=(*cboard)[(av_values[i].first).first][(av_values[i].first).second];
        }
    }
    if(temp_tile){
        cbrain->make_move(temp_tile);
    }

}

