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
    /// </summary>
    /// <returns></returns>

    AI* ai = new AI();
    Player* player = new Player();



    player->CreatePlayerBoard();
    ai->GenerateAIBoard();

    while (player->shipHits < 17 || ai->shipHits < 17)
    {
        ai->PrintAIBoard();
        player->PrintPlayerBoard();
        player->PlayerGuess(ai);
        ai->AIGuessHard(player);
        system("cls");
    }

}