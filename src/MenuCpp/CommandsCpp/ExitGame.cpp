#include"ExitGame.h"
ExitGame::ExitGame(sf::RenderWindow& window, std::unique_ptr<sf::RectangleShape>rect) 
	:
	Command(move(rect)),
	m_window(window)
{

}
void ExitGame::execute() {
	m_window.close();
}

