#include "BaseObject.h"
#include <SFML/Graphics.hpp>

BaseObject::BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCount)
	:m_animation(tex, imgCount), m_character(CHARACTER_SIZE)
{
	m_character.setTexture(&tex);
}

void BaseObject::draw(sf::RenderWindow& window, float deltaTime) {
	m_animation.update(0, deltaTime);
	m_character.setTextureRect(m_animation.texRect);
	window.draw(m_character);
}