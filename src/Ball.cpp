#include "./Ball.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Game.h"
#include "Player.h"

static constexpr float INIT_VELOCITY = 0.1f;

Ball::Ball() {
  this->m_shape.setRadius(35);
  this->m_shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  this->m_shape.setFillColor(sf::Color::Red);
  this->m_velocityX = INIT_VELOCITY;
  this->m_velocityY = INIT_VELOCITY;
}

float Ball::getLeft() {
  sf::FloatRect rect = this->m_shape.getGlobalBounds();
  return rect.left;
}

float Ball::getRight() {
  sf::Vector2f position = this->m_shape.getPosition();
  sf::FloatRect rect = this->m_shape.getGlobalBounds();
  return rect.left + rect.width;
}

float Ball::getTop() {
  sf::Vector2f position = this->m_shape.getPosition();
  return position.y;
}

float Ball::getBottom() {
  sf::Vector2f position = this->m_shape.getPosition();
  sf::FloatRect rect = this->m_shape.getGlobalBounds();
  return position.y + rect.height;
}

float Ball::getCenterY() { return (this->getTop() + this->getBottom()) / 2; }

void Ball::tick(void* pGame, int frame, sf::Event& event,
                sf::RenderWindow& window) {
  float left = this->getLeft();
  float right = this->getRight();
  float top = this->getTop();
  float bottom = this->getBottom();

  std::vector<Player*> players = ((Game*)pGame)->getPlayers();
  for (Player* player : players) {
    if (player->isComputer()) {
      if (right > player->getLeft() && top > player->getTop() &&
          bottom < player->getBottom()) {
        this->m_velocityX *= -1.0f;
      }
    } else {  // is human player
      if (left < player->getRight() && top > player->getTop() &&
          bottom < player->getBottom()) {
        this->m_velocityX *= -1.0f;
      }
    }
  }

  if (left < 0.0f || right > WINDOW_WIDTH) {
    this->m_velocityX *= -1.0f;
  }

  if (top < 0.0f || bottom > WINDOW_HEIGHT) {
    this->m_velocityY *= -1.0f;
  }

  this->m_shape.move(this->m_velocityX, this->m_velocityY);
  window.draw(this->m_shape);
}

std::string Ball::toString() { return "Ball"; }