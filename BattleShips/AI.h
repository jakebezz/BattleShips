#pragma once
#include "Player.h"
#include <iostream>
#ifndef AI_H
#define AI_H
class AI
{
public:
    AI();

    //Used for the while loop, game will stop if this reaches 17
    int shipHits = 0;

    //Variables for the first hit location for the ship, if they miss going in a direction and ship isnt destroyed, they will check the opposite direction
    int origX = 0;
    int origY = 0;

    //Int for checking if the ai has checked that direction before, each number is a different direction
    int lastCheckDir = 0;

    //Arrays for the AI board, show board is the one the player will see
    char aiBoardArr[12][12];
    char showBoard[12][12];

    //Creates numbers around the border
    char numberboardX[11][11] = { " 0 ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 ", "10 " };
    char numberboardY[11][11] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

    void GenerateAIBoard();
    void PrintAIBoard();
    //Two AI difficulties, on Easy the AI will just go to random locations every guess. On Hard the AI will keep guessing until it gets a hit then will keep guessing around that hit until the ship is destroyed
    void AIGuessHard(Player* player);
    void AIGuessEasy(Player* player);
};
#endif // !AI_H

