#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    sf::RectangleShape player(sf::Vector2f(40.f, 45.f));
    auto tex = sf::Texture();
    tex.loadFromFile("Baba.PNG");
    player.setTexture(&tex);
   Animation animation(&tex, sf::Vector2u(3, 3), 0.2f);
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
                if (event.key.code == sf::Keyboard::K) player.move(sf::Vector2f(1, 0));
			break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
		animation.update(2, deltaTime);
		player.setTextureRect(animation.texRect);
        window.clear();
        window.draw(player);
        window.display();
    }
}
