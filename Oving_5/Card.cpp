#include "Card.h"

// BEGIN: 1c
string suitToString(Suit sort){
    return SuitToStringMap.at(sort);
}
// END: 1c

// BEGIN: 1d
string rankToString(Rank nummer){
    return rankToStringMap.at(nummer);
}
// END: 1d

// BEGIN: 2b
Card::Card(Suit suit, Rank rank): s{suit}, r{rank}
{}
// END: 2b

// BEGIN: 2c
Suit Card::getSuit(){
    return s;
}
// END: 2c

// BEGIN: 2d
Rank Card::getRank(){
    return r;
}
// END: 2d

// BEGIN: 2e
string Card::toString(){
    string return_value = rankToString(r) + " of " + suitToString(s);
    return return_value;
}
// END: 2e