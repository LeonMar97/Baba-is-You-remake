#include "BaseObject.h"
#include <SFML/Graphics.hpp>
#include"Attribute.h"

BaseObject::BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc)
	:m_animation(animationData, dir, m_sprite),
	m_lastPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE)
{
	m_sprite.setPosition(m_lastPos);
}
BaseObject::BaseObject(const AnimationData& animationData, Direction dir, const sf::Vector2u& loc, const sf::Color& color)
	:m_animation(animationData, dir, m_sprite),
	m_lastPos(loc.y* OBJECT_SIZE, loc.x* OBJECT_SIZE)
{
	m_sprite.setPosition(m_lastPos);
	m_sprite.setColor(color);
}

void BaseObject::draw(sf::RenderWindow& window, sf::Time deltaTime) {
	m_animation.update(deltaTime);
	window.draw(m_sprite);
}

void BaseObject::move(const sf::Vector2i& dir) {
	m_lastPos = m_sprite.getPosition();
	m_sprite.move(50.f * sf::Vector2f(dir));
}

sf::Vector2f BaseObject:: returnPos()const {
	return m_sprite.getPosition();
}


//~~~~~~~~~~~~~~~~~~~~~~~~collisions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool BaseObject::collidesWith(BaseObject* obj) {
	return m_sprite.getGlobalBounds().intersects(obj->m_sprite.getGlobalBounds());
}

void BaseObject::handleCollision(Board* board, BaseObject* obj) {
	obj->m_sprite.setPosition(obj->m_lastPos);
}
 const std::type_index& BaseObject::baseTypeId() {
	 return typeid(BaseObject);
}
