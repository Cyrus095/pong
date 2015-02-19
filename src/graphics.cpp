#include <iostream>     // cout
#include "graphics.hpp"

static GLuint checkShader(GLuint shader);

const GLchar* vertexSource =
    "#version 150 core\n"
    "in vec2 position;"
    "uniform mat4 model;"
    "uniform mat4 view;"
    "uniform mat4 proj;"
    "void main()"
    "{"
        "gl_Position = proj * view * model * vec4(position, 0.0, 1.0);"
    "}";

const GLchar* fragmentSource =
    "#version 150 core\n"
    "out vec4 outColor;"
    "void main()"
    "{"
        "outColor = vec4(1.0, 1.0, 1.0, 1.0);"
    "}";

/*-----------------------------------------------------------*/

GLuint createVao()
{
    GLuint vao;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}

/*-----------------------------------------------------------*/

GLuint createVbo(GLfloat *vertices, long unsigned int size)
{
    GLuint vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    return vbo;
}

/*-----------------------------------------------------------*/

GLuint createEbo(GLuint *elements, long unsigned int size)
{
    GLuint ebo;

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, elements, GL_STATIC_DRAW);

    return ebo;
}

/*-----------------------------------------------------------*/

GLuint compileVertexShader()
{
    // Compile vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Check if shader compiled correctly
    if (checkShader(vertexShader) != GL_TRUE) {
        GLchar buffer[512];
        std::cout << "Error when compiling vertex shader!\n";
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(1);
    }

    return vertexShader;
}

/*-----------------------------------------------------------*/

GLuint compileFragmentShader()
{
    // Compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Check if shader compiled correctly
    if (checkShader(fragmentShader) != GL_TRUE) {
        GLchar buffer[512];
        std::cout << "Error when compiling fragment shader!\n";
        glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(1);
    }

    return fragmentShader;
}

/*-----------------------------------------------------------*/

GLuint combineShaders(GLuint vertexShader, GLuint fragmentShader)
{
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    return shaderProgram;
}

/*-----------------------------------------------------------*
 *
 * Checks if a shader was correctly compiled.
 *
 */
static GLuint checkShader(GLuint shader)
{
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    return status;
}
