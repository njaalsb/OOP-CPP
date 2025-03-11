#include "Stopwatch.h"
#include <vector>
#include <iostream>

// Utdelt program til oppgave 3

// BEGIN 3b
double sumMatrix(std::vector<std::vector<double>> matrix){ 
    double sum = 0.0;
    for (int row = 0; row < matrix.size(); row++){
        // Bruker 'operator[]' for raskere tilgang
        const std::vector<double>& rowVector = matrix[row];
        for (size_t col = 0; col < rowVector.size(); col++){
            //double value = matrix.at(row).at(col);
            sum += rowVector[col];            
        }
    }
    return sum;
}

void setDiagonalValue(std::vector<std::vector<double>>& matrix, double newValue){
    // bytter ut den dobble for-løkken mot en enkelt forløkke, siden vi kun ønsker å sette verdier på diagonalen,
    // kan vi gjøre dette ved en funksjon som ligner litt på den fra oppgave 2b i øving 7.
    for(size_t i = 0; i < matrix.size(); i++){
        matrix[i][i] = newValue;
    }
}

void optimizationTask(){
    Stopwatch stopwatch;
    stopwatch.start();
    const uint16_t matrixSize = 10000;

    // Oppretter nullmatrisen direkte ved bruk av konstruktøren som tar inn antall og verdi.
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize, 0.0));

    // Setter alle elementer på diagonalen til 0.41
    setDiagonalValue(matrix, 0.41);
    
    // Summerer alle elementene i matrisen
    double total = sumMatrix(matrix);

    double coolerNumber = total + 2;
    std::cout << "TDT" << coolerNumber << std::endl;

    std::cout << "Time taken: " << stopwatch.stop() << "seconds" << std::endl;
}
// END 3b