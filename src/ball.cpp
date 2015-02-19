#include "ball.hpp"
#include "field.hpp" // X_MAX, Y_MAX
#include "matrix.hpp"

/*-----------------------------------------------------------*/

Ball::Ball(float vx, float vy)
{
    x = X_MAX/2;
    y = Y_MAX/2;
    this->vx = vx;
    this->vy = vy;

    GLfloat vertices[] = {
        x - radius, y - radius,
        x - radius, y + radius,
        x + radius, y + radius,
        x + radius, y - radius
    };

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    // Objects
    vao = createVao();
    vbo = createVbo(vertices, sizeof(vertices));
    ebo = createEbo(elements, sizeof(elements));

    // Shaders
    vertexShader = compileVertexShader();
    fragmentShader = compileFragmentShader();
    shaderProgram = combineShaders(vertexShader, fragmentShader);

    // Link vertex data and attributes
    posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);

    // Set up projection
    glm::mat4 view = glm::lookAt(
        glm::vec3(X_MAX/2, Y_MAX/2, 130.0f), // Camera position
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

/*-----------------------------------------------------------*/

Ball::~Ball()
{
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
}

/*-----------------------------------------------------------*/

void Ball::move()
{
    x += vx;
    y += vy;
}

/*-----------------------------------------------------------*/

void Ball::switchVx()
{
    vx *= -1;
}

/*-----------------------------------------------------------*/

void Ball::switchVy()
{
    vy *= -1;
}

/*-----------------------------------------------------------*/

float Ball::getX()
{
    return x;
}

/*-----------------------------------------------------------*/

float Ball::getY()
{
    return y;
}

/*-----------------------------------------------------------*/

void Ball::setXY(float x, float y)
{
    this->x = x;
    this->y = y;
}

/*-----------------------------------------------------------*/

float Ball::getRadius()
{
    return radius;
}

/*-----------------------------------------------------------*/

void Ball::draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);

    glm::mat4 move;
    move = glm::translate(move, glm::vec3(x - X_MAX/2, y - Y_MAX/2, 0.0f));
    glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(move));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
