#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Tickable.h"
#include "./Game.h"
#include "./Player.h"
#include "./Object.h"

Game::Game()
{

}

Game::~Game()
{
  for (Tickable* tickable : this->m_tickables) {
    delete tickable;
  }
}

void Game::add(Tickable* tickable)
{
  this->m_tickables.push_back(tickable);
}

void Game::getPlayers(std::vector<Player*>& players)
{
  players.clear();
  for (Tickable* tickable : this->m_tickables) {
    if (Object* obj = dynamic_cast<Object*>(tickable)) {
      if (obj->toString() == "Player") {
        players.push_back((Player*) tickable);
      }
    }
  }
}

void Game::tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window)
{
  for (Tickable* tickable : this->m_tickables) {
    tickable->tick(pGame, frame, event, window);
  }
}

std::string Game::toString()
{
  return "Game";
}