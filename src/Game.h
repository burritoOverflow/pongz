#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "./Tickable.h"

class Game : Tickable
{

  private:

    std::vector<Tickable*> m_tickables;

  public:

    Game();
    ~Game();
    void add(Tickable* tickable);

    // Tickable
    void tick(int frame, sf::Event& event, sf::RenderWindow& window); 

};

#endif