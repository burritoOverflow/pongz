#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "./Tickable.h"
#include "./Object.h"

class Player : public Tickable, public Object
{

  private:

    sf::RectangleShape m_shape;
    bool m_isComputer;

  public:

    Player(bool isComputer);

    // Tickable
    void tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window);
    
    // Object
    std::string toString();

};

#endif