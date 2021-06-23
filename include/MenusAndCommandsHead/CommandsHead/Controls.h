#pragma once
#include "Command.h"
#include<memory>
#include"MenuControls.h"
class Controls : public Command{
public:
	Controls(std::unique_ptr<sf::RectangleShape>rect, sf::RenderWindow& gameWindeow);
	void execute()override;
private:
	sf::RenderWindow& m_window;
	MenuControls m_menu;
};	