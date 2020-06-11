package main

import "fmt"

func main() {
	cards := newDeck()
	cards.print()

	hand, remainingDeck := deal(cards, 5)
	hand.print()

	remainingDeck.print()

	fmt.Println(cards.toString())
	cards.saveToFile("tmp")

	fmt.Println(deckFromFile("tmp"))

	cards.shuffle()
	fmt.Println(cards)
}

func newCard() string {
	return "Ace of Spades"
}
