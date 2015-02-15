#include <cstdlib>         // srand()
#include <ctime>           // time()
#include "graphics.hpp"

int main(int argc, char **argv)
{
    Graphics *graphics;

    srand(time(NULL));

    graphics = new Graphics();
    graphics->run();

    /*while (field.update() == 0) {
        field.printElements();
    }*/

    return 0;
}
