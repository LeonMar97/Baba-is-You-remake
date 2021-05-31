#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Textures.h"

int main()
{
    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
    auto tex = Textures::instance().get_Textures(flags_t);
    player.scale(0.8f, 0.8f);
    player.setTexture(&tex);
   Animation animation(&tex, sf::Vector2u(3, 1), 0.2f);
   float deltaTime = 0.0f;
   sf::Clock clock;
   auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

   int row = 0;
   while (window.isOpen())
   {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::K) {
                    player.move(sf::Vector2f(5, 0));
                }
			break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
		animation.update(row, deltaTime);
		player.setTextureRect(animation.texRect);
        window.clear();
        window.draw(player);
        window.display();
   }
}
