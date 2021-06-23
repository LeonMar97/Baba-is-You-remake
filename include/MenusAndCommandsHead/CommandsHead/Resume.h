#pragma once
#include "Command.h"
#include<memory>

class Resume : public Command{
public:
	Resume(std::unique_ptr<sf::RectangleShape>rect);
	void execute()override;
private:
	//sf::RenderWindow& m_window;
};	