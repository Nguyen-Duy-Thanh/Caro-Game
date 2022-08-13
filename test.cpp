#include <iostream>
#include <vector>
#include "StartScreen.h"

using namespace std;

int main(){
    StartScreen ss;
    ss.MainMenuShow();
    system("pause");
    ss.BotMenuShow();
    system("pause");
    ss.GuildMenu();
}
