#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Player.h"

Player::Player(bool isComputer)
: m_isComputer(isComputer)
{
  float rectWidth = 20.0f;
  float rectHeight = 150.0f;
  float padding = 3.0f;

  this->m_shape.setSize(sf::Vector2f(rectWidth, rectHeight));
  this->m_shape.setFillColor(sf::Color::Black);
  if (this->m_isComputer) {
    this->m_shape.move(WINDOW_WIDTH - rectWidth - padding, padding);
  } else {
    this->m_shape.move(padding, padding);
  }
}

bool Player::isComputer()
{
  return this->m_isComputer;
}

float Player::getLeft()
{
  sf::FloatRect rect = this->m_shape.getGlobalBounds();
  return rect.left;
}

float Player::getRight()
{
  sf::Vector2f position = this->m_shape.getPosition();
  sf::FloatRect rect = this->m_shape.getGlobalBounds();
  return rect.left + rect.width;
}

float Player::getTop()
{
  sf::Vector2f position = this->m_shape.getPosition();
  return position.y;
}

float Player::getBottom()
{
  sf::Vector2f position = this->m_shape.getPosition();
  sf::FloatRect rect = this->m_shape.getGlobalBounds();
  return position.y + rect.height;
}

void Player::tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window)
{

  if (this->m_isComputer)
  {
    
  }
  else
  {
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            this->m_shape.move(0, -0.1f);
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            this->m_shape.move(0, 0.1f);
        }
    }
  }

  window.draw(this->m_shape);

}

std::string Player::toString()
{
  return "Player";
}