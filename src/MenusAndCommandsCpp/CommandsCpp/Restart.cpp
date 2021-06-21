#include"Restart.h"
Restart::Restart(Controller& c, std::unique_ptr<sf::RectangleShape>rect)
	:
	Command(move(rect)),
	m_cntrl(c)
{

}
void Restart::execute() {
	m_cntrl.restart();
}
