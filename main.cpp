#include<iostream>
#include<vector>
#include"lib/Table.h"
#include"lib/VsPlayer.h"
#include"lib/StartScreen.h"
#include"lib/PlayerInfo.h"
#include"lib/VsBot.h"

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

        if(ss.getMainOption() == 3){
            system("cls");
            PlayerInfo pI;
            pI.printInfo();
            continue;
        }

        if(ss.getMainOption() == 1){
            system("cls");
            ss.VsPlayerMenuShow();
            if(ss.getPlayerOption() == 3) continue;
            else{
                system("cls");
                menuFrame(-1);
                VsPlayer p(ss.getPlayerOption());
                p.Play();
            }
        }

        if(ss.getMainOption() == 2){
            system("cls");
            ss.BotMenuShow();
            if(ss.getBotOption() == 4) continue;
            else if(ss.getBotOption() == 3){
                system("cls");
                VsBot b;
                b.Play();
            }
        }

        system("pause");
    }
    return 0;
}
