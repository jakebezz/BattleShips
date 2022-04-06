#include "AI.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

AI::AI(){}

void AI::GenerateAIBoard()
{
    //Random number generator
    srand((unsigned)time(0));

    //Battleship length
    int length;

    //Input variable
    string input;

    //Temp ints to check that the X and Y location havent been used  before
    int tempY = 0;
    int tempX = 0;

    //Variables for while loop and Switch. Starts at 1 so it is easier to understand for switch
    int shipsPlaced = 1;

    //Bool to check whether the ship was able to be placed
    bool shipDidPlace;

    //Generates the board the player is shown
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            showBoard[i][j] = '-';
        }
    }

    //FOR TESTING DELETE THIS
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            aiBoardArr[i][j] = '-';
        }
    }

    //While loop to check all ships have been placed
    while (shipsPlaced < 6)
    {
        shipDidPlace = false;

        //Random ints for where the AI places the ship and the direction the ship goes
        int xCoord = (rand() % 10) + 1;
        int yCoord = (rand() % 10) + 1;
        int direction = (rand() % 4) + 1;

        //For loop to place ships
        for (int i = 0; i < 5; i++)
        {
            //IS THIS NEEDED? AS IT ONLY STOPS THE SHIP BEING PLACED ON THE PREV SHIP, NOT ALL THE SHIPS. MAYBE AN ARRAY???
            if (tempX == xCoord && tempY == yCoord)
            {
                break;
            }
            else
            {
                //Sets the temp ints to the Coords
                tempX = xCoord;
                tempY = yCoord;

                switch (shipsPlaced)
                {
                case 1:
                    length = 2;
                    break;

                case 2:
                    length = 3;
                    break;

                case 3:
                    length = 3;
                    break;

                case 4:
                    length = 4;
                    break;

                case 5:
                    length = 5;
                    break;

                default:
                    break;
                }

                //North
                if (direction == 1)
                {
                    if (length + 1 > yCoord)
                    {
                        break;
                    }
                    else
                    {
                        //DOESNT WOKR!!!!!!!
                        bool canPlace = false;
                        for (int i = 0; i < length; i++)
                        {
                            if (aiBoardArr[yCoord - i][xCoord] != '@')
                            {
                                canPlace = true;
                            }
                            else
                            {
                                canPlace = false;
                                break;
                            }
                        }
                        //Places the ships on the board
                        if (canPlace == true)
                        {
                            for (int i = 0; i < length; i++)
                            {
                                aiBoardArr[yCoord - i][xCoord] = '@';
                                shipDidPlace = true;
                            }
                        }
                        else
                        {
                            shipDidPlace = false;
                        }
                    }
                }
                //East
                else if (direction == 2)
                {
                    if (length > (11 - xCoord))
                    {
                        break;
                    }
                    else
                    {
                        bool canPlace = false;
                        for (int i = 0; i < length; i++)
                        {
                            if (aiBoardArr[yCoord][xCoord + i] != '@')
                            {
                                canPlace = true;
                            }
                            else
                            {
                                canPlace = false;
                                break;
                            }
                        }
                        if (canPlace == true)
                        {
                            for (int i = 0; i < length; i++)
                            {
                                aiBoardArr[yCoord][xCoord + i] = '@';
                                shipDidPlace = true;
                            }
                        }
                        else
                        {
                            shipDidPlace = false;
                        }
                    }
                }
                //South
                else if (direction == 3)
                {
                    if (length > (11 - yCoord))
                    {
                        break;
                    }
                    else
                    {
                        bool canPlace = false;
                        for (int i = 0; i < length; i++)
                        {
                            if (aiBoardArr[yCoord + i][xCoord] != '@')
                            {
                                canPlace = true;
                            }
                            else
                            {
                                canPlace = false;
                                break;
                            }
                        }
                        if (canPlace == true)
                        {
                            for (int i = 0; i < length; i++)
                            {
                                aiBoardArr[yCoord + i][xCoord] = '@';
                                shipDidPlace = true;
                            }
                        }
                        else
                        {
                            shipDidPlace = false;
                        }

                    }
                }
                //West
                else if (direction == 4)
                {
                    if (length + 1 > xCoord)
                    {
                        break;
                    }
                    else
                    {
                        bool canPlace = false;
                        for (int i = 0; i < length; i++)
                        {
                            if (aiBoardArr[yCoord][xCoord - i] != '@')
                            {
                                canPlace = true;
                            }
                            else
                            {
                                canPlace = false;
                                break;
                            }
                        }
                        if (canPlace == true)
                        {
                            for (int i = 0; i < length; i++)
                            {
                                aiBoardArr[yCoord][xCoord - i] = '@';
                                shipDidPlace = true;
                            }
                        }
                        else
                        {
                            shipDidPlace = false;
                        }
                    }
                }
            }
            if (shipDidPlace == true)
            {
                shipsPlaced++;
            }
        }
    }
}

