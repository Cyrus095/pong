#pragma once

#include "graphics.hpp"

/*-----------------------------------------------------------*/

// Handles a player's score and bar
class Player
{
    private:
        float x, y;                      // Position of the bar's center
        unsigned int score;              // Number of points obtained
        constexpr static float v = 1.6;  // Scalar speed
        constexpr static float rx = 1.0; // Distance from center to left/right
        constexpr static float ry = 8.0; // Distance from center to up/down

        // OpenGL parameters
        GLuint vao, vbo, ebo;                // Objects for drawing
        GLuint vertexShader, fragmentShader;
        GLuint shaderProgram;
        GLint posAttrib;
        GLint uniModel, uniView, uniProj;

    public:
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

        // Draws the Player's bar with OpenGL
        void draw();
};
