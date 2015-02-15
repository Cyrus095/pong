#pragma once

#include "ball.hpp"
#include "player.hpp"

#define X_MAX 200  // Width of the field
#define Y_MAX 150  // Height of the field

/*-----------------------------------------------------------*/

// Handles the game's 'world', as well as updating all movement
class Field
{
    private:
        Ball *ball;
        Player *playerA, *playerB;

    public:
        constexpr static unsigned int end = 10; // Score to end game

        // Initializes the game, setting Ball and Players
        Field();

        // Update positions and scores; also checks collisions
        int update();

        /*
         * Checks whether a Player scored, attributing a point if so.
         * Returns true if any Player scored, and false otherwise.
         */
        bool checkIfScored();

        /*
         * Checks if Ball collided with walls or bars, changing its
         * speed if so.
         */
        void checkCollision();

        // Ends the game by freeing used memory
        void gameOver();

        // TESTING: Prints object coordinates and scores
        void printElements();
};
