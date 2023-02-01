#ifndef _PLAYERINFO_H
#define _PLAYERINFO_H

#include<iostream>
#include<vector>
#include<fstream>
#include<direct.h>
#include"Player.h"
#include <cstdlib>
#include <ctime>
#include"Frame.h"

using namespace std;

class PlayerInfo{
private:
    bool LOWER;
    string m_option;
    vector<Player> ps;

public:
    PlayerInfo(){

        // Check existed player name
        DIR *dir;
        struct dirent *diread;
        vector<string> files;

        if ((dir = opendir("Player")) != nullptr){
            while ((diread = readdir(dir)) != nullptr){
                string file_name = diread->d_name;
                if(file_name.size() > 4){
                    file_name.erase(file_name.begin() + file_name.find(".txt"), file_name.end());
                    Player p(file_name);
                    p.openPlayer();
                    ps.push_back(p);
                }
            }
            closedir (dir);
        }
        else cout << "Direction is not exist" << endl;

        m_option = "4";
        LOWER = true;
    }

    // Sort players
    void Sort(string sort_type, bool LOWER){
        for(int i = 0; i < ps.size(); i++){
            for(int j = i; j < ps.size(); j++){

                // Point
                if(sort_type == "4"){
                    if(LOWER){
                        if(ps[i].calPoint() < ps[j].calPoint()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].calPoint() > ps[j].calPoint()) swap(ps[i], ps[j]);
                    }
                }

                // Wins
                else if(sort_type == "1"){
                    if(LOWER){
                        if(ps[i].getWin() < ps[j].getWin()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getWin() > ps[j].getWin()) swap(ps[i], ps[j]);
                    }
                }

                // Draws
                else if(sort_type == "2"){
                    if(LOWER){
                        if(ps[i].getDraw() < ps[j].getDraw()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getDraw() > ps[j].getDraw()) swap(ps[i], ps[j]);
                    }
                }

                // Loses
                else if(sort_type == "3"){
                    if(LOWER){
                        if(ps[i].getLose() < ps[j].getLose()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getLose() > ps[j].getLose()) swap(ps[i], ps[j]);
                    }
                }
            }
        }
    }

    // Print player info
    void printInfo(){
        string option = "";

        while(m_option != "6"){
            system("cls");

            Sort(m_option, LOWER);

            menuFrame(-1);
            gotoXY(18, 2); cout << "+---Name---+-Wins-+-Draws-+-Loses-+-Point-+" << endl;
            for(int i = 0; i < ps.size(); i++){
                gotoXY(18, 2 + 2 * (i + 1) - 1);
                ps[i].printInfo();

                gotoXY(18, 2 + 2 * (i + 1));
                cout << "+----------+------+-------+-------+-------+" << endl;
            }

            int line = 2 + 2 * (ps.size() + 1);
            gotoXY(30, line); cout << "1. Sort by Wins" << endl;
            gotoXY(30, line + 1); cout << "2. Sort by Draws" << endl;
            gotoXY(30, line + 2); cout << "3. Sort by Loses" << endl;
            gotoXY(30, line + 3); cout << "4. Sort by Points" << endl;
            gotoXY(30, line + 4); cout << "5. Reverse" << endl;
            gotoXY(30, line + 5); cout << "6. Back to Main Menu" << endl;

            // Check option
            checkOption(option, 30, line + 6);

            if(option == "1" || option == "2" || option == "3" || option == "4"){
                m_option = option;
                option = "";
            }
            else if(option == "5"){
                LOWER = !LOWER;
                option = "";
            }
            else if(option == "6") break;
        }
    }

    Player findPlayer(Player p, int line){
        vector<Player> sameLevel;
        vector<Player> higherLevel;
        vector<Player> lowerLevel;
        Sort(m_option, LOWER);
        int position;

        for(int i = 0; i < ps.size(); i++){
            if(ps[i].getName() == p.getName()){
                position = i;
                continue;
            }
            else if(ps[i].calPoint() > (p.calPoint()-6) && ps[i].calPoint() < (p.calPoint() +6)) sameLevel.push_back(ps[i]);
            else if(ps[i].calPoint() <= (p.calPoint()-6)) lowerLevel.push_back(ps[i]);
            else if(ps[i].calPoint() >= (p.calPoint()-6)) higherLevel.push_back(ps[i]);
        }

        while(true){
            if(sameLevel.size() != 0){
                while(true && sameLevel.size() != 0){
                    srand(time(NULL));
                    int r = rand() % sameLevel.size();
                    gotoXY(10, line);
                    cout << "Are you want to play with " << sameLevel[r].getName() << " (P: " << sameLevel[r].calPoint() << ")" << "? (y/n)" << endl;
                    string s = "";
                    while(true){
                        checkOption(s, 10, line + 1);

                        if(tolower(s) == "y" || tolower(s) == "yes") return sameLevel[r];
                        else if(tolower(s) != "n" && tolower(s) != "no"){
                            deleteInputLines(7, 10, line + 1);
                            continue;
                        }
                        else{
                            sameLevel.erase(sameLevel.begin() + r);
                            deleteInputLines(7, 10, line);
                            break;
                        }
                    }
                }
            }

            if(sameLevel.size() == 0 && higherLevel.size() != 0){
                while(true && higherLevel.size() != 0){
                    srand(time(NULL));
                    int r = rand() % higherLevel.size();
                    gotoXY(10, line);
                    cout << "Are you want to play with " << higherLevel[r].getName() << " (P: " << higherLevel[r].calPoint() << ")" << "? (y/n)" << endl;
                    string s = "";
                    while(true){
                        checkOption(s, 10, line + 1);

                        if(tolower(s) == "y" || tolower(s) == "yes") return sameLevel[r];
                        else if(tolower(s) != "n" && tolower(s) != "no"){
                            deleteInputLines(7, 10, line + 1);
                            continue;
                        }
                        else{
                            higherLevel.erase(higherLevel.begin() + r);
                            deleteInputLines(7, 10, line);
                            break;
                        }
                    }
                }
            }

            if(sameLevel.size() == 0 && higherLevel.size() == 0){
                while(true && lowerLevel.size() != 0){
                    srand(time(NULL));
                    int r = rand() % lowerLevel.size();
                    gotoXY(10, line);
                    cout << "Are you want to play with " << lowerLevel[r].getName() << " (P: " << lowerLevel[r].calPoint() << ")" << "? (y/n)" << endl;
                    string s = "";
                    while(true){
                        checkOption(s, 10, line + 1);

                        if(tolower(s) == "y" || tolower(s) == "yes") return sameLevel[r];
                        else if(tolower(s) != "n" && tolower(s) != "no"){
                            deleteInputLines(7, 10, line + 1);
                            continue;
                        }
                        else{
                            lowerLevel.erase(lowerLevel.begin() + r);
                            deleteInputLines(7, 10, line);
                            break;
                        }
                    }
                }
            }

            cout << "Out of player, please choose again" << endl;
            system("pause");
        }
    }

    int getOption() {return stoi(m_option);}

};

#endif // _PLAYERINFO_H
