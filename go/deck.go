package main

import "fmt"

type deck []string

func (d deck) print() {
	for i, c := range d {
		fmt.Println(i, c)
	}
}

func newDeck() deck {
	suits := []string{"Spades", "Diamonds", "Hearts", "Clubs"}
	vals := []string{"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"}
	cards := deck{}

	for i, suit := range suits {
		for j, val := range vals {
			cards = append(cards, suit+" of "+val)
		}
	}

	return cards
}
