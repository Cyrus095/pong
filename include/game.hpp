#pragma once

#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "field.hpp"

#define GAME_BGM "bgm/space.ogg"
#define FRAME_LIMIT 60           // Frames per second

/*-----------------------------------------------------------*/

// Handles the game window
class Game
{
    private:
        sf::Window *window;
        sf::Music music;
        Field *field;
        bool running;

    public:
        // Initializes the game
        Game();

        // Frees data used by the object
        ~Game();

        // Runs the game loop
        void run();

        // Analyzes if game window was closed, resized, etc.
        void windowProperties(sf::Event windowEvent);

        // Plays music defined as GAME_BGM
        void playMusic();

        // Checks user input and reacts accordingly
        void checkInput();
};
