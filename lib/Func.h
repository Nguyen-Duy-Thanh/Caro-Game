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

#endif // _FUNC_H
