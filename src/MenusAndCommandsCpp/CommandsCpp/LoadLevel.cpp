#include"LoadLevel.h"
LoadLevel::LoadLevel(std::unique_ptr<sf::RectangleShape>rect, sf::RenderWindow&window, std::shared_ptr<Controller>& c)
	:
	Command(move(rect)),
	m_lvlMenu(window,c)
{

}
void LoadLevel::execute() {
	m_lvlMenu.activate();
}
