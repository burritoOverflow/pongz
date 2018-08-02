#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "./Tickable.h"
#include "./Object.h"

class Ball : public Tickable, public Object
{

  private:

    sf::CircleShape m_shape;
    float m_velocityX;
    float m_velocityY;

  public:

    Ball();
    float getLeft();
    float getRight();
    float getTop();
    float getBottom();

    // Tickable
    void tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window);

    // Object
    std::string toString();

};

#endif