#ifndef _PLAYERINFO_H
#define _PLAYERINFO_H

#include<iostream>
#include<vector>
#include<fstream>
#include<direct.h>
#include"Player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class PlayerInfo{
private:
    bool LOWER;
    string m_option;
    vector<Player> ps;
public:
    PlayerInfo(){
        DIR *dir;
        struct dirent *diread;
        vector<string> files;

        if ((dir = opendir("Player")) != nullptr) {
            while ((diread = readdir(dir)) != nullptr) {
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

    Player findPlayer(Player p){
        vector<Player> temp;

        for(int i = 0; i < ps.size(); i++){
            if(ps[i].getName() == p.getName()) continue;
            if(ps[i].calPoint() > (p.calPoint()-6) && ps[i].calPoint() < (p.calPoint() +6)) temp.push_back(ps[i]);
        }

        while(true){
            srand(time(NULL));
            int r = rand() % temp.size();
            cout << "Are you want to play with " << temp[r].getName() << "? (y/n)" << endl;
            string s;
            while(true){
                cout << "Choice: "; cin >> s;
                if(tolower(s) == "y" || tolower(s) == "yes") return temp[r];
                else if(tolower(s) != "n" && tolower(s) != "no") cout << "Input error, check again" << endl;
                else break;
            }

        }

    }

    void Sort(string sort_type, bool LOWER){
        for(int i = 0; i < ps.size(); i++){
            for(int j = i; j < ps.size(); j++){
                if(sort_type == "4"){
                    if(LOWER){
                        if(ps[i].calPoint() < ps[j].calPoint()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].calPoint() > ps[j].calPoint()) swap(ps[i], ps[j]);
                    }
                }

                else if(sort_type == "1"){
                    if(LOWER){
                        if(ps[i].getWin() < ps[j].getWin()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getWin() > ps[j].getWin()) swap(ps[i], ps[j]);
                    }
                }

                else if(sort_type == "2"){
                    if(LOWER){
                        if(ps[i].getDraw() < ps[j].getDraw()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getDraw() > ps[j].getDraw()) swap(ps[i], ps[j]);
                    }
                }

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

    void printInfo(){
        string option = "";
        while(m_option != "6"){
            system("cls");
            Sort(m_option, LOWER);
            cout << "+---Name---+-W-+-D-+-L-+-P-+" << endl;
            for(int i = 0; i < ps.size(); i++){
                ps[i].printInfo();
                cout << "+----------+---+---+---+---+" << endl;
            }

            cout << "1. Sort by Wins" << endl;
            cout << "2. Sort by Draws" << endl;
            cout << "3. Sort by Loses" << endl;
            cout << "4. Sort by Points" << endl;
            cout << "5. Reverse" << endl;
            cout << "6. Back to Main Menu" << endl;
            if(option != "") cout << "Input error, check again" << endl;
            cout << "Choice: "; cin >> option;
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

    int getOption() {return stoi(m_option);}

};

#endif // _PLAYERINFO_H
