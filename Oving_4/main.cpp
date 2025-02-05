
#include "std_lib_facilities.h"
#include "test.h"
#include "mastermind.h"

int meny_valg;

int main()
{	
	string printstring;
	Student Njaal;
	Student Roger;
	bool bool_flag;  
	int var1 = 1;
	int var2 = 2;
	cout << "Velg funksjon som skal testes..." << endl;
	cin >> meny_valg;
	switch(meny_valg){
		case(0):
			testCallByValue();
			break;
		case(1):
			testCallByReference();
			break;
		case(2):
			cout << "Var1  " << var1 << "Var2  " << var2 << endl;
			swapNumbers(var1,var2);
			cout << "swapped: Var1  " << var1 << "Var2  " << var2 << endl;
			break;
		case(3):
			Njaal.name = "Njaal";
			Njaal.studyProgram = "BIELSYS";
			Njaal.age = 22;
			printStudent(Njaal);
			break;
		case(4):
			Roger.studyProgram = "maskin";
			bool_flag = isInProgram(Roger, "maskin");
			cout << bool_flag << endl;
			break;
		case(5):
			printstring = randomizeString(10, 10, 0);
			cout << printstring << endl;
			break;
		case(6):
			testString();
			break;
		case(7):
			printstring = readInputToString(6,6,0);
			cout << printstring << endl;
		case(8):
			playMastermind();
		default:
		break;
	}
	
	// Her kan du teste koden og funksjonene dine, 
	// Ingenting som skrives her blir automatisk rettet, du tester her for din egen del

	return 0;
}
