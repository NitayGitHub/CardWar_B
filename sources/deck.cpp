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

const int deckSize = 52;
Deck::Deck()
{
    deck.push_back(Card(ace, "Ace of Spades"));
    deck.push_back(Card(two, "Two of Spades"));
    deck.push_back(Card(three, "Three of Spades"));
    deck.push_back(Card(four, "Four of Spades"));
    deck.push_back(Card(five, "Five of Spades"));
    deck.push_back(Card(six, "Six of Spades"));
    deck.push_back(Card(seven, "Seven of Spades"));
    deck.push_back(Card(eight, "Eight of Spades"));
    deck.push_back(Card(nine, "Nine of Spades"));
    deck.push_back(Card(ten, "Ten of Spades"));
    deck.push_back(Card(jack, "Jack of Spades"));
    deck.push_back(Card(queen, "Queen of Spades"));
    deck.push_back(Card(king, "King of Spades"));
    deck.push_back(Card(ace, "Ace of Hearts"));
    deck.push_back(Card(two, "Two of Hearts"));
    deck.push_back(Card(three, "Three of Hearts"));
    deck.push_back(Card(four, "Four of Hearts"));
    deck.push_back(Card(five, "Five of Hearts"));
    deck.push_back(Card(six, "Six of Hearts"));
    deck.push_back(Card(seven, "Seven of Hearts"));
    deck.push_back(Card(eight, "Eight of Hearts"));
    deck.push_back(Card(nine, "Nine of Hearts"));
    deck.push_back(Card(ten, "Ten of Hearts"));
    deck.push_back(Card(jack, "Jack of Hearts"));
    deck.push_back(Card(queen, "Queen of Hearts"));
    deck.push_back(Card(king, "King of Hearts"));
    deck.push_back(Card(ace, "Ace of Clubs"));
    deck.push_back(Card(two, "Two of Clubs"));
    deck.push_back(Card(three, "Three of Clubs"));
    deck.push_back(Card(four, "Four of Clubs"));
    deck.push_back(Card(five, "Five of Clubs"));
    deck.push_back(Card(six, "Six of Clubs"));
    deck.push_back(Card(seven, "Seven of Clubs"));
    deck.push_back(Card(eight, "Eight of Clubs"));
    deck.push_back(Card(nine, "Nine of Clubs"));
    deck.push_back(Card(ten, "Ten of Clubs"));
    deck.push_back(Card(jack, "Jack of Clubs"));
    deck.push_back(Card(queen, "Queen of Clubs"));
    deck.push_back(Card(king, "King of Clubs"));
    deck.push_back(Card(ace, "Ace of Diamonds"));
    deck.push_back(Card(two, "Two of Diamonds"));
    deck.push_back(Card(three, "Three of Diamonds"));
    deck.push_back(Card(four, "Four of Diamonds"));
    deck.push_back(Card(five, "Five of Diamonds"));
    deck.push_back(Card(six, "Six of Diamonds"));
    deck.push_back(Card(seven, "Seven of Diamonds"));
    deck.push_back(Card(eight, "Eight of Diamonds"));
    deck.push_back(Card(nine, "Nine of Diamonds"));
    deck.push_back(Card(ten, "Ten of Diamonds"));
    deck.push_back(Card(jack, "Jack of Diamonds"));
    deck.push_back(Card(queen, "Queen of Diamonds"));
    deck.push_back(Card(king, "King of Diamonds"));

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