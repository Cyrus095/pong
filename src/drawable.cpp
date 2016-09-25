#include "drawable.hpp"
#include <cstdio>

/*-----------------------------------------------------------*/

void Drawable::begin(GLfloat _vertices[], GLenum usage)
{
    for (int i = 0; i < 8; i++) {
        vertices[i] = _vertices[i];
    }

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    // Arrays and buffers
    vao = createVao();
    vbo = createVbo(vertices, sizeof(vertices), usage);
    ebo = createEbo(elements, sizeof(elements), usage);

    // Shaders
    vertexShader = createShader(GL_VERTEX_SHADER, "shader/object.vert");
    fragmentShader = createShader(GL_FRAGMENT_SHADER, "shader/object.frag");
    shaderProgram = combineShaders(vertexShader, fragmentShader);

    // Link vertex data and attributes
    posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);

    // Set up projection
    glm::mat4 view = glm::lookAt(
        glm::vec3(X_MAX/2, Y_MAX/2, 135.0f), // Camera position
        glm::vec3(X_MAX/2, Y_MAX/2, 0.0f),   // Center of the screen
        glm::vec3(0.0f, 1.0f, 0.0f)          // 'Up' direction of the camera
    );

    uniModel = glGetUniformLocation(shaderProgram, "model");

    uniView = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 300.0f);
    uniProj = glGetUniformLocation(shaderProgram, "proj");
    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

Drawable::~Drawable()
{
    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
}

/*-----------------------------------------------------------*/

GLint Drawable::getUniModel()
{
    return uniModel;
}

/*-----------------------------------------------------------*/

void Drawable::draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);
}
