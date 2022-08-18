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
        int turn = 1, win = -1, check = -1;

        while(true){
            system("cls");
            t.Draw();

            string playerName;
            if(turn % 2 == 1) playerName = p1.getName();
            else playerName = p2.getName();

            int x, y;
            cout << "=> " << playerName << ": "; cin >> x >> y;
            t.Mark(x, y, turn);
            win = t.checkWin(x, y, turn % 2);
            if(win != -1) break;
        }
        system("cls");
        t.Draw();
        if(win == 0){
            cout << p1.getName() << " win" << endl;
            p1.Win();
            p2.Lose();
        }
        else{
            cout << p2.getName() << " win" << endl;
            p1.Lose();
            p2.Win();
        }
    }
};

#endif // _VSPLAYER_H
