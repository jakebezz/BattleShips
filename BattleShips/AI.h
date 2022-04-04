#pragma once
#include "Player.h"
#ifndef AI_H
#define AI_H
class AI
{
public:
    AI();

    //AI Guessing, outside of the function so they're not changed when the function is called
    //int for the While loops
    int shipHit = 0;

    //Variables for the first hit location for the ship, if they miss going in a direction and ship isnt destroyed, they will check the opposite direction
    int origX = 0;
    int origY = 0;

    //Int for checking if the ai has checked that direction before, each number is a different direction
    int lastCheckDir = 0;

    //Arrays for the AI board, show board is the one the player will see
    char aiBoardArr[12][12];
    char showBoard[12][12];
    //Creates numbers around the border
    int numberBoardX[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int numberBoardY[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    void GenerateAIBoard();
    void PrintAIBoard();
    void AIGuess(Player* player);
};
#endif // !AI_H

