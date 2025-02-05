#include "test.h"

void testCallByValue()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
}

void testCallByReference()
{
	// BEGIN: 1d
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = v0;
	incrementByValueNumTimesRef(result, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
	// END: 1d

}


void testString(){
	// 3b OG 3e gjøres inne i her
	// BEGIN: 3e
	double snitt = 0;
	string grades;
	grades = randomizeString(8,6,0);
	cout << "Grades-string: " << grades << endl; 
	vector <int> gradeVec;
	int A =  countChar(grades, 'a')*6;
	gradeVec.push_back(A);
	int B = countChar(grades, 'b')*5;
	gradeVec.push_back(B);
	int C = countChar(grades, 'c')*4;
	gradeVec.push_back(C);
	int D = countChar(grades, 'd')*3;
	gradeVec.push_back(D);
	int E = countChar(grades, 'e')*2;
	gradeVec.push_back(E);
	int F = countChar(grades, 'f')*1;
	gradeVec.push_back(F);
	for(int i = 0; i < gradeVec.size(); i++){
		snitt += gradeVec[i];
	}
	snitt = snitt/gradeVec.size();
	cout << "snittet er:" << snitt << endl;
	// END: 3e
}