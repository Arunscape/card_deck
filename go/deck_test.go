package main

import (
	"os"
	"reflect"
	"testing"
)

func TestNewDeck(t *testing.T) {
	d := newDeck()

	deckLength := 52

	if len(d) != deckLength {
		t.Errorf("New deck length should be %v, not %v", deckLength, len(d))
	}
}

func TestDeckFromFile(t *testing.T) {
	os.Remove("_decktesting")

	deck := newDeck()
	deck.saveToFile("_decktesting")

	loadeddeck := deckFromFile("_decktesting")

	if !reflect.DeepEqual(deck, loadeddeck) {
		t.Error("Loaded deck is not the same as the original")
	}

	os.Remove("_decktesting")

}
