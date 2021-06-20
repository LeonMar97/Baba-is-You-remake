#pragma once
#include <SFML/Graphics.hpp>

class Command{
public:
	Command(std::unique_ptr<sf::RectangleShape>rect);
	virtual void execute() = 0;
	virtual bool contains(sf::Vector2f &mousePos);
	virtual sf::RectangleShape& getRect();

	void mouseHover(sf::Vector2f& mousePos);
protected:
	std::unique_ptr<sf::RectangleShape> m_buttonRect;
};