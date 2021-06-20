#pragma once
#include "Command.h"
#include<memory>

class ExitGame : public Command{
public:
	ExitGame(sf::RenderWindow & window, std::unique_ptr<sf::RectangleShape>rect);
	void execute()override;
private:
	sf::RenderWindow& m_window;
};	