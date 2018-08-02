#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Player.h"
#include "./Ball.h"
#include "./Game.h"

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

float Player::getCenterY()
{
  return (this->getTop() + this->getBottom()) / 2;
}

void Player::tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window)
{

  this->m_velocityY = 0;

  Game* game = (Game*) pGame;

  if (this->m_isComputer)
  {
    if (Ball* ball = game->getBall()) {
      if (ball->getRight() > (WINDOW_WIDTH*0.3)) {
        float direction = (ball->getCenterY() < this->getCenterY()) ? -1 : 1;
        this->m_velocityY = direction * 0.07f;
      }
    }
  }
  else
  {
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            this->m_velocityY = -0.1f;
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            this->m_velocityY = 0.1f;
        }
    }
  }

  this->m_shape.move(0, m_velocityY);

  window.draw(this->m_shape);

}

std::string Player::toString()
{
  return "Player";
}