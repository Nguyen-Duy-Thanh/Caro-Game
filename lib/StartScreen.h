#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include <iostream>
#include <string>
#include"Frame.h"

using namespace std;


class StartScreen{
private:
    string m_mainOption;
    string m_playerOption;
    string m_botOption;
    string m_firstOption;

public:
    // Main menu
    void MainMenuShow(){
        m_mainOption = "";

        while(true){
            system("cls");

            //Words frame
            if(m_mainOption != "") menuFrame(7);
            else menuFrame(6);
            gotoXY(30, 13); cout << ("1. Play with Other Player");
            gotoXY(30, 14); cout << ("2. Play with Bot");
            gotoXY(30, 15); cout << ("3. Player's Information");
            gotoXY(30, 16); cout << ("4. Guild");
            gotoXY(30, 17); cout << ("5. Exit");

            // Check option
            checkOption(m_mainOption, 30, 18);

            if(m_mainOption == "1" || m_mainOption == "2" || m_mainOption == "3" || m_mainOption == "4" || m_mainOption == "5") break;
        }
    }

    // VsPlayer menu
    void VsPlayerMenuShow(){
        m_playerOption = "";

        while(true){
            system("cls");

            // Words frame
            if(m_mainOption != "") menuFrame(5);
            else menuFrame(4);
            gotoXY(30, 13); cout << "1. 2 Player" << endl;
            gotoXY(30, 14); cout << "2. Find Other Player" << endl;
            gotoXY(30, 15); cout << "3. Back to Main Menu" << endl;

            // Check option
            checkOption(m_playerOption, 30, 16);

            if(m_playerOption == "1" || m_playerOption == "2" || m_playerOption == "3") break;
        }
    }

    // Bot menu
    void BotMenuShow(){
        m_botOption = "";

        while(true){
            system("cls");

            // Words frame
            if(m_mainOption != "") menuFrame(6);
            else menuFrame(5);
            gotoXY(30,13); cout << ("1. Easy Mode ");
            gotoXY(30,14); cout << ("2. Normal Mode");
            gotoXY(30,15); cout << ("3. Hard Mode");
            gotoXY(30,16); cout << ("4. Back To Main Menu");

            // Check option
            checkOption(m_botOption, 30, 17);

            if(m_botOption == "1" || m_botOption == "2" || m_botOption == "3" || m_botOption == "4") break;
        }
    }

    // Check go first menu
    void FirstMoveMenu(){
        m_firstOption = "";

        while(true){
            system("cls");

            // Words frame
            if(m_mainOption != "") menuFrame(5);
            else menuFrame(4);
            gotoXY(30, 13); cout << ("1. Go First ");
            gotoXY(30, 14); cout << ("2. Go Second");
            gotoXY(30, 15); cout << ("3. Back To Main Menu");

            // Check option
            checkOption(m_firstOption, 30, 16);

            if(m_firstOption == "1" || m_firstOption == "2" || m_firstOption == "3") break;
        }
    }

    // Guild menu
    void GuildMenu() {
        menuFrame(4);
        gotoXY(30, 13); cout << "Winning condition: ";
        gotoXY(30, 14); cout << "When a player has 4 moves";
        gotoXY(30, 15); cout << "horizontally, vertically ";
        gotoXY(30, 16); cout << "or diagonally, he wins";
        gotoXY(30, 17);
    }

    int getMainOption() {return stoi(m_mainOption);}
    int getPlayerOption() {return stoi(m_playerOption);}
    int getBotOption() {return stoi(m_botOption);}
    int getFirstOption() {return stoi(m_firstOption);}

};

#endif // _STARTSCREEN_H


