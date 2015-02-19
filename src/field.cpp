#include <iostream>  // cout, abs()
#include "field.hpp"
#include "matrix.hpp"

/*-----------------------------------------------------------*/

Field::Field()
{
    ball    = new Ball(0.03, 0.07);
    playerA = new Player(10, Y_MAX/2);
    playerB = new Player(X_MAX - 10, Y_MAX/2);

    GLfloat vertices[] = {
        -midRectX, -midRectY,
        -midRectX,  midRectY,
         midRectX,  midRectY,
         midRectX, -midRectY
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

    // Set up projection
    glm::mat4 view = glm::lookAt(
        glm::vec3(X_MAX/2, Y_MAX/2, 129.0f), // Camera position
        glm::vec3(X_MAX/2, Y_MAX/2, 0.0f),   // Center of the screen
        glm::vec3(0.0f, 1.0f, 0.0f)          // 'Up' direction of the camera
    );

    uniModel = glGetUniformLocation(shaderProgram, "model");

    uniView = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 300.0f);
    uniProj = glGetUniformLocation(shaderProgram, "proj");
    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

/*-----------------------------------------------------------*/

int Field::update()
{
    ball->move();

    draw();
    playerA->draw();
    playerB->draw();
    ball->draw();

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

void Field::moveAUp()
{
    playerA->moveUp();
}

/*-----------------------------------------------------------*/

void Field::moveADown()
{
    playerA->moveDown();
}

/*-----------------------------------------------------------*/

void Field::moveBUp()
{
    playerB->moveUp();
}

/*-----------------------------------------------------------*/

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

/*-----------------------------------------------------------*/

void Field::checkCollision()
{
    float dxA = ball->getX() - playerA->getX();
    float dyA = ball->getY() - playerA->getY();
    float dxB = ball->getX() - playerB->getX();
    float dyB = ball->getY() - playerB->getY();

    // Collision on x axis
    if ((abs(dxA) < playerA->getRx() + ball->getRadius()
        && (abs(dyA) < playerA->getRy() + ball->getRadius()))
        || (abs(dxB) < playerB->getRx() + ball->getRadius()
        && abs(dyB) < playerB->getRy() + ball->getRadius())) {
            ball->switchVx();
    }

    // Collision on y axis
    if (ball->getY() < 0 || ball->getY() > Y_MAX)
        ball->switchVy();
}

/*-----------------------------------------------------------*/

void Field::gameOver()
{
    delete ball;
    delete playerA;
    delete playerB;
}

/*-----------------------------------------------------------*/

void Field::draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);

    for (int dy = 0; dy < Y_MAX; dy += 3*midRectY) {
        glm::mat4 move;
        move = glm::translate(move, glm::vec3(X_MAX/2, dy, 0.0f));
        glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(move));
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
