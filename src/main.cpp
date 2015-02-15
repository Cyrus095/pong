#include <cstdlib>   // srand()
#include <ctime>     // time()
#include "field.hpp"

int main(int argc, char **argv)
{
    Field field;

    srand(time(NULL)); // Not used anywhere for now...

    while (field.update() == 0)
        field.printElements();

    return 0;
}
