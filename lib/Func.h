#ifndef _FUNC_H
#define _FUNC_H

string Align(string str, int s, char al){
    int turn = 0;
    while(str.size() < s){
        if(al == 'c'){
            if(turn % 2 == 1) str = " " + str;
            else str = str + " ";
            turn++;
        }

        else if(al == 'l') str += " ";
        else str = " " + str;

    }

    return str;
}

string tolower(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += ('a' - 'A');
    }

    return s;
}

bool checkString(string s, vector<string> ss){
    for(int i = 0; i < ss.size(); i++) if(s == ss[i]) return true;
    return false;
}

#endif // _FUNC_H
