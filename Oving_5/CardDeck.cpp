#include "CardDeck.h"
#include <random>
// BEGIN: 3b
CardDeck::CardDeck()
{
    for(int i =0; i < 4; i++){
        for(int j = 2; j < 15; j++){
            Card c{static_cast<Suit>(i), static_cast<Rank>(j)};
            cards.emplace_back(static_cast<Suit>(i), static_cast<Rank>(j));
            cout << c.toString() << endl;
        }
    }    
};
// END: 3b

// BEGIN: 3c
void CardDeck::swap(int i, int j){
    CardDeck::cards;
    vector<Card> temp;
    temp.push_back(cards[i]);
    temp.push_back(cards[j]);
    cards[i] = temp[1];
    cards[j] = temp[0];
};
// END: 3c

// BEGIN: 3d
void CardDeck::print(){
    CardDeck::cards;
    for(int i = 0; i < 52; i++){
        cout << cards[i].toString() << endl;
    }
}
// END: 3d

// BEGIN: 3e
void CardDeck::shuffle(){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 51);
    for(int i = 0; i < 51; i++){
        int number1 = distribution(generator);
        int number2 = distribution(generator);
        CardDeck::cards;
        CardDeck::swap(number1,number2);
    }
}
// END: 3e

// BEGIN: 3f
Card CardDeck::drawCard(){
    CardDeck::cards;
    int last = cards.size() -1;
    Card drawn = cards[last];
    cards.pop_back();
    return drawn;
}
// END: 3f
