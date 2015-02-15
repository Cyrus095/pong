#include <cstdlib>    // rand()
#include "player.hpp"
#include "field.hpp"  // Y_MAX

/*-----------------------------------------------------------*/

Player::Player(double x, double y)
{
    this->x = x;
    this->y = y;
    score = 0;
}

/*-----------------------------------------------------------*/

void Player::moveUp()
{
    y += v;
}

/*-----------------------------------------------------------*/

void Player::moveDown()
{
    y -= v;
}

/*-----------------------------------------------------------*/

void Player::updateScore()
{
    score += 1;
}

/*-----------------------------------------------------------*/

double Player::getX()
{
    return x;
}

/*-----------------------------------------------------------*/

double Player::getY()
{
    return y;
}

/*-----------------------------------------------------------*/

double Player::getRx()
{
    return rx;
}

/*-----------------------------------------------------------*/

double Player::getRy()
{
    return ry;
}

/*-----------------------------------------------------------*/

unsigned int Player::getScore()
{
    return score;
}
