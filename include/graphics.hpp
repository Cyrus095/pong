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
 * Compiles a vertex shader. Leaves program
 * if an error is detected during the process.
 */
GLuint compileVertexShader();

/*
 * Compiles a fragment shader. Leaves program
 * if an error is detected during the process.
 */
GLuint compileFragmentShader();

// Combines vertex and fragment shaders, returning the created program
GLuint combineShaders(GLuint vertexShader, GLuint fragmentShader);
