#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Menu {
private:
	sf::RenderWindow& m_menuWindow;
public:
	Menu(sf::RenderWindow&);
};