#pragma once
#include <iostream>
#ifndef Player_H
#define Player_H

//Constuctor so Player can access AI (alternative for using #incluide "AI.h" but that broke the code)
class AI;

class Player
{
public:
    Player();
    //Variables for the players board
    char playerBoardArr[11][11];
    //Creates numbers around the border
    char numberboardX[11][11] = { " 0 ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 ", "10 " };
    char numberboardY[11][11] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

    //Int used for the While loop and for Switch used for the order of placing the ships
    int shipNumber = 1;

    //Int for Ship Hits, when this reacher 17(total ship parts for each player) the game will end
    int shipHits = 0;

    //Creation of the functions
    void CreatePlayerBoard();
    void PrintPlayerBoard();
    void PlayerGuess(AI* ai);
};
#endif // !Player_H
