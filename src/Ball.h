#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "Object.h"
#include "Tickable.h"

class Ball : public Tickable, public Object {
 private:
  sf::CircleShape m_shape;
  float m_velocityX;
  float m_velocityY;

 public:
  Ball();
  ~Ball() override = default;
  float getLeft();
  float getRight();
  float getTop();
  float getBottom();
  float getCenterY();

  // Tickable
  void tick(void* pGame, int frame, sf::Event& event,
            sf::RenderWindow& window) override;

  // Object
  std::string toString() override;
};

#endif