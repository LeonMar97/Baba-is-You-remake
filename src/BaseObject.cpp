#include "BaseObject.h"
#include <SFML/Graphics.hpp>

BaseObject::BaseObject(const Animation& animation)
	:m_animation(animation), m_character(CHARACTER_SIZE)
{
	
}

void BaseObject::draw(sf::RenderWindow& window, float deltaTime) {
	m_animation.update(0, deltaTime);
	m_character.setTextureRect(m_animation.texRect);
	window.draw(m_character);
}