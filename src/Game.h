#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Ball.h"
#include "Object.h"
#include "Player.h"
#include "Tickable.h"

class Game : public Tickable, public Object {
 private:
  std::vector<Tickable*> m_tickables;

 public:
  Game();
  ~Game();
  void add(Tickable* tickable);
  void defaultInit();
  Ball* getBall();
  std::vector<Player*> getPlayers();

  // Tickable
  void tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window);

  // Object
  std::string toString();
};

#endif