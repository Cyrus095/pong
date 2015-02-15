#include "ball.hpp"
#include "field.hpp" // X_MAX, Y_MAX

/*-----------------------------------------------------------*/

Ball::Ball(double vx, double vy)
{
    this->x = X_MAX/2;
    this->y = Y_MAX/2;
    this->vx = vx;
    this->vy = vy;
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

double Ball::getX()
{
    return x;
}

/*-----------------------------------------------------------*/

double Ball::getY()
{
    return y;
}

/*-----------------------------------------------------------*/

double Ball::getRadius()
{
    return radius;
}

void Ball::draw()
{
    double vertices[] = {
        x - radius, y - radius,
        x - radius, y + radius,
        x + radius, y + radius,
        x + radius, y - radius
    };

}
