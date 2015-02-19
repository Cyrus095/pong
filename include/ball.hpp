#pragma once

#include "graphics.hpp"

/*-----------------------------------------------------------*/

// Handles the game's ball
class Ball
{
    private:
        float x, y;   // Position of the Ball's center on the xy axis
        float vx, vy; // Speed on the xy axis
        constexpr static float radius = 1.0;

        // OpenGL parameters
        GLuint vao, vbo, ebo; // Objects for drawing
        GLuint vertexShader, fragmentShader;
        GLuint shaderProgram;
        GLint posAttrib;
        GLint uniModel, uniView, uniProj;

    public:
        // Creates a Ball on the center of the field with specified speed
        Ball(float vx, float vy);

        // Clears objects used for drawing
        ~Ball();

        // Changes Ball's position according to it's speed and angle
        void move();

        // Inverts the Ball's speed on the x axis
        void switchVx();

        // Inverts the Ball's speed on the y axis
        void switchVy();

        // Returns the Ball's "x" position
        float getX();

        // Returns the Ball's "y" position
        float getY();

        // Sets the Ball's "x" and "y" position
        void setXY(float x, float y);

        // Returns the Ball's radius
        float getRadius();

        // Draws the Ball with OpenGL
        void draw();
};
