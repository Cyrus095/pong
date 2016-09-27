#include "player.hpp"
#include "matrix.hpp"

/*-----------------------------------------------------------*/

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;
    score = 0;

    GLfloat vertices[] = {
        x - RX, y - RY,
        x - RX, y + RY,
        x + RX, y + RY,
        x + RX, y - RY
    };

    Drawable::begin(vertices, GL_STREAM_DRAW);
}

/*-----------------------------------------------------------*/

void Player::moveUp()
{
    if (y + RY < Y_MAX) y += V;
}

void Player::moveDown()
{
    if (y - RY > 0) y -= V;
}

/*-----------------------------------------------------------*/

unsigned int Player::getScore()
{
    return score;
}

void Player::updateScore()
{
    score += 1;
}

/*-----------------------------------------------------------*/

float Player::getX()
{
    return x;
}

float Player::getY()
{
    return y;
}

float Player::getRx()
{
    return RX;
}

float Player::getRy()
{
    return RY;
}

/*-----------------------------------------------------------*/

void Player::draw()
{
    Drawable::draw();

    glm::mat4 move;
    move = glm::translate(move, glm::vec3(0.0, y - Y_MAX/2, 0.0f));
    glUniformMatrix4fv(getUniModel(), 1, GL_FALSE, glm::value_ptr(move));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
