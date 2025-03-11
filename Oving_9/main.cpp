#include "Stopwatch.h"
#include "measurePerformance.h"
#include "optimizeVector.h"
#include "optimizationTask.h"
#include "templatefunctions.h"
#include "MyArray.h"



int main() {
    // Oppgave 1
    
    double printVal = measurePerformanceShared();
    
    std::cout << printVal << "S " << std::endl;
    
    double printVal2 = measurePerformanceUnique();
    
    std::cout << printVal2 << "S " << std::endl;
    
    double printVal3 = measurePerformanceStack();

    std::cout << printVal3 << "S " << std::endl;
    
    double printVal4 = measurePerformanceHeap();

    std::cout << printVal4 << "S " << std::endl;
    
    // Oppgave 2
    optimizeVector();

    // Oppgave 3
    optimizationTask();

    // Oppgave 4
    testTemplateFunctions();
    
    // Oppgave 5
    //testMyArray();
    return 0;
}