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
        while(m_Table[2 * (temp + 1) + 2][4 * y + 3] == m_Table[2 * x + 2][4 * y + 3]){
            temp++;
            point++;
        }
        temp = x;
        while(m_Table[2 * (temp - 1) + 2][4 * y + 3] == m_Table[2 * x + 2][4 * y + 3]){
            temp--;
            point++;
        }
        return point;
    }

    int horizonCheck(int x, int y){
        int temp = y, point = 1;
        while(m_Table[2 * x + 2][4 * (temp + 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
            temp += 1;
            point += 1;
        }
        temp = y;
        while(m_Table[2 * x + 2][4 * (temp - 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
            temp -= 1;
            point += 1;
        }
        return point;
    }

    int diagonCheck(int x, int y){
        int tempX = x, tempY = y, point = 1;
        while(m_Table[2 * (tempX + 1) + 2][4 * (tempY + 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
            tempX++;
            tempY++;
            point++;
        }
        tempX = x; tempY = y;
        while(m_Table[2 * (tempX - 1) + 2][4 * (tempY - 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
            tempX--;
            tempY--;
            point++;
        }
        return point;
    }

    int invertDiagonCheck(int x, int y){
        int tempX = x, tempY = y, point = 1;
        while(m_Table[2 * (tempX + 1) + 2][4 * (tempY - 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
            tempX++;
            tempY++;
            point++;
        }
        tempX = x; tempY = y;
        while(m_Table[2 * (tempX - 1) + 2][4 * (tempY + 1) + 3] == m_Table[2 * x + 2][4 * y + 3]){
            tempX--;
            tempY--;
            point++;
        }
        return point;
    }

    int checkWin(int x, int y, int player){
        if(horizonCheck(x, y) == 4 || verticalCheck(x, y) == 4 ||  diagonCheck(x, y) == 4 || invertDiagonCheck(x, y) == 4){
            if(player == 0) return 0;
            else return 1;
        }
        return -1;
    }

    ~Table(){
        m_Table.clear();
    }
};

#endif // _TABLE_H

