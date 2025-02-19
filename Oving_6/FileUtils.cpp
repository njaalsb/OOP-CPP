#include "FileUtils.h"
#include <fstream>
#include <filesystem>

void writeUserInputToFile(const std::string &path)
{
	// BEGIN: 1a
	std::filesystem::path fileName{path};

	std::ofstream outputStream{fileName};

	string temp = "hei";

	while(temp != "quit"){

		cout << "Skriv en melding til: " << fileName << endl;

		cin >> temp;
		if(temp == "quit"){
			break;
		}
		
		outputStream << temp << endl;

		cin.clear();
	}
	// END: 1a
}


void addLineNumbers(const std::string &filename)
{
	// BEGIN: 1b
	std::ifstream inputStream{filename};

	// genererer ny fil, med samme navn som filen vi leser fra og legger til strengen .linum
	std::filesystem::path outputFileName{filename + ".linum"};

	// Denne linjen setter outputstreamen til filen vi nettopp genererte 
	std::ofstream outputStream{outputFileName};

	// lager en string of å lagre linjene vi leser
	std::string nextLine;

	int lineCounter = 0;
	if(!inputStream) { 
		std::cout << "Could not open file" << std::endl;
	}
	else {
		while(std::getline(inputStream, nextLine)){
			cout << lineCounter++ << endl;
			
			outputStream << lineCounter << " " << nextLine << endl;
		}

	}
	// END: 1b
}