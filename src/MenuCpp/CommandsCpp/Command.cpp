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

