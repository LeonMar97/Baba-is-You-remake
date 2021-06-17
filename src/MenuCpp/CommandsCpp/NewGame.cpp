#include"NewGame.h"
#include "Controller.h"
NewGame::NewGame(std::shared_ptr<Controller> &c)
	:m_cntrl(c)
{

}
void NewGame::execute() {
	m_cntrl->startGame();
}
