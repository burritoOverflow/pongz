#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "Ball.h"
#include "Game.h"

// use this to leave a small amount of space between the player Shape and the
// y-axis bounds
static constexpr uint8_t PADDING = 5;

Player::Player(bool isComputer) : m_isComputer(isComputer) {
    float rectWidth = 20.0f;
    float rectHeight = 150.0f;
    float padding = 3.0f;

    this->m_shape.setSize(sf::Vector2f(rectWidth, rectHeight));
    this->m_shape.setFillColor(sf::Color::Black);

    if (this->m_isComputer) {
        this->m_shape.move(WINDOW_WIDTH - rectWidth - padding, padding);
    } else {
        this->m_shape.move(padding, padding);
    }
}

bool Player::isComputer() const { return this->m_isComputer; }

float Player::getLeft() {
    sf::FloatRect rect = this->m_shape.getGlobalBounds();
    return rect.left;
}

float Player::getRight() {
    sf::Vector2f position = this->m_shape.getPosition();
    sf::FloatRect rect = this->m_shape.getGlobalBounds();
    return rect.left + rect.width;
}

float Player::getTop() {
    sf::Vector2f position = this->m_shape.getPosition();
    return position.y;
}

float Player::getBottom() {
    sf::Vector2f position = this->m_shape.getPosition();
    sf::FloatRect rect = this->m_shape.getGlobalBounds();
    return position.y + rect.height;
}

static bool isDownKey(const sf::Keyboard::Key &code) {
    return code == sf::Keyboard::Down || code == sf::Keyboard::J;
}

static bool isUpKey(const sf::Keyboard::Key &code) {
    return code == sf::Keyboard::Up || code == sf::Keyboard::K;
}

float Player::getCenterY() { return (this->getTop() + this->getBottom()) / 2; }

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
                this->m_velocityY = -0.1f;
            } else if (isDownKey(event.key.code) &&
                       (shapePosition.y + this->m_shape.getSize().y + PADDING) <
                       WINDOW_HEIGHT) {
                this->m_velocityY = 0.1f;
            }
        }
    }

    this->m_shape.move(0, m_velocityY);
    window.draw(this->m_shape);
}

std::string Player::toString() { return "Player"; }