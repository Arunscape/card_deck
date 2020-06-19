use crate::card::{Card, Suit, Value};
use std::fmt;
use rand::thread_rng;
use rand::seq::SliceRandom;

#[derive(Debug)]
pub struct Deck {
    cards: Vec<Card>,
}

impl std::fmt::Display for Deck {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> std::fmt::Result {

        let mut output = String::new();
        for c in &self.cards {
            output += &format!("{}\n", c);
        }
        write!(f, "{}", output)
    }
}

impl Deck {
    pub fn new() -> Self {
        let mut cards = Vec::new();

        let suits = vec![Suit::Spade, Suit::Diamond, Suit::Heart, Suit::Club];

        let values = vec![
            Value::Ace,
            Value::Two,
            Value::Three,
            Value::Four,
            Value::Five,
            Value::Six,
            Value::Seven,
            Value::Eight,
            Value::Nine,
            Value::Ten,
            Value::Jack,
            Value::Queen,
            Value::King,
        ];

        for s in suits {
            for v in &values {
                cards.push(Card::new(s, *v));
            }
        }

        Deck { cards }
    }

    pub fn shuffle(&mut self){
        self.cards.shuffle(&mut thread_rng())
    }

    pub fn deal(&mut self, hand_size: usize)  {
        self.cards = self.cards.split_off(hand_size)
    }

    pub fn size(&self) -> usize{
        self.cards.len()
    }
}
