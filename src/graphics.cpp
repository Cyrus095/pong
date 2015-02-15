#include "graphics.hpp"
#include "field.hpp"

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
}

/*-----------------------------------------------------------*/

void Graphics::run()
{
    Field field;
    running = true;

    while (running) {
        sf::Event windowEvent;
        while (window->pollEvent(windowEvent))
            checkInput(windowEvent);

        // TODO: Update game!
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
