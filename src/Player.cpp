#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "Ball.h"
#include "Game.h"

// use this to leave a small amount of space between the player Shape and the
// y-axis bounds
static constexpr uint8_t PADDING = 5;

Player::Player(const bool isComputer) : m_isComputer(isComputer) {
    this->m_shape.setSize(sf::Vector2f(rectWidth, rectHeight));
    this->m_shape.setFillColor(sf::Color::Black);

    if (this->m_isComputer) {
        this->m_shape.move(WINDOW_WIDTH - rectWidth - padding, padding);
    } else {
        this->m_shape.move(padding, padding);
    }
}

bool Player::isComputer() const { return this->m_isComputer; }

float Player::getLeft() const {
    sf::FloatRect rect = this->m_shape.getGlobalBounds();
    return rect.left;
}

float Player::getRight() const {
    const sf::FloatRect rect = this->m_shape.getGlobalBounds();
    return rect.left + rect.width;
}

float Player::getTop() const {
    const sf::Vector2f position = this->m_shape.getPosition();
    return position.y;
}

float Player::getBottom() const {
    const sf::Vector2f position = this->m_shape.getPosition();
    const sf::FloatRect rect = this->m_shape.getGlobalBounds();
    return position.y + rect.height;
}

static bool isDownKey(const sf::Keyboard::Key &code) {
    return code == sf::Keyboard::Down || code == sf::Keyboard::J;
}

static bool isUpKey(const sf::Keyboard::Key &code) {
    return code == sf::Keyboard::Up || code == sf::Keyboard::K;
}

float Player::getCenterY() const { return (this->getTop() + this->getBottom()) / 2; }

void Player::tick(void *pGame, int frame, sf::Event &event,
                  sf::RenderWindow &window) {
    this->m_velocityY = 0;

    if (this->m_isComputer) {
        if (Ball *ball = ((Game *) pGame)->getBall()) {
            if (ball->getRight() > (WINDOW_WIDTH * 0.3)) {
                float direction = (ball->getCenterY() < this->getCenterY()) ? -1 : 1;
                this->m_velocityY = direction * 0.07f;
            }
        }
    } else {
        if (event.type == sf::Event::KeyPressed) {
            // @TODO for some reason alphanumeric keys are not functioning for these events
            const auto shapePosition = this->m_shape.getPosition();
            if (isUpKey(event.key.code) && shapePosition.y > 0 + PADDING) {
                // move up
                this->m_velocityY = -0.1f;
            } else if (isDownKey(event.key.code) &&
                       (shapePosition.y + this->m_shape.getSize().y + PADDING) <
                       WINDOW_HEIGHT) {
                // move down
                this->m_velocityY = 0.1f;
            }
        }
    }

    this->m_shape.move(0, m_velocityY);
    window.draw(this->m_shape);
}

std::string Player::toString() { return "Player"; }