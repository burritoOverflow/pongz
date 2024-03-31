#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Object.h"
#include "Tickable.h"

class Player : public Tickable, public Object {
 private:
  sf::RectangleShape m_shape;
  bool m_isComputer;
  float m_velocityY;

 public:
  Player() = default;
  ~Player() override = default;
  Player(bool isComputer);
  bool isComputer() const;
  float getLeft();
  float getRight();
  float getTop();
  float getBottom();
  float getCenterY();
  float getVelocityY();

  // Tickable
  void tick(void* pGame, int frame, sf::Event& event,
            sf::RenderWindow& window) override;

  // Object
  std::string toString() override;
};

#endif