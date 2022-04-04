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
    /// - Fix placement so it more consistently detects if they are overlapping
    /// - Fix player guessing so it prints X when hitting the enemy ship
    /// - Fix the 10th row pushing the line to the right
    /// - Pretty up with menu and UI
    /// - Add an easy AI mode so it just guesses random places
    /// </summary>
    /// <returns></returns>

    AI* ai = new AI();
    Player *player = new Player();

    player->CreatePlayerBoard();
    ai->GenerateAIBoard();

    while (true)
    {
        ai->PrintAIBoard();
        player->PrintPlayerBoard();
        player->PlayerGuess();
        ai->AIGuess(player);
        system("cls");
    }

}