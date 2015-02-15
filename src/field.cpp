#include <iostream>  // cout, abs()
#include <cmath>     // M_PI
#include "field.hpp"

/*-----------------------------------------------------------*/

Field::Field()
{
    playerA = new Player(10, Y_MAX/2);
    playerB = new Player(X_MAX - 10, Y_MAX/2);
    ball = new Ball(X_MAX/2, Y_MAX/2, M_PI/3);
}

/*-----------------------------------------------------------*/

int Field::update()
{
    // Moves objects
    ball->move();
    playerA->move();
    playerB->move();

    // Check for collisions
    if (checkIfScored()) {
        // Recreate the ball
        delete ball;
        ball = new Ball(X_MAX/2, Y_MAX/2, M_PI/3);
    }
    else if (checkCollision())
        ball->collision();

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

void Field::printElements()
{
    std::cout << "B : " << ball->getX() << ", " << ball->getY() << std::endl;
    std::cout << "PA: " << playerA->getX() << ", " << playerA->getY() << std::endl;
    std::cout << "PB: " << playerB->getX() << ", " << playerB->getY() << std::endl;
    std::cout << "SA: " << playerA->getScore() << std::endl;
    std::cout << "SB: " << playerB->getScore() << std::endl;
}

/*-----------------------------------------------------------*
 *
 * Checks whether a Player scored, attributing a point if so.
 * Returns true if any Player scored, and false otherwise.
 *
 */
bool Field::checkIfScored()
{
    if (ball->getX() < 0) {
        playerA->updateScore();
        return true;
    }
    if (ball->getX() > X_MAX) {
        playerB->updateScore();
        return true;
    }

    return false;
}

/*-----------------------------------------------------------*
 *
 * Checks if Ball collided with walls or bars.
 *
 */
bool Field::checkCollision()
{
    double dxA = ball->getX() - playerA->getX();
    double dyA = ball->getY() - playerA->getY();
    double dxB = ball->getX() - playerB->getX();
    double dyB = ball->getY() - playerB->getY();

    return
        // Ball's colision with upper or lower wall
        (ball->getY() < 0 || ball->getY() > Y_MAX)

        // Ball's collision with PlayerA's bar
        || (abs(dxA) < playerA->getRx()/2 + ball->getRadius())
        || (abs(dyA) < playerA->getRy()/2 + ball->getRadius())

        // Ball's collision with PlayerB's bar
        || (abs(dxB) < playerB->getRx()/2 + ball->getRadius())
        || (abs(dyB) < playerB->getRy()/2 + ball->getRadius());
}

/*-----------------------------------------------------------*
 *
 * Ends the game by freeing used memory.
 *
 */
void Field::gameOver()
{
    delete ball;
    delete playerA;
    delete playerB;
}
