package main

import "fmt"

type deck []string

func (d deck) print() {
	for i, c := range d {
		fmt.Println(i, c)
	}
}

func newDeck() deck {
	suits := []string{"♠️", "♦️", "♥️", "♣️"}
	vals := []string{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}
	cards := deck{}

	for _, suit := range suits {
		for _, val := range vals {
			cards = append(cards, suit+" "+val)
		}
	}

	return cards
}

func deal(d deck, handSize int) (deck, deck) {
	return d[:handSize], d[handSize:]
}
