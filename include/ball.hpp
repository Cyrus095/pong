#pragma once

#include "graphics.hpp"
#include "drawable.hpp"

/*-----------------------------------------------------------*/

// Handles the game's ball
class Ball : public Drawable
{
    private:
        static constexpr float RADIUS = 1.0f;
        float x, y;   // Position of the Ball's center on the xy axis
        float vx, vy; // Speed on the xy axis

    public:
        // Creates a Ball on the center of the field with specified speed
        Ball(float vx, float vy);

        // Changes Ball's position according to it's speed and angle
        void move();

        // Inverts the Ball's speed on the respective axis
        void switchVx();
        void switchVy();

        // Returns the Ball's position and speed
        float getX();
        float getY();
        float getVx();
        float getVy();

        // Sets the Ball's "x" and "y" position
        void setXY(float x, float y);

        // Returns the Ball's radius
        float getRadius();

        // Draws the Ball with OpenGL
        void draw();
};
