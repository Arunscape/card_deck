use std::fmt;

#[derive(Debug, Copy, Clone)]
pub enum Suit {
    Spade,
    Diamond,
    Heart,
    Club,
}

#[derive(Debug, Copy, Clone)]
pub enum Value {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
}

#[derive(Debug)]
pub struct Card {
    suit: Suit,
    value: Value,
}

impl std::fmt::Display for Card {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> std::fmt::Result {
        let suit = match self.suit {
            Suit::Spade => "♠️",
            Suit::Diamond => "♦️",
            Suit::Heart => "♥️",
            Suit::Club => "♣️",
        };

        let value = match self.value {
            Value::Ace => "A",
            Value::Two => "2",
            Value::Three => "3",
            Value::Four => "4",
            Value::Five => "5",
            Value::Six => "6",
            Value::Seven => "7",
            Value::Eight => "8",
            Value::Nine => "9",
            Value::Ten => "10",
            Value::Jack => "J",
            Value::Queen => "Q",
            Value::King => "K",
        };

        write!(f, "{}{}", suit, value)
    }
}

impl Card {
    pub fn new(suit: Suit, value: Value) -> Self {
        Self { suit, value }
    }
}
