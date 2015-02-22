#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include <iostream> // std::string, std::cout

/*-----------------------------------------------------------*/

// Vertex shader
extern const GLchar* vertexSource;

// Fragment shader
extern const GLchar* fragmentSource;

/*-----------------------------------------------------------*/

// Create and return a Vertex Array Object
GLuint createVao();

/*
 * Returns a Vertex Buffer Object and copies the vertex data to it.
 * Usage can be:
 *  GL_STATIC_DRAW:  Data will be uploaded once and drawn many times.
 *  GL_DYNAMIC_DRAW: Data will be changed from time to time, but drawn
 *                   many times more than that.
 *  GL_STREAM_DRAW:  Data will change almost every time it's drawn.
 */

GLuint createVbo(GLfloat vertices[], long unsigned int size, GLenum usage);

/*
 * Returns an Element Buffer Object and copies the element data to it.
 * Usage can be:
 *  GL_STATIC_DRAW:  Data will be uploaded once and drawn many times.
 *  GL_DYNAMIC_DRAW: Data will be changed from time to time, but drawn
 *                   many times more than that.
 *  GL_STREAM_DRAW:  Data will change almost every time it's drawn.
 */
GLuint createEbo(GLuint elements[], long unsigned int size, GLenum usage);

/*
 * Create and compile a shader of the specified type and with source
   contained in 'sourceName' file.
 * Leaves program if shader couldn't be compiled correctly.
 */
GLuint createShader(GLenum type, std::string sourceName);

// Combines a vertex and a fragment shader, returning the created program
GLuint combineShaders(GLuint vertexShader, GLuint fragmentShader);
