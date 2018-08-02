#ifndef TICKABLE_H
#define TICKABLE_H

#include <SFML/Graphics.hpp>

class Tickable
{

  public:

    virtual void tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window) = 0;

};

#endif