#include "window.hpp"
#include "graphics.hpp"

/*-----------------------------------------------------------*/

Window::Window()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    window = new sf::Window(sf::VideoMode::getDesktopMode(),
                            "Pong",
                            sf::Style::Close|sf::Style::Fullscreen,
                            settings);

    window->setMouseCursorVisible(false);   // Hides mouse cursor
    window->setFramerateLimit(FRAME_LIMIT); // Sets frame rate!

    // Start GLEW
    glewExperimental = GL_TRUE;
    glewInit();
}

/*-----------------------------------------------------------*/

Window::~Window()
{
    delete window;
}

/*-----------------------------------------------------------*/

void Window::run()
{
    field = new Field();
    running = true;

    // Play BGM
    playMusic();

    // Game loop
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
        field->draw();

        // Swap buffers
        window->display();
    }

    delete field;
}

/*-----------------------------------------------------------*/

void Window::windowProperties(sf::Event windowEvent)
{
    if (windowEvent.type == sf::Event::Closed)
        running = false;
}

/*-----------------------------------------------------------*/

void Window::playMusic()
{
    if (!music.openFromFile(GAME_BGM)) {
        std::cout << "Error! Music '" << GAME_BGM << "' not found!\n";
        exit(-1);
    }
    music.play();
    music.setLoop(true);
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
