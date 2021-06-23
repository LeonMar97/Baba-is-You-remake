#pragma once
#include "Command.h"
#include<memory>
#include "Controller.h"
class Restart : public Command{
public:
	Restart(Controller& c, std::unique_ptr<sf::RectangleShape>rect);
	void execute()override;
private:
	Controller& m_cntrl;
};	