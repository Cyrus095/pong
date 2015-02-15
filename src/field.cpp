#include <iostream>  // cout
#include <cmath>     // M_PI
#include "field.hpp"

static bool checkIfScored();
static void checkCollision();

/*-----------------------------------------------------------*/

Field::Field()
{
    playerA = new Player(10, sizeY/2);
    playerB = new Player(sizeX - 10, sizeY/2);
    ball = new Ball(sizeX/2, sizeY/2, M_PI/3);
}

/*-----------------------------------------------------------*/

void Field::update()
{
    ball->move();
    playerA->move();
    playerB->move();
}

/*-----------------------------------------------------------*/

void Field::printPositions()
{
    std::cout << "B : " << ball->getX() << ", " << ball->getY() << std::endl;
    std::cout << "PA: " << playerA->getX() << ", " << playerA->getY() << std::endl;
    std::cout << "PB: " << playerB->getX() << ", " << playerB->getY() << std::endl;
}

/*-----------------------------------------------------------*
 *
 * Checks and returns whether a Player scored.
 *
 */
static bool checkIfScored()
{
    return true;
}

/*-----------------------------------------------------------*
 *
 * Checks if Ball collided with walls or bars.
 *
 */
static void checkCollision()
{

}
