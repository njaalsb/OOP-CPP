#include <iostream>
#include "DynamicMemory.h"
#include "Matrix.h"
#include "Dummy.h"

int main() {
	int rows = 4;
	int columns = 5;
	Matrix m(rows);
	int* arr;
	int meny;
	std::cout << "inne i main" << std::endl;
	std::cin >> meny;
	switch(meny){
		case 1:
		std::cout << "inne i Case 1" << std::endl;
		fillInFibonacciNumbers(arr, 10);
		for(int i = 0; i < 10; i++){
			std::cout << arr[i] << std::endl;
		} break;
		case 2:
		std::cout << "inne i Case 2" << std::endl;
		printArray(arr, 10);
		break;
		case 3: 
		createFibonacci();
		break;
		case 4:
			std::cout << m;
		break;
		case 5:
			dummyTest();
		default:
			;
		break;
	}
	return 0;
}