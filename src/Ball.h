#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "./Tickable.h"

class Ball : Tickable
{

  private:

    sf::CircleShape shape;
    int velocityX;
    int velocityY;


  public:

    Ball();

    // Tickable
    void tick(int frame, sf::Event& event, sf::RenderWindow& window);

};

#endif