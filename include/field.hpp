#pragma once

#include "ball.hpp"
#include "player.hpp"

#define X_MAX 200  // Width of the field
#define Y_MAX 150  // Height of the field

/*-----------------------------------------------------------*/

// Handles the game's 'world', as well as updating all movement
class Field
{
    private:
        Ball *ball;
        Player *playerA, *playerB;
        constexpr static unsigned int end = 10; // Score to end game
        constexpr static float midRectX = 0.5;  // X radius of the rectangles on middle of the screen
        constexpr static float midRectY = 3;    // Y radius of the rectangles on middle of the screen

        // OpenGL parameters
        GLuint vao, vbo, ebo; // Objects for drawing
        GLuint vertexShader, fragmentShader;
        GLuint shaderProgram;
        GLint posAttrib;
        GLint uniModel, uniView, uniProj;

    public:
        // Initializes the game, setting Ball and Players
        Field();

        // Update positions and scores; also checks collisions
        int update();

        // Moves Player A's bar up
        void moveAUp();

        // Moves Player A's bar down
        void moveADown();

        // Moves Player B's bar up
        void moveBUp();

        // Moves Player B's bar down
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

        // Ends the game by freeing used memory
        void gameOver();

        // Draws rectangle line dividing middle of the screen
        void draw();

        // TESTING: Prints object coordinates and scores
        void printElements();
};
