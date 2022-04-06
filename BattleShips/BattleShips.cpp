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
    /// <summary>
    /// TO DO LIST:
    /// - Pretty up with menu and UI
    /// - Game end when either players ships are destoryed
    /// - Bug fixes
    /// </summary>
    /// <returns></returns>

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
            while (player->shipHits < 17 || ai->shipHits < 17)
            {
                ai->PrintAIBoard();
                cout << endl;
                player->PrintPlayerBoard();
                player->PlayerGuess(ai);
                ai->AIGuessEasy(player);
                system("cls");
            }
            //Sets gameRun to false so endscreen can be shown
            gameRun = false;
            system("cls");
        }
        //Hard Mode
        else if (input == "2")
        {
            player->CreatePlayerBoard();
            ai->GenerateAIBoard();

            while (player->shipHits < 16 || ai->shipHits < 16)
            {
                ai->PrintAIBoard();
                player->PrintPlayerBoard();
                player->PlayerGuess(ai);
                ai->AIGuessHard(player);
                system("cls");
            }
            gameRun = false;
            system("cls");
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

    cout << "  _____          __  __ ______    ______      ________ _____ " << endl;
    cout << " / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ " << endl;
    cout << "| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |" << endl;
    cout << "| | |_ | / /\\ \\ | |\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / " << endl;
    cout << "| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ " << endl;
    cout << " \\_____/_/    \\_\\_|  |_|______|  \____/   \\/   |______|_|  \\_\\ " << endl;

}