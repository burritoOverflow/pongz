#include "Game.h"

#include <SFML/Graphics.hpp>
#include <vector>

#include "Object.h"
#include "Player.h"
#include "Tickable.h"

Game::Game() {}

Game::~Game() {
  for (Tickable* tickable : this->m_tickables) {
    delete tickable;
  }
}

void Game::defaultInit() {
  this->add((Tickable*)new Ball());
  this->add((Tickable*)new Player(false));
  this->add((Tickable*)new Player(true));
}

void Game::add(Tickable* tickable) { this->m_tickables.push_back(tickable); }

Ball* Game::getBall() {
  for (Tickable* tickable : this->m_tickables) {
    if (auto* obj = dynamic_cast<Object*>(tickable)) {
      if (obj->toString() == "Ball") {
        return (Ball*)obj;
      }
    }
  }
  return nullptr;
}

std::vector<Player*> Game::getPlayers() {
  std::vector<Player*> players;

  for (Tickable* tickable : this->m_tickables) {
    if (Object* obj = dynamic_cast<Object*>(tickable)) {
      if (obj->toString() == "Player") {
        players.push_back((Player*)tickable);
      }
    }
  }
  return players;
}

void Game::tick(void* pGame, int frame, sf::Event& event,
                sf::RenderWindow& window) {
  for (Tickable* tickable : this->m_tickables) {
    tickable->tick(pGame, frame, event, window);
  }
}

std::string Game::toString() { return "Game"; }