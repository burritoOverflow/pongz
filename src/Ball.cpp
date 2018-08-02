#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Ball.h"

Ball::Ball()
{
  this->shape = sf::CircleShape(20);
  this->shape.setFillColor(sf::Color::Black);
  this->velocityX = 0.02f;
  this->velocityY = 0.05f;
}

void Ball::tick(int frame, sf::Event& event, sf::RenderWindow& window)
{

  sf::Vector2f position = this->shape.getPosition();
  sf::FloatRect rect = this->shape.getGlobalBounds();

  float left = rect.left;
  float right = rect.left + rect.width;
  float top = position.y;
  float bottom = position.y + rect.height;

  if (left < 0.0f || right > WINDOW_WIDTH)
  {
    this->velocityX *= -1.0f;
  }

  if (top < 0.0f || bottom > WINDOW_HEIGHT)
  {
    this->velocityY *= -1.0f;
  }

  this->shape.move(this->velocityX, this->velocityY);

  window.draw(this->shape);

}
