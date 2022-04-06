// BattleShips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "AI.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    AI* ai = new AI();
    Player* player = new Player();

    bool gameRun = true;
    while (gameRun)
    {        
        //Title screen
        cout << " ____       _______ _______ _      ______  _____ _    _ _____ _____   _____ " << endl;
        cout << "|  _ \\   /\\|__   __|__   __| |    |  ____|/ ____| |  | |_   _|  __ \\ / ____|" << endl;
        cout << "| |_) | /  \\  | |     | |  | |    | |__  | (___ | |__| | | | | |__) | (___  " << endl;
        cout << "|  _ < / /\\ \\ | |     | |  | |    |  __|  \\___ \\|  __  | | | |  ___/ \\___ \\ " << endl;
        cout << "| |_) / ____ \\| |     | |  | |____| |____ ____) | |  | |_| |_| |     ____) |" << endl;
        cout << "|____/_/    \\_\\_|     |_|  |______|______|_____/|_|  |_|_____|_|    |_____/ " << endl;

        //Choose AI difficulty
        cout << "Please choose your difficulty:" << endl;
        cout << "1. Easy   2. Hard" << endl;
        string input;
        cin >> input;

        //Easy Mode
        if (input == "1")
        {
            player->CreatePlayerBoard();
            ai->GenerateAIBoard();

            //Player and AI keep guessing until one of them hits all their opponents ships
            while (gameRun)
            {
                ai->PrintAIBoard();
                cout << endl;
                player->PrintPlayerBoard();
                player->PlayerGuess(ai);
                ai->AIGuessEasy(player);
                system("cls");

                if (player->shipHits == 17 || ai->shipHits == 17)
                {
                    gameRun = false;
                }
            }
            //Sets gameRun to false so endscreen can be shown
            
        }
        //Hard Mode
        else if (input == "2")
        {
            player->CreatePlayerBoard();
            ai->GenerateAIBoard();

            while (gameRun)
            {
                ai->PrintAIBoard();
                player->PrintPlayerBoard();
                player->PlayerGuess(ai);
                ai->AIGuessHard(player);
                system("cls");

                if (player->shipHits == 17 || ai->shipHits == 17)
                {
                    gameRun = false;
                }
            }
        }
        else
        {
            cout << "Please enter a valid input" << endl;
            cout << "Press Enter to continue" << endl;
            cin;
            system("cls");
            continue;
        }
    }

    //Gameover screen
    cout << "  _____          __  __ ______    ______      ________ _____ " << endl;
    cout << " / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ " << endl;
    cout << "| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |" << endl;
    cout << "| | |_ | / /\\ \\ |  |\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / " << endl;
    cout << "| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ " << endl;
    cout << " \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ " << endl;

    if(player->shipHits == 17)
    {
        cout << "CONGRATULATIONS!!!" << endl;
        cout << "YOU BEAT AN AI WITH THE INTELLIGENCE OF AN 8 YEAR OLD!";
    }
    else
    {
        cout << "YOU LOST TO AN AI WITH THE INTELLIGENCE OF AN 8 YEAR OLD!" << endl;
        cout << "This Battleship grind is not for you...";
    }
}