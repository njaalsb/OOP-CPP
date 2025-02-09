#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

int main()
{
	Rank r =  Rank::king;
	Suit s = Suit::clubs;
	string rank  =  rankToString(r);
	string suit = suitToString(s);
	cout << rank << setw(10) << suit << endl;

	Card c{s, r};
	/*
	cout << c.toString() << endl;
	*/
	CardDeck cd;
	/*
	int storrelse;
	storrelse = static_cast<int>(cd.cards.size());
	for(int i = 0; i < storrelse; i++){
		cout << "inneholder:" << i << endl;
	}*/

	string linespaces = "spacing\r\n\r\n\r\n\r\n";

	cout << linespaces << endl;

	cd.print();
	cd.shuffle();	
	cout << linespaces << endl;
	cd.print();
	return 0;
}