#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <sstream>
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel{
const int DECKSIZE = 52;

class Deck
{
private:
    vector<Card> deck;

public:
    Deck();
    void shuffle();
    Card getCard(int index);
};
}
#endif