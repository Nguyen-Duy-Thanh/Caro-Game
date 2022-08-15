#include<iostream>
#include<vector>
#include"lib/Table.h"
#include"lib/VsPlayer.h"
#include"lib/StartScreen.h"
#include"lib/PlayerInfo.h"

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
        }

        if(ss.getMainOption() == 1){
            system("cls");
            VsPlayer p;
            p.Play();
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
