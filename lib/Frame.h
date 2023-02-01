#ifndef _FRAME_H
#define _FRAME_H

#include<iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

// Coordinate
void gotoXY(int x, int y){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { (short int)x, (short int)y };
    SetConsoleCursorPosition(h,c);
}

// Frame color
void color(){
    system("Color F0"); // White background, black words
}

// Menu frame size 79x46
void menuFrame(int lines){
    // Top
    for(int i = 0; i < 78; i++){
        gotoXY(1 + i, 0);
        cout << "-";
    }

    // Bottom
    for(int i = 0; i < 78; i++){
        gotoXY(1 + i, 56);
        cout << "-";
    }

    // Left
    for(int i = 0; i < 55; i++){
        gotoXY(0, i + 1);
        cout << "|";
    }

    // Right
    for(int i = 0; i < 55; i++){
        gotoXY(79, i + 1);
        cout << "|";
    }

    // Corner
    gotoXY(0, 0); cout << "+";
    gotoXY(0, 56); cout << "+";
    gotoXY(79, 0); cout << "+";
    gotoXY(79, 56); cout << "+";
    gotoXY(34, 0);  cout<< " CARO GAME ";

    if(lines != -1){
        // Words border
        for(int i = 0; i < 55; i++){
            gotoXY(18 + i, 11);
            cout << "-";
        }

        for(int i = 0; i < 55; i++){
            gotoXY(18 + i, 11 + lines + 3);
            cout << "-";
        }
    }
}

// Check input error
void checkOption(string &option, int coordX, int coordY){
    if(option != ""){
        gotoXY(coordX, coordY); cout << "Input error, check again" << endl;
        gotoXY(coordX + 7, coordY + 1); cout << "                                                           ";
        gotoXY(coordX, coordY + 1); cout << "Choice: ";
        cin >> option;
    }
    else{
        gotoXY(coordX, coordY); cout << "Choice: ";
        cin >> option;
    }
}

// Reset input line
void deleteInputLines(int stringSize, int coordX, int coordY){
    gotoXY(coordX + stringSize, coordY);
    cout << "                                                           ";
    gotoXY(coordX, coordY + 1);
    cout << "                                                           ";
    gotoXY(coordX, coordY + 2);
    cout << "                                                           ";
    gotoXY(coordX, coordY + 3);
    cout << "                                                           ";
}

#endif // _FRAME_H
