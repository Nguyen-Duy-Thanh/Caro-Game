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

    void Play(int x, int y, int player){
        if(player == 1) m_Table[2 * x + 2][4 * y + 3] = 'X';
        if(player == 2) m_Table[2 * x + 2][4 * y + 3] = 'O';
    }

    ~Table(){
        m_length = NULL;
        m_width = NULL;
        m_Table.clear();
    }
};

#endif // _TABLE_H

