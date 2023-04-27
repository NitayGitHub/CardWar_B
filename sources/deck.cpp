#include "card.hpp"
#include "deck.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
using namespace ariel;
using namespace std;
const int ace = 1;
const int two = 2;
const int three = 3;
const int four = 4;
const int five = 5;
const int six = 6;
const int seven = 7;
const int eight = 8;
const int nine = 9;
const int ten = 10;
const int jack = 11;
const int queen = 12;
const int king = 13;
const string types[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};

const int deckSize = 52;
Deck::Deck()
{
    for(int i = 0; i < 4; i++){
        deck.push_back(Card(ace, "Ace of " + types[i]));
        deck.push_back(Card(two, "Two of " + types[i]));
        deck.push_back(Card(three, "Three of " + types[i]));
        deck.push_back(Card(four, "Four of " + types[i]));
        deck.push_back(Card(five, "Five of " + types[i]));
        deck.push_back(Card(six, "Six of " + types[i]));
        deck.push_back(Card(seven, "Seven of " + types[i]));
        deck.push_back(Card(eight, "Eight of " + types[i]));
        deck.push_back(Card(nine, "Nine of " + types[i]));
        deck.push_back(Card(ten, "Ten of " + types[i]));
        deck.push_back(Card(jack, "Jack of " + types[i]));
        deck.push_back(Card(queen, "Queen of " + types[i]));
        deck.push_back(Card(king, "King of " + types[i]));
    }

}

void Deck::shuffle()
{
    srand(time(0));
    for (int i = 0; i < deckSize; i++)
    {
        int j = i + (rand() % (deckSize - i));
        swap(deck.at((unsigned)i), deck.at((unsigned)j));
    }
}

Card Deck::getCard(int index)
{
    return this->deck[(unsigned)index];
}