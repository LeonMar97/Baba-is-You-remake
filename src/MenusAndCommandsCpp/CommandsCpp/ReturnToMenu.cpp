#include"ReturnToMenu.h"
ReturnToMenu::ReturnToMenu(Controller &c, std::unique_ptr<sf::RectangleShape>rect)
	:
	Command(move(rect)),
	m_cntrl(c)
{

}
void ReturnToMenu::execute() {

	m_cntrl.retToMainMenu();
}
