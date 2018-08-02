#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "./Tickable.h"

class Player : Tickable
{

  private:

    sf::RectangleShape m_shape;
    bool m_isComputer;

  public:

    Player(bool isComputer);

    // Tickable
    void tick(int frame, sf::Event& event, sf::RenderWindow& window);

};

#endif