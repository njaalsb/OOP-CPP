#pragma once
#include "Card.h"

// BEGIN: 3a
class CardDeck {
    private:
    ;
    public:
    CardDeck();
    vector<Card> cards;
    void swap(int i, int j);
    void print();
    void shuffle();
    Card drawCard();
};
// END: 3a
