package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"math/rand"
	"os"
	"time"
)

type deck []card

type card struct {
	suit  string
	value string
}

func (d deck) print() {
	for i, c := range d {
		fmt.Println(i, c)
	}
}

func (d deck) toString() string {
	return fmt.Sprint(d)
}

func (d deck) saveToFile(filename string) error {
	return ioutil.WriteFile(filename, []byte(d.toString()), 0666)
}

func deckFromFile(filename string) deck {
	byteslice, err := ioutil.ReadFile(filename)
	if err != nil {
		log.Println(err)
		os.Exit(1)
	}

	return deck()
}

func newDeck() deck {
	suits := []string{"♠️", "♦️", "♥️", "♣️"}
	vals := []string{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}
	cards := deck{}

	for _, suit := range suits {
		for _, val := range vals {
			cards = append(cards, suit+val)
		}
	}

	return cards
}

func (d deck) shuffle() {
	rand.Seed(time.Now().UnixNano())
	for i := len(d) - 1; i >= 1; i -= 1 {
		j := rand.Intn(i)
		d[j], d[i] = d[i], d[j]
	}
}

func deal(d deck, handSize int) (deck, deck) {
	return d[:handSize], d[handSize:]
}
