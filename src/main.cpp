#include <cstdlib>    // srand()
#include <ctime>      // time()
#include "game.hpp"

int main(int argc, char **argv)
{
    srand(time(NULL));

    Game *game = new Game();
    game->run();
    delete game;

    return 0;
}
