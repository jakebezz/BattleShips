// BattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Player
{
public:
    //Variables for the play board
    char playerBoardArr[11][11];
    int numberBoardX[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numberBoardY[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    void CreatePlayerBoard()
    {
        //Variables for placing battleships
        int xCoord;
        int yCoord;
        int length = 0;
        char direction;

        //Bools and int for if ship has been placed
        bool fiveLength = false;
        bool fourLength = false;
        int threeLength = 0; // max 2
        bool twoLength = false;

        //Input variable
        string input;

        //Temp variables to check that the X and Y location havent been used  before
        int tempY = 0;
        int tempX = 0;



        //Generates the play board
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                playerBoardArr[i][j] = '-';

            }
        }

        //While loop to check all ships have been placed
        int shipsPlaces = 0;
        while (shipsPlaces < 5)
        {
            //For loop to place ships
            for (int i = 0; i < 5; i++)
            {
                //X axis start position
                cout << "Input X Position (1 - 10): ";
                cin >> xCoord;
                cout << endl;

                //Y axis start position
                cout << "Input Y Postition (1 - 10): ";
                cin >> yCoord;
                cout << endl;

                if (tempX == xCoord && tempY == yCoord)
                {
                    cout << "Cannot place ship in same place";
                    cin;
                    break;
                }

                else
                {
                    //Sets the temp ints to the Coords
                    tempX = xCoord;
                    tempY = yCoord;

                    //Choose ships length, doesn't display a previous length if its been used
                    cout << "Which ship do you choose?:" << endl;
                    if (fiveLength == false)
                    {
                        cout << "1. 5 Length" << endl;
                        fiveLength = true;
                    }
                    if (fourLength == false)
                    {
                        cout << "2. 4 Length" << endl;
                        fourLength = true;
                    }
                    if (threeLength != 2)
                    {
                        cout << "3. 3 Length" << endl;
                    }
                    if (twoLength == false)
                    {
                        cout << "4. 2 Length" << endl;
                    }
                    cin >> input;

                    //Confirms ships length
                    if (input == "1")
                    {
                        length = 5;
                        fiveLength = true;
                    }
                    else if (input == "2")
                    {
                        length = 4;
                        fourLength = true;
                    }
                    else if (input == "3")
                    {
                        length = 3;
                        threeLength++;
                    }
                    else if (input == "4")
                    {
                        length = 2;
                        twoLength = true;
                    }
                    cout << endl;

                    //Direction ship will build
                    cout << "Input Direction of Ship (N, E, S, W): ";
                    cin >> direction;
                    cout << endl;

                    //North
                    if (direction == 'N' || direction == 'n')
                    {
                        if (length + 1 > yCoord)
                        {
                            cout << "ship too long" << endl;
                            cin;
                            break;
                        }
                        else
                        {
                            for (int i = 0; i < length; i++)
                            {
                                playerBoardArr[yCoord - i][xCoord - 1] = '@';
                            }
                        }
                    }

                    //East
                    else if (direction == 'E' || direction == 'e')
                    {
                        if (length > (11 - xCoord))
                        {
                            cout << "Ship too long" << endl;
                            cin;
                            break;
                        }
                        else
                        {
                            for (int i = 0; i < length; i++)
                            {
                                playerBoardArr[yCoord][xCoord + i] = '@';
                            }
                        }
                    }

                    //South
                    else if (direction == 'S' || direction == 's')
                    {
                        if (length > (11 - yCoord))
                        {
                            cout << "Ship too long" << endl;
                            cin;
                            break;
                        }
                        else
                        {
                            for (int i = 0; i < length; i++)
                            {
                                playerBoardArr[yCoord + i][xCoord] = '@';
                            }
                        }
                    }

                    //West
                    else if (direction == 'W' || direction == 'w')
                    {
                        if (length + 1 > xCoord)
                        {
                            cout << "Ship too long" << endl;
                            cin;
                            break;
                        }

                        else
                        {
                            for (int i = 0; i < length; i++)
                            {
                                playerBoardArr[yCoord - 1][xCoord - 1 - i] = '@';
                            }
                        }
                    }

                    //Prints ship to board
                    for (int i = 0; i < 11; i++)
                    {
                        for (int j = 0; j < 11; j++)
                        {
                            if (j == 0)
                            {
                                cout << numberBoardX[i];
                            }
                            else if(i == 0)
                            {
                                cout << numberBoardY[j];
                            }
                            else
                            {
                                cout << playerBoardArr[i][j];
                            }
                        }
                        cout << "\n";
                    }
                }
            }
        }
    }

    void PrintPlayerBoard()
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (j == 0)
                {
                    cout << numberBoardX[i];
                }
                else if (i == 0)
                {
                    cout << numberBoardY[j];
                }
                else
                {
                    cout << playerBoardArr[i][j];
                }
            }
            cout << "\n";
        }
    }
};

int main()
{
    Player player;
    player.CreatePlayerBoard();

}