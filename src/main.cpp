#include <cstdlib>  // srand()
#include <ctime>    // time()
#include "field.hpp"

int main(int argc, char **argv)
{
    Field field;

    srand(time(NULL));

    for (int i = 0; i < 2000; i++) {
        field.printPositions();
        field.update();
    }
    return 0;
}
