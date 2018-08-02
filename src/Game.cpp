#include <iostream>

#include <SFML/Graphics.hpp>

#include "./Tickable.h"
#include "./Game.h"

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

void Game::tick(int frame, sf::Event& event, sf::RenderWindow& window)
{
  for (Tickable* tickable : this->m_tickables) {
    tickable->tick(frame, event, window);
  }
}
