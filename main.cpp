#include "application.h"
#include "widget.h"
#include "counter.h"
#include "drop_list.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;

class MyApp: public Application{
private:
    Counter *c1;
    Counter *c2;
    Droplist *d1;
    Droplist *d2;
public:
    MyApp(){
    c1= new Counter(this,50,50,-111111,99,0); ///Min/max ertek alapjan van a meret
    c2= new Counter(this,50,100,50,-1999,2020,0); ///fix meret; a min/max hozzaigazitva
    d1= new Droplist(this,50,150,200,4,vector<string> {"elso","alma", "körte", "ezegytulhosszuszovegaminemferki","narancs","utolso"});
    d2= new Droplist(this,270,150,200,3,vector<string> {"piros","sárga","kék","barna"});
    }
    void action(string action_id){
        if(action_id=="enter"){
            ofstream kif("output.txt");
            kif<<"A widgetek ertekei:"<<endl;
            for (Widget* w:widgets){
                kif<<(w->getvalue());
            }
            kif.close();
            }
        if(action_id=="right"){
            if(d1->get_id()!=-1){
            string val1=d1->getvalue();
            val1=val1.substr(0,val1.size()-1);
            d1->remelement(d1->get_id());
            d2->addelement(val1);
            d1->reset_id();
            }
        }
        if(action_id=="left"){

        }
    }
};
int main()
{
    gout.open(500,500);
    MyApp app;
    app.events();
    return 0;
}
