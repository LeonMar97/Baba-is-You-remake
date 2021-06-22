#pragma once
#include "Command.h"
#include<memory>
class Controller;
class LvlLoadCommand : public Command {
public:
	LvlLoadCommand (std::shared_ptr<Controller>& c, std::unique_ptr<sf::RectangleShape>rect,const unsigned int& lvlNum);
	void execute()override;
private:
	std::shared_ptr<Controller>&m_cntrl;
	unsigned int m_lvl;
};