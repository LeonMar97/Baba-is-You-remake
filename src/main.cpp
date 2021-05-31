#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    sf::RectangleShape player1(sf::Vector2f(45.f, 45.f));
    sf::RectangleShape player2(sf::Vector2f(45.f, 45.f));
    auto tex = sf::Texture();
    tex.loadFromFile("Baba.PNG");
    player1.setTexture(&tex);
    player2.setTexture(&tex);
    player2.setPosition(100, 100);
   Animation animation1(&tex, sf::Vector2u(3, 2), 0.2f);
   Animation animation2(&tex, sf::Vector2u(3, 2), 0.2f);
    float deltaTime = 0.0f;
    sf::Clock clock;
    auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

    while (window.isOpen())
    {
		deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::K) player1.move(sf::Vector2f(1, 0));
			break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
		animation1.update(1, deltaTime);
		player1.setTextureRect(animation1.texRect);
		animation2.update(0, deltaTime);
		player2.setTextureRect(animation2.texRect);
        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.display();
    }
}
