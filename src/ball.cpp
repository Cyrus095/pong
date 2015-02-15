#include <cmath>    // M_PI, cos(), sin()
#include <cstdlib>  // rand()
#include "ball.hpp"

/*-----------------------------------------------------------*/

Ball::Ball(double x, double y, double angle)
{
    x = x;
    y = y;
    v = rand() % 50; // For now...
    angle = angle;
}

/*-----------------------------------------------------------*/

void Ball::move()
{
    x += v*cos(angle);
    y += v*sin(angle);
}

/*-----------------------------------------------------------*/

void Ball::collision()
{
    angle = M_PI - angle;
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
