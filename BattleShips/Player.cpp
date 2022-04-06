#include "Player.h"
#include "AI.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Player::Player(){}

void Player::CreatePlayerBoard()
{
    //Variables for placing battleships
    int xCoord;
    int yCoord;
    int length = 0;
    char direction;

    //Input variable
    string input;

    //Generates the play board with the base
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            playerBoardArr[i][j] = '-';

        }
    }

    //While loop to check all ships have been placed
    while (shipNumber <= 5)
    {
        //Clears console
        system("cls");
        PrintPlayerBoard();
        //Switch for deciding the length of the ship to be placed
        switch (shipNumber)
        {
        case 1:
            length = 5;
            break;

        case 2:
            length = 4;
            break;

        case 3:
            length = 3;
            break;

        case 4:
            length = 3;
            break;
        case 5:
            length = 2;
            break;
        }

        cout << "Where do you want to place your " << length << " length ship?:" << endl;

        //Checks that player put in an int. (honestly dont know how it works but it works :) )
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        //X axis start position
        cout << "Input X Position (1 - 10): ";
        cin >> xCoord;
        cout << endl;

        //Y axis start position
        cout << "Input Y Postition (1 - 10): ";
        cin >> yCoord;
        cout << endl;

        if (xCoord > 10 || xCoord < 1 || yCoord > 10 || yCoord < 1)
        {
            cout << "Please enter a valid input" << endl;
            continue;
        }


        //Direction ship will build
        cout << "Input Direction of Ship (N, E, S, W): ";
        cin >> direction;
        cout << endl;

        //North
        if (direction == 'N' || direction == 'n')
        {
            //Stops the ships from being placed on the border
            if (length + 1 > yCoord)
            {
                cout << "Ship too long to be placed" << endl;
                cout << "Press any key to continue" << endl;
                cin;
                continue;
            }
            else
            {
                //Checks if ships are overlapping, if they're not the ship can place
                bool canPlace = false;
                for (int i = 0; i < length; i++)
                {
                    if (playerBoardArr[yCoord - i][xCoord] != '@')
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
                        playerBoardArr[yCoord - i][xCoord] = '@';
                    }
                }
                else
                {
                    cout << "Ship already exists here" << endl;
                    cout << "Press any key to continue" << endl;
                    cin;
                    continue;
                }
            }
        }

        //East
        else if (direction == 'E' || direction == 'e')
        {
            if (length > (11 - xCoord))
            {
                cout << "Ship too long to be placed" << endl;
                cout << "Press any key to continue" << endl;
                cin;
                continue;
            }
            else
            {
                bool canPlace = false;
                for (int i = 0; i < length; i++)
                {
                    if (playerBoardArr[yCoord][xCoord + i] != '@')
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
                        playerBoardArr[yCoord][xCoord + i] = '@';
                    }
                }
                else
                {
                    cout << "Ship already exists here" << endl;
                    cout << "Press any key to continue" << endl;
                    cin;
                    continue;
                }
            }
        }

        //South
        else if (direction == 'S' || direction == 's')
        {
            if (length > (11 - yCoord))
            {
                cout << "Ship too long to be placed" << endl;
                cout << "Press any key to continue" << endl;
                cin;
                continue;
            }
            else
            {
                bool canPlace = false;
                for (int i = 0; i < length; i++)
                {
                    if (playerBoardArr[yCoord + i][xCoord] != '@')
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
                        playerBoardArr[yCoord + i][xCoord] = '@';
                    }
                }
                else
                {
                    cout << "Ship already exists here" << endl;
                    cout << "Press any key to continue" << endl;
                    cin;
                    continue;
                }
            }
        }

        //West
        else if (direction == 'W' || direction == 'w')
        {
            if (length + 1 > xCoord)
            {
                cout << "Ship too long to be placed" << endl;
                cout << "Press any key to continue" << endl;
                cin;
                continue;
            }
            else
            {
                bool canPlace = false;
                for (int i = 0; i < length; i++)
                {
                    if (playerBoardArr[yCoord][xCoord - i] != '@')
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
                        playerBoardArr[yCoord][xCoord - i] = '@';
                    }
                }
                else
                {
                    cout << "Ship already exists here" << endl;
                    cout << "Press any key to continue" << endl;
                    cin;
                    continue;
                }
            }
        }
        else
        {
            cout << "Please enter a valid input" << endl;
            continue;
        }

        //Prints ship to board
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                //If Y is 0, print the X numbers
                if (j == 0)
                {
                    cout << numberboardX[i];
                }
                //If X is 0, print the Y numbers
                else if (i == 0)
                {
                    cout << numberboardY[j];
                }
                else
                {
                    cout << playerBoardArr[i][j];
                }
            }
            cout << "\n";
        }
        //Increase ship number when ship has been placed
        shipNumber++;
    }
}

//Function for printing the players board, this is seperate to the creation so that it can be reprinted with visual changes
void Player::PrintPlayerBoard()
{
    cout << "Player:" << endl;
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
                cout << playerBoardArr[i][j];
            }
        }
        cout << "\n";
    }
}

//Function for the players turn
void Player::PlayerGuess(AI* ai)
{
    //Ints for players guess
    int xGuess, yGuess;

    bool playerTurn = true;
    while (playerTurn)
    {
        //Checks that player put in an int. (honestly dont know how it works but it works :) )
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        cout << "Player Hits: " << shipHits << endl;

        cout << "Guess X: ";
        cin >> xGuess;
        cout << endl;

        cout << "Guess Y: ";
        cin >> yGuess;

        cout << endl;
        if (xGuess > 10 || xGuess < 1 || yGuess > 10 || yGuess < 1)
        {
            cout << "Please enter a valid input" << endl;
            continue;
        }
        //Checks if the location on the AI board is the ship char
        if (ai->aiBoardArr[yGuess][xGuess] == '@')
        {
            cout << "HIT!" << endl;
            ai->showBoard[yGuess][xGuess] = 'X';
            //Sets the board not shown to X too so that if the player guess' there again it doesnt count as a hit
            ai->aiBoardArr[yGuess][xGuess] = 'X';
            shipHits++;
            playerTurn = false;
        }
        else
        {
            cout << "MISS!" << endl;
            ai->showBoard[yGuess][xGuess] = 'M';
            playerTurn = false;
        }
    }
}

