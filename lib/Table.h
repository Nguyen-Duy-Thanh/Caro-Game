#ifndef _TABLE_H
#define _TABLE_H

#include<string>

using namespace std;

class Table{
private:
    int m_length;
    int m_width;
    vector<string> m_Table;
public:
    Table(int length = 0, int width = 0): m_length(length), m_width(width){
        string firstLine = "   ";
        string line = "|";
        string border = " |";
        for(int i = 0; i < m_width; i++){
            firstLine += to_string(i) + "   ";
            line += "   |";
            border += "---|";
        }

        m_Table.push_back(firstLine);
        m_Table.push_back(border);
        for(int i = 0; i < m_length; i++){
            string tempLine = to_string(i) + line;
            m_Table.push_back(tempLine);
            m_Table.push_back(border);
        }
    }

    int getLength() {return m_length;}
    int getWidth() {return m_width;}

    char position(int x, int y) {return m_Table[2 * x + 2][4 * y + 3];}

    void Draw(){
        for(int i = 0; i< m_Table.size(); i++) cout << m_Table[i] << endl;
    }

    void Mark(int x, int y, int &turn){
        if(x < 0 || x >= m_length || y < 0 || y >= m_width){
            cout << "Input out of range. Do it again" << endl;
            system("pause");
            return;
        }
        else if(m_Table[2 * x + 2][4 * y + 3] == 'X' || m_Table[2 * x + 2][4 * y + 3] == 'O'){
            cout << "Exist other player move" << endl;
            system("pause");
            return;
        }
        else if(turn % 2 == 1) m_Table[2 * x + 2][4 * y + 3] = 'X';
        else m_Table[2 * x + 2][4 * y + 3] = 'O';
        turn++;
    }

    int verticalCheck(int x, int y){
        int temp = x, point = 1;
        if(temp < 9){
            while(m_Table[2 * (temp + 1) + 2][4 * y + 3] == m_Table[2 * x + 2][4 * y + 3]){
                temp += 1;
                point += 1;
                if(temp == 10) break;
            }
        }

        temp = x;
        if(temp > 0){
            while(m_Table[2 * (temp - 1) + 2][4 * y + 3] == m_Table[2 * x + 2][4 * y + 3]){
                temp -= 1;
                point += 1;
                if(temp == -1) break;
            }
        }

        return point;
    }

    int horizonCheck(int x, int y){
        int temp = y, point = 1;
        if(temp < 9){
            while(m_Table[2 * x + 2][4 * (temp + 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
                temp += 1;
                point += 1;
                if(temp == 10) break;
            }
        }

        temp = y;
        if(temp > 0){
            while(m_Table[2 * x + 2][4 * (temp - 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
                temp -= 1;
                point += 1;
                if(temp == -1) break;
            }
        }

        return point;
    }

    int diagonCheck(int x, int y){
        int tempX = x, tempY = y, point = 1;
        if(tempX < 9 && tempY < 9){
            while(m_Table[2 * (tempX + 1) + 2][4 * (tempY + 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
                tempX++;
                tempY++;
                point++;
                if(tempX == 10 || tempY == 10) break;
            }
        }

        tempX = x; tempY = y;
        if(tempX > 0 && tempY > 0){
            while(m_Table[2 * (tempX - 1) + 2][4 * (tempY - 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
                tempX--;
                tempY--;
                point++;
                if(tempX == -1 || tempY == -1) break;
            }
        }

        return point;
    }

    int invertDiagonCheck(int x, int y){
        int tempX = x, tempY = y, point = 1;
        if(tempX < 9 && tempY > 0){
            while(m_Table[2 * (tempX + 1) + 2][4 * (tempY - 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
                tempX++;
                tempY--;
                point++;
                if(tempX == 10 || tempY == -1) break;
            }
        }

        tempX = x; tempY = y;
        if(tempX > 0 && tempY < 9){
            while(m_Table[2 * (tempX - 1) + 2][4 * (tempY + 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
                tempX--;
                tempY++;
                point++;
                if(tempX == -1 || tempY == 10) break;
            }
        }

        return point;
    }

    int checkPoint(int x, int y, int player){
        if(player == 0) m_Table[2 * x + 2][4 * y + 3] = 'O';
        else if(player == 1) m_Table[2 * x + 2][4 * y + 3] = 'X';

        int check = -1;
        if(horizonCheck(x, y) >= 4 || verticalCheck(x, y) >= 4 ||  diagonCheck(x, y) >= 4 || invertDiagonCheck(x, y) >= 4) check = 4;
        else if(horizonCheck(x, y) == 3 || verticalCheck(x, y) == 3 ||  diagonCheck(x, y) == 3 || invertDiagonCheck(x, y) == 3) check = 3;
        else if(horizonCheck(x, y) == 2 || verticalCheck(x, y) == 2 ||  diagonCheck(x, y) == 2 || invertDiagonCheck(x, y) == 2) check = 2;
        else if(horizonCheck(x, y) == 1 || verticalCheck(x, y) == 1 ||  diagonCheck(x, y) == 1 || invertDiagonCheck(x, y) == 1) check = 1;

        m_Table[2 * x + 2][4 * y + 3] = ' ';
        return check;
    }

    int checkWin(int x, int y, int turn){
        if(horizonCheck(x, y) == 4 || verticalCheck(x, y) == 4 ||  diagonCheck(x, y) == 4 || invertDiagonCheck(x, y) == 4){
            if(turn % 2 == 0) return 0;
            else return 1;
        }

        else if(turn == m_length * m_width) return 2;

        return -1;
    }

    vector<string> accepttedInput(){
        vector<string> ss;
        for(int i = 0; i < max(m_length, m_width); i++) ss.push_back(to_string(i));

        return ss;
    }

    ~Table(){
        m_Table.clear();
    }
};

#endif // _TABLE_H

