#ifndef _PLAYERINFO_H
#define _PLAYERINFO_H

#include<iostream>
#include<vector>
#include<fstream>
#include<direct.h>
#include"Player.h"

using namespace std;

class PlayerInfo{
private:
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
    }

    void Sort(string sort_type = "p", bool LOWER = true){
        for(int i = 0; i < ps.size(); i++){
            for(int j = i; j < ps.size(); j++){
                if(sort_type == "p"){
                    if(LOWER){
                        if(ps[i].calPoint() < ps[j].calPoint()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].calPoint() > ps[j].calPoint()) swap(ps[i], ps[j]);
                    }
                }

                else if(sort_type == "w"){
                    if(LOWER){
                        if(ps[i].getWin() < ps[j].getWin()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getWin() > ps[j].getWin()) swap(ps[i], ps[j]);
                    }
                }

                else if(sort_type == "d"){
                    if(LOWER){
                        if(ps[i].getDraw() < ps[j].getDraw()) swap(ps[i], ps[j]);
                    }
                    else{
                        if(ps[i].getDraw() > ps[j].getDraw()) swap(ps[i], ps[j]);
                    }
                }

                else if(sort_type == "l"){
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
        Sort();
        cout << "+---Name---+-W-+-D-+-L-+-P-+" << endl;
        for(int i = 0; i < ps.size(); i++){
            ps[i].printInfo();
            cout << "+----------+---+---+---+---+" << endl;
        }
    }
};

#endif // _PLAYERINFO_H
