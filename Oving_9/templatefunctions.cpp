#include "templatefunctions.h"

void testTemplateFunctions(){
    int a = 1;
    int b = 2;
    int c = maximum<int>(a, b);
    std::cout << c << std::endl;
    // c er nå 2.
    double d = 2.4;
    double e = 3.2;
    double f = maximum<double>(d,e);
    std::cout << f << std::endl;
    // f er nå 3.2
}
