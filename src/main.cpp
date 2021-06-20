#include <SFML/Graphics.hpp>
#include <fstream>
#include "Animation.h"
#include "Resources.h"
#include "Controller.h"
#include "MainMenu.h"

void startGame() {
    auto window = sf::RenderWindow(sf::VideoMode(1920, 1080), "Baba is you", sf::Style::Fullscreen);
    MainMenu m(window);
    m.activate();

}

int main()
{
    startGame();
   
}
