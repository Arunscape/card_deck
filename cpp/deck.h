// deck.h
//
// @brief A class that represents a deck of playing cards
//
// @details
// This class is responsible for shuffling and dealing a deck of cards. The deck
// should contain 52 cards 2 - 10, Jack,Queen, King, Ace of four suits, but no
// jokers.
//

#include "card.h"
#include <array>
#include <iostream>
#include <string>
using namespace std;

class Deck {
public:
  Deck();

  ~Deck();

  // prints N sets of M cards
  // The internal set of cards in the deck is not altered
  // two consecutive 'deals' should produce the same result.
  // The deck must be shuffled in order to produce a different 'deal'.
  void deal_hand(int sets, int cards);

  // Prints the entire deck to standard out.
  // Prints 4 rows of 13 cards each.
  void print_deck();

  // all 52 cards should be randomly permuted.
  void shuffle(int seed);

  //** sort function:
  //*** Sorts the deck from lowest to highest by suit then by card face value.
  //*** The suits are valued from highest to lowest: Spades, Hearts, Clubs,
  //Diamonds
  //*** The cards are valued from highest to lowest:
  //King,Queen,Jack,10,9,8,7,6,5,4,3,2,Ace
  void sort();

private:
  array<Card, 52> deck;

  int partition(int lo, int hi);
  void quicksort_deck(int lo, int hi);
};