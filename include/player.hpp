#pragma once

// Handles the player's bar
class Player
{
    private:
        double x, y;                  // Position of the bar's center
        unsigned int score;           // Number of points obtained

    public:
        constexpr static double v = 2.0;  // Scalar speed
        constexpr static double rx = 1.0; // Distance from center to left/right
        constexpr static double ry = 2.0; // Distance from center to up/down

        // Creates a bar with center on specified coordinates
        Player(double x, double y);

        // Changes the bar's position (vertical movement!)
        void move();

        // Gives 1 point to the Player
        void updateScore();

        // Returns the Player's "x" position
        double getX();

        // Returns the Player's "y" position
        double getY();

        // Returns the bar's "x" radius
        double getRx();

        // Returns the bar's "y" radius
        double getRy();

        // Returns the Player's "y" radius
        unsigned int getScore();
};
