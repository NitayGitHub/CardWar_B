#include "card.hpp"
using namespace ariel;
using namespace std;

Card::Card(int value, string cardName): value(value), cardName(cardName){}

Card::Card(): value(0) {}

int Card::getValue(){
    return this->value;
}

string Card::toString(){
    return this->cardName;
}