//Function for Printing the AIs board, seperate from the generation so it can be reprinted with visual changes
void AI::PrintAIBoard()
{
    //Prints the AI board without ships
    cout << "Enemy: " << endl;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (j == 0)
            {
                cout << numberboardX[i];
            }
            else if (i == 0)
            {
                cout << numberboardY[j];
            }
            else
            {
                //cout << aiBoardArr[i][j];
                cout << showBoard[i][j];
            }
        }
        cout << "\n";
    }
}

//Function for the AIs guessing
void AI::AIGuessHard(Player* player)
{
    srand((unsigned)time(0));

    bool aiTurn = true;
    while (aiTurn)
    {
        //If the origX and Y int have be used
        if (origX != 0 && origY != 0)
        {
            //If last hit was left, guess right
            if (lastCheckDir == 1)
            {
                //For loop that will keep going in one direction until it misses a ship
                for (int i = 1; i < 6; i++)
                {
                    //Hit
                    if (player->playerBoardArr[origY][origX + i] == '@')
                    {
                        //Sets the players ship to X (hit)
                        player->playerBoardArr[origY][origX + i] = 'X';
                        //Sets lastCheckDir to this direction so it whill check here again until it misses
                        lastCheckDir = 1;
                        //Increase ship hits
                        shipHits++;
                    }
                    //Miss
                    else
                    {
                        //Sets the players board to M (miss)
                        player->playerBoardArr[origY][origX + i] = 'M';
                        //Reset variables
                        origX = 0;
                        origY = 0;
                        lastCheckDir = 0;
                        aiTurn = false;
                        i = 6;
                    }
                }
                continue;
            }
            //If last hit was right, guess left
            if (lastCheckDir == 2)
            {
                for (int i = 1; i < 6; i++)
                {
                    if (player->playerBoardArr[origY][origX + i] == '@')
                    {
                        player->playerBoardArr[origY][origX + i] = 'X';
                        lastCheckDir = 2;
                        shipHits++;
                    }
                    else
                    {
                        player->playerBoardArr[origY][origX + i] = 'M';
                        origX = 0;
                        origY = 0;
                        lastCheckDir = 0;
                        aiTurn = false;
                        i = 6;
                    }
                }
                continue;
            }
            //If last hit was up, guess down
            if (lastCheckDir == 3)
            {
                for (int i = 1; i < 6; i++)
                {
                    if (player->playerBoardArr[origY + i][origX] == '@')
                    {
                        player->playerBoardArr[origY + i][origX] = 'X';
                        lastCheckDir = 3;
                        shipHits++;
                    }
                    else
                    {
                        player->playerBoardArr[origY + i][origX] = 'M';
                        origX = 0;
                        origY = 0;
                        lastCheckDir = 0;
                        aiTurn = false;
                        i = 6;
                    }
                }
                continue;
            }
            //If last hit was down, guess up
            if (lastCheckDir == 4)
            {
                for (int i = 1; i < 6; i++)
                {
                    if (player->playerBoardArr[origY - i][origX] == '@')
                    {
                        player->playerBoardArr[origY - i][origX] = 'X';
                        lastCheckDir = 4;
                        shipHits++;
                    }
                    else
                    {
                        player->playerBoardArr[origY - i][origX] = 'M';
                        origX = 0;
                        origY = 0;
                        lastCheckDir = 0;
                        aiTurn = false;
                        i = 6;
                    }
                }
                continue;
            }
        }

        else
        {
            //Random numbers for the X and Y coord guess
            int guessX = (rand() % 10) + 1;
            int guessY = (rand() % 10) + 1;

            if (player->playerBoardArr[guessY][guessX] == '@')
            {
                //If the AI hits a ship, change the "@" on the players board to a "X"
                player->playerBoardArr[guessY][guessX] = 'X';
                origX = guessX;
                origY = guessY;
                shipHits++;

                //Random number for the direction the AI guesses
                int nextGuess = (rand() % 3) + 1;

                //Left
                if (nextGuess == 1)
                {
                    for (int i = 1; i < 6; i++)
                    {
                        if (player->playerBoardArr[guessY][guessX - i] == '@')
                        {
                            player->playerBoardArr[guessY][guessX - i] = 'X';
                            //Sets lastCheckDir to 1 so it will check right next
                            lastCheckDir = 1;
                            shipHits++;
                        }
                        //Counts as miss but doesn't change to X to an M
                        else if (player->playerBoardArr[guessY][guessX - i] == 'X')
                        {
                            player->playerBoardArr[guessY][guessX - i] = 'X';
                            lastCheckDir = 1;
                            aiTurn = false;
                            i = 6;
                        }
                        else
                        {
                            player->playerBoardArr[guessY][guessX - i] = 'M';
                            lastCheckDir = 1;
                            aiTurn = false;
                            i = 6;
                        }
                    }
                    continue;
                }
                //Right
                if (nextGuess == 2)
                {
                    for (int i = 1; i < 6; i++)
                    {
                        if (player->playerBoardArr[guessY][guessX + i] == '@')
                        {
                            player->playerBoardArr[guessY][guessX + i] = 'X';
                            lastCheckDir = 2;
                            shipHits++;
                        }
                        else if (player->playerBoardArr[guessY][guessX + i] == 'X')
                        {
                            player->playerBoardArr[guessY][guessX + i] = 'X';
                            lastCheckDir = 2;
                            aiTurn = false;
                            i = 6;
                        }
                        else
                        {
                            player->playerBoardArr[guessY][guessX + i] = 'M';
                            lastCheckDir = 2;
                            aiTurn = false;
                            i = 6;
                        }
                    }
                    continue;
                }
                //Up
                if (nextGuess == 3)
                {
                    for (int i = 1; i < 6; i++)
                    {
                        if (player->playerBoardArr[guessY - i][guessX] == '@')
                        {
                            player->playerBoardArr[guessY - i][guessX] = 'X';
                            lastCheckDir = 3;
                            shipHits++;
                        }
                        else if (player->playerBoardArr[guessY - i][guessX] == 'X')
                        {
                            player->playerBoardArr[guessY - i][guessX] = 'X';
                            lastCheckDir = 3;
                            aiTurn = false;
                            i = 6;
                        }
                        else
                        {
                            player->playerBoardArr[guessY - i][guessX] = 'M';
                            lastCheckDir = 3;
                            aiTurn = false;
                            i = 6;
                        }
                    }
                    continue;
                }
                //Down
                if (nextGuess == 4)
                {
                    for (int i = 1; i < 6; i++)
                    {
                        if (player->playerBoardArr[guessY + i][guessX] == '@')
                        {
                            player->playerBoardArr[guessY + i][guessX] = 'X';
                            lastCheckDir = 4;
                            shipHits++;
                        }
                        else if (player->playerBoardArr[guessY][guessX - i] == 'X')
                        {
                            player->playerBoardArr[guessY + i][guessX] = 'X';
                            lastCheckDir = 4;
                            aiTurn = false;
                            i = 6;
                        }
                        else
                        {
                            player->playerBoardArr[guessY + i][guessX] = 'M';
                            lastCheckDir = 4;
                            aiTurn = false;
                            i = 6;
                        }
                    }
                    continue;
                }
            }
            else if (player->playerBoardArr[guessY][guessX] == 'X')
            {
                player->playerBoardArr[guessY][guessX] = 'X';
                continue;
            }
            else
            {
                cout << "MISS!" << endl;
                player->playerBoardArr[guessY][guessX] = 'M';
                aiTurn = false;
                continue;
            }
        }
    }
}

void AI::AIGuessEasy(Player* player)
{
    bool aiTurn = true;
    while (aiTurn)
    {
        //Random numbers for the X and Y coord guess
        int guessX = (rand() % 10) + 1;
        int guessY = (rand() % 10) + 1;

        if (player->playerBoardArr[guessY][guessX] == '@')
        {
            //If the AI hits a ship, change the "@" on the players board to a "X"
            cout << "HIT!" << endl;
            player->playerBoardArr[guessY][guessX] = 'X';
            origX = guessX;
            origY = guessY;
            shipHits++;
        }
        else if (player->playerBoardArr[guessY][guessX] == 'X')
        {
            player->playerBoardArr[guessY][guessX] = 'X';
            continue;
        }
        else
        {
            cout << "MISS!" << endl;
            player->playerBoardArr[guessY][guessX] = 'M';
            aiTurn = false;
            continue;
        }
    }
}
