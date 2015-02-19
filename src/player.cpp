#include "player.hpp"
#include "field.hpp"  // Y_MAX
#include "matrix.hpp"

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

    // Set up projection
    glm::mat4 view = glm::lookAt(
        glm::vec3(X_MAX/2, Y_MAX/2, 130.0f), // Camera position
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

void Player::moveUp()
{
    if (y + ry < Y_MAX) y += v;
}

/*-----------------------------------------------------------*/

void Player::moveDown()
{
    if (y - ry > 0) y -= v;
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

    glm::mat4 move;
    move = glm::translate(move, glm::vec3(0.0, y - Y_MAX/2, 0.0f));
    glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(move));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
