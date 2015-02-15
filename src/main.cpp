#include <cstdlib>   // srand()
#include <ctime>     // time()
#include "field.hpp"

int main(int argc, char **argv)
{
    Field field;

    srand(time(NULL));

    while (field.update() == 0) {
        field.printElements();
    }

    return 0;
}
