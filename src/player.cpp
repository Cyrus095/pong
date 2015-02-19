#include <cstdlib>    // rand()
#include "player.hpp"
#include "field.hpp"  // Y_MAX

/*-----------------------------------------------------------*/

Player::Player(float x, float y)
{
    this->x = x;
    this->y = y;
    score = 0;

    GLfloat vertices[] = {
        x - rx, y - ry,
        x - rx, y + ry,
        x + rx, y + ry,
        x + rx, y - ry
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

/*-----------------------------------------------------------*/

void Player::draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
