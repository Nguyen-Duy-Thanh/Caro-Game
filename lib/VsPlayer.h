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
        Table t(10, 10);
        int turn = 1;

        while(true){
            system("cls");
            t.Draw();

            string playerName;
            if(turn % 2 == 1) playerName = p1.getName();
            else playerName = p2.getName();

            int x, y;
            cout << "=> " << playerName << ": "; cin >> x >> y;
            t.Mark(x, y, turn);
        }
    }
};

#endif // _VSPLAYER_H
