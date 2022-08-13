#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include<iostream>

using namespace std;

class StartScreen{
private:
    int m_mainOption;
    int m_botOption;
public:
    void MainMenuShow(){
        cout << "+-------MAIN MENU-------+" << endl;
        cout << "1. Play with Other Player" << endl;
        cout << "2. Play with Bot" << endl;
        cout << "3. Player's Information" << endl;
        cout << "4. Guild" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: "; cin >> m_mainOption;
    }

    void BotMenuShow(){
        cout << "+--Play with Bot---+" << endl;
        cout << "1. Easy Mode" << endl;
        cout << "2. Normal Mode" << endl;
        cout << "3. Hard Mode" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Choice: "; cin >> m_botOption;
    }

    void GuildMenu(){
        cout << "+---------Guild---------+" << endl;
        cout << "Winning condition: " << endl;
        cout << "When a player has 4 moves" << endl;
        cout << "horizontally, vertically " << endl;
        cout << "or diagonally, he wins" << endl;
    }

    int getMainOption() {return m_mainOption;}
    int getBotOption() {return m_botOption;}

};

#endif // _STARTSCREEN_H
