#pragma once

#include "graphics.hpp"
#include "matrix.hpp"

#define X_MAX 200  // Width of the field
#define Y_MAX 150  // Height of the field

/*-----------------------------------------------------------*/

class Drawable
{
    private:
        GLfloat vertices[8];
        
        // OpenGL parameters
        GLuint vao, vbo, ebo; // Objects for drawing
        GLuint vertexShader, fragmentShader;
        GLuint shaderProgram;
        GLint posAttrib;
        GLint uniModel, uniView, uniProj;

    public:
        // Creates a drawable object
        void begin(GLfloat _vertices[], GLenum usage);

        // Clears data used for drawing
        ~Drawable();

        // Returns uniModel id
        GLint getUniModel();

        // Part of the process of drawing
        void draw();
};
