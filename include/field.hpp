#pragma once

#include "ball.hpp"
#include "player.hpp"

#define X_MAX 200
#define Y_MAX 150

/*-----------------------------------------------------------*/

// Handles the game's 'world', as well as updating all movement
class Field
{
    private:
        Player *playerA, *playerB;
        Ball *ball;

    public:
        constexpr static unsigned int end = 10; // Score to end game

        // Initializes the game, setting Ball and Players
        Field();

        // Update positions and scores; also checks collisions
        int update();

        // TESTING: Prints object coordinates and scores
        void printElements();

        bool checkIfScored();

        bool checkCollision();

        void gameOver();
};
