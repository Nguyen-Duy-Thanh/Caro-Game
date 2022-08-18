#ifndef _VSPLAYER_H
#define _VSPLAYER_H

#include<iostream>
#include<string>
#include "Player.h"
#include"PlayerInfo.h"
#include"Func.h"

using namespace std;

class VsPlayer{
private:
    Player p1;
    Player p2;
public:
    VsPlayer(int option){
        p1.Input();

        if(option == 1) p2.Input();
        else{
            PlayerInfo pI;
            p2 = pI.findPlayer(p1);
        }
    }

    string getPlayer1() {return p1.getName();}
    string getPlayer2() {return p2.getName();}

    void Play(){
        Table t(10, 10);
        int turn = 1, win = -1, check = -1;
        string x = "", y = "";
        vector<string> ss = t.accepttedInput();

        while(true){
            system("cls");
            t.Draw();

            string playerName;
            if(turn % 2 == 1) playerName = p1.getName();
            else playerName = p2.getName();

            if(x == "-1" || y == "-1") cout << "Input error, check again" << endl;
            cout << "=> " << playerName << ": "; cin >> x >> y;
            if(!checkString(x, ss) || !checkString(y, ss)){
                x = "-1";
                y = "-1";
                continue;
            }
            int X = stoi(x), Y = stoi(y);
            t.Mark(X, Y, turn);
            win = t.checkWin(X, Y, turn % 2);
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
