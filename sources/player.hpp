#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <array>
#include "card.hpp"
using namespace std;

constexpr int STACKINISIZE = 26;
namespace ariel
{
class Player
{
private:
    string name;
    int stackSize;
    int wonCardsSize;
    string currRival;
    bool isPlaying;

public:
    Player(string name);
    string getName();
    void setState(bool state);
    bool getState();

    int cardesTaken();
    int stacksize();
    void addWonCards(int cards_won);
    void newStack();
    void decreaseStack();
};
}
#endif