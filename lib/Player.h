#ifndef _PLAYER_H
#define _PLAYER_H

#include<iostream>
#include<vector>
#include<string>
#include<dirent.h>
#include<fstream>
#include"Func.h"
#include"Frame.h"

using namespace std;

string direct =  "Player";

class Player{
private:
    int m_lose;
    int m_win;
    int m_draw;
    string m_name;
public:
    Player(string name = "", int win = 0, int lose = 0, int draw = 0): m_name(tolower(name)), m_win(win), m_lose(lose), m_draw(draw) {}

    bool checkPlayer(){
        DIR *dir;
        struct dirent *diread;
        vector<string> files;

        if ((dir = opendir("Player")) != nullptr) {
            while ((diread = readdir(dir)) != nullptr) {
                string file_name = diread->d_name;
                string playerFile = m_name + ".txt";
                if(file_name == playerFile) return true;
            }
            closedir (dir);
        }
        else {
            perror ("opendir");
            return EXIT_FAILURE;
        }

        return false;
    }

    void createPlayer(){
        string fileName = direct + "/" + m_name + ".txt";
        ofstream playerFile(fileName);
        playerFile << "Win: " << m_win << endl;
        playerFile << "Lose: " << m_lose << endl;
        playerFile << "Draw: " << m_draw << endl;
        playerFile.close();
    }

    void openPlayer(){
        string fileName = direct + "/" + m_name + ".txt";
        ifstream playerFile(fileName);

        vector<string> lines;
        while(!playerFile.eof()){
            string line;
            playerFile >> line;
            lines.push_back(line);
        }
        playerFile.close();

        m_win = stoi(lines[1]);
        m_lose = stoi(lines[3]);
        m_draw = stoi(lines[5]);
    }

    void Input(int line){
        while(true){
            gotoXY(10, line);
            cout << "Player name: ";
            string name;
            cin >> name;
            m_name = tolower(name);

            if(checkPlayer()){
                string check;

                gotoXY(10, line + 1);
                cout << "Player with the same name already exist, is that you? (y/n)";

                while(true){
                    checkOption(check, 10, line + 2);

                    if(tolower(check) == "y" || tolower(check) == "yes"){
                        openPlayer();
                        break;
                    }
                    else if(tolower(check) != "n" && tolower(check) != "no"){
                        continue;
                    }
                    else break;
                }

                if(tolower(check) == "y" || tolower(check) == "yes") break;
                else deleteInputLines(12, 10, line);
            }
            else{
                createPlayer();
                break;
            }
        }
    }

    string getName() {return m_name;}
    int getWin() {return m_win;}
    int getLose() {return m_lose;}
    int getDraw() {return m_draw;}

    void Win() {m_win += 1;}
    void Lose() {m_lose += 1;}
    void Draw() {m_draw += 1;}
    int calPoint(){
        int point = 3*m_win - m_lose;
        return point < 0 ? 0 : point;
    }

    void printInfo(){
        cout << "|" << Align(m_name, 10, 'l') << "|" << Align(to_string(m_win), 6, 'c') << "|" << Align(to_string(m_draw), 7, 'c') << "|" << Align(to_string(m_lose), 7, 'c') << "|" << Align(to_string(calPoint()), 7, 'c') << "|" << endl;
    }

    ~Player(){
        createPlayer();
    }

};

#endif // _PLAYER_H

