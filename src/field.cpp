#include <iostream>  // cout, abs()
#include <cmath>     // tan()
#include "field.hpp"
#include "matrix.hpp"

/*-----------------------------------------------------------*/

Field::Field()
{
    ball    = new Ball(1.5, 2.5);
    playerA = new Player(10, Y_MAX/2);
    playerB = new Player(X_MAX - 10, Y_MAX/2);

    GLfloat vertices[8] = {
        -MID_RECT_X, -MID_RECT_Y,
        -MID_RECT_X,  MID_RECT_Y,
         MID_RECT_X,  MID_RECT_Y,
         MID_RECT_X, -MID_RECT_Y
    };

    Drawable::begin(vertices, GL_STATIC_DRAW);
}

Field::~Field()
{
    delete ball;
    delete playerA;
    delete playerB;
}

/*-----------------------------------------------------------*/

int Field::update()
{
    ball->move();

    // Check for scoring or collisions
    if (checkIfScored()) {
        ball->setXY(X_MAX/2, Y_MAX/2);
    }
    else checkCollision();

    // Check if game has ended
    if (playerA->getScore() >= END_SCORE)
        return 1;
    if (playerB->getScore() >= END_SCORE)
        return 2;

    return 0;
}

/*-----------------------------------------------------------*/

void Field::moveAUp()
{
    playerA->moveUp();
}

void Field::moveADown()
{
    playerA->moveDown();
}

void Field::moveBUp()
{
    playerB->moveUp();
}

void Field::moveBDown()
{
    playerB->moveDown();
}

/*-----------------------------------------------------------*/

bool Field::checkIfScored()
{
    if (ball->getX() < 0) {
        playerB->updateScore();
        return true;
    }
    if (ball->getX() > X_MAX) {
        playerA->updateScore();
        return true;
    }

    return false;
}

void Field::checkCollision()
{
    float dxA = ball->getX() - playerA->getX();
    float dyA = ball->getY() - playerA->getY();
    float dxB = ball->getX() - playerB->getX();
    float dyB = ball->getY() - playerB->getY();

    // Collision on x axis - Player A
    if ((abs(dxA) <= playerA->getRx() + ball->getRadius()
        && (abs(dyA) <= playerA->getRy() + ball->getRadius())
        && ball->getVx() < 0)) {
            if (abs(tan(dyA/dxA)) >= tan(playerA->getRy()/playerA->getRx()))
                ball->switchVx();
            else
                ball->switchVy();
        }

    // Collision on x axis - Player B
    if ((abs(dxB) <= playerB->getRx() + ball->getRadius()
        && (abs(dyB) <= playerB->getRy() + ball->getRadius())
        && ball->getVx() > 0)) {
            if (abs(tan(dyB/dxB)) >= tan(playerB->getRy()/playerB->getRx()))
                ball->switchVx();
            else
                ball->switchVy();
        }

    // Collision on y axis
    if ((ball->getY() - ball->getRadius() < 0)
        || (ball->getY() + ball->getRadius() > Y_MAX))
            ball->switchVy();
}

/*-----------------------------------------------------------*/

void Field::draw()
{
    playerA->draw();
    playerB->draw();
    ball->draw();

    Drawable::draw();

    for (int dy = MID_RECT_Y; dy < Y_MAX; dy += 3 * MID_RECT_Y) {
        glm::mat4 move;
        move = glm::translate(move, glm::vec3(X_MAX/2, dy, 0.0f));
        glUniformMatrix4fv(getUniModel(), 1, GL_FALSE, glm::value_ptr(move));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

/*-----------------------------------------------------------*/

void Field::printElements()
{
    std::cout << "B : " << ball->getX() << ", " << ball->getY() << std::endl;
    std::cout << "PA: " << playerA->getX() << ", " << playerA->getY() << std::endl;
    std::cout << "PB: " << playerB->getX() << ", " << playerB->getY() << std::endl;
    std::cout << "SA: " << playerA->getScore() << std::endl;
    std::cout << "SB: " << playerB->getScore() << std::endl;
}
