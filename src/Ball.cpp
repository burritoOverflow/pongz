#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Ball.h"

Ball::Ball()
{
  this->m_shape.setRadius(20);
  this->m_shape.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
  this->m_shape.setFillColor(sf::Color::Black);
  this->m_velocityX = 0.04f;
  this->m_velocityY = 0.05f;
}

void Ball::tick(int frame, sf::Event& event, sf::RenderWindow& window)
{

  sf::Vector2f position = this->m_shape.getPosition();
  sf::FloatRect rect = this->m_shape.getGlobalBounds();

  float left = rect.left;
  float right = rect.left + rect.width;
  float top = position.y;
  float bottom = position.y + rect.height;

  if (left < 0.0f || right > WINDOW_WIDTH)
  {
    this->m_velocityX *= -1.0f;
  }

  if (top < 0.0f || bottom > WINDOW_HEIGHT)
  {
    this->m_velocityY *= -1.0f;
  }

  this->m_shape.move(this->m_velocityX, this->m_velocityY);

  window.draw(this->m_shape);

}
