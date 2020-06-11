package main

import "testing"

func TestNewDeck(t *testing.T) {
	d := newDeck()

	deckLength := 52

	if len(d) != deckLength {
		t.Errorf("New deck length should be %d, not %d", deckLength, len(d))
	}
}
