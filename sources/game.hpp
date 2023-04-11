#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <sstream>
#include <stack>
#include "player.hpp"
#include "deck.hpp"
using namespace std;
namespace ariel{

class Game
{
private:
    Player& player1;
    Player& player2;
    int turn;
    Deck deck;
    stack <string> turnOutcome;
    string winner;
    bool gameStarted;
    int drawCounter;

public:
    Game(Player& player1, Player& player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    int whoWonTurn(int p1Val, int p2Val);
};

}

#endif