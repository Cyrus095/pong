#include "window.hpp"
#include "graphics.hpp"
#include "field.hpp"

/*-----------------------------------------------------------*/

Window::Window()
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
}

/*-----------------------------------------------------------*/

void Window::run()
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
        
        if (field.update() != 0) running = false;

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
            if (windowEvent.key.code == sf::Keyboard::Escape)
                running = false;
            break;

        default:
            break;
    }
}
