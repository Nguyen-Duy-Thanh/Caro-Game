#ifndef _VSPLAYER_H
#define _VSPLAYER_H

#include<iostream>
#include "Player.h"

using namespace std;

class VsPlayer{
private:
    Player p1;
    Player p2;
public:
    VsPlayer(){
        p1.Input();

        p2.Input();
    }

    string getPlayer1() {return p1.getName();}
    string getPlayer2() {return p2.getName();}

    void Play(){

    }
};

#endif // _VSPLAYER_H
