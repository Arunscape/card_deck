#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <iterator>
#include "deck.h"

Deck::Deck()
{
  top = 0;
  for (int suit=Card::Suit::SPADES; suit<=Card::Suit::CLUBS; suit++){
    for (int val=Card::Value::ACE; val<=Card::Value::KING; val++, top++){
      deck[top] = Card(static_cast<Card::Suit>(suit), static_cast<Card::Value>(val));
    }
  }
  top--;
  assert (top=51);
}
  
Deck::~Deck()
{
}
  
void Deck::deal_hand(int sets, int cards)
{
  for (int i=0; i < sets; i++ ){
    for (int c = 0; c < cards; c++){
      cout << "Dealt ";
      deck[top].print();
      cout << " to Player " << i << endl;
      top--;
    }
  }
}
  
void Deck::print_deck()
{
  for (int i=0; i <= top; i++){
    deck[i].print();
  }
}

int myrandom (int i) { return std::rand()%i;}

void Deck::shuffle(int seed)
{
  srand(seed);
  auto end = std::begin(deck) + top;

  std::random_shuffle(std::begin(deck), end, myrandom);
}

void Deck::sort()
{
  std::sort(std::begin(deck), std::begin(deck) + top + 1);
}

