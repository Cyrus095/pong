#pragma once

#define GLEW_STATIC
#include "GL/glew.h"

/*-----------------------------------------------------------*/

// Vertex shader
extern const GLchar* vertexSource;

// Fragment shader
extern const GLchar* fragmentSource;

/*-----------------------------------------------------------*/

// Create and return a Vertex Array Object
GLuint createVao();

// Reuturns a Vertex Buffer Object and copies the vertex data to it
GLuint createVbo(GLfloat vertices[], long unsigned int size);

// Returns an Element Buffer Object and copies the element data to it
GLuint createEbo(GLuint elements[], long unsigned int size);

/*
 * Compiles the vertex shader. Leaves program
 * if an error is detected during the process.
 */
GLuint compileVertexShader();

/*
 * Compiles the fragment shader. Leaves program
 * if an error is detected during the process.
 */
GLuint compileFragmentShader();

// Combine vertex and fragment shaders into a program
GLuint combineShaders(GLuint vertexShader, GLuint fragmentShader);
