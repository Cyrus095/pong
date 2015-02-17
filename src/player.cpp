#include <cstdlib>    // rand()
#include "player.hpp"
#include "field.hpp"  // Y_MAX

/*-----------------------------------------------------------*/

Player::Player(float x, float y)
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

float Player::getX()
{
    return x;
}

/*-----------------------------------------------------------*/

float Player::getY()
{
    return y;
}

/*-----------------------------------------------------------*/

float Player::getRx()
{
    return rx;
}

/*-----------------------------------------------------------*/

float Player::getRy()
{
    return ry;
}

/*-----------------------------------------------------------*/

unsigned int Player::getScore()
{
    return score;
}
