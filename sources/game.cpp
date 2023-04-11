#include "player.hpp"
#include "game.hpp"
#include <stdexcept>
#include <cmath>
#include <stack>
using namespace std;
using namespace ariel;
const int rate = 100;
const int deckSize = 52;
const int midStack = 26;
const int midStackminus = 25;

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2), turn(0), deck(), gameStarted(false), drawCounter(0)
{
    if (!(this->player1.getState()))
    {
        this->player1.newStack();
    }
    if (!(this->player2.getState()))
    {
        this->player2.newStack();
    }
}

void Game::playTurn()
{
    if (!winner.empty())
    {
        throw string("Game has ended.");
    }
    if (&(this->player1) == &(this->player2))
    {
        throw string("Player can't play against itself.");
    }

    if (!(this->player1.getState()) && !(this->player2.getState()))
    {
        this->player1.newStack();
        this->player2.newStack();
        this->player1.setState(true);
        this->player2.setState(true);
        gameStarted = true;
        this->deck.shuffle();
    }
    if ((this->player1.getState() && !(this->player2.getState())) || (!(this->player1.getState()) && this->player2.getState()))
    {
        throw string("One of the players is in the middle of a game.");
    }
    if (this->gameStarted == false)
    {
        throw string("Two of the players are in the middle of other games.");
    }
    this->turn++;
    this->player1.decreaseStack();
    this->player2.decreaseStack();
    int player1CardIndx = midStackminus - this->player1.stacksize();
    int p2CardIndx = midStackminus + (midStack - this->player2.stacksize());
    Card player1Card = this->deck.getCard(player1CardIndx);
    Card p2Card = this->deck.getCard(p2CardIndx);
    int WinWeight = 2;

    // Game Logic

    // A draw
    if (player1Card.getValue() == p2Card.getValue())
    {
        string outcome = "";
        while (player1Card.getValue() == p2Card.getValue())
        {
            outcome += this->player1.getName() + " played " + player1Card.toString() + " and " + this->player2.getName() + " played " + p2Card.toString() + ". Draw. ";
            WinWeight += 2;
            this->drawCounter++;
            this->player1.decreaseStack();
            this->player2.decreaseStack();
            if (this->player1.stacksize() == 0 && this->player2.stacksize() == 0)
            {
                this->player1.addWonCards(WinWeight);
                this->player2.addWonCards(WinWeight);
                outcome += "No more cards.";
                this->turnOutcome.push(outcome);
                break;
            }
            WinWeight += 2;
            this->player1.decreaseStack();
            this->player2.decreaseStack();
            if (this->player1.stacksize() == 0 && this->player2.stacksize() == 0)
            {
                this->player1.addWonCards(WinWeight);
                this->player2.addWonCards(WinWeight);
                this->turnOutcome.push(outcome);
                outcome += "No more cards.";
                break;
            }
            player1CardIndx = midStackminus - this->player1.stacksize();
            p2CardIndx = midStackminus + (midStack - this->player2.stacksize());
            player1Card = this->deck.getCard(player1CardIndx);
            p2Card = this->deck.getCard(p2CardIndx);
            if (player1Card.getValue() == p2Card.getValue())
            {
                continue;
            }
            else
            {
                int whoWon = whoWonTurn(player1Card.getValue(), p2Card.getValue());
                if (whoWon == 1)
                {
                    this->player1.addWonCards(WinWeight);
                    outcome += this->player1.getName() + " played " + player1Card.toString() + " and " + this->player2.getName() + " played " + p2Card.toString() + ". " + this->player1.getName() + " won.";
                    this->turnOutcome.push(outcome);
                }
                else if (whoWon == 2)
                {
                    this->player2.addWonCards(WinWeight);
                    outcome += this->player1.getName() + " played " + player1Card.toString() + " and " + this->player2.getName() + " played " + p2Card.toString() + ". " + this->player2.getName() + " won.";
                    this->turnOutcome.push(outcome);
                }
                else
                {
                    throw string("Error in whoWonTurn function");
                }
            }
        }
    }
    // No draw
    else
    {
        int whoWon = whoWonTurn(player1Card.getValue(), p2Card.getValue());
        if (whoWon == 1)
        {
            this->player1.addWonCards(WinWeight);
            this->turnOutcome.push(this->player1.getName() + " played " + player1Card.toString() +
                                   " and " + this->player2.getName() + " played " + p2Card.toString() + ". " + this->player1.getName() + " won.");
        }
        else if (whoWon == 2)
        {
            this->player2.addWonCards(WinWeight);
            this->turnOutcome.push(this->player1.getName() + " played " + player1Card.toString() +
                                   " and " + this->player2.getName() + " played " + p2Card.toString() + ". " + this->player2.getName() + " won.");
        }
        else
        {
            throw string("Error in whoWonTurn function");
        }
    }

    // Final turn
    if (this->player1.stacksize() == 0 && this->player2.stacksize() == 0)
    {
        this->player1.setState(false);
        this->player2.setState(false);
        if (this->player1.cardesTaken() > this->player2.cardesTaken())
        {
            this->winner = this->player1.getName();
        }
        else if (this->player1.cardesTaken() < this->player2.cardesTaken())
        {
            this->winner = this->player2.getName();
        }
        else
        {
            this->winner = "Tie";
        }
        gameStarted = false;
    }
}
void Game::playAll()
{
    do
    {
        this->playTurn();
    } while (this->player1.stacksize() != 0);
}
void Game::printLastTurn()
{

    if (this->turn == 0)
    {
        throw string("No turns were played yet");
    }
    else
    {
        cout << this->turnOutcome.top() << endl;
    }
}
void Game::printWiner()
{

    if (this->winner.empty())
    {
        cout << "No winner was announced yet" << endl;
    }
    else if (this->winner == "Tie")
    {
        cout << "No winner. It's a tie" << endl;
    }
    else
    {
        cout << this->winner << " won the game." << endl;
    }
}
void Game::printLog()
{
    if (this->turn == 0)
    {
        throw string("No turns were played yet");
    }
    else
    {
        stack<string> temp;
        for (int i = 0; i < this->turn; i++)
        {
            temp.push(this->turnOutcome.top());
            this->turnOutcome.pop();
        }
        for (int i = 0; i < this->turn; i++)
        {
            cout << temp.top() << endl;
            this->turnOutcome.push(temp.top());
            temp.pop();
        }
    }
}
void Game::printStats()
{
    cout << "    <Game Stats>" << endl;
    cout << "    " << this->player1.getName() << " won " << this->player1.cardesTaken() << " cards with a win rate of " << round(((float)(this->player1.cardesTaken()) / deckSize) * rate) << "%." << endl;
    cout << "    " << this->player2.getName() << " won " << this->player2.cardesTaken() << " cards with a win rate of " << round(((float)(this->player2.cardesTaken()) / deckSize) * rate) << "%." << endl;
    cout << "    Number of draws: " << this->drawCounter << ". Draw rate: " << round(((float)(this->drawCounter) / (float)this->turn) * rate) << "%." << endl;
    cout << "    Number of turns: " << this->turn << "." << endl;
};
int Game::whoWonTurn(int p1Val, int p2Val)
{

    if (p1Val == 1 && p2Val == 2)
    {
        return 2;
    }
    else if (p1Val == 2 && p2Val == 1)
    {
        return 1;
    }
    else if (p1Val == 1)
    {
        return 1;
    }
    else if (p2Val == 1)
    {
        return 2;
    }
    else if (p1Val > p2Val)
    {
        return 1;
    }
    else
    {
        return 2;
    }

    return 0;
}