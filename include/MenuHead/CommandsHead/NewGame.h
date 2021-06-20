#pragma once
#include "Command.h"
#include<memory>
class Controller;
class NewGame : public Command{
public:
	NewGame(std::shared_ptr<Controller>& c, std::unique_ptr<sf::RectangleShape>rect);
	void execute()override;
private:
	std::shared_ptr<Controller>m_cntrl;
};	