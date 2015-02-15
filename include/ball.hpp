#pragma once

/*-----------------------------------------------------------*/

// Handles the game's ball
class Ball
{
    private:
        double x, y;       // Position of the Ball's center on the xy axis
        double vx, vy;     // Speed on the xy axis

    public:
        constexpr static double radius = 1.0;

        // Creates a Ball on the center of the field with specified speed
        Ball(double vx, double vy);

        // Changes Ball's position according to it's speed and angle
        void move();

        // Inverts the Ball's speed on the x axis
        void switchVx();

        // Inverts the Ball's speed on the y axis
        void switchVy();

        // Returns the Ball's "x" position
        double getX();

        // Returns the Ball's "y" position
        double getY();

        // Returns the Ball's radius
        double getRadius();

        // Draws the Ball with openGL
        void draw();
};
