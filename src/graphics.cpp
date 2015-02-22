#include <fstream>      // std::ifstream
#include <vector>
#include "graphics.hpp"

static GLuint      checkShader(GLuint shader);
static std::string readShaderSource(std::string sourceName);

/*-----------------------------------------------------------*/

GLuint createVao()
{
    GLuint vao;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}

/*-----------------------------------------------------------*/

GLuint createVbo(GLfloat *vertices, long unsigned int size, GLenum usage)
{
    GLuint vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);

    return vbo;
}

/*-----------------------------------------------------------*/

GLuint createEbo(GLuint *elements, long unsigned int size, GLenum usage)
{
    GLuint ebo;

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, elements, usage);

    return ebo;
}

/*-----------------------------------------------------------*/

GLuint createShader(GLenum type, std::string sourceName)
{
    // Create shader
    GLuint shader = glCreateShader(type);

    // Read source
    const std::string shaderString = readShaderSource(sourceName);
    const GLchar *shaderSource = shaderString.c_str();

    // Compile shader
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    // Check if shader compiled correctly
    if (checkShader(shader) != GL_TRUE) {
        GLchar buffer[512];
        std::cout << "Error when compiling shader!\n";
        glGetShaderInfoLog(shader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(1);
    }

    return shader;
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

/*-----------------------------------------------------------*
 *
 * Reads and returns text from shader source file.
 *
 */
static std::string readShaderSource(std::string sourceName)
{
    std::ifstream file(sourceName.c_str());

    if (!file.is_open()) {
        std::cout << "Error! File '" << sourceName << "' not found!\n";
        exit(2);
    }

    // Find the file size
    file.seekg(0,std::ios::end);
    std::streampos length = file.tellg();
    file.seekg(0,std::ios::beg);

    // Read whole file into a vector:
    std::vector<char> buffer(length);
    file.read(&buffer[0],length);


    // Return the shader string
    return std::string(buffer.begin(), buffer.end());
}
