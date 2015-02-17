#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include "SFML/Window.hpp"

/*-----------------------------------------------------------*/

// Handles the game window and graphics
class Graphics
{
    private:
        // Window attributes
        sf::Window *window;
        bool running;

        // OpenGL attributes
        GLuint vertexShader;
        GLuint fragmentShader;
        GLuint shaderProgram;
        GLint posAttrib;

        GLuint vao, vbo;

        // Vertex shader
        const GLchar* vertexSource =
        "#version 150 core\n"
        "in vec2 position;"
        "void main()"
        "{"
            "gl_Position = vec4(position, 0.0, 1.0);"
        "}";

        // Fragment shader
        const GLchar* fragmentSource =
        "#version 150 core\n"
        "out vec4 outColor;"
        "void main()"
        "{"
            "outColor = vec4(1.0, 1.0, 1.0, 1.0);"
        "}";

    public:
        // Initializes the game window
        Graphics();

        // Frees data used by the object
        ~Graphics();

        // Important function, needs beter description
        void run();

        // Checks user input and reacts accordingly
        void checkInput(sf::Event windowEvent);

        /*
         * Compiles the vertex shader. Leaves program
         * if an error is detected during the process.
         */
        void compileVertexShader();

        /*
         * Compiles the fragment shader. Leaves program
         * if an error is detected during the process.
         */
        void compileFragmentShader();

        // Checks if ashader was correctly compiled
        GLuint checkShader(GLuint shader);

        // Combine vertex and fragment shaders into a program
        void combineShaders();

        // Makes some kind of link
        void linkAttributes();
};
