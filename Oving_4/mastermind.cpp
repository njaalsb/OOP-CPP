#include "mastermind.h"

// BEGIN: 4
//Oppgave 4a til 4j løses her forutenom 4e og 4f
void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    string code;
    string guess;
    code = randomizeString(size,0,letters-1);
    guess = readInputToString(size, 0, letters-1);
    int result = checkCharactersAndPosition(code, guess);
    while(result > size){
        guess = readInputToString(size, 0, letters-1);
        result = checkCharactersAndPosition(code, guess);
    }
}
// END: 4

// BEGIN: 4e
int checkCharactersAndPosition(string code, string guess) {
    int total = 0;
    for(int i = 0; i < code.size(); i++){
        if(code[i] == guess[i]){
            total++;
        }
    }
    return total;
}
// END: 4e

// BEGIN: 4f
int checkCharacters(string code, string guess) {
    int counter = 0;
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(guess[i] == code[j]){
                counter++;
            }
        }
    }
    return counter;
}
// END: 4f
