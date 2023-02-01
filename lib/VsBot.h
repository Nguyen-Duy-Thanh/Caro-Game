#ifndef _VSBOT_H
#define _VSBOT_H

#include<iostream>
#include<string>
#include "Player.h"
#include"PlayerInfo.h"
#include"Func.h"
#include"Minimax.h"

using namespace std;

class VsBot{
private:
    Player p1;
public:
    VsBot(){
        //p1.Input();
    }

    string getPlayer1() {return p1.getName();}

    void Play(){
        Table t(10, 10);
        int turn = 1, win = -1, check = -1;
        string x = "", y = "";
        vector<string> ss = t.accepttedInput();

        while(true){
            system("cls");
            t.Draw();

            if(turn % 2 == 1){
                string playerName = p1.getName();

                if(x == "-1" || y == "-1") cout << "Input error, check again" << endl;
                cout << "=> " << playerName << ": " << endl;
                cout << "Row: "; cin >> x;
                cout << "Column: "; cin >> y;
                if(!checkString(x, ss) || !checkString(y, ss)){
                    x = "-1";
                    y = "-1";
                    continue;
                }
                int X = stoi(x), Y = stoi(y);
                t.Mark(X, Y, turn);
                win = t.checkWin(X, Y, turn);
            }

            else{
                vector<int> bestMove = findBestMoveHard(t, turn);
                //vector<int> bestMove = findBestMoveBot(t, turn);
                cout << bestMove[0] << bestMove[1] << endl;
                t.Mark(bestMove[0], bestMove[1], turn);
                win = t.checkWin(bestMove[0], bestMove[1], turn);
            }

            if(win != -1) break;
        }

        system("cls");
        t.Draw();
        if(win == 0){
            cout << p1.getName() << " win" << endl;
            p1.Win();
        }
        else if(win = 1){
            cout << p1.getName() << " lose" << endl;
            p1.Lose();
        }
        else if(win == 2){
            cout << "Game draw" << endl;
            p1.Draw();
        }
    }
};

#endif // _VSBOT_H
