#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Object.h"
#include "Tickable.h"

class Player : public Tickable, public Object {
private:
    sf::RectangleShape m_shape;
    bool m_isComputer{};
    float m_velocityY{};

    const float rectWidth = 20.0f;
    const float rectHeight = 150.0f;
    const float padding = 3.0f;

public:
    Player() = default;

    ~Player() override = default;

    explicit Player(bool isComputer);

    bool isComputer() const;

    float getLeft() const;

    float getRight() const;

    float getTop() const;

    float getBottom() const;

    float getCenterY() const;

    float getVelocityY() const;

    // Tickable
    void tick(void *pGame, int frame, sf::Event &event,
              sf::RenderWindow &window) override;

    // Object
    std::string toString() override;
};

#endif