#include"LvlLoadCommand.h"
#include "Controller.h"
LvlLoadCommand::LvlLoadCommand(std::shared_ptr<Controller> &c, std::unique_ptr<sf::RectangleShape>rect,const unsigned int &lvlNum)
	:
	Command(move(rect)),m_lvl(lvlNum),
	m_cntrl(c)
{

}
void LvlLoadCommand::execute() {

	m_cntrl->loadLevel(m_lvl);
	m_cntrl->startGameLoop();
}
