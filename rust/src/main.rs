#![warn(clippy::all)]
mod card;
use card::{Card, Suit, Value};
mod deck;
use deck::Deck;

fn main() {
    println!("Hello, world!");

    let c = Card::new(Suit::Heart, Value::Ace);
    println!("{}", c);

    let mut d = Deck::new();
    println!("{}", d);
    
    println!("Shuffled");
    d.shuffle();

    println!("{}", d);


    let mut d = Deck::new();
    println!("{:?}, {}", d, d.size());

    d.deal(5);
    println!("{:?}, {}", d, d.size());
}
