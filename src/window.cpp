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

    glewExperimental = GL_TRUE;
    glewInit();
}

/*-----------------------------------------------------------*/

void Window::run()
{
    field = new Field();
    running = true;

    while (running) {
        // Clear the screen to black
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        sf::Event windowEvent;
        while (window->pollEvent(windowEvent))
            checkInput(windowEvent);

        // TESTING: field->printElements();
        if (field->update() != 0) running = false;

        // Swap buffers
        window->display();
    }
}

/*-----------------------------------------------------------*/

void Window::checkInput(sf::Event windowEvent)
{
    switch (windowEvent.type) {

        case sf::Event::Closed:
            running = false;
            break;

        case sf::Event::KeyPressed:
            // Main controls
            if (windowEvent.key.code == sf::Keyboard::Escape)
                running = false;

            // Move Player A
            if (windowEvent.key.code == sf::Keyboard::W)
                field->moveAUp();
            if (windowEvent.key.code == sf::Keyboard::S)
                field->moveADown();

            // Move Player B
            if (windowEvent.key.code == sf::Keyboard::Up)
                field->moveBUp();
            if (windowEvent.key.code == sf::Keyboard::Down)
                field->moveBDown();

            break;

        default:
            break;
    }
}
