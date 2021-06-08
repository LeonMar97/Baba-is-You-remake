#include "BaseObject.h"
#include <SFML/Graphics.hpp>
#include"Attribute.h"

BaseObject::BaseObject(const sf::Texture& tex, const sf::Vector2u& imgCount, const sf::Vector2u& loc)
	:m_animation(tex, imgCount), m_character(sf::Vector2f(OBJECT_SIZE, OBJECT_SIZE)),
	m_lastPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE)
{
	
	m_character.setTexture(&tex);
	m_character.setPosition(m_lastPos);
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

sf::Vector2f BaseObject:: returnPos()const {
	return m_character.getPosition();
}


//~~~~~~~~~~~~~~~~~~~~~~~~collisions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool BaseObject::collidesWith(BaseObject* obj) {
	return m_character.getGlobalBounds().intersects(obj->m_character.getGlobalBounds());
}

void BaseObject::handleCollision(Board* board, BaseObject* obj) {
	obj->m_character.setPosition(obj->m_lastPos);
}
