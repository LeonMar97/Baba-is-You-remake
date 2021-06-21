#pragma once
#include "Command.h"
#include<memory>
#include "Controller.h"

class ReturnToMenu : public Command{
public:
	ReturnToMenu(Controller& c, std::unique_ptr<sf::RectangleShape>rect);
	void execute()override;
private:
	Controller& m_cntrl;
};	