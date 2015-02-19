#include "ball.hpp"
#include "field.hpp" // X_MAX, Y_MAX

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
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
