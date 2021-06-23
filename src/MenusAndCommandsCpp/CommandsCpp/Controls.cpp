#include"Controls.h"
#include "Controller.h"
Controls::Controls(std::unique_ptr<sf::RectangleShape>rect, sf::RenderWindow& gameWindeow)
	:
	Command(move(rect)),
	m_window(gameWindeow),
	m_menu(gameWindeow)
{

}
void Controls::execute() {
	m_menu.activate();
}
