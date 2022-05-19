#include "graphics.hpp"
#include "cmath"
#include "vector"

using namespace genv;
using namespace std;

class widget{
protected:
    int x;
    int y;
    int sx;
    int sy;
    bool selected=false;
public:
    void setkord(int newx, int newy){
        x=newx;
        y=newy;
    }
    void setsize(int new_x, int new_y){
        sx=new_x;
        sy=new_y;
    }
    bool kivan(){
        return selected;
    }
    void kivalsztva(event ev){
        if(ev.type==ev_mouse){
            if(ev.pos_x >= x and ev.pos_y >= y and ev.pos_x  <= x+sx and ev.pos_y <= y+sy and ev.button<0){
                selected=true;
            }
            else{
                selected=false;
            }
        }
    }
    void rajz();
};

struct mezoures:widget{
protected:
public:
    void rajz(){
        gout<<color(255,255,255)<<move_to(x,y)<<box(sx,sy)<<color(0,0,0)<<move_to(x-1,y-1)<<box(sx-1,sy-1);
    }
};

struct mezoO:mezoures{
protected:
public:
    void rajz(){
        gout<<color(255,255,255)<<move_to(x,y)<<box(sx,sy)<<color(0,0,0)<<move_to(x-1,y-1)<<box(sx-1,sy-1);
        for(int i=0;i<sy;i++){
            for(int j=0;j<sx;j++){
                if(i^2+j^2==((sx-2)/2)^2){
                    gout<<color(255,0,0)<<move_to(x+j,y+i)<<dot;
                }
            }
        }
    }
};

struct mezoX:mezoures{
protected:
public:
    void rajz(){
        gout<<color(255,255,255)<<move_to(x,y)<<box(sx,sy)<<color(0,0,0)<<move_to(x-1,y-1)<<box(sx-1,sy-1);
        gout<<color(0,0,255)<<move_to(x-1,y-1)<<line(sx-2,sy-2)<<move_to(x+sx-3,y-1)<<line(-sx+1,sy+1);
    }
};

class maistro{
protected:
    bool Xturn=false;
    bool Oturn=true;
    int mapsize;
    vector<mezoures> ures;
    vector<mezoO> O;
    vector<mezoX> X;
public:
    void setmap(int newsize){
        mapsize=newsize;
    }
    void turn(event ev){
        if(Oturn==true and Xturn==false and ev.button>0){
            for(int i=0;i<ures.size();i++){
                if(ures[i].kivan()==true)
                O.push_back(ures[i]);
            }
        }
    }
};

int main()
{
    gout.open(400,400);
    event ev;
    while(gin >> ev) {
    }
    return 0;
}
