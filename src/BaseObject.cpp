#include "BaseObject.h"
#include <SFML/Graphics.hpp>

BaseObject::BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCount, const sf::Vector2u& loc)
	:m_animation(tex, imgCount), m_character(sf::Vector2f(OBJECT_SIZE, OBJECT_SIZE)),
	m_currentPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE)
{
	m_lastPos = m_currentPos;
	m_character.setTexture(&tex);
	m_character.setPosition(m_currentPos);
}

void BaseObject::draw(sf::RenderWindow& window, float deltaTime) {
	m_animation.update(0, deltaTime);
	m_character.setTextureRect(m_animation.texRect);
	window.draw(m_character);
}

void BaseObject::move(const sf::Vector2i& dir) {
	m_lastPos = m_character.getPosition();
	m_character.move(50.f * sf::Vector2f(dir));
}

bool BaseObject::collidesWith(BaseObject* obj) {
	return m_character.getGlobalBounds().intersects(obj->m_character.getGlobalBounds());
}

void BaseObject::handleCollision(Board* board, BaseObject* obj) {
	obj->m_character.setPosition(obj->m_lastPos);
}
