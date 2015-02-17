#pragma once

/*-----------------------------------------------------------*/

// Handles a player's score and bar
class Player
{
    private:
        float x, y;                  // Position of the bar's center
        unsigned int score;           // Number of points obtained

    public:
        constexpr static float v = 2.0;  // Scalar speed
        constexpr static float rx = 1.0; // Distance from center to left/right
        constexpr static float ry = 2.0; // Distance from center to up/down

        // Creates a bar with center on specified coordinates
        Player(float x, float y);

        // Moves the Player's bar upwards
        void moveUp();

        // Moves the Player's bar downwards
        void moveDown();

        // Gives 1 point to the Player
        void updateScore();

        // Returns the Player's "x" position
        float getX();

        // Returns the Player's "y" position
        float getY();

        // Returns the bar's "x" radius
        float getRx();

        // Returns the bar's "y" radius
        float getRy();

        // Returns the Player's "y" radius
        unsigned int getScore();
};
