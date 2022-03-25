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
    //YOU CANT CHANGE OTHER PLAYERS BOARD FROM THE GUESS FUNCTIONS

    Player player;
    AI ai;

    player.CreatePlayerBoard();
    ai.GenerateAIBoard();

    while (true)
    {
        ai.PrintAIBoard();
        player.PrintPlayerBoard();
        player.PlayerGuess();
        ai.AIGuess();
        system("cls");
    }

}