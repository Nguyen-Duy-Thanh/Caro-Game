#include<iostream>
#include<vector>
#include"lib/Table.h"
#include"lib/VsPlayer.h"
#include"lib/StartScreen.h"

using namespace std;

int main(){
    StartScreen ss;
    int turn = 0;

    while(true){
        system("cls");
        ss.MainMenuShow();

        if(ss.getMainOption() == 5) break;

        if(ss.getMainOption() == 4){
            system("cls");
            ss.GuildMenu();
        }

        if(ss.getMainOption() == 1){
            system("cls");
            VsPlayer p;
            Table t(10, 10);
            int turn = 1;

            while(true){
                system("cls");
                t.Draw();

                string playerName;
                int playerTurn;
                if(turn % 2 == 1){
                    playerName = p.getPlayer1();
                    playerTurn = 1;
                }
                else{
                    playerName = p.getPlayer2();
                    playerTurn = 2;
                }

                int x, y;
                cout << playerName << ": "; cin >> x >> y;
                t.Play(x, y, playerTurn);

                turn++;

                break;
            }
        }

        if(ss.getMainOption() == 2){
            system("cls");
            ss.BotMenuShow();
            if(ss.getBotOption() == 4) continue;
        }

        system("pause");
    }
    return 0;
}
