#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "./Tickable.h"
#include "./Ball.h"
#include "./Player.h"
#include "./Object.h"

class Game : public Tickable, public Object
{

  private:

    std::vector<Tickable*> m_tickables;

  public:

    Game();
    ~Game();
    void add(Tickable* tickable);
    void getPlayers(std::vector<Player*>& players);

    // Tickable
    void tick(void* pGame, int frame, sf::Event& event, sf::RenderWindow& window); 

    // Object
    std::string toString();

};

#endif