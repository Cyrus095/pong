#include <iostream>  // cout, abs()
#include "field.hpp"

/*-----------------------------------------------------------*/

Field::Field()
{
    ball    = new Ball(3, 4);
    playerA = new Player(10, Y_MAX/2);
    playerB = new Player(X_MAX - 10, Y_MAX/2);
}

/*-----------------------------------------------------------*/

int Field::update()
{
    ball->draw();
    return 0;

    // Moves objects
    ball->move();
    // TODO: Check input to move Player bars!

    // Check for scoring or collisions
    if (checkIfScored()) {
        ball->setXY(X_MAX/2, Y_MAX/2);
    }
    else checkCollision();

    // Check if game has ended
    if (playerA->getScore() >= end) {
        gameOver();
        return 1;
    }
    if (playerB->getScore() >= end) {
        gameOver();
        return 2;
    }

    return 0;
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

/*-----------------------------------------------------------*/

void Field::checkCollision()
{
    float dxA = ball->getX() - playerA->getX();
    float dyA = ball->getY() - playerA->getY();
    float dxB = ball->getX() - playerB->getX();
    float dyB = ball->getY() - playerB->getY();

    // Collision on x axis
    if (abs(dxA) < playerA->getRx()/2 + ball->getRadius()
        && abs(dxB) < playerB->getRx()/2 + ball->getRadius()) {
            ball->switchVx();
    }

    // Collision on y axis
    if (ball->getY() < 0 || ball->getY() > Y_MAX
        || (abs(dyA) < playerA->getRy()/2 + ball->getRadius()
        && abs(dyB) < playerB->getRy()/2 + ball->getRadius())) {
            ball->switchVy();
    }
}

/*-----------------------------------------------------------*/

void Field::gameOver()
{
    delete ball;
    delete playerA;
    delete playerB;
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
