#include <iostream>     // cout
#include "graphics.hpp"
#include "field.hpp"

GLfloat vertices[] = {
     0.0f,  0.5f,
     0.5f, -0.5f,
    -0.5f, -0.5f
};

/*-----------------------------------------------------------*/

Graphics::Graphics()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    window = new sf::Window(sf::VideoMode(800, 600),
                            "Pong",
                            sf::Style::Close,
                            settings);

    glewExperimental = GL_TRUE;
    glewInit();

    // Create Vertex Array Object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object and copy the vertex data to it
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    compileVertexShader();
    compileFragmentShader();
    combineShaders();
    linkAttributes();
}

/*-----------------------------------------------------------*/

Graphics::~Graphics()
{
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

/*-----------------------------------------------------------*/

void Graphics::run()
{
    Field field;
    running = true;

    while (running) {
        // Clear the screen to black
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        sf::Event windowEvent;
        while (window->pollEvent(windowEvent))
            checkInput(windowEvent);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers
        window->display();
    }
}

/*-----------------------------------------------------------*/

void Graphics::checkInput(sf::Event windowEvent)
{
    switch (windowEvent.type) {

        case sf::Event::Closed:
            running = false;
            break;

        case sf::Event::KeyPressed:
            if (windowEvent.key.code == sf::Keyboard::Escape)
                running = false;
            break;

        default:
            break;
    }
}

/*-----------------------------------------------------------*/

void Graphics::compileVertexShader()
{
    // Compile vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Check if shader compiled correctly
    if (checkShader(vertexShader) != GL_TRUE) {
        std::cout << "Error when compiling vertex shader!\n";
        exit(1);
    }
}

/*-----------------------------------------------------------*/

void Graphics::compileFragmentShader()
{
    // Compile fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Check if shader compiled correctly
    if (checkShader(fragmentShader) != GL_TRUE) {
        std::cout << "Error when compiling fragment shader!\n";
        exit(1);
    }
}

/*-----------------------------------------------------------*/

GLuint Graphics::checkShader(GLuint shader)
{
    GLint status;
    GLchar buffer[512];

    glGetShaderInfoLog(shader, 512, NULL, buffer);
    printf("%s\n", buffer);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    return status;
}

/*-----------------------------------------------------------*/

void Graphics::combineShaders()
{
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glBindFragDataLocation(shaderProgram, 0, "outColor");

    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
}

/*-----------------------------------------------------------*/

void Graphics::linkAttributes()
{
    posAttrib = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(posAttrib);
}
