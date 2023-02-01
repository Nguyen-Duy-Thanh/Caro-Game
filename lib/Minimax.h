#ifndef _MINIMAX_H
#define _MINIMAX_H

#include<iostream>
#include<vector>
#include <cstdlib>
#include<ctime>

#include"table.h"

using namespace std;

vector<int> createMove(Table t){
    srand(time(NULL));
    int x, y;
    do{
        x = rand() % t.getLength();
        y = rand() % t.getWidth();
    }while(t.position(x, y) != ' ');

    vector<int> move;
    move.push_back(x);
    move.push_back(y);
    move.push_back(t.checkPoint(x, y, 0));

    return move;
}

vector<int> findBestMove(Table t, int turn){
    vector<int> bestMove;
    bestMove = createMove(t);
    for(int i = 0; i < t.getLength(); i++){
        for(int j = 0; j < t.getWidth(); j++){
            if(t.position(i, j) == ' ' && !(i == bestMove[0] && j == bestMove[1])){
                if(t.checkPoint(i, j, turn % 2) > t.checkPoint(bestMove[0], bestMove[1], turn % 2)){
                    bestMove.clear();
                    bestMove.push_back(i);
                    bestMove.push_back(j);
                    bestMove.push_back(t.checkPoint(i, j, turn % 2));
                }
            }
        }
    }

    return bestMove;
}

int minimax(Table t, int x, int y, int turn, int depth){
    Table temp = t;
    temp.Mark(x, y, turn);
    temp.Draw();
    system("pause");
    turn -= 1;

    if(temp.checkWin(x, y, 0) == 0) return 10 - depth;
    if(temp.checkWin(x, y, 1) == 1) return -10 + depth;
    if(turn == temp.getLength() * temp.getWidth()) return 0;

    vector<int> bestMove;
    if(turn % 2 == 0){
        int bestVal = -100;

        bestMove = findBestMove(t, turn+1);
        int value = minimax(temp, bestMove[0], bestMove[1], turn + 1, depth + 1);
        bestVal = max( bestVal, value);
        temp.Draw();
        cout << turn << " " << bestVal << endl;
        system("pause");
        return bestVal;
    }

    else if(turn % 2 == 1){
        int bestVal = 100;

        bestMove = findBestMove(t, turn+1);
        int value = minimax(temp, bestMove[0], bestMove[1], turn + 1, depth + 1);
        bestVal = min( bestVal, value);
        temp.Draw();
        cout << turn << " " << bestVal << endl;
        system("pause");
        return bestVal;
    }
}

vector<int> findBestMoveHard(Table t, int turn){
    vector<int> playerBestMove = findBestMove(t, turn + 1);
    vector<int> botBestMove = findBestMove(t, turn);

    if(botBestMove[2] > 2) return botBestMove;
    if(playerBestMove[2] > 2 || turn == 2) return playerBestMove;

    return botBestMove;
}

vector<int> findBestMoveBot(Table t, int turn){
    vector<int> bestMove;
    bestMove = createMove(t);
    for(int i = 0; i < t.getLength(); i++){
        for(int j = 0; j < t.getWidth(); j++){
            if(t.position(i, j) == ' ' && !(i == bestMove[0] && j == bestMove[1])){
                if(minimax(t, i, j, 0, 0) > minimax(t, i, j, 0, 0)){
                    bestMove.clear();
                    bestMove.push_back(i);
                    bestMove.push_back(j);
                    bestMove.push_back(t.checkPoint(i, j, turn % 2));
                }
            }
        }
    }

    return bestMove;
}

#endif // _MINIMAX_H
