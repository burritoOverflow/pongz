#include <SFML/Graphics.hpp>

int main()
{

    int windowWidth = 800;
    int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    int velocityX = 1;
    int velocityY = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(shape);
        // shape.move(velocityX, velocityY);

        window.display();
    }

    return 0;
}