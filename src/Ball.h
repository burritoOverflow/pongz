#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "./Tickable.h"

class Ball : Tickable
{

  private:

    sf::CircleShape shape;
    float velocityX;
    float velocityY;

  public:

    Ball();
    float getTop();
    float getBottom();
    float getLeft();
    float getRight();

    // Tickable
    void tick(int frame, sf::Event& event, sf::RenderWindow& window);

};

#endif