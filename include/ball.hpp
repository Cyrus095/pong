#pragma once

// Handles the game's ball
class Ball
{
    private:
        double x, y;       // Position of the Ball's center
        double v;          // Scalar speed
        double angle;      // Angle with the xy axis, in radians

    public:
        constexpr static double radius = 1.0;

        // Creates a Ball with the specified initial angle
        Ball(double x, double y, double angle);

        // Changes Ball's position according to it's speed and angle
        void move();

        // Changes the Ball's angle to its supplementary value
        void collision();

        // Returns the Ball's "x" position
        double getX();

        // Returns the Ball's "y" position
        double getY();

        // Returns the Ball's radius
        double getRadius();
};
