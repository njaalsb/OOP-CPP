
#pragma once
#include "std_lib_facilities.h"

// BEGIN: 1b
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
// END: 1b

// BEGIN: 1d
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
// END: 1d

// BEGIN: 1e
void swapNumbers(int& num1, int& num2); 
// END: 1e

// BEGIN: 2a
struct Student {
    string name;
    string studyProgram;
    int age;
};
// END: 2a

// BEGIN: 2b
void printStudent(Student stud);
// END: 2b

// BEGIN: 2c
bool isInProgram(Student Roger, string program);
// END: 2c

// BEGIN: 3a
string randomizeString(int str_length, int ovre, int nedre);
// END: 3a

// BEGIN: 3c
string readInputToString(int lengde, int ovre, int nedre);
// END: 3c

// BEGIN: 3d
int countChar(string input_string, char tester);
// END: 3d
