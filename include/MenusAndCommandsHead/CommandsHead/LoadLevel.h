#pragma once
#include "Command.h"
#include<memory>
#include "Controller.h"
#include "MenuLevels.h"
class LoadLevel : public Command{
public:
	LoadLevel( std::unique_ptr<sf::RectangleShape>rect, sf::RenderWindow&, std::shared_ptr<Controller>& c);
	void execute()override;
private:
	MenuLevels m_lvlMenu;
	//sf::RenderWindow& m_window;
};	