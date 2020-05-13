// deck.h
//
// @brief A class that represents a deck of playing cards
//
// @details
// This class is responsible for shuffling and dealing a deck of cards. The deck should
// contain 52 cards 2 - 10, Jack,Queen, King, Ace of four suits, but no jokers.
//

#include <string>
#include <iostream>
#include "card.h"
using namespace std;

class Deck
{
public:

	Deck();

	~Deck();

	void deal_hand(int sets, int cards);

	void print_deck();

	void shuffle(int seed);

	void sort();

  private:
    Card deck[52];
    int top;
};