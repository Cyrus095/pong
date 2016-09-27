#pragma once

#include "ball.hpp"
#include "player.hpp"
#include "drawable.hpp"

/*-----------------------------------------------------------*/

// Handles the game's 'world', as well as updating all movement
class Field : public Drawable
{
    private:
        static constexpr unsigned int END_SCORE = 10; // Score to end game
        static constexpr float MID_RECT_X = 0.5f;
        static constexpr float MID_RECT_Y = 3.0f;

        Ball *ball;
        Player *playerA, *playerB;

    public:
        // Initializes the game, setting Ball and Players
        Field();

        // Clears Ball, Players and objects used for drawing
        ~Field();

        // Update positions and scores; also checks collisions
        int update();

        // Moves Player's bar
        void moveAUp();
        void moveADown();
        void moveBUp();
        void moveBDown();

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

        // Draws all objects that belong to the Field
        void draw();

        // TESTING: Prints object coordinates and scores
        void printElements();
};
