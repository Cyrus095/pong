#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include "SFML/Window.hpp"

/*-----------------------------------------------------------*/

// Handles the game window and graphics
class Graphics
{
    private:
        sf::Window *window;
        bool running;

        // Vertex shader
        const GLchar* vertexSource =
        "#version 150 core\n"
        "in vec2 position;"
        "in vec3 color;"
        "out vec3 Color;"
        "void main() {"
            " Color = color;"
            " gl_Position = vec4(position, 0.0, 1.0);"
        "}";

        // Fragment shader
        const GLchar* fragmentSource =
        "#version 150 core\n"
        "in vec3 Color;"
        "out vec4 outColor;"
        "void main() {"
            " outColor = vec4(Color, 1.0);"
        "}";

    public:
        // Initializes the game window
        Graphics();

        // Important function, needs beter description
        void run();

        // Checks user input and reacts accordingly
        void checkInput(sf::Event windowEvent);
};
