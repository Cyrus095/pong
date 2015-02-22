#include <cstdlib>    // srand()
#include <ctime>      // time()
#include "window.hpp"

int main(int argc, char **argv)
{
    Window *window;

    srand(time(NULL));

    window = new Window();
    window->run();
    delete window;

    return 0;
}
