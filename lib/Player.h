#ifndef _PLAYER_H
#define _PLAYER_H

#include<iostream>
#include<vector>
#include<string>
#include<dirent.h>
#include<fstream>

using namespace std;

string direct =  "C:/Users/admin/Desktop/Caro/Player";

class Player{
private:
    int m_lose;
    int m_win;
    int m_draw;
    string m_name;
public:
    Player(string name = "", int win = 0, int lose = 0, int draw = 0): m_name(name), m_win(win), m_lose(lose), m_draw(draw) {}

    bool checkPlayer(){
        DIR *dir;
        struct dirent *diread;
        vector<string> files;

        if ((dir = opendir("C:/Users/admin/Desktop/Caro/Player")) != nullptr) {
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
    }

    void Input(){
        while(true){
            cout << "Player name: "; cin >> m_name;

            if(checkPlayer()){
                char check;
                cout << "Player with the same name already exist, is that you? (y/n)" << endl;
                cout << ">"; cin >> check;
                if(check == 'y'){
                    openPlayer();
                    break;
                }
                else continue;
            }
            else{
                createPlayer();
                break;
            }
        }
    }

    string getName() {return m_name;}
    void Win() {m_win += 1;}
    void Lose() {m_lose += 1;}
    void Draw() {m_draw += 1;}

    ~Player(){
        createPlayer();
    }

};

#endif // _PLAYER_H

