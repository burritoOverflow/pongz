#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Tickable.h"
#include "./Game.h"
#include "./Ball.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    Game game;
    game.add((Tickable*) new Ball());

    int frame = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        game.tick(frame++, event, window);
        window.display();
    }

    return 0;
}