#include "Stopwatch.h"
#include "optimizeVector.h"
#include <vector>
#include <iostream>


// BEGIN 2a
void testVector(){
    std::vector<int> vec;
    //vec.resize(20);
    
    for (int i = 0; i < 19; i++)
    {
        vec.push_back(i);
        std::cout << "Størrelse: " << vec.size() << std::endl;
        std::cout << "Kapasitet: " << vec.capacity() << std::endl;
    }
}
// END 2a


void optimizeVector(){
    // BEGIN 2d
    Stopwatch s;
    uint16_t iterasjoner = 1000000;
    std::vector<int> vec_1;

    s.start();
    for (int i = 0; i < iterasjoner; i++)
    {
        vec_1.push_back(i);
    }
    double tid = s.stop()/static_cast<double>(iterasjoner);

    std::cout << "Oppgave 2d: " << tid << std::endl;
    // END 2d

    // BEGIN 2e
    int elements2e = 1000000;
    std::vector<int> vector2eReserve;
    Stopwatch watch2eReserve;
    watch2eReserve.start();
    vector2eReserve.reserve(elements2e);
    for (int i = 0; i < elements2e; i++){
        vector2eReserve.push_back(i);
    }
    std::string tidReserve = std::to_string(watch2eReserve.stop());
    std::cout << "Oppgave 2e: " + tidReserve << std::endl;


    std::vector<int> vector2eResize;
    Stopwatch watch2eResize;
    watch2eResize.start();
    vector2eResize.resize(elements2e);

    for (int i = 0; i < elements2e; i++){
        vector2eResize[i] = i;
    }

    std::string tidResize = std::to_string(watch2eResize.stop());
    std::cout << "Oppgave 2e: " + tidResize << std::endl;

    // END 2e  
}