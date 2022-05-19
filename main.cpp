#include "graphics.hpp"
using namespace genv;

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

int main()
{
    gout.open(400,400);
    event ev;
    while(gin >> ev) {
    }
    return 0;
}
