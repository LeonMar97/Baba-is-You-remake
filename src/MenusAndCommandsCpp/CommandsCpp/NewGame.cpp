#include"NewGame.h"
#include "Controller.h"
NewGame::NewGame(std::shared_ptr<Controller> &c, std::unique_ptr<sf::RectangleShape>rect)
	:
	Command(move(rect)),
	m_cntrl(c)
{

}
void NewGame::execute() {

	m_cntrl->loadLevel(0);
	m_cntrl->startGameLoop();
}
