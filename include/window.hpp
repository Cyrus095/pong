#pragma once

#include "SFML/Window.hpp"
#include "field.hpp"

/*-----------------------------------------------------------*/

// Handles the game window
class Window
{
    private:
        sf::Window *window;
        Field *field;
        bool running;

    public:
        // Initializes the game window
        Window();

        // Frees data used by the object
        ~Window();

        // Important function, needs beter description
        void run();

        // Checks user input and reacts accordingly
        void checkInput(sf::Event windowEvent);
};
