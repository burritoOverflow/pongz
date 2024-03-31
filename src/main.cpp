#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ball.h"
#include "Game.h"
#include "Player.h"
#include "Tickable.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          WINDOW_TITLE);
  Game game;
  game.defaultInit();

  void *pGame = &game;
  int frame = 0;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
          window.close();
        }
      }
    }

    window.clear(sf::Color::White);
    game.tick(pGame, frame++, event, window);
    window.display();
  }

  return 0;
}