#include "ball.hpp"

/*-----------------------------------------------------------*/

Ball::Ball(float vx, float vy)
{
    x = X_MAX/2;
    y = Y_MAX/2;
    this->vx = vx;
    this->vy = vy;

    GLfloat vertices[] = {
        x - RADIUS, y - RADIUS,
        x - RADIUS, y + RADIUS,
        x + RADIUS, y + RADIUS,
        x + RADIUS, y - RADIUS
    };

    Drawable::begin(vertices, GL_STREAM_DRAW);
}

/*-----------------------------------------------------------*/

void Ball::move()
{
    x += vx;
    y += vy;
}

void Ball::switchVx()
{
    vx *= -1;
}

void Ball::switchVy()
{
    vy *= -1;
}

/*-----------------------------------------------------------*/

float Ball::getX()
{
    return x;
}

float Ball::getY()
{
    return y;
}

float Ball::getVx()
{
    return vx;
}

float Ball::getVy()
{
    return vy;
}

void Ball::setXY(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Ball::getRadius()
{
    return RADIUS;
}

/*-----------------------------------------------------------*/

void Ball::draw()
{
    Drawable::draw();

    glm::mat4 move;
    move = glm::translate(move, glm::vec3(x - X_MAX/2, y - Y_MAX/2, 0.0f));
    glUniformMatrix4fv(getUniModel(), 1, GL_FALSE, glm::value_ptr(move));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
