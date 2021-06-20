#include "Command.h"
Command::Command(std::unique_ptr<sf::RectangleShape>rect)
	:
	m_buttonRect(move(rect))
{}
bool Command::contains(sf::Vector2f& mousePos) {
	return m_buttonRect->getGlobalBounds().contains(mousePos);
}
sf::RectangleShape& Command::getRect() {
	return *m_buttonRect;
}
//button function for command
void Command::mouseHover(sf::Vector2f& mousePos) {
	if (contains(mousePos) ){
		m_buttonRect->setFillColor(sf::Color::Black);
	}
	else
		m_buttonRect->setFillColor(sf::Color::White);
}

