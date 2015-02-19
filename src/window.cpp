#include "window.hpp"
#include "graphics.hpp"

/*-----------------------------------------------------------*/

Window::Window()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    window = new sf::Window(sf::VideoMode(800, 600),
                            "Pong",
                            sf::Style::Close|sf::Style::Fullscreen,
                            settings);
    window->setMouseCursorVisible(false); // Hide mouse cursor

    // Start GLEW
    glewExperimental = GL_TRUE;
    glewInit();
}

/*-----------------------------------------------------------*/

void Window::run()
{
    field = new Field();
    running = true;

    // Play bgm
    sf::Music music;
    if (!music.openFromFile("bgm/space.ogg"))
        exit(-1);
    music.play();

    while (running) {
        // Clear the screen to black
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        sf::Event windowEvent;
        while (window->pollEvent(windowEvent))
            windowProperties(windowEvent);

        
        checkInput();
        /* TESTING: field->printElements(); */
        if (field->update() != 0) running = false;

        // Swap buffers
        window->display();
    }
}

/*-----------------------------------------------------------*/

void Window::windowProperties(sf::Event windowEvent)
{
    if (windowEvent.type == sf::Event::Closed)
        running = false;
}

/*-----------------------------------------------------------*/

void Window::checkInput()
{
    // Main controls
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        running = false;

    // Move Player A
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        field->moveAUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        field->moveADown();

    // Move Player B
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        field->moveBUp();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        field->moveBDown();
}
