#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Ball.h"

Ball::Ball()
{
  this->shape = sf::CircleShape(20);
  this->shape.setFillColor(sf::Color::Black);
  this->velocityX = 2;
  this->velocityY = 1;
}

void Ball::tick(int frame, sf::Event& event, sf::RenderWindow& window)
{

  sf::Vector2f position = this->shape.getPosition();

  if (position.x < 0 || position.x > WINDOW_WIDTH)
  {
    this->velocityX *= -1;
  }

  if (position.y < 0 || position.y > WINDOW_HEIGHT)
  {
    this->velocityY *= -1;
  }

  this->shape.move(this->velocityX, this->velocityY);

  window.draw(this->shape);

}
