#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++){
		startValue += increment;
	}
	return startValue;
}

// BEGIN: 1d
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
	for (int i = 0; i < numTimes; i++){
		startValue += increment;
	}
}
// END: 1d

// BEGIN: 1e
void swapNumbers(int& num1, int& num2){
	int z;
	z = num1;
	num1 = num2;
	num2 = z;
}
// END: 1e

// BEGIN: 2b
void printStudent(Student stud) {
	cout << "Navn: " << setw(5) << stud.name << endl;
	cout << "Studieprogram: " << setw(5) << stud.studyProgram << endl;
	cout << "Alder: " << setw(5) << stud.age << endl;
}
// END: 2b

// BEGIN: 2c
bool isInProgram(Student Roger, string program){
		if (Roger.studyProgram == program){
			return true;
		}
		else {
			return false;
		}
}
// END: 2c


// BEGIN: 3a
string randomizeString(int str_length, int ovre, int nedre){
	string random_string;
	char rand_char;
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distribution(nedre, ovre);
	for(int i = 0; i < str_length; i++){
		int number = distribution(generator);
		rand_char = 'a' + number;
		random_string += rand_char;
	}
	return random_string;  
}
// END: 3a

// BEGIN: 3c
string readInputToString(int lengde, int ovre, int nedre){
	string output_string;
	cout << "Skriv inn " << lengde << "Bokstaver\r\n";
	for(int i = 0; i < lengde; i++){
		char karakter;
		cin >> karakter;
		karakter = tolower(karakter);
		if(karakter + 0 < nedre + 'a'){
			i--;
			cout << "Du skrev inn en karakter utenfor grensene" << endl;
		} else if(karakter + 1 > ovre +'a'){
			i--;
			cout << "Du skrev inn en karakter utenfor grensene" << endl;
		}
		else {
			output_string += karakter; //tolower(karakter);
		}
	}
	return output_string;
}
// END: 3c

// BEGIN: 3d
int countChar(string input_string, char tester){
	//input_string = tolower(input_string);
	tester = tolower(tester);
	int count = 0;
	for(int i = 0; i < input_string.size(); i++){
		if(input_string[i] == tester){
			count++;
		}
	}
	return count;
}
// END: 3d
