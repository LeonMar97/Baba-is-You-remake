#include "BaseObject.h"
#include <SFML/Graphics.hpp>

BaseObject::BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCount, const sf::Vector2u& loc)
	:m_animation(tex, imgCount), m_character(sf::Vector2f(OBJECT_SIZE, OBJECT_SIZE))
{
	m_character.setTexture(&tex);
	m_character.setPosition(sf::Vector2f(loc.y*OBJECT_SIZE, loc.x * OBJECT_SIZE));
}

void BaseObject::draw(sf::RenderWindow& window, float deltaTime) {
	m_animation.update(0, deltaTime);
	m_character.setTextureRect(m_animation.texRect);
	window.draw(m_character);
}
