#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <iterator>
#include "deck.h"

Deck::Deck()
{
  int index=0;
  for (int suit=Card::Suit::DIAMONDS; suit<=Card::Suit::SPADES; suit++){
    for (int val=Card::Value::ACE; val<=Card::Value::KING; val++, index++){
      deck[index] = Card(static_cast<Card::Suit>(suit), static_cast<Card::Value>(val));
    }
  }
}
  
Deck::~Deck()
{
}


void Deck::deal_hand(int sets, int cards)
{
  int top = 51;

  for (int i=0; i < sets; i++ ){
    for (int c = 0; c < cards; c++, top--){
      deck[top].print();
    }
    cout << endl;
  }
}


void Deck::print_deck()
{
  for (int i=0; i < deck.size(); i++){
    if (i % 13 ==0){
      cout << endl;
    }
    deck[i].print();
  }
}

int myrandom (int i) { return rand()%i;}

void Deck::shuffle(int seed)
{
  srand(seed);
  random_shuffle(deck.begin(), deck.end(), myrandom);
}

int Deck::partition(int lo, int hi){
  Card pivot = deck[hi];
  int partition_index = lo;

  for (int i=lo; i<hi; i++){
    if (deck[i] <= pivot ){
      swap(deck[i], deck[partition_index]);
      partition_index++;
    }
  }
  swap(deck[partition_index], deck[hi]);
  return partition_index;
}

void Deck::quicksort_deck(int lo, int hi) {
  
  if (lo >= hi) return;
  
  int partition_index = partition(lo, hi);
  quicksort_deck(lo, partition_index-1);
  quicksort_deck(partition_index+1, hi);

}


void Deck::sort()
{
  quicksort_deck(0, deck.size()-1);
}
