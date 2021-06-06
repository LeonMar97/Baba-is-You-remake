#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
class Controller;
class Menu {
private:
	sf::RenderWindow& m_menuWindow;
	Controller& m_ctrl;
	sf::RectangleShape m_startGameButton;
	sf::RectangleShape m_exitGameButton;
public:
	Menu(Controller& ctrl, sf::RenderWindow&);
	void run();
};