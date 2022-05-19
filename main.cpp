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

int main()
{
    gout.open(400,400);
    event ev;
    while(gin >> ev) {
    }
    return 0;
}
