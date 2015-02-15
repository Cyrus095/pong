#pragma once

#include "ball.hpp"
#include "player.hpp"

// Handles the game's ball
class Field
{
    private:
        Player *playerA, *playerB;
        Ball *ball;

    public:
        constexpr static double sizeX = 200;
        constexpr static double sizeY = 150;
        constexpr static unsigned int end = 10; // Score to end game

        // Initializes the game, setting Ball and Players
        Field();

        // Update positions and scores; also checks collisions
        void update();

        // TESTING: Prints coordinates of the Ball and Players
        void printPositions();
};
