#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include<iostream>
#include<string>

using namespace std;

class StartScreen{
private:
    string m_mainOption;
    string m_playerOption;
    string m_botOption;
public:
    void MainMenuShow(){
        m_mainOption = "";
        while(true){
            system("cls");
            cout << "+-------MAIN MENU-------+" << endl;
            cout << "1. Play with Other Player" << endl;
            cout << "2. Play with Bot" << endl;
            cout << "3. Player's Information" << endl;
            cout << "4. Guild" << endl;
            cout << "5. Exit" << endl;
            if(m_mainOption != "") cout << "Input error, check again" << endl;
            cout << "Choice: "; cin >> m_mainOption;
            if(m_mainOption == "1" || m_mainOption == "2" || m_mainOption == "3" || m_mainOption == "4" || m_mainOption == "5") break;

        }
    }

    void VsPlayerMenuShow(){
        m_playerOption = "";
        while(true){
            system("cls");
            cout << "+-Play with Player-+" << endl;
            cout << "1. 2 Player" << endl;
            cout << "2. Find Other Player" << endl;
            cout << "3. Back to Main Menu" << endl;
            if(m_playerOption != "") cout << "Input error, check again" << endl;
            cout << "Choice: "; cin >> m_playerOption;
            if(m_playerOption == "1" || m_playerOption == "2" || m_playerOption == "3") break;
        }
    }

    void BotMenuShow(){
        m_botOption = "";
        while(true){
            system("cls");
            cout << "+--Play with Bot---+" << endl;
            cout << "1. Easy Mode" << endl;
            cout << "2. Normal Mode" << endl;
            cout << "3. Hard Mode" << endl;
            cout << "4. Back to Main Menu" << endl;
            if(m_botOption != "") cout << "Input error, check again" << endl;
            cout << "Choice: "; cin >> m_botOption;
            if(m_botOption == "1" || m_botOption == "2" || m_botOption == "3" || m_botOption == "4") break;
        }
    }

    void GuildMenu(){
        cout << "+---------Guild---------+" << endl;
        cout << "Winning condition: " << endl;
        cout << "When a player has 4 moves" << endl;
        cout << "horizontally, vertically " << endl;
        cout << "or diagonally, he wins" << endl;
    }

    int getMainOption() {return stoi(m_mainOption);}
    int getPlayerOption() {return stoi(m_playerOption);}
    int getBotOption() {return stoi(m_botOption);}

};

#endif // _STARTSCREEN_H
