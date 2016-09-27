#pragma once

#include "graphics.hpp"
#include "drawable.hpp"

#define RX 1.0f  // Distance from center to left/right
#define RY 8.0f  // Distance from center to up/down

/*-----------------------------------------------------------*/

// Handles a player's score and bar
class Player : public Drawable
{
    private:
        constexpr static float V = 1.6;  // Scalar speed
        float x, y;                      // Position of the bar's center
        unsigned int score;              // Number of points obtained

    public:
        // Creates a bar with center on specified coordinates
        Player(float x, float y);

        // Moves the Player's bar
        void moveUp();
        void moveDown();

        // Gives 1 point to the Player
        void updateScore();

        // Returns the Player's score
        unsigned int getScore();

        // Returns the Player's position and radius
        float getX();
        float getY();
        float getRx();
        float getRy();

        // Draws the Player's bar with OpenGL
        void draw();
};
