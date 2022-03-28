#pragma once
#ifndef Player_H
#define Player_H

class AI;

class Player
{
public:

    AI* pAI;

    Player();
    //Variables for the players board
    char playerBoardArr[11][11];
    //Creates numbers around the border
    int numberBoardX[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int numberBoardY[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    //Int used for the While loop and for Switch used for the order of placing the ships
    int shipNumber = 1;

    //Creation of the functions
    void CreatePlayerBoard();
    void PrintPlayerBoard();
    void PlayerGuess(AI* ai);
};
#endif // !Player_H
